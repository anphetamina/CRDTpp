#ifndef PDS_CPP_SHAREDEDITOR_H
#define PDS_CPP_SHAREDEDITOR_H

#include <vector>
#include <map>
#include "Symbol.h"
#include "Message.h"

class NetworkServer;

typedef struct Position {
    int line;
    int index;
    Position(int line, int index) : line(line), index(index){};
} Position;

class SharedEditor {
private:
    NetworkServer& _server;
    int _siteId;
    std::vector<std::vector<Symbol>> _symbols;
    int _counter;
    std::map<int, bool> strategies;
    int base;
    int boundary;
    uint64_t counter_id;

public:
    void setCounter(int counter);

    SharedEditor(NetworkServer &server);

    NetworkServer &getServer() const;

    void setServer(NetworkServer &server);

    int getSiteId() const;

    std::vector<std::vector<Symbol>>& getSymbols();

    int getCounter() const;

    int getBase() const;

    int generateIdBetween(int n1, int n2, bool strategy) const;
    std::vector<int> generatePosBetween(std::vector<int> pos1, std::vector<int> pos2, std::vector<int> newPos, int level);
    bool retrieveStrategy(int level);
    std::vector<int> findPosBefore(Position pos);
    std::vector<int> findPosAfter(Position pos);
    void localInsert(Position pos, char value);
    void insertSymbol(Position pos, Symbol symbol);
    void localErase(Position startPos, Position endPos);
    std::vector<Symbol> eraseSingleLine(Position startPos, Position endPos);
    std::vector<Symbol> eraseMultipleLines(Position startPos, Position endPos);
    void process(const Message& m);
    void remoteInsert(Symbol symbol);
    void remoteErase(Symbol symbol);
    std::string to_string();
};


#endif //PDS_CPP_SHAREDEDITOR_H
