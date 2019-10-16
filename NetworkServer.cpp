//
// Created by asant on 05/10/2019.
//

#include <random>
#include <iostream>
#include <algorithm>
#include "NetworkServer.h"

int NetworkServer::connect(SharedEditor *sharedEditor) {
    editors.push_back(sharedEditor);
    uint32_t id = reinterpret_cast<uint64_t>(&sharedEditor);
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
