//
// Created by asant on 05/10/2019.
//

#ifndef PDS_CPP_SYMBOL_H
#define PDS_CPP_SYMBOL_H


#include <string>
#include <vector>

class Symbol {
private:
    char c;
    std::string id;
    std::vector<int> position;
public:
    Symbol(char c, const std::string id, const std::vector<int> position);

    char getC() const;

    void setC(char c);

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::vector<int> &getPosition() const;

    void setPosition(const std::vector<int> &position);

    bool operator==(const Symbol &symbol) const;
    bool operator>(const Symbol &symbol) const;
    bool operator<(const Symbol &symbol) const;
};


#endif //PDS_CPP_SYMBOL_H
