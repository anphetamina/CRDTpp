//
// Created by asant on 05/10/2019.
//

#include "Symbol.h"

Symbol::Symbol(char c, const std::string id, const std::vector<int> position) : c(c), id(id), position(position) {}

char Symbol::getC() const {
    return c;
}

void Symbol::setC(char c) {
    Symbol::c = c;
}

const std::string &Symbol::getId() const {
    return id;
}

void Symbol::setId(const std::string &id) {
    Symbol::id = id;
}

const std::vector<int> &Symbol::getPosition() const {
    return position;
}

void Symbol::setPosition(const std::vector<int> &position) {
    Symbol::position = position;
}

bool Symbol::operator==(const Symbol &symbol) const {
    const std::vector<int>& pos = symbol.getPosition();
    return this->position == pos;
}

bool Symbol::operator>(const Symbol &symbol) const {
    if (this->position.size() < symbol.getPosition().size()) {
        return false;
    } else if (this->position.size() > symbol.getPosition().size()) {
        return true;
    } else {
        auto it2 = symbol.getPosition().begin();
        for (auto it1 = this->position.begin(); it1 != this->position.end(); it1++) {
            if (*it1 > *it2++) {
                return true;
            }
        }
        return false;
    }
}

bool Symbol::operator<(const Symbol &symbol) const {
    if (this->position.size() < symbol.getPosition().size()) {
        return true;
    } else if (this->position.size() > symbol.getPosition().size()) {
        return false;
    } else {
        auto it2 = symbol.getPosition().begin();
        for (auto it1 = this->position.begin(); it1 != this->position.end(); it1++) {
            if (*it1 < *it2++) {
                return true;
            }
        }
        return false;
    }
}
