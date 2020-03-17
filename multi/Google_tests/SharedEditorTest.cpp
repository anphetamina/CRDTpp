#include "gtest/gtest.h"
#include "../src/NetworkServer.h"

class SharedEditorTest : public ::testing::Test {

protected:

    virtual void SetUp() {

        ed1->getSymbols().push_back(Symbol(char('a'), std::string{"0_0"}, std::vector<int>{1}));
        ed1->getSymbols().push_back(Symbol(char('n'), std::string{"0_1"}, std::vector<int>{2}));
        ed1->getSymbols().push_back(Symbol(char('t'), std::string{"0_2"}, std::vector<int>{3}));
        ed1->getSymbols().push_back(Symbol(char('o'), std::string{"0_3"}, std::vector<int>{4}));
        ed1->getSymbols().push_back(Symbol(char('n'), std::string{"0_4"}, std::vector<int>{5}));
        ed1->getSymbols().push_back(Symbol(char('i'), std::string{"0_5"}, std::vector<int>{6}));
        ed1->getSymbols().push_back(Symbol(char('o'), std::string{"0_6"}, std::vector<int>{7}));
        ed1->setCounter(7);
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

TEST_F(SharedEditorTest, findPosAfter) {
    ASSERT_EQ(std::vector<int>{6}, ed1->findPosAfter(5));
    ASSERT_EQ(std::vector<int>{ed1->getBase()}, ed1->findPosAfter(100));

    ed1->getSymbols().insert(ed1->getSymbols().begin() + 2, Symbol(char('z'), std::string{"0_8"}, std::vector<int>{2, 5}));
    ed1->getSymbols().insert(ed1->getSymbols().begin() + 2, Symbol(char('y'), std::string{"0_9"}, std::vector<int>{2, 2}));
    ed1->getSymbols().insert(ed1->getSymbols().begin() + 3, Symbol(char('x'), std::string{"0_10"}, std::vector<int>{2, 2, 10}));
    ed1->setCounter(ed1->getCounter() + 3);

    ASSERT_EQ((std::vector<int>{3}), ed1->findPosAfter(5));
    ASSERT_EQ((std::vector<int>{2, 2, 10}), ed1->findPosAfter(3));
    ASSERT_EQ((std::vector<int>{2, 5}), ed1->findPosAfter(4));

    ASSERT_THROW(ed1->findPosAfter(-1), std::invalid_argument);
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
    std::vector<Symbol> s;
    s.push_back(Symbol(char('a'), std::string{"0_0"}, std::vector<int>{1}));
    s.push_back(Symbol(char('n'), std::string{"0_1"}, std::vector<int>{2}));
    s.push_back(Symbol(char('t'), std::string{"0_2"}, std::vector<int>{3}));
    s.push_back(Symbol(char('o'), std::string{"0_3"}, std::vector<int>{4}));
    s.push_back(Symbol(char('n'), std::string{"0_4"}, std::vector<int>{5}));
    s.push_back(Symbol(char('i'), std::string{"0_5"}, std::vector<int>{6}));
    s.push_back(Symbol(char('o'), std::string{"0_6"}, std::vector<int>{7}));

    ed1->getSymbols().clear();
    ed1->setCounter(0);

    ed1->localInsert(0, 'a');
    ed1->localInsert(1, 'n');
    ed1->localInsert(2, 't');
    ed1->localInsert(3, 'o');
    ed1->localInsert(4, 'n');
    ed1->localInsert(5, 'i');
    ed1->localInsert(60, 'o');

    ASSERT_EQ(s, ed1->getSymbols());
    ASSERT_THROW(ed1->localInsert(-1, 'z'), std::invalid_argument);
}

TEST_F(SharedEditorTest, localErase) {
    std::vector<Symbol> s;
    s.push_back(Symbol(char('n'), std::string{"0_1"}, std::vector<int>{2}));
    s.push_back(Symbol(char('t'), std::string{"0_2"}, std::vector<int>{3}));
    s.push_back(Symbol(char('n'), std::string{"0_4"}, std::vector<int>{5}));
    s.push_back(Symbol(char('i'), std::string{"0_5"}, std::vector<int>{6}));

    ed1->localErase(3);
    ed1->localErase(0);
    ed1->localErase(60);

    ASSERT_EQ(s, ed1->getSymbols());
    ASSERT_THROW(ed1->localErase(-1), std::invalid_argument);
}

TEST_F(SharedEditorTest, remoteInsert) {
    std::vector<Symbol> s;
    s.push_back(Symbol(char('k'), std::string{"1_9"}, std::vector<int>{0, 2}));
    s.push_back(Symbol(char('k'), std::string{"1_88"}, std::vector<int>{0, 2, 4}));
    s.push_back(Symbol(char('z'), std::string{"1_0"}, std::vector<int>{0, 5}));
    s.push_back(Symbol(char('a'), std::string{"0_0"}, std::vector<int>{1}));
    s.push_back(Symbol(char('n'), std::string{"0_1"}, std::vector<int>{2}));
    s.push_back(Symbol(char('t'), std::string{"0_2"}, std::vector<int>{3}));
    s.push_back(Symbol(char('o'), std::string{"0_3"}, std::vector<int>{4}));
    s.push_back(Symbol(char('w'), std::string{"1_20"}, std::vector<int>{4, 20}));
    s.push_back(Symbol(char('x'), std::string{"1_5"}, std::vector<int>{4, 20, 2}));
    s.push_back(Symbol(char('n'), std::string{"0_4"}, std::vector<int>{5}));
    s.push_back(Symbol(char('i'), std::string{"0_5"}, std::vector<int>{6}));
    s.push_back(Symbol(char('o'), std::string{"0_6"}, std::vector<int>{7}));
    s.push_back(Symbol(char('y'), std::string{"1_2"}, std::vector<int>{7, 6, 6}));
    s.push_back(Symbol(char('y'), std::string{"1_44"}, std::vector<int>{7, 6, 6, 9}));
    s.push_back(Symbol(char('y'), std::string{"1_56"}, std::vector<int>{7, 6, 8}));


    Symbol s1(char('x'), std::string{"1_5"}, std::vector<int>{4, 20, 2});
    Symbol s2(char('z'), std::string{"1_0"}, std::vector<int>{0, 5});
    Symbol s3(char('y'), std::string{"1_2"}, std::vector<int>{7, 6, 6});
    Symbol s4(char('w'), std::string{"1_20"}, std::vector<int>{4, 20});
    Symbol s5(char('k'), std::string{"1_9"}, std::vector<int>{0, 2});
    Symbol s6(char('k'), std::string{"1_88"}, std::vector<int>{0, 2, 4});
    Symbol s7(char('y'), std::string{"1_44"}, std::vector<int>{7, 6, 6, 9});
    Symbol s8(char('y'), std::string{"1_56"}, std::vector<int>{7, 6, 8});

    ed1->remoteInsert(s1);
    ed1->remoteInsert(s2);
    ed1->remoteInsert(s3);
    ed1->remoteInsert(s4);
    ed1->remoteInsert(s5);
    ed1->remoteInsert(s6);
    ed1->remoteInsert(s7);
    ed1->remoteInsert(s8);

    ASSERT_EQ(s, ed1->getSymbols());

    Symbol s9(char('d'), std::string{"2_58"}, std::vector<int>{7, 6, 8});
    ed1->remoteInsert(s9);
    ASSERT_EQ(ed1->getSymbols().back().getId(), "2_58");
    ASSERT_EQ(ed1->getSymbols().back().getC(), 'd');

    Symbol s10(char('j'), std::string{"2_1"}, std::vector<int>{3});
    ed1->remoteInsert(s10);
    ASSERT_EQ(ed1->getSymbols()[6].getId(), "2_1");
    ASSERT_EQ(ed1->getSymbols()[6].getC(), 'j');
}

TEST_F(SharedEditorTest, remoteErase) {

    ed1->getSymbols().clear();
    ed1->setCounter(0);
    ed1->getSymbols().push_back(Symbol(char('k'), std::string{"1_9"}, std::vector<int>{0, 2}));
    ed1->getSymbols().push_back(Symbol(char('k'), std::string{"1_88"}, std::vector<int>{0, 2, 4}));
    ed1->getSymbols().push_back(Symbol(char('z'), std::string{"1_0"}, std::vector<int>{0, 5}));
    ed1->getSymbols().push_back(Symbol(char('a'), std::string{"0_0"}, std::vector<int>{1}));
    ed1->getSymbols().push_back(Symbol(char('n'), std::string{"0_1"}, std::vector<int>{2}));
    ed1->getSymbols().push_back(Symbol(char('t'), std::string{"0_2"}, std::vector<int>{3}));
    ed1->getSymbols().push_back(Symbol(char('o'), std::string{"0_3"}, std::vector<int>{4}));
    ed1->getSymbols().push_back(Symbol(char('w'), std::string{"1_20"}, std::vector<int>{4, 20}));
    ed1->getSymbols().push_back(Symbol(char('x'), std::string{"1_5"}, std::vector<int>{4, 20, 2}));
    ed1->getSymbols().push_back(Symbol(char('n'), std::string{"0_4"}, std::vector<int>{5}));
    ed1->getSymbols().push_back(Symbol(char('i'), std::string{"0_5"}, std::vector<int>{6}));
    ed1->getSymbols().push_back(Symbol(char('o'), std::string{"0_6"}, std::vector<int>{7}));
    ed1->getSymbols().push_back(Symbol(char('y'), std::string{"1_2"}, std::vector<int>{7, 6, 6}));
    ed1->getSymbols().push_back(Symbol(char('y'), std::string{"1_44"}, std::vector<int>{7, 6, 6, 9}));
    ed1->getSymbols().push_back(Symbol(char('y'), std::string{"1_56"}, std::vector<int>{7, 6, 8}));

    Symbol s11(char('k'), std::string{"1_9"}, std::vector<int>{0, 2});
    Symbol s12(char('y'), std::string{"1_56"}, std::vector<int>{7, 6, 8});
    Symbol s13(char('x'), std::string{"1_5"}, std::vector<int>{4, 20, 2});
    ed1->remoteErase(s11);
    ed1->remoteErase(s12);
    ed1->remoteErase(s13);
    ASSERT_EQ(ed1->getSymbols()[0].getId(), "1_88");
    ASSERT_EQ(ed1->getSymbols()[0].getC(), 'k');
    ASSERT_EQ(ed1->getSymbols()[11].getId(), "1_44");
    ASSERT_EQ(ed1->getSymbols()[11].getC(), 'y');
    ASSERT_EQ(ed1->getSymbols()[7].getId(), "0_4");
    ASSERT_EQ(ed1->getSymbols()[7].getC(), 'n');
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}