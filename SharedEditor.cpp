//
// Created by asant on 05/10/2019.
//

#define INSERT 1
#define DELETE -1
#include <algorithm>
#include "SharedEditor.h"

SharedEditor::SharedEditor(NetworkServer &server)
        : _server(server) {}

NetworkServer &SharedEditor::getServer() const {
    return _server;
}

int SharedEditor::getSiteId() const {
    return _siteId;
}

const std::vector<Symbol> &SharedEditor::getSymbols() const {
    return _symbols;
}

int SharedEditor::getCounter() const {
    return _counter;
}

void SharedEditor::localInsert(int index, char value) {
    // todo
}

void SharedEditor::localErase(int index) {
    // todo
}

void SharedEditor::process(const Message &m) {
    switch (m.getType()) {
        case INSERT:
            // todo
            break;

        case DELETE:
            // todo
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
