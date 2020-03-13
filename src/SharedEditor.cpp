//
// Created by asant on 05/10/2019.
//

#define INSERT 1
#define DELETE -1

#include <exception>
#include <algorithm>
#include <random>
#include <iostream>
#include "SharedEditor.h"
#include "NetworkServer.h"

SharedEditor::SharedEditor(NetworkServer &server)
        : _server(server), _counter(0), base(32), boundary(10) {
    _siteId = server.connect(this);
}

NetworkServer &SharedEditor::getServer() const {
    return _server;
}

int SharedEditor::getSiteId() const {
    return _siteId;
}

std::vector<Symbol> & SharedEditor::getSymbols() {
    return _symbols;
}

int SharedEditor::getCounter() const {
    return _counter;
}

bool SharedEditor::retrieveStrategy(int level) {
    if (strategies.size() < level && level != 0) {
        return strategies.at(level);
    }
    bool strategy;
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(1, 10);
    int n = distribution(generator);
    strategy = n % 2 == 0;
    this->strategies.insert(std::pair<int,bool>(level, strategy));
    return strategy;
}

/**
 *
 * @param min
 * @param max
 * @param strategy
 * @return random number in ]min, max[
 */
int SharedEditor::generateIdBetween(int min, int max, bool strategy) const {

    if (min < 0 && max < 0) {
        throw std::invalid_argument("min and max is negative");
    }
    if (min < 0) {
        throw std::invalid_argument("min is negative");
    }
    if (max < 0) {
        throw std::invalid_argument("max is negative");
    }
    if (max < min) {
        throw std::range_error("min is greater than max");
    }
    if (min == max) {
        throw std::range_error("min is equal to max");
    }

    std::random_device random_device;
    std::mt19937 generator(random_device());

    if ((max - min) < boundary) {
        min = min + 1;
        max = max - 1;
    } else {
        if (!strategy) { // boundary-
            min = max - boundary;
            max = max - 1;
        } else { // boundary+
            max = min + boundary;
            min = min + 1;
        }
    }
    std::uniform_int_distribution<> distribution(min, max);
    return distribution(generator);
}

/**
 *
 * @param index
 * @return the pos of the next previous symbol from index
 */
std::vector<int> SharedEditor::findPosBefore(int index) {
    if (index < 0) {
        throw std::invalid_argument("index is negative");
    }
    std::vector<int> pos;
    if (_symbols.empty()) {
        pos = {0};
    } else {
        if (index == 0) {
            pos = {0};
        } else if (index > _counter) {
            pos = _symbols.back().getPosition();
        } else {
            pos = _symbols.at(index - 1).getPosition();
        }
    }
    return pos;
}

std::vector<int> SharedEditor::findPosAfter(int index) {
    std::vector<int> pos;
    if (_symbols.empty()) {
        pos = {this->base};
    } else {
        if (index >= _counter) {
            pos = {this->base};
        } else {
            pos = _symbols.at(index).getPosition();
        }
    }

    return pos;
}

/**
 *
 * @param pos1
 * @param pos2
 * @param newPos
 * @param level
 * @return fractional pos between pos1 and pos2
 */
std::vector<int> SharedEditor::generatePosBetween(std::vector<int> pos1, std::vector<int> pos2, std::vector<int> newPos, int level) {
    if (pos1.empty()) {
        throw std::invalid_argument("pos1 is empty");
    }
    if (level < 0) {
        throw std::invalid_argument("level is negative");
    }

    int id1 = 0;
    int id2 = static_cast<int>(std::pow(2, level)*base);
    if (pos1.size() > level) {
        id1 = pos1.at(level);
    }
    if (!pos2.empty() && pos2.size() > level) {
        id2 = pos2.at(level);
    }

    bool boundaryStrategy = retrieveStrategy(level);

    if ((id2 - id1) > 1) {
        int newId = 0;
        try {
            newId = generateIdBetween(id1, id2, boundaryStrategy);
        } catch (std::exception& e) {
            throw;
        }
        newPos.push_back(newId);
        return newPos;
    } else if ((id2 - id1) == 1) {
        newPos.push_back(id1);
        try {
            return this->generatePosBetween(pos1, {}, newPos, level+1);
        } catch(...) {
            throw;
        }
    } else if (id1 == id2) {
        newPos.push_back(id1);
        try {
            return this->generatePosBetween(pos1, pos2, newPos, level+1);
        } catch(...) {
            throw;
        }
    }
}

/**
 *
 * @param index
 * @param value
 * insert value at index in symbols
 */
void SharedEditor::localInsert(int index, char value) {
    if (index < 0) {
        throw std::invalid_argument("index is negative");
    }

    std::string sym_id = std::to_string(_siteId);
    sym_id.append("_");
    sym_id.append(std::to_string(_counter));
    std::vector<int> sym_position;

    std::vector<int> pos1 = findPosBefore(index);
    std::vector<int> pos2 = findPosAfter(index);
    try {
        sym_position = generatePosBetween(pos1, pos2, sym_position, 0);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl << "localInsert failed" << std::endl;
        return;
    }

    Symbol sym(value, sym_id, sym_position);
    if (index >= _counter) {
        _symbols.push_back(sym);
    } else {
        _symbols.insert(_symbols.begin() + index, sym);
    }
    _counter++;
    Message m(INSERT, sym, _siteId);
    _server.send(m);
}

void SharedEditor::localErase(int index) {
    if (_symbols.empty()) {
        return;
    } else if (index > _counter) {
        Symbol sym = _symbols.back();
        _symbols.pop_back();
        _counter--;
        Message m(DELETE, sym, _siteId);
        _server.send(m);
    } else {
        Symbol sym = _symbols.at(index);
        _symbols.erase(_symbols.begin() + index);
        _counter--;
        Message m(DELETE, sym, _siteId);
        _server.send(m);
    }
}

void SharedEditor::process(const Message &m) {
    Symbol symbol = m.getS();
    auto it = _symbols.begin();
    int index = 0;
    switch (m.getType()) {
        case INSERT:
            if (_symbols.empty()) {
                _symbols.insert(_symbols.begin(), symbol);
            } else {
                while (it != _symbols.end()) {
                    if (symbol < *it) {
                        _symbols.insert(_symbols.begin() + index, symbol);
                        break;
                    } else if (symbol.getPosition() == it->getPosition()) {
                        std::vector<int> sym_position;
                        sym_position = generatePosBetween(symbol.getPosition(), it->getPosition(), sym_position, 0);
                        symbol.setPosition(sym_position);
                        _symbols.insert(_symbols.begin() + index, symbol);
                    }
                    it++;
                    index++;
                }
                if (it == _symbols.end()) {
                    _symbols.push_back(symbol);
                }
            }
            _counter++;
            break;

        case DELETE:
            if (!_symbols.empty()) {
                while (it != _symbols.end()) {
                    if (*it == symbol) {
                        _symbols.erase(_symbols.begin() + index);
                        _counter--;
                        break;
                    }
                    it++;
                    index++;
                }
            }
            break;

        default:
            break;
    }
}

std::string SharedEditor::to_string() {
    std::string string;
    std::for_each(_symbols.begin(), _symbols.end(), [&](Symbol s){
        string += s.getC();
    });
    return string;
}

void SharedEditor::setServer(NetworkServer &server) {
    _server = server;
}

int SharedEditor::getBase() const {
    return base;
}

void SharedEditor::setCounter(int counter) {
    _counter = counter;
}
