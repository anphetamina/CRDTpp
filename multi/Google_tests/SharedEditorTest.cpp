#include "gtest/gtest.h"
#include "../src/NetworkServer.h"

class SharedEditorTest : public ::testing::Test {

protected:

    virtual void SetUp() {

        ed1->getSymbols()[0].push_back(a1));
        ed1->getSymbols()[0].push_back(n1));
        ed1->getSymbols()[0].push_back(t1));
        ed1->getSymbols()[0].push_back(o1));
        ed1->getSymbols()[0].push_back(n2));
        ed1->getSymbols()[0].push_back(i1));
        ed1->getSymbols()[0].push_back(o2));
        ed1->getSymbols()[0].push_back(slash1));
        ed1->getSymbols().emplace_back();
        ed1->getSymbols()[1].push_back(a2));
        ed1->getSymbols()[1].push_back(g1));
        ed1->getSymbols()[1].push_back(o3));
        ed1->getSymbols()[1].push_back(s1));
        ed1->getSymbols()[1].push_back(t2));
        ed1->getSymbols()[1].push_back(i2));
        ed1->getSymbols()[1].push_back(n3));
        ed1->getSymbols()[1].push_back(o4));
        ed1->getSymbols()[1].push_back(slash2));
        ed1->getSymbols().emplace_back();
        ed1->getSymbols()[2].push_back(m1));
        ed1->getSymbols()[2].push_back(a3));
        ed1->getSymbols()[2].push_back(r1));
        ed1->getSymbols()[2].push_back(c1));
        ed1->getSymbols()[2].push_back(o5));
        ed1->getSymbols()[2].push_back(slash3));
        ed1->getSymbols().emplace_back();
        ed1->getSymbols()[3].push_back(e1));
        ed1->getSymbols()[3].push_back(m2));
        ed1->getSymbols()[3].push_back(a4));
        ed1->getSymbols()[3].push_back(n4));
        ed1->getSymbols()[3].push_back(u1));
        ed1->getSymbols()[3].push_back(e2));
        ed1->getSymbols()[3].push_back(l1));
        ed1->getSymbols()[3].push_back(e3));
        ed1->getSymbols()[3].push_back(slash4));
        ed1->getSymbols().emplace_back();
        ed1->setCounter(32);
        ed1->setIdCounter(32);
    }

    virtual void TearDown() {
    }

    NetworkServer server;
    SharedEditor* ed1 = new SharedEditor(server);
    Symbol* a1 = new Symbol(char('a'), std::string{"0-0"}, std::vector<Identifier>{Identifier(1, 0)});
    Symbol* n1 = new Symbol(char('n'), std::string{"0-1"}, std::vector<Identifier>{Identifier(2, 0)});
    Symbol* t1 = new Symbol(char('t'), std::string{"0-2"}, std::vector<Identifier>{Identifier(3, 0)});
    Symbol* o1 = new Symbol(char('o'), std::string{"0-3"}, std::vector<Identifier>{Identifier(3, 0), Identifier(9, 0), Identifier(10, 0)});
    Symbol* n2 = new Symbol(char('n'), std::string{"0-4"}, std::vector<Identifier>{Identifier(3, 0), Identifier(10, 0)});
    Symbol* i1 = new Symbol(char('i'), std::string{"0-5"}, std::vector<Identifier>{Identifier(6, 0)});
    Symbol* o2 = new Symbol(char('o'), std::string{"0-6"}, std::vector<Identifier>{Identifier(7, 0)});
    Symbol* slash1 = new Symbol(char('\n'), std::string{"0-7"}, std::vector<Identifier>{Identifier(7, 0), Identifier(2, 0), Identifier(1, 0)});
    Symbol* a2 = new Symbol(char('a'), std::string{"0-8"}, std::vector<Identifier>{Identifier(7, 0), Identifier(2, 0), Identifier(5, 0), Identifier(6, 0)});
    Symbol* g1 = new Symbol(char('g'), std::string{"0-9"}, std::vector<Identifier>{Identifier(9, 0), Identifier(9, 0)});
    Symbol* o3 = new Symbol(char('o'), std::string{"0-10"}, std::vector<Identifier>{Identifier(10, 0), Identifier(39, 0), Identifier(6, 0)});
    Symbol* s1 = new Symbol(char('s'), std::string{"0-11"}, std::vector<Identifier>{Identifier(11, 0)});
    Symbol* t2 = new Symbol(char('t'), std::string{"0-12"}, std::vector<Identifier>{Identifier(11 0), Identifier(3, 0), Identifier(5, 0)});
    Symbol* i2 = new Symbol(char('i'), std::string{"0-13"}, std::vector<Identifier>{Identifier(12, 0), Identifier(9, 0), Identifier(7, 0), Identifier(6, 0)});
    Symbol* n3 = new Symbol(char('n'), std::string{"0-14"}, std::vector<Identifier>{Identifier(12, 0), Identifier(9, 0), Identifier(7, 0), Identifier(9, 0)});
    Symbol* o4 = new Symbol(char('o'), std::string{"0-15"}, std::vector<Identifier>{Identifier(15, 0)});
    Symbol* slash2 = new Symbol(char('\n'), std::string{"0-16"}, std::vector<Identifier>{Identifier(15, 0), Identifier(8, 0)});
    Symbol* m1 = new Symbol(char('m'), std::string{"0-17"}, std::vector<Identifier>{Identifier(16,0)});
    Symbol* a3 = new Symbol(char('a'), std::string{"0-18"}, std::vector<Identifier>{Identifier(17,0)});
    Symbol* r1 = new Symbol(char('r'), std::string{"0-19"}, std::vector<Identifier>{Identifier(17, 0), Identifier(1, 0)});
    Symbol* c1 = new Symbol(char('c'), std::string{"0-20"}, std::vector<Identifier>{Identifier(19, 0)});
    Symbol* o5 = new Symbol(char('o'), std::string{"0-21"}, std::vector<Identifier>{Identifier(19, 0), Identifier(8, 0), Identifier(2, 0)});
    Symbol* slash3 = new Symbol(char('\n'), std::string{"0-22"}, std::vector<Identifier>{Identifier(19, 0), Identifier(8, 0), Identifier(2, 0), Identifier(3, 0)});
    Symbol* e1 = new Symbol(char('e'), std::string{"0-23"}, std::vector<Identifier>{Identifier(21, 0)});
    Symbol* m2 = new Symbol(char('m'), std::string{"0-24"}, std::vector<Identifier>{Identifier(21, 0), Identifier(2, 0)});
    Symbol* a4 = new Symbol(char('a'), std::string{"0-25"}, std::vector<Identifier>{Identifier(23, 0), Identifier(1, 0)});
    Symbol* n4 = new Symbol(char('n'), std::string{"0-26"}, std::vector<Identifier>{Identifier(24, 0)});
    Symbol* u1 = new Symbol(char('u'), std::string{"0-27"}, std::vector<Identifier>{Identifier(24, 0), Identifier(5, 0), Identifier(6, 0)});
    Symbol* e2 = new Symbol(char('e'), std::string{"0-28"}, std::vector<Identifier>{Identifier(24, 0), Identifier(5, 0), Identifier(8, 0)});
    Symbol* l1 = new Symbol(char('l'), std::string{"0-29"}, std::vector<Identifier>{Identifier(24, 0), Identifier(6, 0)});
    Symbol* e3 = new Symbol(char('e'), std::string{"0-30"}, std::vector<Identifier>{Identifier(27, 0), Identifier(8, 0)});
    Symbol* slash4 = new Symbol(char('\n'), std::string{"0-31"}, std::vector<Identifier>{Identifier(27, 0), Identifier(8, 0), Identifier(9, 0)});

};

