//
// Created by asant on 05/10/2019.
//

#include "Symbol.h"

Symbol::Symbol(char c, const std::string &id, const std::vector<int> &position) : c(c), id(id), position(position) {}

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
