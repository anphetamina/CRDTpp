//
// Created by asant on 05/10/2019.
//

#include "Message.h"

Message::Message(int type, const Symbol &s, int siteId, int counter) : type(type), s(s), siteId(siteId),
                                                                       counter(counter) {}

int Message::getType() const {
    return type;
}

const Symbol &Message::getS() const {
    return s;
}

int Message::getSiteId() const {
    return siteId;
}

int Message::getCounter() const {
    return counter;
}

