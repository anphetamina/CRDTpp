//
// Created by asant on 12/05/2019.
//

#include <random>
#include <iostream>
#include "NetworkServer.h"

static std::string random_string(std::size_t length) {
    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);

    std::string random_string;

    for (std::size_t i = 0; i < length; ++i) {
        random_string += characters[distribution(generator)];
    }

    return random_string;
}

int main() {
    NetworkServer network;
    SharedEditor ed1(network);
    SharedEditor ed2(network);

    ed1.localInsert(0, 'c');
    ed1.localInsert(1, 'a');
    ed1.localInsert(2, 't');
    network.dispatchMessages();
    std::cout << "ed1: " << ed1.to_string() << std::endl;
    std::cout << "ed2: " << ed1.to_string() << std::endl;

    ed1.localInsert(1, 'h');
    ed2.localErase(1);

    network.dispatchMessages();
    std::cout << "ed1: " << ed1.to_string() << std::endl;
    std::cout << "ed2: " << ed1.to_string() << std::endl;

    return 0;
}