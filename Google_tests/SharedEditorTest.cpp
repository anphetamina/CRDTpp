//
// Created by asant on 12/03/2020.
//

#include "gtest/gtest.h"
#include "../NetworkServer.h"

class SharedEditorTest : public ::testing::Test {

protected:

    virtual void SetUp() {

        ed1 = new SharedEditor(server);

        /*ed1->getSymbols().push_back(Symbol(char('a'), std::string{"0_1"}, std::vector<int>{1}));
        ed1->getSymbols().push_back(Symbol(char('n'), std::string{"0_2"}, std::vector<int>{2}));
        ed1->getSymbols().push_back(Symbol(char('t'), std::string{"0_3"}, std::vector<int>{3}));
        ed1->getSymbols().push_back(Symbol(char('o'), std::string{"0_4"}, std::vector<int>{4}));
        ed1->getSymbols().push_back(Symbol(char('n'), std::string{"0_5"}, std::vector<int>{5}));
        ed1->getSymbols().push_back(Symbol(char('i'), std::string{"0_6"}, std::vector<int>{6}));
        ed1->getSymbols().push_back(Symbol(char('o'), std::string{"0_7"}, std::vector<int>{7}));
        std::cout << "ed1: " << ed1->to_string() << std::endl;*/
    }

    virtual void TearDown() {

    }

    NetworkServer server;
    SharedEditor* ed1{};
};


TEST_F(SharedEditorTest, TestName) {
    std::cout << ed1->getCounter() << std::endl;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}