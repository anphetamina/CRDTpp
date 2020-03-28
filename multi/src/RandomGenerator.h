//
// Created by asant on 28/03/2020.
//

#ifndef CRDTPP_MULTI_RANDOMGENERATOR_H
#define CRDTPP_MULTI_RANDOMGENERATOR_H

#include <mutex>
#include <random>

class RandomGenerator {
private:

    inline static RandomGenerator* instance;
    inline static std::once_flag inited;
    std::mt19937 generator;

    RandomGenerator();
public:
    static RandomGenerator* getInstance();
    std::mt19937& getGenerator();

    ~RandomGenerator();
};


#endif //CRDTPP_MULTI_RANDOMGENERATOR_H
