//
// Created by asant on 28/03/2020.
//

#include "RandomGenerator.h"

RandomGenerator::RandomGenerator() : generator(std::random_device()()) {}

RandomGenerator *RandomGenerator::getInstance() {
    std::call_once(inited, [&]{
        instance = new RandomGenerator();
    });
    return instance;
}

std::mt19937& RandomGenerator::getGenerator() {
    return generator;
}
