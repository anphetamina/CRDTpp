//
// Created by asant on 12/05/2019.
//

#include <iostream>
#include "NetworkServer.h"



int main() {
    NetworkServer network;
    SharedEditor ed1(network);
    SharedEditor ed2(network);

    ed1.localInsert(0, 'a');
    ed1.localInsert(2, 't');
    ed1.localInsert(1, 'n');
    ed1.localInsert(5, 'i');
    ed1.localInsert(3, 'o');
    ed1.localInsert(4, 'n');
    ed1.localInsert(60, 'o');

    network.dispatchMessages();
    std::cout << "ed1: " << ed1.to_string() << std::endl;
    std::cout << "ed2: " << ed2.to_string() << std::endl;

    ed2.localInsert(0, 'g');
    ed2.localInsert(1, 'i');
    ed2.localInsert(2, 'o');
    ed2.localInsert(3, 'v');
    ed2.localInsert(4, 'a');
    ed2.localInsert(5, 'n');
    ed2.localInsert(6, 'n');
    ed2.localInsert(7, 'i');
    ed2.localInsert(0, 'g');
    ed2.localInsert(1, 'i');
    ed2.localInsert(2, 'o');
    ed2.localInsert(3, 'v');
    ed2.localInsert(4, 'a');
    ed2.localInsert(5, 'n');
    ed2.localInsert(6, 'n');
    ed2.localInsert(7, 'i');
    ed2.localInsert(0, 'g');
    ed2.localInsert(1, 'i');
    ed2.localInsert(2, 'o');
    ed2.localInsert(3, 'v');
    ed2.localInsert(4, 'a');
    ed2.localInsert(5, 'n');
    ed2.localInsert(6, 'n');
    ed2.localInsert(7, 'i');
    ed2.localInsert(0, 'g');
    ed2.localInsert(1, 'i');
    ed2.localInsert(2, 'o');
    ed2.localInsert(3, 'v');
    ed2.localInsert(4, 'a');
    ed2.localInsert(5, 'n');
    ed2.localInsert(6, 'n');
    ed2.localInsert(7, 'i');

    network.dispatchMessages();
    std::cout << "ed1: " << ed1.to_string() << std::endl;
    std::cout << "ed2: " << ed2.to_string() << std::endl;

    ed2.localErase(0);
    ed2.localErase(20);
    ed2.localErase(1);
    network.dispatchMessages();
    std::cout << "ed1: " << ed1.to_string() << std::endl;
    std::cout << "ed2: " << ed2.to_string() << std::endl;

    return 0;
}