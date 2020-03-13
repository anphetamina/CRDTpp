//
// Created by asant on 05/10/2019.
//

#ifndef PDS_CPP_SHAREDEDITOR_H
#define PDS_CPP_SHAREDEDITOR_H

#include <vector>
#include <map>
#include "Symbol.h"
#include "Message.h"

class NetworkServer;

class SharedEditor {
private:
    NetworkServer& _server;
    int _siteId;
    std::vector<Symbol> _symbols;
    int _counter;
    std::map<int, bool> strategies;
    int base;
    int boundary;

public:
    void setCounter(int counter);

    SharedEditor(NetworkServer &server);

    NetworkServer &getServer() const;

    void setServer(NetworkServer &server);

    int getSiteId() const;

    std::vector<Symbol> &getSymbols();

    int getCounter() const;

    int getBase() const;

    int generateIdBetween(int n1, int n2, bool strategy) const;
    std::vector<int> generatePosBetween(std::vector<int> pos1, std::vector<int> pos2, std::vector<int> newPos, int level);
    bool retrieveStrategy(int level);
    std::vector<int> findPosBefore(int index);
    std::vector<int> findPosAfter(int index);
    void localInsert(int index, char value);
    void localErase(int index);
    void process(const Message& m);
    std::string to_string();
};


#endif //PDS_CPP_SHAREDEDITOR_H
