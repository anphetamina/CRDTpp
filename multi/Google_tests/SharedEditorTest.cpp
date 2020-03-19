#include "gtest/gtest.h"
#include "../src/NetworkServer.h"

class SharedEditorTest : public ::testing::Test {

protected:

    virtual void SetUp() {

        ed1->getSymbols().emplace_back();
        ed1->getSymbols()[0].push_back(Symbol(char('a'), std::string{"0_0"}, std::vector<int>{1}));
        ed1->getSymbols()[0].push_back(Symbol(char('n'), std::string{"0_1"}, std::vector<int>{2}));
        ed1->getSymbols()[0].push_back(Symbol(char('t'), std::string{"0_2"}, std::vector<int>{3}));
        ed1->getSymbols()[0].push_back(Symbol(char('o'), std::string{"0_3"}, std::vector<int>{3, 9, 10}));
        ed1->getSymbols()[0].push_back(Symbol(char('n'), std::string{"0_4"}, std::vector<int>{3, 10}));
        ed1->getSymbols()[0].push_back(Symbol(char('i'), std::string{"0_5"}, std::vector<int>{6}));
        ed1->getSymbols()[0].push_back(Symbol(char('o'), std::string{"0_6"}, std::vector<int>{7}));
        ed1->getSymbols()[0].push_back(Symbol(char('\n'), std::string{"0_7"}, std::vector<int>{7, 2, 1}));
        ed1->getSymbols().emplace_back();
        ed1->getSymbols()[1].push_back(Symbol(char('a'), std::string{"0_8"}, std::vector<int>{7, 2, 5, 6}));
        ed1->getSymbols()[1].push_back(Symbol(char('g'), std::string{"0_9"}, std::vector<int>{9, 9}));
        ed1->getSymbols()[1].push_back(Symbol(char('o'), std::string{"0_10"}, std::vector<int>{10, 3, 6}));
        ed1->getSymbols()[1].push_back(Symbol(char('s'), std::string{"0_11"}, std::vector<int>{11}));
        ed1->getSymbols()[1].push_back(Symbol(char('t'), std::string{"0_12"}, std::vector<int>{11, 3, 5}));
        ed1->getSymbols()[1].push_back(Symbol(char('i'), std::string{"0_13"}, std::vector<int>{12, 9, 7, 6}));
        ed1->getSymbols()[1].push_back(Symbol(char('n'), std::string{"0_14"}, std::vector<int>{12, 9, 7, 9}));
        ed1->getSymbols()[1].push_back(Symbol(char('o'), std::string{"0_15"}, std::vector<int>{15}));
        ed1->getSymbols()[1].push_back(Symbol(char('\n'), std::string{"0_16"}, std::vector<int>{15, 8}));
        ed1->getSymbols().emplace_back();
        ed1->getSymbols()[2].push_back(Symbol(char('m'), std::string{"0_17"}, std::vector<int>{16}));
        ed1->getSymbols()[2].push_back(Symbol(char('a'), std::string{"0_18"}, std::vector<int>{17}));
        ed1->getSymbols()[2].push_back(Symbol(char('r'), std::string{"0_19"}, std::vector<int>{17, 1}));
        ed1->getSymbols()[2].push_back(Symbol(char('c'), std::string{"0_20"}, std::vector<int>{19}));
        ed1->getSymbols()[2].push_back(Symbol(char('o'), std::string{"0_21"}, std::vector<int>{19, 8, 2}));
        ed1->getSymbols()[2].push_back(Symbol(char('\n'), std::string{"0_22"}, std::vector<int>{19, 8, 2, 3}));
        ed1->getSymbols().emplace_back();
        ed1->getSymbols()[3].push_back(Symbol(char('e'), std::string{"0_23"}, std::vector<int>{21}));
        ed1->getSymbols()[3].push_back(Symbol(char('m'), std::string{"0_24"}, std::vector<int>{21, 2}));
        ed1->getSymbols()[3].push_back(Symbol(char('a'), std::string{"0_25"}, std::vector<int>{23, 1}));
        ed1->getSymbols()[3].push_back(Symbol(char('n'), std::string{"0_26"}, std::vector<int>{24}));
        ed1->getSymbols()[3].push_back(Symbol(char('u'), std::string{"0_27"}, std::vector<int>{24, 5, 6}));
        ed1->getSymbols()[3].push_back(Symbol(char('e'), std::string{"0_28"}, std::vector<int>{24, 5, 8}));
        ed1->getSymbols()[3].push_back(Symbol(char('l'), std::string{"0_29"}, std::vector<int>{24, 6}));
        ed1->getSymbols()[3].push_back(Symbol(char('e'), std::string{"0_30"}, std::vector<int>{27, 8}));
        ed1->getSymbols()[3].push_back(Symbol(char('\n'), std::string{"0_31"}, std::vector<int>{27, 8, 9}));
        ed1->setCounter(32);
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
    ASSERT_EQ((std::vector<int>{19, 8, 2, 3}), ed1->findPosBefore(Position(3, 0)));
    ASSERT_EQ((std::vector<int>{27, 8, 9}), ed1->findPosBefore(Position(3, 9)));
    ASSERT_EQ(std::vector<int>{0}, ed1->findPosBefore(Position(0, 0)));
    ASSERT_EQ((std::vector<int>{11, 3, 5}), ed1->findPosBefore(Position(1, 5)));
    ASSERT_EQ((std::vector<int>{7}), ed1->findPosBefore(Position(0, 7)));
    ASSERT_EQ((std::vector<int>{7, 2, 1}), ed1->findPosBefore(Position(1, 0)));

    ed1->getSymbols()[1].insert(ed1->getSymbols()[1].begin() + 3, Symbol(char('s'), std::string{"0_32"}, std::vector<int>{10, 5, 9}));
    ASSERT_EQ((std::vector<int>{10, 5, 9}), ed1->findPosBefore(Position(1, 4)));

    ASSERT_THROW(ed1->findPosBefore(Position(-1, 0)), std::out_of_range);
    ASSERT_THROW(ed1->findPosBefore(Position(0, -1)), std::out_of_range);
    ASSERT_THROW(ed1->findPosBefore(Position(5, 0)), std::out_of_range);
    ASSERT_THROW(ed1->findPosBefore(Position(0, 10)), std::out_of_range);
}

TEST_F(SharedEditorTest, findPosAfter) {
    ASSERT_EQ(std::vector<int>{21}, ed1->findPosAfter(Position(3, 0)));
    ASSERT_EQ((std::vector<int>{ed1->getBase()}), ed1->findPosAfter(Position(3, 9)));
    ASSERT_EQ(std::vector<int>{1}, ed1->findPosAfter(Position(0, 0)));
    ASSERT_EQ((std::vector<int>{12, 9, 7, 6}), ed1->findPosAfter(Position(1, 5)));
    ASSERT_EQ((std::vector<int>{7, 2, 1}), ed1->findPosAfter(Position(0, 7)));

    ed1->getSymbols()[1].insert(ed1->getSymbols()[1].begin() + 3, Symbol(char('s'), std::string{"0_32"}, std::vector<int>{10, 5, 9}));
    ASSERT_EQ(std::vector<int>{11}, ed1->findPosAfter(Position(1, 4)));

    ASSERT_THROW(ed1->findPosAfter(Position(-1, 0)), std::out_of_range);
    ASSERT_THROW(ed1->findPosAfter(Position(0, -1)), std::out_of_range);
    ASSERT_THROW(ed1->findPosAfter(Position(5, 0)), std::out_of_range);
    ASSERT_THROW(ed1->findPosAfter(Position(0, 10)), std::out_of_range);
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

TEST_F(SharedEditorTest, insertSymbolNotCRLF) {

    Symbol s5('x', "0_32", {28});
    ed1->insertSymbol(Position(3, 9), s5);
    ASSERT_EQ(ed1->getSymbols()[3].size(), 10);
    ASSERT_EQ(Symbol(char('e'), std::string{"0_23"}, std::vector<int>{21}), ed1->getSymbols()[3][0]);
    ASSERT_EQ(Symbol(char('m'), std::string{"0_24"}, std::vector<int>{21, 2}), ed1->getSymbols()[3][1]);
    ASSERT_EQ(Symbol(char('a'), std::string{"0_25"}, std::vector<int>{23, 1}), ed1->getSymbols()[3][2]);
    ASSERT_EQ(Symbol(char('n'), std::string{"0_26"}, std::vector<int>{24}), ed1->getSymbols()[3][3]);
    ASSERT_EQ(Symbol(char('u'), std::string{"0_27"}, std::vector<int>{24, 5, 6}), ed1->getSymbols()[3][4]);
    ASSERT_EQ(Symbol(char('e'), std::string{"0_28"}, std::vector<int>{24, 5, 8}), ed1->getSymbols()[3][5]);
    ASSERT_EQ(Symbol(char('l'), std::string{"0_29"}, std::vector<int>{24, 6}), ed1->getSymbols()[3][6]);
    ASSERT_EQ(Symbol(char('e'), std::string{"0_30"}, std::vector<int>{27, 8}), ed1->getSymbols()[3][7]);
    ASSERT_EQ(Symbol(char('\n'), std::string{"0_31"}, std::vector<int>{27, 8, 9}), ed1->getSymbols()[3][8]);
    ASSERT_EQ(s5, ed1->getSymbols()[3][9]);

    Symbol s1('x', "0_33", {0, 5});
    ed1->insertSymbol(Position(0, 0), s1);
    ASSERT_EQ(ed1->getSymbols()[0].size(), 9);
    ASSERT_EQ(s1, ed1->getSymbols()[0][0]);
    ASSERT_EQ(Symbol(char('a'), std::string{"0_0"}, std::vector<int>{1}), ed1->getSymbols()[0][1]);
    ASSERT_EQ(Symbol(char('n'), std::string{"0_1"}, std::vector<int>{2}), ed1->getSymbols()[0][2]);
    ASSERT_EQ(Symbol(char('t'), std::string{"0_2"}, std::vector<int>{3}), ed1->getSymbols()[0][3]);
    ASSERT_EQ(Symbol(char('o'), std::string{"0_3"}, std::vector<int>{3, 9, 10}), ed1->getSymbols()[0][4]);
    ASSERT_EQ(Symbol(char('n'), std::string{"0_4"}, std::vector<int>{3, 10}), ed1->getSymbols()[0][5]);
    ASSERT_EQ(Symbol(char('i'), std::string{"0_5"}, std::vector<int>{6}), ed1->getSymbols()[0][6]);
    ASSERT_EQ(Symbol(char('o'), std::string{"0_6"}, std::vector<int>{7}), ed1->getSymbols()[0][7]);
    ASSERT_EQ(Symbol(char('\n'), std::string{"0_7"}, std::vector<int>{7, 2, 1}), ed1->getSymbols()[0][8]);


    Symbol s2('x', "0_34", {27, 8, 3});
    ed1->insertSymbol(Position(3, 8), s2);
    ASSERT_EQ(ed1->getSymbols()[3].size(), 11);
    ASSERT_EQ(s2, ed1->getSymbols()[3][8]);
    ASSERT_EQ(Symbol(char('e'), std::string{"0_23"}, std::vector<int>{21}), ed1->getSymbols()[3][0]);
    ASSERT_EQ(Symbol(char('m'), std::string{"0_24"}, std::vector<int>{21, 2}), ed1->getSymbols()[3][1]);
    ASSERT_EQ(Symbol(char('a'), std::string{"0_25"}, std::vector<int>{23, 1}), ed1->getSymbols()[3][2]);
    ASSERT_EQ(Symbol(char('n'), std::string{"0_26"}, std::vector<int>{24}), ed1->getSymbols()[3][3]);
    ASSERT_EQ(Symbol(char('u'), std::string{"0_27"}, std::vector<int>{24, 5, 6}), ed1->getSymbols()[3][4]);
    ASSERT_EQ(Symbol(char('e'), std::string{"0_28"}, std::vector<int>{24, 5, 8}), ed1->getSymbols()[3][5]);
    ASSERT_EQ(Symbol(char('l'), std::string{"0_29"}, std::vector<int>{24, 6}), ed1->getSymbols()[3][6]);
    ASSERT_EQ(Symbol(char('e'), std::string{"0_30"}, std::vector<int>{27, 8}), ed1->getSymbols()[3][7]);
    ASSERT_EQ(Symbol(char('\n'), std::string{"0_31"}, std::vector<int>{27, 8, 9}), ed1->getSymbols()[3][9]);
    ASSERT_EQ(s5, ed1->getSymbols()[3][10]);

    Symbol s3('x', "0_35", {19, 8, 2, 2});
    ed1->insertSymbol(Position(2, 5), s3);
    ASSERT_EQ(ed1->getSymbols()[2].size(), 7);
    ASSERT_EQ(s3, ed1->getSymbols()[2][5]);
    ASSERT_EQ(Symbol(char('m'), std::string{"0_17"}, std::vector<int>{16}), ed1->getSymbols()[2][0]);
    ASSERT_EQ(Symbol(char('a'), std::string{"0_18"}, std::vector<int>{17}), ed1->getSymbols()[2][1]);
    ASSERT_EQ(Symbol(char('r'), std::string{"0_19"}, std::vector<int>{17, 1}), ed1->getSymbols()[2][2]);
    ASSERT_EQ(Symbol(char('c'), std::string{"0_20"}, std::vector<int>{19}), ed1->getSymbols()[2][3]);
    ASSERT_EQ(Symbol(char('o'), std::string{"0_21"}, std::vector<int>{19, 8, 2}), ed1->getSymbols()[2][4]);
    ASSERT_EQ(Symbol(char('\n'), std::string{"0_22"}, std::vector<int>{19, 8, 2, 3}), ed1->getSymbols()[2][6]);

    Symbol s4('x', "0_36", {7, 2, 3});
    ed1->insertSymbol(Position(1, 0), s4);
    ASSERT_EQ(ed1->getSymbols()[1].size(), 10);
    ASSERT_EQ(s4, ed1->getSymbols()[1][0]);
    ASSERT_EQ(Symbol(char('a'), std::string{"0_8"}, std::vector<int>{7, 2, 5, 6}), ed1->getSymbols()[1][1]);
    ASSERT_EQ(Symbol(char('g'), std::string{"0_9"}, std::vector<int>{9, 9}), ed1->getSymbols()[1][2]);
    ASSERT_EQ(Symbol(char('o'), std::string{"0_10"}, std::vector<int>{10, 3, 6}), ed1->getSymbols()[1][3]);
    ASSERT_EQ(Symbol(char('s'), std::string{"0_11"}, std::vector<int>{11}), ed1->getSymbols()[1][4]);
    ASSERT_EQ(Symbol(char('t'), std::string{"0_12"}, std::vector<int>{11, 3, 5}), ed1->getSymbols()[1][5]);
    ASSERT_EQ(Symbol(char('i'), std::string{"0_13"}, std::vector<int>{12, 9, 7, 6}), ed1->getSymbols()[1][6]);
    ASSERT_EQ(Symbol(char('n'), std::string{"0_14"}, std::vector<int>{12, 9, 7, 9}), ed1->getSymbols()[1][7]);
    ASSERT_EQ(Symbol(char('o'), std::string{"0_15"}, std::vector<int>{15}), ed1->getSymbols()[1][8]);
    ASSERT_EQ(Symbol(char('\n'), std::string{"0_16"}, std::vector<int>{15, 8}), ed1->getSymbols()[1][9]);
}

TEST_F(SharedEditorTest, insertSymbolCRLF) {

    Symbol s5('\n', "0_37", {29});
    ed1->insertSymbol(Position(3, 9), s5);
    ASSERT_EQ(ed1->getSymbols()[3].size(), 10);
    ASSERT_EQ(s5, ed1->getSymbols()[3][9]);
    ASSERT_EQ(Symbol(char('e'), std::string{"0_23"}, std::vector<int>{21}), ed1->getSymbols()[3][0]);
    ASSERT_EQ(Symbol(char('m'), std::string{"0_24"}, std::vector<int>{21, 2}), ed1->getSymbols()[3][1]);
    ASSERT_EQ(Symbol(char('a'), std::string{"0_25"}, std::vector<int>{23, 1}), ed1->getSymbols()[3][2]);
    ASSERT_EQ(Symbol(char('n'), std::string{"0_26"}, std::vector<int>{24}), ed1->getSymbols()[3][3]);
    ASSERT_EQ(Symbol(char('u'), std::string{"0_27"}, std::vector<int>{24, 5, 6}), ed1->getSymbols()[3][4]);
    ASSERT_EQ(Symbol(char('e'), std::string{"0_28"}, std::vector<int>{24, 5, 8}), ed1->getSymbols()[3][5]);
    ASSERT_EQ(Symbol(char('l'), std::string{"0_29"}, std::vector<int>{24, 6}), ed1->getSymbols()[3][6]);
    ASSERT_EQ(Symbol(char('e'), std::string{"0_30"}, std::vector<int>{27, 8}), ed1->getSymbols()[3][7]);
    ASSERT_EQ(Symbol(char('\n'), std::string{"0_31"}, std::vector<int>{27, 8, 9}), ed1->getSymbols()[3][8]);

    Symbol s2('\n', "0_34", {27, 8, 3});
    ed1->insertSymbol(Position(3, 8), s2);
    ASSERT_EQ(ed1->getSymbols()[3].size(), 9);
    ASSERT_EQ(ed1->getSymbols()[4].size(), 2);
    ASSERT_EQ(Symbol(char('e'), std::string{"0_23"}, std::vector<int>{21}), ed1->getSymbols()[3][0]);
    ASSERT_EQ(Symbol(char('m'), std::string{"0_24"}, std::vector<int>{21, 2}), ed1->getSymbols()[3][1]);
    ASSERT_EQ(Symbol(char('a'), std::string{"0_25"}, std::vector<int>{23, 1}), ed1->getSymbols()[3][2]);
    ASSERT_EQ(Symbol(char('n'), std::string{"0_26"}, std::vector<int>{24}), ed1->getSymbols()[3][3]);
    ASSERT_EQ(Symbol(char('u'), std::string{"0_27"}, std::vector<int>{24, 5, 6}), ed1->getSymbols()[3][4]);
    ASSERT_EQ(Symbol(char('e'), std::string{"0_28"}, std::vector<int>{24, 5, 8}), ed1->getSymbols()[3][5]);
    ASSERT_EQ(Symbol(char('l'), std::string{"0_29"}, std::vector<int>{24, 6}), ed1->getSymbols()[3][6]);
    ASSERT_EQ(Symbol(char('e'), std::string{"0_30"}, std::vector<int>{27, 8}), ed1->getSymbols()[3][7]);
    ASSERT_EQ(s2, ed1->getSymbols()[3][8]);
    ASSERT_EQ(Symbol(char('\n'), std::string{"0_31"}, std::vector<int>{27, 8, 9}), ed1->getSymbols()[4][0]);
    ASSERT_EQ(s5, ed1->getSymbols()[4][1]);

    Symbol s3('\n', "0_35", {17, 5});
    ed1->insertSymbol(Position(2, 3), s3);
    ASSERT_EQ(ed1->getSymbols()[2].size(), 4);
    ASSERT_EQ(ed1->getSymbols()[3].size(), 3);
    ASSERT_EQ(Symbol(char('m'), std::string{"0_17"}, std::vector<int>{16}), ed1->getSymbols()[2][0]);
    ASSERT_EQ(Symbol(char('a'), std::string{"0_18"}, std::vector<int>{17}), ed1->getSymbols()[2][1]);
    ASSERT_EQ(Symbol(char('r'), std::string{"0_19"}, std::vector<int>{17, 1}), ed1->getSymbols()[2][2]);
    ASSERT_EQ(s3, ed1->getSymbols()[2][3]);
    ASSERT_EQ(Symbol(char('c'), std::string{"0_20"}, std::vector<int>{19}), ed1->getSymbols()[3][0]);
    ASSERT_EQ(Symbol(char('o'), std::string{"0_21"}, std::vector<int>{19, 8, 2}), ed1->getSymbols()[3][1]);
    ASSERT_EQ(Symbol(char('\n'), std::string{"0_22"}, std::vector<int>{19, 8, 2, 3}), ed1->getSymbols()[3][2]);

    Symbol s4('\n', "0_36", {7, 2, 3});
    ed1->insertSymbol(Position(1, 0), s4);
    ASSERT_EQ(ed1->getSymbols()[1].size(), 1);
    ASSERT_EQ(ed1->getSymbols()[2].size(), 9);
    ASSERT_EQ(s4, ed1->getSymbols()[1][0]);
    ASSERT_EQ(Symbol(char('a'), std::string{"0_8"}, std::vector<int>{7, 2, 5, 6}), ed1->getSymbols()[2][0]);
    ASSERT_EQ(Symbol(char('g'), std::string{"0_9"}, std::vector<int>{9, 9}), ed1->getSymbols()[2][1]);
    ASSERT_EQ(Symbol(char('o'), std::string{"0_10"}, std::vector<int>{10, 3, 6}), ed1->getSymbols()[2][2]);
    ASSERT_EQ(Symbol(char('s'), std::string{"0_11"}, std::vector<int>{11}), ed1->getSymbols()[2][3]);
    ASSERT_EQ(Symbol(char('t'), std::string{"0_12"}, std::vector<int>{11, 3, 5}), ed1->getSymbols()[2][4]);
    ASSERT_EQ(Symbol(char('i'), std::string{"0_13"}, std::vector<int>{12, 9, 7, 6}), ed1->getSymbols()[2][5]);
    ASSERT_EQ(Symbol(char('n'), std::string{"0_14"}, std::vector<int>{12, 9, 7, 9}), ed1->getSymbols()[2][6]);
    ASSERT_EQ(Symbol(char('o'), std::string{"0_15"}, std::vector<int>{15}), ed1->getSymbols()[2][7]);
    ASSERT_EQ(Symbol(char('\n'), std::string{"0_16"}, std::vector<int>{15, 8}), ed1->getSymbols()[2][8]);

    Symbol s1('\n', "0_33", {0, 5});
    ed1->insertSymbol(Position(0, 0), s1);
    ASSERT_EQ(ed1->getSymbols()[0].size(), 1);
    ASSERT_EQ(ed1->getSymbols()[1].size(), 8);
    ASSERT_EQ(s1, ed1->getSymbols()[0][0]);
    ASSERT_EQ(Symbol(char('a'), std::string{"0_0"}, std::vector<int>{1}), ed1->getSymbols()[1][0]);
    ASSERT_EQ(Symbol(char('n'), std::string{"0_1"}, std::vector<int>{2}), ed1->getSymbols()[1][1]);
    ASSERT_EQ(Symbol(char('t'), std::string{"0_2"}, std::vector<int>{3}), ed1->getSymbols()[1][2]);
    ASSERT_EQ(Symbol(char('o'), std::string{"0_3"}, std::vector<int>{3, 9, 10}), ed1->getSymbols()[1][3]);
    ASSERT_EQ(Symbol(char('n'), std::string{"0_4"}, std::vector<int>{3, 10}), ed1->getSymbols()[1][4]);
    ASSERT_EQ(Symbol(char('i'), std::string{"0_5"}, std::vector<int>{6}), ed1->getSymbols()[1][5]);
    ASSERT_EQ(Symbol(char('o'), std::string{"0_6"}, std::vector<int>{7}), ed1->getSymbols()[1][6]);
    ASSERT_EQ(Symbol(char('\n'), std::string{"0_7"}, std::vector<int>{7, 2, 1}), ed1->getSymbols()[1][7]);
}

TEST_F(SharedEditorTest, localInsertNotCRLF) {
    ed1->localInsert(Position(3, 9), 'x');
    ASSERT_EQ('x', ed1->getSymbols()[3][9].getC());
    ASSERT_EQ('\n', ed1->getSymbols()[3][8].getC());

    ed1->localInsert(Position(0, 0), 'y');
    ASSERT_EQ('y', ed1->getSymbols()[0][0].getC());

    ed1->localInsert(Position(3, 8), 'z');
    ASSERT_EQ('z', ed1->getSymbols()[3][8].getC());

    ed1->localInsert(Position(2, 5), 'k');
    ASSERT_EQ('k', ed1->getSymbols()[2][5].getC());

    ed1->localInsert(Position(1, 0), 'q');
    ASSERT_EQ('q', ed1->getSymbols()[1][0].getC());
}

TEST_F(SharedEditorTest, localInsertCRLF) {

    ed1->localInsert(Position(3, 9), '\n');
    ASSERT_EQ('\n', ed1->getSymbols()[3][8].getC());
    ASSERT_EQ('\n', ed1->getSymbols()[3][9].getC());

    ed1->localInsert(Position(3, 8), '\n');
    ASSERT_EQ('\n', ed1->getSymbols()[3][8].getC());
    ASSERT_EQ('\n', ed1->getSymbols()[4][0].getC());

    ed1->localInsert(Position(2, 3), '\n');
    ASSERT_EQ('\n', ed1->getSymbols()[2][3].getC());
    ASSERT_EQ('c', ed1->getSymbols()[3][0].getC());

    ed1->localInsert(Position(1, 0), '\n');
    ASSERT_EQ('\n', ed1->getSymbols()[1][0].getC());
    ASSERT_EQ('a', ed1->getSymbols()[2][0].getC());

    ed1->localInsert(Position(0, 0), '\n');
    ASSERT_EQ('\n', ed1->getSymbols()[0][0].getC());
    ASSERT_EQ('a', ed1->getSymbols()[1][0].getC());
}

TEST_F(SharedEditorTest, eraseSingleLine) {
    ed1->eraseSingleLine(Position(3, 5), Position(3, 8));
    ASSERT_EQ(ed1->getSymbols()[3].size(), 5);
    ASSERT_EQ(Symbol(char('u'), std::string{"0_27"}, std::vector<int>{24, 5, 6}), ed1->getSymbols()[3][4]);

    ed1->eraseSingleLine(Position(2, 0), Position(2, 2));
    ASSERT_EQ(Symbol(char('c'), std::string{"0_20"}, std::vector<int>{19}), ed1->getSymbols()[2][0]);
    ASSERT_EQ(Symbol(char('o'), std::string{"0_21"}, std::vector<int>{19, 8, 2}), ed1->getSymbols()[2][1]);
    ASSERT_EQ(Symbol(char('\n'), std::string{"0_22"}, std::vector<int>{19, 8, 2, 3}), ed1->getSymbols()[2][2]);

    ed1->eraseSingleLine(Position(1, 2), Position(1, 5));
    ASSERT_EQ(Symbol(char('n'), std::string{"0_14"}, std::vector<int>{12, 9, 7, 9}), ed1->getSymbols()[1][2]);
    ASSERT_EQ(Symbol(char('o'), std::string{"0_15"}, std::vector<int>{15}), ed1->getSymbols()[1][3]);
    ASSERT_EQ(Symbol(char('\n'), std::string{"0_16"}, std::vector<int>{15, 8}), ed1->getSymbols()[1][4]);

    ed1->eraseSingleLine(Position(0, 3), Position(0, 3));
    ASSERT_EQ(Symbol(char('n'), std::string{"0_4"}, std::vector<int>{3, 10}), ed1->getSymbols()[0][3]);
}

TEST_F(SharedEditorTest, eraseMultipleLines) {

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