#define INSERT 1
#define DELETE -1

#include <exception>
#include <algorithm>
#include <random>
#include <iostream>
#include "SharedEditor.h"
#include "NetworkServer.h"

static std::random_device random_device;
static std::mt19937 generator(random_device());

SharedEditor::SharedEditor(NetworkServer &server)
        : _server(server), _counter(0), base(32), boundary(10), counter_id(0) {
    _siteId = server.connect(this);
}

NetworkServer& SharedEditor::getServer() const {
    return _server;
}

int SharedEditor::getSiteId() const {
    return _siteId;
}

std::vector<std::vector<Symbol>>& SharedEditor::getSymbols() {
    return _symbols;
}

int SharedEditor::getCounter() const {
    return _counter;
}

bool SharedEditor::retrieveStrategy(int level) {
    if (level < 0) {
        throw std::invalid_argument("level is negative");
    }
    if (strategies.size() < level && level != 0) {
        return strategies.at(level);
    }
    bool strategy;
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
 * @return the position of the next previous symbol from pos
 */
std::vector<int> SharedEditor::findPosBefore(Position pos) {

    int line = pos.line;
    int index = pos.index;

    if (line < 0) {
        throw std::out_of_range("line is negative");
    } else if (line > _symbols.size()) {
        throw std::out_of_range("line out of range");
    } else if (index < 0) {
        throw std::out_of_range("index is negative");
    } else if (index > _symbols[line].size()) {
        throw std::out_of_range("index out of range");
    }

    if (_symbols.empty()) {
        return {0};
    }


    if (index == 0 && line == 0) {
        return {0};
    } else if (index == 0 && line != 0) {
        line = line - 1;
        index = _symbols[line].size();
    }

    return _symbols[line].at(index-1).getPosition();
}

/**
 *
 * @param index
 * @return the position of the next following symbol from pos
 */
std::vector<int> SharedEditor::findPosAfter(Position pos) {

    int line = pos.line;
    int index = pos.index;

    if (line < 0) {
        throw std::out_of_range("line is negative");
    } else if (line > _symbols.size()) {
        throw std::out_of_range("line out of range");
    } else if (index < 0) {
        throw std::out_of_range("index is negative");
    } else if (index > _symbols[line].size()) {
        throw std::out_of_range("index out of range");
    }

    if (_symbols.empty()) {
        return {this->base};
    }

    int nLines = _symbols.size();

    if (line == nLines - 1 && index == _symbols[nLines - 1].size()) {
        return {this->base};
    } else if (line < nLines - 1 && index == _symbols[line].size()) {
        line++;
        index = 0;
    } else if (line > nLines - 1 && index == 0) {
        return {this->base}; // todo check
    }

    return _symbols[line].at(index).getPosition();
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
 * @param pos
 * @param symbol
 * insert symbol at the given pos
 */
void SharedEditor::insertSymbol(Position pos, Symbol symbol) {

    int line = pos.line;
    int index = pos.index;
    char value = symbol.getC();

    if (_symbols.begin()+line == _symbols.end()) {
        _symbols.emplace_back();
    }

    if (_symbols[line].begin()+index == _symbols[line].end()) {
        line++;
        index = 0;
        _symbols.emplace_back();
    }

    if (value == '\n') {

        std::vector<Symbol> lineAfter;

        if (index == _symbols[line].size()) {
            lineAfter = {};
        } else {
            lineAfter.assign(_symbols[line].begin() + index, _symbols[line].end());
        }

        if (lineAfter.empty()) {
            _symbols[line].push_back(symbol);
        } else {
            std::vector<Symbol> lineBefore(_symbols[line].begin(), _symbols[line].begin() + index);
            lineBefore.push_back(symbol);
            _symbols[line] = lineBefore;
            _symbols.insert(_symbols.begin() + line + 1, lineAfter);
        }
    } else {
        _symbols[line].insert(_symbols[line].begin() + index, symbol);
    }
}

/**
 *
 * @param index
 * @param value
 * insert value at index in symbols
 */
void SharedEditor::localInsert(Position pos, char value) {

    std::string sym_id = std::to_string(_siteId);
    sym_id.append("_");
    sym_id.append(std::to_string(counter_id));
    std::vector<int> sym_position;
    std::vector<int> pos1;
    std::vector<int> pos2;
    try {
        pos1 = findPosBefore(pos);
        pos2 = findPosAfter(pos);
        sym_position = generatePosBetween(pos1, pos2, sym_position, 0);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl << ", localInsert failed" << std::endl;
        return;
    }

    Symbol sym(value, sym_id, sym_position);
    insertSymbol(pos, sym);
    _counter++;
    counter_id++;

    Message m(INSERT, sym, _siteId);
    _server.send(m);
}

/**
 *
 * @param startPos
 * @param endPos
 * @return symbols erased from [startPos, endPos] in a single line
 */
std::vector<Symbol> SharedEditor::eraseSingleLine(Position startPos, Position endPos) {
    int startIndex = startPos.index;
    int endIndex = endPos.index+1;
    int line = startPos.line;

    std::vector<Symbol> symbols(_symbols[line].begin() + startIndex, _symbols[line].begin() + endIndex);
    _symbols[line].erase(_symbols[line].begin() + startIndex, _symbols[line].begin() + endIndex);

    return symbols;
}

/**
 *
 * @param startPos
 * @param endPos
 * @return symbols erased from [startPos, endPos] between multiple lines
 */
std::vector<Symbol> SharedEditor::eraseMultipleLines(Position startPos, Position endPos) {
    int startIndex = startPos.index;
    int endIndex = endPos.index;
    int startLine = startPos.line;
    int endLine = endPos.line;

    std::vector<Symbol> symbols(_symbols[startLine].begin() + startIndex, _symbols[startLine].end());
    for (int i = startLine+1; i < endLine; i++) {
        symbols.insert(symbols.end(), _symbols[i].begin(), _symbols[i].end());
    }
    symbols.insert(symbols.end(), _symbols[endLine].begin(), _symbols[endLine].begin() + endIndex+1);
    _symbols[startLine].erase(_symbols[startLine].begin() + startIndex, _symbols[startLine].end());
    _symbols[endLine].erase(_symbols[endLine].begin(), _symbols[endLine].begin() + endIndex + 1);
    if (endLine-startLine != 1) {
        _symbols.erase(_symbols.begin() + startLine + 1, _symbols.begin() + endLine);
    }

    return symbols;
}

/**
 *
 * @param index
 * remove symbols from [startPos, endPos]
 */
void SharedEditor::localErase(Position startPos, Position endPos) {

    int startLine = startPos.line;
    int endLine = endPos.line;
    int startIndex = startPos.index;
    int endIndex = endPos.index;

    std::vector<Symbol> symbols;
    bool mergeLines = false;
    if (_symbols.empty()) {
        return;
    } else if (startLine != endLine) {
        symbols = eraseMultipleLines(startPos, endPos);
        mergeLines = true;
    } else {
        symbols = eraseSingleLine(startPos, endPos);
        if (symbols.back().getC() == '\n') {
            if (_symbols.back().empty()) {
                _symbols.erase(_symbols.end());
            } else {
                mergeLines = true;
            }
        }
    }

    if (mergeLines) {
        _symbols[startLine].insert(_symbols[startLine].end(), _symbols[startLine+1].begin(), _symbols[startLine+1].end());
        _symbols.erase(_symbols.begin() + startLine+1);
        if (_symbols[startLine].empty()) {
            _symbols.erase(_symbols.begin() + startLine);
        }
    }

    for (Symbol sym : symbols) {
        Message m(DELETE, sym, _siteId);
        _counter--;
        _server.send(m);
    }

}


/**
 *
 * @param symbol
 * insert symbol right before the first one with the higher fractional position
 */
void SharedEditor::remoteInsert(Symbol symbol) {
    std::vector<std::vector<Symbol>>::iterator line_it;
    line_it = std::lower_bound(_symbols.begin(), _symbols.end(), symbol, [](const std::vector<Symbol> & it, const Symbol& symbol){
        return it[0] < symbol;
    });
    int line = line_it - _symbols.begin();

    if (line_it == _symbols.begin() && symbol < (*line_it)[0]) {
        insertSymbol(Position(0, 0), symbol);
    } else {
        line_it--;
        line--;
        std::vector<Symbol>::iterator index_it;
        index_it = std::lower_bound(line_it->begin(), line_it->end(), symbol);
        int index = index_it - line_it->begin();
        if (index_it->getPosition() == symbol.getPosition()) {
            std::vector<int> sym_position;
            sym_position = generatePosBetween(symbol.getPosition(), index_it->getPosition(), sym_position, 0);
            symbol.setPosition(sym_position);
            insertSymbol(Position(line, index + 1), symbol);
        } else {
            insertSymbol(Position(line, index), symbol);
        }
    }

    _counter++;

}

/**
 *
 * @param symbol
 * remove symbol
 */
void SharedEditor::remoteErase(Symbol symbol) {
    if (!_symbols.empty()) {
        std::vector<std::vector<Symbol>>::iterator line_it;
        bool mergeLines = false;
        line_it = std::lower_bound(_symbols.begin(), _symbols.end(), symbol, [](const std::vector<Symbol> & it, const Symbol& symbol){
            return it[0] < symbol;
        });

        if (*line_it->begin() == symbol) {
            if (line_it->begin()->getC() == '\n') {
                mergeLines = true;
            }
            line_it->erase(line_it->begin());
        } else {
            std::vector<Symbol>::iterator index_it;
            index_it = std::lower_bound(line_it->begin(), line_it->end(), symbol);
            if (*index_it == symbol) {
                if (index_it->getC() == '\n') {
                    mergeLines = true;
                }
                line_it->erase(index_it);
            }
        }

        if (mergeLines && line_it+1 != _symbols.end()) {
            line_it->insert(line_it->end(), (line_it + 1)->begin(), (line_it + 1)->end());
            _symbols.erase(line_it + 1);
        }

        _counter--;
    }
}

/**
 *
 * @param m
 * if m.type = 1 insert the symbol respecting the fractional position
 * if m.type = -1 remove the symbol given the fractional position
 */
void SharedEditor::process(const Message &m) {
    Symbol symbol = m.getS();
    switch (m.getType()) {
        case INSERT:
            remoteInsert(symbol);
            break;

        case DELETE:
            remoteErase(symbol);
            break;

        default:
            throw std::runtime_error("process: forbidden action");
    }
}

std::string SharedEditor::to_string() {

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
