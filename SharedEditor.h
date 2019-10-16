//
// Created by asant on 05/10/2019.
//

#ifndef PDS_CPP_SHAREDEDITOR_H
#define PDS_CPP_SHAREDEDITOR_H

#include <vector>
#include "Symbol.h"
#include "Message.h"

class NetworkServer;

class SharedEditor {
private:
    NetworkServer& _server;
    int _siteId;
    std::vector<Symbol> _symbols;
    int _counter;

public:
    SharedEditor(NetworkServer &server);

    NetworkServer &getServer() const;

    int getSiteId() const;

    const std::vector<Symbol> &getSymbols() const;

    int getCounter() const;

    void localInsert(int index, char value);
    void localErase(int index);
    void process(const Message& m);
    std::string to_string();
};


#endif //PDS_CPP_SHAREDEDITOR_H
