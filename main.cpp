//
// Created by asant on 12/05/2019.
//

#include <iostream>
#include "NetworkServer.h"



int main() {
    NetworkServer network;
    SharedEditor ed1(network);
    SharedEditor ed2(network);

    ed1.localInsert(0, 'c');
    ed1.localInsert(1, 'a');
    ed1.localInsert(2, 't');
    network.dispatchMessages();
    std::cout << "ed1: " << ed1.to_string() << std::endl;
    std::cout << "ed2: " << ed2.to_string() << std::endl;

    ed1.localInsert(1, 'h');
    ed2.localErase(1);

    network.dispatchMessages();
    std::cout << "ed1: " << ed1.to_string() << std::endl;
    std::cout << "ed2: " << ed2.to_string() << std::endl;

    return 0;
}