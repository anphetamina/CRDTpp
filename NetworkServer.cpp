//
// Created by asant on 05/10/2019.
//

#include <random>
#include <iostream>
#include <algorithm>
#include "NetworkServer.h"

static std::string random_string(int length) {
    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);

    std::string random_string;

    for (int i = 0; i < length; ++i) {
        random_string += characters[distribution(generator)];
    }

    return random_string;
}

int NetworkServer::connect(SharedEditor *sharedEditor) {
    // todo fix
    editors.push_back(sharedEditor);
    std::string string_id = random_string(10);
    uint32_t id = reinterpret_cast<uint64_t>(&string_id);
    return id;
}

void NetworkServer::disconnect(SharedEditor *sharedEditor) {
    auto it = std::find_if(editors.begin(), editors.end(), [&](SharedEditor* it){ return (it->getSiteId()==sharedEditor->getSiteId());});
    editors.erase(it);
}

void NetworkServer::send(const Message &m) {
    messages.push_back(m);
}

void NetworkServer::dispatchMessages() {
    std::for_each(editors.begin(), editors.end(), [&](SharedEditor* it){
        std::for_each(messages.begin(), messages.end(), [&](Message m){
            if (m.getSiteId() != it->getSiteId()) {
                it->process(m);
            }
        });
    });
}
