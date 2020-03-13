//
// Created by asant on 12/03/2020.
//

#include "gtest/gtest.h"
#include "../src/NetworkServer.h"

class SharedEditorTest : public ::testing::Test {

protected:

    virtual void SetUp() {

        ed1 = new SharedEditor(server);

        ed1->getSymbols().push_back(Symbol(char('a'), std::string{"0_1"}, std::vector<int>{1}));
        ed1->getSymbols().push_back(Symbol(char('n'), std::string{"0_2"}, std::vector<int>{2}));
        ed1->getSymbols().push_back(Symbol(char('t'), std::string{"0_3"}, std::vector<int>{3}));
        ed1->getSymbols().push_back(Symbol(char('o'), std::string{"0_4"}, std::vector<int>{4}));
        ed1->getSymbols().push_back(Symbol(char('n'), std::string{"0_5"}, std::vector<int>{5}));
        ed1->getSymbols().push_back(Symbol(char('i'), std::string{"0_6"}, std::vector<int>{6}));
        ed1->getSymbols().push_back(Symbol(char('o'), std::string{"0_7"}, std::vector<int>{7}));
        ed1->setCounter(7);
    }

    virtual void TearDown() {

    }

    NetworkServer server;
    SharedEditor* ed1{};
};


TEST_F(SharedEditorTest, generateIdBetween) {
    int n1 = 0;
    int n2 = 10;
    int n = ed1->generateIdBetween(n1, n2, true);
    ASSERT_GE(n, n1);
    ASSERT_LT(n, n2);

    ASSERT_THROW(ed1->generateIdBetween(n2, n1, true), std::range_error);
    ASSERT_THROW(ed1->generateIdBetween(n1, n1, true), std::range_error);
    ASSERT_THROW(ed1->generateIdBetween(-1, n1, true), std::invalid_argument);
    ASSERT_THROW(ed1->generateIdBetween(n1, -2, true), std::invalid_argument);
    ASSERT_THROW(ed1->generateIdBetween(-1, -2, true), std::invalid_argument);

    ASSERT_EQ(2, ed1->generateIdBetween(1, 3, true));
}

TEST_F(SharedEditorTest, findPosBefore) {
    ASSERT_EQ(std::vector<int>{0}, ed1->findPosBefore(0));
    ASSERT_EQ(std::vector<int>{1}, ed1->findPosBefore(1));
    ASSERT_EQ(std::vector<int>{7}, ed1->findPosBefore(100));

    ed1->getSymbols().insert(ed1->getSymbols().begin() + 2, Symbol(char('z'), std::string{"0_8"}, std::vector<int>{2, 5}));
    ed1->getSymbols().insert(ed1->getSymbols().begin() + 2, Symbol(char('y'), std::string{"0_9"}, std::vector<int>{2, 2}));
    ed1->getSymbols().insert(ed1->getSymbols().begin() + 3, Symbol(char('x'), std::string{"0_10"}, std::vector<int>{2, 2, 10}));
    ed1->setCounter(ed1->getCounter() + 3);

    ASSERT_EQ((std::vector<int>{2, 5}), ed1->findPosBefore(5));
    ASSERT_EQ((std::vector<int>{2, 2}), ed1->findPosBefore(3));
    ASSERT_EQ((std::vector<int>{2, 2, 10}), ed1->findPosBefore(4));

    ASSERT_THROW(ed1->findPosBefore(-1), std::invalid_argument);
}

TEST_F(SharedEditorTest, generatePosBetween) {
    ASSERT_EQ(std::vector<int>{1}, ed1->generatePosBetween({0}, {2}, {}, 0));
    ASSERT_GT(ed1->generatePosBetween({0, 5}, {1, 7}, {}, 0)[1], 5);
    ASSERT_EQ((std::vector<int>{0, 6}), ed1->generatePosBetween({0, 5}, {0, 7}, {}, 0));
    ASSERT_GT(ed1->generatePosBetween({2, 5}, {2, 6}, {}, 0)[2], 5);
    ASSERT_LT(ed1->generatePosBetween({5, 4}, {5, 4, 7}, {}, 0)[2], 7);

    ASSERT_THROW(ed1->generatePosBetween({}, {2}, {}, 0), std::invalid_argument);
    ASSERT_THROW(ed1->generatePosBetween({1}, {2}, {}, -1), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}