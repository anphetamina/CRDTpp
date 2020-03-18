#include "gtest/gtest.h"
#include "../src/NetworkServer.h"

class SharedEditorTest : public ::testing::Test {

protected:

    virtual void SetUp() {

        ed1->getSymbols().emplace_back();
        ed1->getSymbols()[0].push_back(Symbol(char('a'), std::string{"0_0"}, std::vector<int>{1}));
        ed1->getSymbols()[0].push_back(Symbol(char('n'), std::string{"0_1"}, std::vector<int>{2}));
        ed1->getSymbols()[0].push_back(Symbol(char('t'), std::string{"0_2"}, std::vector<int>{3}));
        ed1->getSymbols()[0].push_back(Symbol(char('o'), std::string{"0_3"}, std::vector<int>{4}));
        ed1->getSymbols()[0].push_back(Symbol(char('n'), std::string{"0_4"}, std::vector<int>{5}));
        ed1->getSymbols()[0].push_back(Symbol(char('i'), std::string{"0_5"}, std::vector<int>{6}));
        ed1->getSymbols()[0].push_back(Symbol(char('o'), std::string{"0_6"}, std::vector<int>{7}));
        ed1->getSymbols().emplace_back();
        ed1->getSymbols()[1].push_back(Symbol(char('a'), std::string{"0_7"}, std::vector<int>{8}));
        ed1->getSymbols()[1].push_back(Symbol(char('g'), std::string{"0_8"}, std::vector<int>{9}));
        ed1->getSymbols()[1].push_back(Symbol(char('o'), std::string{"0_9"}, std::vector<int>{10}));
        ed1->getSymbols()[1].push_back(Symbol(char('s'), std::string{"0_10"}, std::vector<int>{11}));
        ed1->getSymbols()[1].push_back(Symbol(char('t'), std::string{"0_11"}, std::vector<int>{12}));
        ed1->getSymbols()[1].push_back(Symbol(char('i'), std::string{"0_12"}, std::vector<int>{13}));
        ed1->getSymbols()[1].push_back(Symbol(char('n'), std::string{"0_13"}, std::vector<int>{14}));
        ed1->getSymbols()[1].push_back(Symbol(char('o'), std::string{"0_14"}, std::vector<int>{15}));
        ed1->getSymbols().emplace_back();
        ed1->getSymbols()[2].push_back(Symbol(char('m'), std::string{"0_15"}, std::vector<int>{16}));
        ed1->getSymbols()[2].push_back(Symbol(char('a'), std::string{"0_16"}, std::vector<int>{17}));
        ed1->getSymbols()[2].push_back(Symbol(char('r'), std::string{"0_17"}, std::vector<int>{18}));
        ed1->getSymbols()[2].push_back(Symbol(char('c'), std::string{"0_18"}, std::vector<int>{19}));
        ed1->getSymbols()[2].push_back(Symbol(char('o'), std::string{"0_19"}, std::vector<int>{20}));
        ed1->getSymbols().emplace_back();
        ed1->getSymbols()[3].push_back(Symbol(char('e'), std::string{"0_20"}, std::vector<int>{21}));
        ed1->getSymbols()[3].push_back(Symbol(char('m'), std::string{"0_21"}, std::vector<int>{22}));
        ed1->getSymbols()[3].push_back(Symbol(char('a'), std::string{"0_22"}, std::vector<int>{23}));
        ed1->getSymbols()[3].push_back(Symbol(char('n'), std::string{"0_23"}, std::vector<int>{24}));
        ed1->getSymbols()[3].push_back(Symbol(char('u'), std::string{"0_24"}, std::vector<int>{25}));
        ed1->getSymbols()[3].push_back(Symbol(char('e'), std::string{"0_25"}, std::vector<int>{26}));
        ed1->getSymbols()[3].push_back(Symbol(char('l'), std::string{"0_26"}, std::vector<int>{27}));
        ed1->getSymbols()[3].push_back(Symbol(char('e'), std::string{"0_27"}, std::vector<int>{28}));
        ed1->setCounter(28);
    }

    virtual void TearDown() {
    }

    NetworkServer server;
    SharedEditor* ed1 = new SharedEditor(server);
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
    ASSERT_EQ(std::vector<int>{20}, ed1->findPosBefore(Position(3, 0)));
    ASSERT_EQ(std::vector<int>{28}, ed1->findPosBefore(Position(3, 8)));
    ASSERT_EQ(std::vector<int>{0}, ed1->findPosBefore(Position(0, 0)));
    ASSERT_EQ(std::vector<int>{12}, ed1->findPosBefore(Position(1, 5)));

    ed1->getSymbols()[1].insert(ed1->getSymbols()[1].begin() + 3, Symbol(char('s'), std::string{"0_28"}, std::vector<int>{10, 5, 9}));
    ASSERT_EQ((std::vector<int>{10, 5, 9}), ed1->findPosBefore(Position(1, 4)));

    ASSERT_THROW(ed1->findPosBefore(Position(-1, 0)), std::out_of_range);
    ASSERT_THROW(ed1->findPosBefore(Position(0, -1)), std::out_of_range);
    ASSERT_THROW(ed1->findPosBefore(Position(5, 0)), std::out_of_range);
    ASSERT_THROW(ed1->findPosBefore(Position(0, 8)), std::out_of_range);
}

TEST_F(SharedEditorTest, findPosAfter) {

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

TEST_F(SharedEditorTest, localInsert) {

}

TEST_F(SharedEditorTest, localErase) {

}

TEST_F(SharedEditorTest, remoteInsert) {

}

TEST_F(SharedEditorTest, remoteErase) {

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}