// todo testare prima riga vuota e le altre no
/*

TEST_F(SharedEditorTest, generateIdBetween) {
    int n1 = 0;
    int n2 = 10;
    int n = ed1->generateIdBetween(n1, n2, true);
    EXPECT_GE(n, n1);
    EXPECT_LT(n, n2);

    EXPECT_THROW(ed1->generateIdBetween(n2, n1, true), std::range_error);
    EXPECT_THROW(ed1->generateIdBetween(n1, n1, true), std::range_error);
    EXPECT_THROW(ed1->generateIdBetween(-1, n1, true), std::invalid_argument);
    EXPECT_THROW(ed1->generateIdBetween(n1, -2, true), std::invalid_argument);
    EXPECT_THROW(ed1->generateIdBetween(-1, -2, true), std::invalid_argument);

    EXPECT_EQ(2, ed1->generateIdBetween(1, 3, true));
}

TEST_F(SharedEditorTest, findPosBefore) {
    EXPECT_EQ(ed1->getSymbols()[2][5].getPosition(), ed1->findPosBefore(2, 5));
    EXPECT_EQ(std::vector<int>{0}, ed1->findPosBefore(Position(0, 0)));
    EXPECT_EQ((std::vector<int>{11, 3, 5}), ed1->findPosBefore(Position(1, 5)));
    EXPECT_EQ((std::vector<int>{7}), ed1->findPosBefore(Position(0, 7)));
    EXPECT_EQ((std::vector<int>{7, 2, 1}), ed1->findPosBefore(Position(1, 0)));

    ed1->getSymbols()[1].insert(ed1->getSymbols()[1].begin() + 3, Symbol(char('s'), std::string{"0_32"}, std::vector<int>{10, 5, 9}));
    EXPECT_EQ((std::vector<int>{10, 5, 9}), ed1->findPosBefore(Position(1, 4)));

    EXPECT_THROW(ed1->findPosBefore(Position(-1, 0)), std::out_of_range);
    EXPECT_THROW(ed1->findPosBefore(Position(0, -1)), std::out_of_range);
    EXPECT_THROW(ed1->findPosBefore(Position(5, 0)), std::out_of_range);
    EXPECT_THROW(ed1->findPosBefore(Position(0, 10)), std::out_of_range);

    ed1->getSymbols().clear();
    ed1->getSymbols().emplace_back();
    ed1->setCounter(0);
    EXPECT_EQ(std::vector<int>{0}, ed1->findPosBefore(Position(0, 0)));
}

TEST_F(SharedEditorTest, findPosAfter) {
    EXPECT_EQ(std::vector<int>{21}, ed1->findPosAfter(Position(3, 0)));
    EXPECT_EQ(std::vector<int>{1}, ed1->findPosAfter(Position(0, 0)));
    EXPECT_EQ((std::vector<int>{12, 9, 7, 6}), ed1->findPosAfter(Position(1, 5)));
    EXPECT_EQ((std::vector<int>{7, 2, 1}), ed1->findPosAfter(Position(0, 7)));

    ed1->getSymbols()[1].insert(ed1->getSymbols()[1].begin() + 3, Symbol(char('s'), std::string{"0_32"}, std::vector<int>{10, 5, 9}));
    EXPECT_EQ(std::vector<int>{11}, ed1->findPosAfter(Position(1, 4)));

    EXPECT_THROW(ed1->findPosAfter(Position(-1, 0)), std::out_of_range);
    EXPECT_THROW(ed1->findPosAfter(Position(0, -1)), std::out_of_range);
    EXPECT_THROW(ed1->findPosAfter(Position(5, 0)), std::out_of_range);
    EXPECT_THROW(ed1->findPosAfter(Position(0, 10)), std::out_of_range);

    ed1->getSymbols().clear();
    ed1->getSymbols().emplace_back();
    ed1->setCounter(0);
    EXPECT_EQ(std::vector<int>{ed1->getBase()}, ed1->findPosAfter(Position(0, 0)));
}

TEST_F(SharedEditorTest, generatePosBetween) {
    EXPECT_EQ(std::vector<int>{1}, ed1->generatePosBetween({0}, {2}, {}, 0));
    EXPECT_GT(ed1->generatePosBetween({0, 5}, {1, 7}, {}, 0)[1], 5);
    EXPECT_EQ((std::vector<int>{0, 6}), ed1->generatePosBetween({0, 5}, {0, 7}, {}, 0));
    EXPECT_GT(ed1->generatePosBetween({2, 5}, {2, 6}, {}, 0)[2], 5);
    EXPECT_LT(ed1->generatePosBetween({5, 4}, {5, 4, 7}, {}, 0)[2], 7);
    EXPECT_LT(ed1->generatePosBetween({19, 8, 2}, {19, 8, 2, 3}, {}, 0)[3], 3);
    EXPECT_GT(ed1->generatePosBetween({19, 8, 2}, {19, 8, 2, 1}, {}, 0)[4], -1);

    EXPECT_THROW(ed1->generatePosBetween({}, {2}, {}, 0), std::invalid_argument);
    EXPECT_THROW(ed1->generatePosBetween({1}, {2}, {}, -1), std::invalid_argument);
}

TEST_F(SharedEditorTest, insertSymbolNotCRLF) {


    Symbol s5('x', "0_32", {28});
    ed1->insertSymbol(Position(4, 0), s5);
    EXPECT_EQ(ed1->getSymbols()[3].size(), 9);
    EXPECT_EQ(ed1->getSymbols()[4].size(), 1);
    EXPECT_EQ(Symbol(char('e'), std::string{"0_23"}, std::vector<int>{21}), ed1->getSymbols()[3][0]);
    EXPECT_EQ(Symbol(char('m'), std::string{"0_24"}, std::vector<int>{21, 2}), ed1->getSymbols()[3][1]);
    EXPECT_EQ(Symbol(char('a'), std::string{"0_25"}, std::vector<int>{23, 1}), ed1->getSymbols()[3][2]);
    EXPECT_EQ(Symbol(char('n'), std::string{"0_26"}, std::vector<int>{24}), ed1->getSymbols()[3][3]);
    EXPECT_EQ(Symbol(char('u'), std::string{"0_27"}, std::vector<int>{24, 5, 6}), ed1->getSymbols()[3][4]);
    EXPECT_EQ(Symbol(char('e'), std::string{"0_28"}, std::vector<int>{24, 5, 8}), ed1->getSymbols()[3][5]);
    EXPECT_EQ(Symbol(char('l'), std::string{"0_29"}, std::vector<int>{24, 6}), ed1->getSymbols()[3][6]);
    EXPECT_EQ(Symbol(char('e'), std::string{"0_30"}, std::vector<int>{27, 8}), ed1->getSymbols()[3][7]);
    EXPECT_EQ(Symbol(char('\n'), std::string{"0_31"}, std::vector<int>{27, 8, 9}), ed1->getSymbols()[3][8]);
    EXPECT_EQ(s5, ed1->getSymbols()[4][0]);

    Symbol s1('x', "0_33", {0, 5});
    ed1->insertSymbol(Position(0, 0), s1);
    EXPECT_EQ(ed1->getSymbols()[0].size(), 9);
    EXPECT_EQ(s1, ed1->getSymbols()[0][0]);
    EXPECT_EQ(Symbol(char('a'), std::string{"0_0"}, std::vector<int>{1}), ed1->getSymbols()[0][1]);
    EXPECT_EQ(Symbol(char('n'), std::string{"0_1"}, std::vector<int>{2}), ed1->getSymbols()[0][2]);
    EXPECT_EQ(Symbol(char('t'), std::string{"0_2"}, std::vector<int>{3}), ed1->getSymbols()[0][3]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_3"}, std::vector<int>{3, 9, 10}), ed1->getSymbols()[0][4]);
    EXPECT_EQ(Symbol(char('n'), std::string{"0_4"}, std::vector<int>{3, 10}), ed1->getSymbols()[0][5]);
    EXPECT_EQ(Symbol(char('i'), std::string{"0_5"}, std::vector<int>{6}), ed1->getSymbols()[0][6]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_6"}, std::vector<int>{7}), ed1->getSymbols()[0][7]);
    EXPECT_EQ(Symbol(char('\n'), std::string{"0_7"}, std::vector<int>{7, 2, 1}), ed1->getSymbols()[0][8]);


    Symbol s2('x', "0_34", {27, 8, 3});
    ed1->insertSymbol(Position(3, 8), s2);
    EXPECT_EQ(ed1->getSymbols()[3].size(), 10);
    EXPECT_EQ(Symbol(char('e'), std::string{"0_23"}, std::vector<int>{21}), ed1->getSymbols()[3][0]);
    EXPECT_EQ(Symbol(char('m'), std::string{"0_24"}, std::vector<int>{21, 2}), ed1->getSymbols()[3][1]);
    EXPECT_EQ(Symbol(char('a'), std::string{"0_25"}, std::vector<int>{23, 1}), ed1->getSymbols()[3][2]);
    EXPECT_EQ(Symbol(char('n'), std::string{"0_26"}, std::vector<int>{24}), ed1->getSymbols()[3][3]);
    EXPECT_EQ(Symbol(char('u'), std::string{"0_27"}, std::vector<int>{24, 5, 6}), ed1->getSymbols()[3][4]);
    EXPECT_EQ(Symbol(char('e'), std::string{"0_28"}, std::vector<int>{24, 5, 8}), ed1->getSymbols()[3][5]);
    EXPECT_EQ(Symbol(char('l'), std::string{"0_29"}, std::vector<int>{24, 6}), ed1->getSymbols()[3][6]);
    EXPECT_EQ(Symbol(char('e'), std::string{"0_30"}, std::vector<int>{27, 8}), ed1->getSymbols()[3][7]);
    EXPECT_EQ(s2, ed1->getSymbols()[3][8]);
    EXPECT_EQ(Symbol(char('\n'), std::string{"0_31"}, std::vector<int>{27, 8, 9}), ed1->getSymbols()[3][9]);

    Symbol s3('x', "0_35", {19, 8, 2, 2});
    ed1->insertSymbol(Position(2, 5), s3);
    EXPECT_EQ(ed1->getSymbols()[2].size(), 7);
    EXPECT_EQ(s3, ed1->getSymbols()[2][5]);
    EXPECT_EQ(Symbol(char('m'), std::string{"0_17"}, std::vector<int>{16}), ed1->getSymbols()[2][0]);
    EXPECT_EQ(Symbol(char('a'), std::string{"0_18"}, std::vector<int>{17}), ed1->getSymbols()[2][1]);
    EXPECT_EQ(Symbol(char('r'), std::string{"0_19"}, std::vector<int>{17, 1}), ed1->getSymbols()[2][2]);
    EXPECT_EQ(Symbol(char('c'), std::string{"0_20"}, std::vector<int>{19}), ed1->getSymbols()[2][3]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_21"}, std::vector<int>{19, 8, 2}), ed1->getSymbols()[2][4]);
    EXPECT_EQ(Symbol(char('\n'), std::string{"0_22"}, std::vector<int>{19, 8, 2, 3}), ed1->getSymbols()[2][6]);

    Symbol s4('x', "0_36", {7, 2, 3});
    ed1->insertSymbol(Position(1, 0), s4);
    EXPECT_EQ(ed1->getSymbols()[1].size(), 10);
    EXPECT_EQ(s4, ed1->getSymbols()[1][0]);
    EXPECT_EQ(Symbol(char('a'), std::string{"0_8"}, std::vector<int>{7, 2, 5, 6}), ed1->getSymbols()[1][1]);
    EXPECT_EQ(Symbol(char('g'), std::string{"0_9"}, std::vector<int>{9, 9}), ed1->getSymbols()[1][2]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_10"}, std::vector<int>{10, 3, 6}), ed1->getSymbols()[1][3]);
    EXPECT_EQ(Symbol(char('s'), std::string{"0_11"}, std::vector<int>{11}), ed1->getSymbols()[1][4]);
    EXPECT_EQ(Symbol(char('t'), std::string{"0_12"}, std::vector<int>{11, 3, 5}), ed1->getSymbols()[1][5]);
    EXPECT_EQ(Symbol(char('i'), std::string{"0_13"}, std::vector<int>{12, 9, 7, 6}), ed1->getSymbols()[1][6]);
    EXPECT_EQ(Symbol(char('n'), std::string{"0_14"}, std::vector<int>{12, 9, 7, 9}), ed1->getSymbols()[1][7]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_15"}, std::vector<int>{15}), ed1->getSymbols()[1][8]);
    EXPECT_EQ(Symbol(char('\n'), std::string{"0_16"}, std::vector<int>{15, 8}), ed1->getSymbols()[1][9]);

    ed1->getSymbols().clear();
    ed1->getSymbols().emplace_back();
    ed1->setCounter(0);
    ed1->insertSymbol(Position(0, 0), s4);
    EXPECT_EQ(ed1->getSymbols().size(), 1);
    EXPECT_EQ(ed1->getSymbols()[0].size(), 1);
    EXPECT_EQ(ed1->getSymbols()[0][0], s4);
}

TEST_F(SharedEditorTest, insertSymbolCRLF) {

    Symbol s5('\n', "0_37", {29});
    ed1->insertSymbol(Position(4, 0), s5);
    EXPECT_EQ(ed1->getSymbols()[3].size(), 9);
    EXPECT_EQ(ed1->getSymbols()[4].size(), 1);
    EXPECT_EQ(s5, ed1->getSymbols()[4][0]);
    EXPECT_EQ(Symbol(char('e'), std::string{"0_23"}, std::vector<int>{21}), ed1->getSymbols()[3][0]);
    EXPECT_EQ(Symbol(char('m'), std::string{"0_24"}, std::vector<int>{21, 2}), ed1->getSymbols()[3][1]);
    EXPECT_EQ(Symbol(char('a'), std::string{"0_25"}, std::vector<int>{23, 1}), ed1->getSymbols()[3][2]);
    EXPECT_EQ(Symbol(char('n'), std::string{"0_26"}, std::vector<int>{24}), ed1->getSymbols()[3][3]);
    EXPECT_EQ(Symbol(char('u'), std::string{"0_27"}, std::vector<int>{24, 5, 6}), ed1->getSymbols()[3][4]);
    EXPECT_EQ(Symbol(char('e'), std::string{"0_28"}, std::vector<int>{24, 5, 8}), ed1->getSymbols()[3][5]);
    EXPECT_EQ(Symbol(char('l'), std::string{"0_29"}, std::vector<int>{24, 6}), ed1->getSymbols()[3][6]);
    EXPECT_EQ(Symbol(char('e'), std::string{"0_30"}, std::vector<int>{27, 8}), ed1->getSymbols()[3][7]);
    EXPECT_EQ(Symbol(char('\n'), std::string{"0_31"}, std::vector<int>{27, 8, 9}), ed1->getSymbols()[3][8]);

    Symbol s2('\n', "0_34", {27, 8, 3});
    ed1->insertSymbol(Position(3, 8), s2);
    EXPECT_EQ(ed1->getSymbols()[3].size(), 9);
    EXPECT_EQ(ed1->getSymbols()[4].size(), 1);
    EXPECT_EQ(Symbol(char('e'), std::string{"0_23"}, std::vector<int>{21}), ed1->getSymbols()[3][0]);
    EXPECT_EQ(Symbol(char('m'), std::string{"0_24"}, std::vector<int>{21, 2}), ed1->getSymbols()[3][1]);
    EXPECT_EQ(Symbol(char('a'), std::string{"0_25"}, std::vector<int>{23, 1}), ed1->getSymbols()[3][2]);
    EXPECT_EQ(Symbol(char('n'), std::string{"0_26"}, std::vector<int>{24}), ed1->getSymbols()[3][3]);
    EXPECT_EQ(Symbol(char('u'), std::string{"0_27"}, std::vector<int>{24, 5, 6}), ed1->getSymbols()[3][4]);
    EXPECT_EQ(Symbol(char('e'), std::string{"0_28"}, std::vector<int>{24, 5, 8}), ed1->getSymbols()[3][5]);
    EXPECT_EQ(Symbol(char('l'), std::string{"0_29"}, std::vector<int>{24, 6}), ed1->getSymbols()[3][6]);
    EXPECT_EQ(Symbol(char('e'), std::string{"0_30"}, std::vector<int>{27, 8}), ed1->getSymbols()[3][7]);
    EXPECT_EQ(s2, ed1->getSymbols()[3][8]);
    EXPECT_EQ(Symbol(char('\n'), std::string{"0_31"}, std::vector<int>{27, 8, 9}), ed1->getSymbols()[4][0]);
    EXPECT_EQ(s5, ed1->getSymbols()[5][0]);

    Symbol s3('\n', "0_35", {17, 5});
    ed1->insertSymbol(Position(2, 3), s3);
    EXPECT_EQ(ed1->getSymbols()[2].size(), 4);
    EXPECT_EQ(ed1->getSymbols()[3].size(), 3);
    EXPECT_EQ(Symbol(char('m'), std::string{"0_17"}, std::vector<int>{16}), ed1->getSymbols()[2][0]);
    EXPECT_EQ(Symbol(char('a'), std::string{"0_18"}, std::vector<int>{17}), ed1->getSymbols()[2][1]);
    EXPECT_EQ(Symbol(char('r'), std::string{"0_19"}, std::vector<int>{17, 1}), ed1->getSymbols()[2][2]);
    EXPECT_EQ(s3, ed1->getSymbols()[2][3]);
    EXPECT_EQ(Symbol(char('c'), std::string{"0_20"}, std::vector<int>{19}), ed1->getSymbols()[3][0]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_21"}, std::vector<int>{19, 8, 2}), ed1->getSymbols()[3][1]);
    EXPECT_EQ(Symbol(char('\n'), std::string{"0_22"}, std::vector<int>{19, 8, 2, 3}), ed1->getSymbols()[3][2]);

    Symbol s4('\n', "0_36", {7, 2, 3});
    ed1->insertSymbol(Position(1, 0), s4);
    EXPECT_EQ(ed1->getSymbols()[1].size(), 1);
    EXPECT_EQ(ed1->getSymbols()[2].size(), 9);
    EXPECT_EQ(s4, ed1->getSymbols()[1][0]);
    EXPECT_EQ(Symbol(char('a'), std::string{"0_8"}, std::vector<int>{7, 2, 5, 6}), ed1->getSymbols()[2][0]);
    EXPECT_EQ(Symbol(char('g'), std::string{"0_9"}, std::vector<int>{9, 9}), ed1->getSymbols()[2][1]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_10"}, std::vector<int>{10, 3, 6}), ed1->getSymbols()[2][2]);
    EXPECT_EQ(Symbol(char('s'), std::string{"0_11"}, std::vector<int>{11}), ed1->getSymbols()[2][3]);
    EXPECT_EQ(Symbol(char('t'), std::string{"0_12"}, std::vector<int>{11, 3, 5}), ed1->getSymbols()[2][4]);
    EXPECT_EQ(Symbol(char('i'), std::string{"0_13"}, std::vector<int>{12, 9, 7, 6}), ed1->getSymbols()[2][5]);
    EXPECT_EQ(Symbol(char('n'), std::string{"0_14"}, std::vector<int>{12, 9, 7, 9}), ed1->getSymbols()[2][6]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_15"}, std::vector<int>{15}), ed1->getSymbols()[2][7]);
    EXPECT_EQ(Symbol(char('\n'), std::string{"0_16"}, std::vector<int>{15, 8}), ed1->getSymbols()[2][8]);

    Symbol s1('\n', "0_33", {0, 5});
    ed1->insertSymbol(Position(0, 0), s1);
    EXPECT_EQ(ed1->getSymbols()[0].size(), 1);
    EXPECT_EQ(ed1->getSymbols()[1].size(), 8);
    EXPECT_EQ(s1, ed1->getSymbols()[0][0]);
    EXPECT_EQ(Symbol(char('a'), std::string{"0_0"}, std::vector<int>{1}), ed1->getSymbols()[1][0]);
    EXPECT_EQ(Symbol(char('n'), std::string{"0_1"}, std::vector<int>{2}), ed1->getSymbols()[1][1]);
    EXPECT_EQ(Symbol(char('t'), std::string{"0_2"}, std::vector<int>{3}), ed1->getSymbols()[1][2]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_3"}, std::vector<int>{3, 9, 10}), ed1->getSymbols()[1][3]);
    EXPECT_EQ(Symbol(char('n'), std::string{"0_4"}, std::vector<int>{3, 10}), ed1->getSymbols()[1][4]);
    EXPECT_EQ(Symbol(char('i'), std::string{"0_5"}, std::vector<int>{6}), ed1->getSymbols()[1][5]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_6"}, std::vector<int>{7}), ed1->getSymbols()[1][6]);
    EXPECT_EQ(Symbol(char('\n'), std::string{"0_7"}, std::vector<int>{7, 2, 1}), ed1->getSymbols()[1][7]);

    ed1->getSymbols().clear();
    ed1->getSymbols().emplace_back();
    ed1->setCounter(0);
    ed1->insertSymbol(Position(0, 0), s1);
    EXPECT_EQ(ed1->getSymbols().size(), 2);
    EXPECT_EQ(ed1->getSymbols()[0][0], s1);
}

TEST_F(SharedEditorTest, localInsertNotCRLF) {
    ed1->localInsert(Position(3, 9), 'x');
    EXPECT_EQ('x', ed1->getSymbols()[4][0].getC());
    EXPECT_EQ('\n', ed1->getSymbols()[3][8].getC());

    ed1->localInsert(Position(0, 0), 'y');
    EXPECT_EQ('y', ed1->getSymbols()[0][0].getC());

    ed1->localInsert(Position(3, 8), 'z');
    EXPECT_EQ('z', ed1->getSymbols()[3][8].getC());

    ed1->localInsert(Position(2, 5), 'k');
    EXPECT_EQ('k', ed1->getSymbols()[2][5].getC());

    ed1->localInsert(Position(1, 0), 'q');
    EXPECT_EQ('q', ed1->getSymbols()[1][0].getC());

    ed1->getSymbols().clear();
    ed1->getSymbols().emplace_back();
    ed1->setCounter(0);
    ed1->localInsert(Position(0, 0), 'a');
    EXPECT_EQ(ed1->getSymbols().size(), 1);
    EXPECT_EQ(ed1->getSymbols()[0][0].getC(), 'a');
}

TEST_F(SharedEditorTest, localInsertCRLF) {

    ed1->localInsert(Position(3, 9), '\n');
    EXPECT_EQ('\n', ed1->getSymbols()[4][0].getC());
    EXPECT_EQ('\n', ed1->getSymbols()[3][8].getC());

    ed1->localInsert(Position(3, 8), '\n');
    EXPECT_EQ('\n', ed1->getSymbols()[3][8].getC());
    EXPECT_EQ('\n', ed1->getSymbols()[4][0].getC());

    ed1->localInsert(Position(2, 3), '\n');
    EXPECT_EQ('\n', ed1->getSymbols()[2][3].getC());
    EXPECT_EQ('c', ed1->getSymbols()[3][0].getC());

    ed1->localInsert(Position(1, 0), '\n');
    EXPECT_EQ('\n', ed1->getSymbols()[1][0].getC());
    EXPECT_EQ('a', ed1->getSymbols()[2][0].getC());

    ed1->localInsert(Position(0, 0), '\n');
    EXPECT_EQ('\n', ed1->getSymbols()[0][0].getC());
    EXPECT_EQ('a', ed1->getSymbols()[1][0].getC());

    ed1->getSymbols().clear();
    ed1->getSymbols().emplace_back();
    ed1->setCounter(0);
    ed1->localInsert(Position(0, 0), '\n');
    EXPECT_EQ(ed1->getSymbols().size(), 2);
    EXPECT_EQ(ed1->getSymbols()[0][0].getC(), '\n');
}

TEST_F(SharedEditorTest, eraseSingleLine) {
    ed1->eraseSingleLine(Position(3, 5), Position(3, 8));
    EXPECT_EQ(ed1->getSymbols()[3].size(), 5);
    EXPECT_EQ(ed1->getSymbols().size(), 5);
    EXPECT_EQ(Symbol(char('e'), std::string{"0_23"}, std::vector<int>{21}), ed1->getSymbols()[3][0]);
    EXPECT_EQ(Symbol(char('m'), std::string{"0_24"}, std::vector<int>{21, 2}), ed1->getSymbols()[3][1]);
    EXPECT_EQ(Symbol(char('a'), std::string{"0_25"}, std::vector<int>{23, 1}), ed1->getSymbols()[3][2]);
    EXPECT_EQ(Symbol(char('n'), std::string{"0_26"}, std::vector<int>{24}), ed1->getSymbols()[3][3]);
    EXPECT_EQ(Symbol(char('u'), std::string{"0_27"}, std::vector<int>{24, 5, 6}), ed1->getSymbols()[3][4]);

    ed1->eraseSingleLine(Position(2, 0), Position(2, 2));
    EXPECT_EQ(ed1->getSymbols().size(), 5);
    EXPECT_EQ(Symbol(char('c'), std::string{"0_20"}, std::vector<int>{19}), ed1->getSymbols()[2][0]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_21"}, std::vector<int>{19, 8, 2}), ed1->getSymbols()[2][1]);
    EXPECT_EQ(Symbol(char('\n'), std::string{"0_22"}, std::vector<int>{19, 8, 2, 3}), ed1->getSymbols()[2][2]);

    ed1->eraseSingleLine(Position(1, 2), Position(1, 5));
    EXPECT_EQ(ed1->getSymbols().size(), 5);
    EXPECT_EQ(Symbol(char('a'), std::string{"0_8"}, std::vector<int>{7, 2, 5, 6}), ed1->getSymbols()[1][0]);
    EXPECT_EQ(Symbol(char('g'), std::string{"0_9"}, std::vector<int>{9, 9}), ed1->getSymbols()[1][1]);
    EXPECT_EQ(Symbol(char('n'), std::string{"0_14"}, std::vector<int>{12, 9, 7, 9}), ed1->getSymbols()[1][2]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_15"}, std::vector<int>{15}), ed1->getSymbols()[1][3]);
    EXPECT_EQ(Symbol(char('\n'), std::string{"0_16"}, std::vector<int>{15, 8}), ed1->getSymbols()[1][4]);

    ed1->eraseSingleLine(Position(0, 3), Position(0, 3));
    EXPECT_EQ(ed1->getSymbols().size(), 5);
    EXPECT_EQ(Symbol(char('a'), std::string{"0_0"}, std::vector<int>{1}), ed1->getSymbols()[0][0]);
    EXPECT_EQ(Symbol(char('n'), std::string{"0_1"}, std::vector<int>{2}), ed1->getSymbols()[0][1]);
    EXPECT_EQ(Symbol(char('t'), std::string{"0_2"}, std::vector<int>{3}), ed1->getSymbols()[0][2]);
    EXPECT_EQ(Symbol(char('n'), std::string{"0_4"}, std::vector<int>{3, 10}), ed1->getSymbols()[0][3]);
    EXPECT_EQ(Symbol(char('i'), std::string{"0_5"}, std::vector<int>{6}), ed1->getSymbols()[0][4]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_6"}, std::vector<int>{7}), ed1->getSymbols()[0][5]);
    EXPECT_EQ(Symbol(char('\n'), std::string{"0_7"}, std::vector<int>{7, 2, 1}), ed1->getSymbols()[0][6]);
}

TEST_F(SharedEditorTest, eraseMultipleLines) {
    ed1->eraseMultipleLines(Position(2, 3), Position(3, 5));
    EXPECT_EQ(ed1->getSymbols().size(), 5);
    EXPECT_EQ(Symbol(char('m'), std::string{"0_17"}, std::vector<int>{16}), ed1->getSymbols()[2][0]);
    EXPECT_EQ(Symbol(char('a'), std::string{"0_18"}, std::vector<int>{17}), ed1->getSymbols()[2][1]);
    EXPECT_EQ(Symbol(char('r'), std::string{"0_19"}, std::vector<int>{17, 1}), ed1->getSymbols()[2][2]);
    EXPECT_EQ(Symbol(char('l'), std::string{"0_29"}, std::vector<int>{24, 6}), ed1->getSymbols()[3][0]);
    EXPECT_EQ(Symbol(char('e'), std::string{"0_30"}, std::vector<int>{27, 8}), ed1->getSymbols()[3][1]);
    EXPECT_EQ(Symbol(char('\n'), std::string{"0_31"}, std::vector<int>{27, 8, 9}), ed1->getSymbols()[3][2]);

    ed1->eraseMultipleLines(Position(0, 0), Position(2, 2));
    EXPECT_EQ(ed1->getSymbols().size(), 4);
    EXPECT_TRUE(ed1->getSymbols()[0].empty());
    EXPECT_TRUE(ed1->getSymbols()[1].empty());
    EXPECT_EQ(Symbol(char('l'), std::string{"0_29"}, std::vector<int>{24, 6}), ed1->getSymbols()[2][0]);
    EXPECT_EQ(Symbol(char('e'), std::string{"0_30"}, std::vector<int>{27, 8}), ed1->getSymbols()[2][1]);
    EXPECT_EQ(Symbol(char('\n'), std::string{"0_31"}, std::vector<int>{27, 8, 9}), ed1->getSymbols()[2][2]);
}

TEST_F(SharedEditorTest, localEraseSingleLine) {
    ed1->localErase(Position(3, 0), Position(3, 8));
    EXPECT_EQ(ed1->getSymbols().size(), 4);

    ed1->localErase(Position(1, 8), Position(1, 8));
    EXPECT_EQ(ed1->getSymbols().size(), 3);
    EXPECT_EQ(Symbol(char('a'), std::string{"0_8"}, std::vector<int>{7, 2, 5, 6}), ed1->getSymbols()[1][0]);
    EXPECT_EQ(Symbol(char('g'), std::string{"0_9"}, std::vector<int>{9, 9}), ed1->getSymbols()[1][1]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_10"}, std::vector<int>{10, 3, 6}), ed1->getSymbols()[1][2]);
    EXPECT_EQ(Symbol(char('s'), std::string{"0_11"}, std::vector<int>{11}), ed1->getSymbols()[1][3]);
    EXPECT_EQ(Symbol(char('t'), std::string{"0_12"}, std::vector<int>{11, 3, 5}), ed1->getSymbols()[1][4]);
    EXPECT_EQ(Symbol(char('i'), std::string{"0_13"}, std::vector<int>{12, 9, 7, 6}), ed1->getSymbols()[1][5]);
    EXPECT_EQ(Symbol(char('n'), std::string{"0_14"}, std::vector<int>{12, 9, 7, 9}), ed1->getSymbols()[1][6]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_15"}, std::vector<int>{15}), ed1->getSymbols()[1][7]);
    EXPECT_EQ(Symbol(char('m'), std::string{"0_17"}, std::vector<int>{16}), ed1->getSymbols()[1][8]);
    EXPECT_EQ(Symbol(char('a'), std::string{"0_18"}, std::vector<int>{17}), ed1->getSymbols()[1][9]);
    EXPECT_EQ(Symbol(char('r'), std::string{"0_19"}, std::vector<int>{17, 1}), ed1->getSymbols()[1][10]);
    EXPECT_EQ(Symbol(char('c'), std::string{"0_20"}, std::vector<int>{19}), ed1->getSymbols()[1][11]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_21"}, std::vector<int>{19, 8, 2}), ed1->getSymbols()[1][12]);
    EXPECT_EQ(Symbol(char('\n'), std::string{"0_22"}, std::vector<int>{19, 8, 2, 3}), ed1->getSymbols()[1][13]);

    ed1->localErase(Position(0, 0), Position(0, 7));
    EXPECT_EQ(ed1->getSymbols().size(), 2);
    EXPECT_EQ(Symbol(char('a'), std::string{"0_8"}, std::vector<int>{7, 2, 5, 6}), ed1->getSymbols()[0][0]);
    EXPECT_EQ(Symbol(char('g'), std::string{"0_9"}, std::vector<int>{9, 9}), ed1->getSymbols()[0][1]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_10"}, std::vector<int>{10, 3, 6}), ed1->getSymbols()[0][2]);
    EXPECT_EQ(Symbol(char('s'), std::string{"0_11"}, std::vector<int>{11}), ed1->getSymbols()[0][3]);
    EXPECT_EQ(Symbol(char('t'), std::string{"0_12"}, std::vector<int>{11, 3, 5}), ed1->getSymbols()[0][4]);
    EXPECT_EQ(Symbol(char('i'), std::string{"0_13"}, std::vector<int>{12, 9, 7, 6}), ed1->getSymbols()[0][5]);
    EXPECT_EQ(Symbol(char('n'), std::string{"0_14"}, std::vector<int>{12, 9, 7, 9}), ed1->getSymbols()[0][6]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_15"}, std::vector<int>{15}), ed1->getSymbols()[0][7]);
    EXPECT_EQ(Symbol(char('m'), std::string{"0_17"}, std::vector<int>{16}), ed1->getSymbols()[0][8]);
    EXPECT_EQ(Symbol(char('a'), std::string{"0_18"}, std::vector<int>{17}), ed1->getSymbols()[0][9]);
    EXPECT_EQ(Symbol(char('r'), std::string{"0_19"}, std::vector<int>{17, 1}), ed1->getSymbols()[0][10]);
    EXPECT_EQ(Symbol(char('c'), std::string{"0_20"}, std::vector<int>{19}), ed1->getSymbols()[0][11]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_21"}, std::vector<int>{19, 8, 2}), ed1->getSymbols()[0][12]);
    EXPECT_EQ(Symbol(char('\n'), std::string{"0_22"}, std::vector<int>{19, 8, 2, 3}), ed1->getSymbols()[0][13]);

    ed1->localErase(Position(0, 0), Position(0, 13));
    EXPECT_EQ(ed1->getSymbols().size(), 1);
}

TEST_F(SharedEditorTest, localEraseMultipleLine) {
    ed1->localErase(Position(1, 8), Position(3, 8));
    EXPECT_EQ(ed1->getSymbols().size(), 2);
    EXPECT_EQ(Symbol(char('a'), std::string{"0_8"}, std::vector<int>{7, 2, 5, 6}), ed1->getSymbols()[1][0]);
    EXPECT_EQ(Symbol(char('g'), std::string{"0_9"}, std::vector<int>{9, 9}), ed1->getSymbols()[1][1]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_10"}, std::vector<int>{10, 3, 6}), ed1->getSymbols()[1][2]);
    EXPECT_EQ(Symbol(char('s'), std::string{"0_11"}, std::vector<int>{11}), ed1->getSymbols()[1][3]);
    EXPECT_EQ(Symbol(char('t'), std::string{"0_12"}, std::vector<int>{11, 3, 5}), ed1->getSymbols()[1][4]);
    EXPECT_EQ(Symbol(char('i'), std::string{"0_13"}, std::vector<int>{12, 9, 7, 6}), ed1->getSymbols()[1][5]);
    EXPECT_EQ(Symbol(char('n'), std::string{"0_14"}, std::vector<int>{12, 9, 7, 9}), ed1->getSymbols()[1][6]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_15"}, std::vector<int>{15}), ed1->getSymbols()[1][7]);

    ed1->localErase(Position(0, 7), Position(1, 0));
    EXPECT_EQ(ed1->getSymbols().size(), 1);
    EXPECT_EQ(Symbol(char('a'), std::string{"0_0"}, std::vector<int>{1}), ed1->getSymbols()[0][0]);
    EXPECT_EQ(Symbol(char('n'), std::string{"0_1"}, std::vector<int>{2}), ed1->getSymbols()[0][1]);
    EXPECT_EQ(Symbol(char('t'), std::string{"0_2"}, std::vector<int>{3}), ed1->getSymbols()[0][2]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_3"}, std::vector<int>{3, 9, 10}), ed1->getSymbols()[0][3]);
    EXPECT_EQ(Symbol(char('n'), std::string{"0_4"}, std::vector<int>{3, 10}), ed1->getSymbols()[0][4]);
    EXPECT_EQ(Symbol(char('i'), std::string{"0_5"}, std::vector<int>{6}), ed1->getSymbols()[0][5]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_6"}, std::vector<int>{7}), ed1->getSymbols()[0][6]);
    EXPECT_EQ(Symbol(char('g'), std::string{"0_9"}, std::vector<int>{9, 9}), ed1->getSymbols()[0][7]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_10"}, std::vector<int>{10, 3, 6}), ed1->getSymbols()[0][8]);
    EXPECT_EQ(Symbol(char('s'), std::string{"0_11"}, std::vector<int>{11}), ed1->getSymbols()[0][9]);
    EXPECT_EQ(Symbol(char('t'), std::string{"0_12"}, std::vector<int>{11, 3, 5}), ed1->getSymbols()[0][10]);
    EXPECT_EQ(Symbol(char('i'), std::string{"0_13"}, std::vector<int>{12, 9, 7, 6}), ed1->getSymbols()[0][11]);
    EXPECT_EQ(Symbol(char('n'), std::string{"0_14"}, std::vector<int>{12, 9, 7, 9}), ed1->getSymbols()[0][12]);
    EXPECT_EQ(Symbol(char('o'), std::string{"0_15"}, std::vector<int>{15}), ed1->getSymbols()[0][13]);

    ed1->getSymbols().back().push_back(Symbol(char('\n'), std::string{"0_32"}, std::vector<int>{16}));
    ed1->getSymbols().emplace_back();
    ed1->getSymbols().back().push_back(Symbol(char('x'), std::string{"0_33"}, std::vector<int>{18}));
    ed1->setCounter(ed1->getCounter()+2);
    ed1->localErase(Position(0, 0), Position(1, 0));
    EXPECT_EQ(ed1->getSymbols().size(), 1);
}

TEST_F(SharedEditorTest, remoteInsert) {
    Symbol s1('x', "0_32", {28});
    ed1->remoteInsert(s1);
    EXPECT_EQ(ed1->getSymbols()[4][0], s1);

    Symbol s11('t', "0_42", {27, 8, 9});
    ed1->remoteInsert(s11);
    EXPECT_EQ(ed1->getSymbols()[4][0], s11);
    EXPECT_EQ(ed1->getSymbols()[4][1], s1);

    Symbol s12('w', "0_43", {27, 8, 1});
    ed1->remoteInsert(s12);
    EXPECT_EQ(ed1->getSymbols()[3][8], s12);
    EXPECT_EQ(ed1->getSymbols()[3][9], Symbol(char('\n'), std::string{"0_31"}, std::vector<int>{27, 8, 9}));
    EXPECT_EQ(ed1->getSymbols()[4][0], s11);
    EXPECT_EQ(ed1->getSymbols()[4][1], s1);

    Symbol s2('\n', "0_33", {26});
    ed1->remoteInsert(s2);
    EXPECT_EQ(ed1->getSymbols().size(), 6);
    EXPECT_EQ(ed1->getSymbols()[3][6], Symbol(char('l'), std::string{"0_29"}, std::vector<int>{24, 6}));
    EXPECT_EQ(ed1->getSymbols()[3][7], s2);
    EXPECT_EQ(ed1->getSymbols()[4][0], Symbol(char('e'), std::string{"0_30"}, std::vector<int>{27, 8}));
    EXPECT_EQ(ed1->getSymbols()[4][1], s12);
    EXPECT_EQ(ed1->getSymbols()[4][2], Symbol(char('\n'), std::string{"0_31"}, std::vector<int>{27, 8, 9}));

    Symbol s3('z', "0_34", {20});
    ed1->remoteInsert(s3);
    EXPECT_EQ(ed1->getSymbols()[3][0], s3);
    EXPECT_EQ(ed1->getSymbols()[3][1], Symbol(char('e'), std::string{"0_23"}, std::vector<int>{21}));

    Symbol s4('k', "0_35", {19, 8, 2});
    ed1->remoteInsert(s4);
    EXPECT_LT(ed1->getSymbols()[2][4], ed1->getSymbols()[2][5]);
    EXPECT_LT(ed1->getSymbols()[2][5], ed1->getSymbols()[2][6]);
    EXPECT_EQ(ed1->getSymbols()[2][4], Symbol(char('o'), std::string{"0_21"}, std::vector<int>{19, 8, 2}));
    EXPECT_EQ(ed1->getSymbols()[2][5], s4);
    EXPECT_EQ(ed1->getSymbols()[2][6], Symbol(char('\n'), std::string{"0_22"}, std::vector<int>{19, 8, 2, 3}));

    Symbol s6('q', "0_37", {15, 8});
    ed1->remoteInsert(s6);
    EXPECT_LT(ed1->getSymbols()[1][8], ed1->getSymbols()[2][0]);
    EXPECT_LT(ed1->getSymbols()[2][0], ed1->getSymbols()[2][1]);
    EXPECT_EQ(ed1->getSymbols()[2][0], s6);
    EXPECT_EQ(ed1->getSymbols()[2][1], Symbol(char('m'), std::string{"0_17"}, std::vector<int>{16}));

    Symbol s7('p', "0_38", {3, 5});
    ed1->remoteInsert(s7);
    EXPECT_EQ(ed1->getSymbols()[0][2], Symbol(char('t'), std::string{"0_2"}, std::vector<int>{3}));
    EXPECT_EQ(ed1->getSymbols()[0][3], s7);

    Symbol s5('l', "0_36", {0, 4});
    ed1->remoteInsert(s5);
    EXPECT_EQ(ed1->getSymbols()[0][0], s5);
    EXPECT_EQ(ed1->getSymbols()[0][1], Symbol(char('a'), std::string{"0_0"}, std::vector<int>{1}));

    Symbol s8('t', "0_39", {0, 4});
    ed1->remoteInsert(s8);
    EXPECT_EQ(ed1->getSymbols()[0][0], s5);
    EXPECT_EQ(ed1->getSymbols()[0][1], s8);

    ed1->getSymbols().clear();
    ed1->getSymbols().emplace_back();
    ed1->setCounter(0);
    Symbol s9('a', "0_40", {30});
    ed1->remoteInsert(s9);
    EXPECT_EQ(ed1->getSymbols().size(), 1);
    EXPECT_EQ(ed1->getSymbols()[0][0], s9);

    ed1->getSymbols().clear();
    ed1->getSymbols().emplace_back();
    ed1->setCounter(0);
    Symbol s10('\n', "0_41", {30});
    ed1->remoteInsert(s10);
    EXPECT_EQ(ed1->getSymbols().size(), 2);
    EXPECT_EQ(ed1->getSymbols()[0][0], s10);
}

TEST_F(SharedEditorTest, remoteErase) {
    ed1->remoteErase(Symbol(char('\n'), std::string{"0_31"}, std::vector<int>{27, 8, 9}));
    EXPECT_EQ(ed1->getSymbols()[3].size(), 8);
    EXPECT_EQ(ed1->getSymbols()[3][7], Symbol(char('e'), std::string{"0_30"}, std::vector<int>{27, 8}));

    ed1->remoteErase(Symbol(char('u'), std::string{"0_27"}, std::vector<int>{24, 5, 6}));
    EXPECT_EQ(ed1->getSymbols()[3].size(), 7);
    EXPECT_EQ(ed1->getSymbols()[3][3], Symbol(char('n'), std::string{"0_26"}, std::vector<int>{24}));
    EXPECT_EQ(ed1->getSymbols()[3][4], Symbol(char('e'), std::string{"0_28"}, std::vector<int>{24, 5, 8}));

    ed1->remoteErase(Symbol(char('\n'), std::string{"0_22"}, std::vector<int>{19, 8, 2, 3}));
    EXPECT_EQ(ed1->getSymbols()[2].size(), 12);
    EXPECT_EQ(ed1->getSymbols()[2][4], Symbol(char('o'), std::string{"0_21"}, std::vector<int>{19, 8, 2}));
    EXPECT_EQ(ed1->getSymbols()[2][5], Symbol(char('e'), std::string{"0_23"}, std::vector<int>{21}));

    ed1->remoteErase(Symbol(char('a'), std::string{"0_0"}, std::vector<int>{1}));
    EXPECT_EQ(ed1->getSymbols()[0].size(), 7);
    EXPECT_EQ(ed1->getSymbols()[0][0], Symbol(char('n'), std::string{"0_1"}, std::vector<int>{2}));


    ed1->remoteErase(Symbol(char('n'), std::string{"0_4"}, std::vector<int>{3, 10, 6}));
    EXPECT_EQ(ed1->getSymbols()[0].size(), 6);
    EXPECT_EQ(ed1->getSymbols()[0][3], Symbol(char('i'), std::string{"0_5"}, std::vector<int>{6}));

    ed1->remoteErase(Symbol(char('a'), std::string{"0_8"}, std::vector<int>{7, 2, 1}));
    EXPECT_EQ(ed1->getSymbols()[0].size(), 6);
    EXPECT_EQ(ed1->getSymbols()[1].size(), 8);
    EXPECT_EQ(ed1->getSymbols()[0][5], Symbol(char('\n'), std::string{"0_7"}, std::vector<int>{7, 2, 1}));
    EXPECT_EQ(ed1->getSymbols()[1][0], Symbol(char('g'), std::string{"0_9"}, std::vector<int>{9, 9}));

    ed1->getSymbols().clear();
    ed1->getSymbols().emplace_back();
    ed1->setCounter(0);
    Symbol s10('\n', "0_41", {30});
    ed1->remoteErase(s10);
    EXPECT_EQ(ed1->getSymbols().size(), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}*/
