#include <iostream>
#include "src/NetworkServer.h"

int main() {
    NetworkServer network;
    SharedEditor ed1(network);
    SharedEditor ed2(network);

    ed1.localInsert(0, 0, 'a');
    ed1.localInsert(0, 1, 'n');
    ed1.localInsert(0, 2, 't');
    ed1.localInsert(0, 3, 'o');
    ed1.localInsert(0, 4, 'n');
    ed1.localInsert(0, 5, 'i');
    ed1.localInsert(0, 6, 'o');
    ed1.localInsert(0, 7, '\n');

    network.dispatchMessages();
    std::cout << "messages dispatched" << std::endl;
    std::cout << "ed1" << std::endl;
    std::cout << ed1.to_string();
    std::cout << "ed2" << std::endl;
    std::cout << ed2.to_string();
    std::cout << "-------------" << std::endl;

    ed2.localInsert(0, 0, 'a');
    ed2.localInsert(0, 1, 'g');
    ed2.localInsert(0, 2, 'o');
    ed2.localInsert(0, 3, 's');
    ed2.localInsert(0, 4, 't');
    ed2.localInsert(0, 5, 'i');
    ed2.localInsert(0, 6, 'n');
    ed2.localInsert(0, 7, 'o');

    network.dispatchMessages();
    std::cout << "messages dispatched" << std::endl;
    std::cout << "ed1" << std::endl;
    std::cout << ed1.to_string();
    std::cout << "ed2" << std::endl;
    std::cout << ed2.to_string();
    std::cout << "-------------" << std::endl;

    ed1.localInsert(1, 0, 'm');
    ed1.localInsert(1, 1, 'a');
    ed1.localInsert(1, 2, 'r');
    ed1.localInsert(1, 3, 'c');
    ed1.localInsert(1, 4, 'o');
    ed1.localInsert(1, 5, '\n');

    ed2.localInsert(1, 0, '\n');

    std::cout << "ed1" << std::endl;
    std::cout << ed1.to_string();
    std::cout << "ed2" << std::endl;
    std::cout << ed2.to_string();
    std::cout << "-------------" << std::endl;

    network.dispatchMessages();
    std::cout << "messages dispatched" << std::endl;
    std::cout << "ed1" << std::endl;
    std::cout << ed1.to_string();
    std::cout << "ed2" << std::endl;
    std::cout << ed2.to_string();
    std::cout << "-------------" << std::endl;

    ed1.localErase(1, 0, 1, 0);
    ed2.localErase(1, 0, 1, 0);

    std::cout << "ed1" << std::endl;
    std::cout << ed1.to_string();
    std::cout << "ed2" << std::endl;
    std::cout << ed2.to_string();
    std::cout << "-------------" << std::endl;

    network.dispatchMessages();
    std::cout << "messages dispatched" << std::endl;
    std::cout << "ed1" << std::endl;
    std::cout << ed1.to_string();
    std::cout << "ed2" << std::endl;
    std::cout << ed2.to_string();
    std::cout << "-------------" << std::endl;
    return 0;
}