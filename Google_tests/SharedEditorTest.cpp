#include "gtest/gtest.h"
#include "../src/NetworkServer.h"

class SharedEditorTest : public ::testing::Test {

protected:

    virtual void SetUp() {

        ed1->getSymbols()[0].push_back(*a1);
        ed1->getSymbols()[0].push_back(*n1);
        ed1->getSymbols()[0].push_back(*t1);
        ed1->getSymbols()[0].push_back(*o1);
        ed1->getSymbols()[0].push_back(*n2);
        ed1->getSymbols()[0].push_back(*i1);
        ed1->getSymbols()[0].push_back(*o2);
        ed1->getSymbols()[0].push_back(*slash1);
        ed1->getSymbols().emplace_back();
        ed1->getSymbols()[1].push_back(*a2);
        ed1->getSymbols()[1].push_back(*g1);
        ed1->getSymbols()[1].push_back(*o3);
        ed1->getSymbols()[1].push_back(*s1);
        ed1->getSymbols()[1].push_back(*t2);
        ed1->getSymbols()[1].push_back(*i2);
        ed1->getSymbols()[1].push_back(*n3);
        ed1->getSymbols()[1].push_back(*o4);
        ed1->getSymbols()[1].push_back(*slash2);
        ed1->getSymbols().emplace_back();
        ed1->getSymbols()[2].push_back(*m1);
        ed1->getSymbols()[2].push_back(*a3);
        ed1->getSymbols()[2].push_back(*r1);
        ed1->getSymbols()[2].push_back(*c1);
        ed1->getSymbols()[2].push_back(*o5);
        ed1->getSymbols()[2].push_back(*slash3);
        ed1->getSymbols().emplace_back();
        ed1->getSymbols()[3].push_back(*e1);
        ed1->getSymbols()[3].push_back(*m2);
        ed1->getSymbols()[3].push_back(*a4);
        ed1->getSymbols()[3].push_back(*n4);
        ed1->getSymbols()[3].push_back(*u1);
        ed1->getSymbols()[3].push_back(*e2);
        ed1->getSymbols()[3].push_back(*l1);
        ed1->getSymbols()[3].push_back(*e3);
        ed1->getSymbols()[3].push_back(*slash4);
        ed1->getSymbols().emplace_back();
        ed1->setCounter(32);
        ed1->setIdCounter(32);

        ed3->getSymbols()[0].push_back(*sym0);
        ed3->getSymbols()[0].push_back(*sym1);
        ed3->getSymbols()[0].push_back(*sym2);
        ed3->getSymbols()[0].push_back(*sym3);
        ed3->getSymbols()[0].push_back(*sym4);
        ed3->getSymbols()[0].push_back(*sym5);
        ed3->getSymbols()[0].push_back(*sym6);
        ed3->getSymbols()[0].push_back(*sym7);
        ed3->getSymbols()[0].push_back(*sym8);
        ed3->getSymbols()[0].push_back(*sym9);
        ed3->getSymbols()[0].push_back(*sym_slash0);
        ed3->getSymbols().emplace_back();
        ed3->getSymbols()[1].push_back(*sym10);
        ed3->getSymbols()[1].push_back(*sym11);
        ed3->getSymbols()[1].push_back(*sym12);
        ed3->getSymbols()[1].push_back(*sym13);
        ed3->getSymbols()[1].push_back(*sym14);
        ed3->getSymbols()[1].push_back(*sym15);
        ed3->getSymbols()[1].push_back(*sym16);
        ed3->getSymbols()[1].push_back(*sym17);
        ed3->getSymbols()[1].push_back(*sym18);
        ed3->getSymbols()[1].push_back(*sym19);
        ed3->getSymbols()[1].push_back(*sym_slash1);
        ed3->getSymbols().emplace_back();
        ed3->getSymbols()[2].push_back(*sym_slash2);
        ed3->getSymbols().emplace_back();
        ed3->getSymbols()[3].push_back(*sym_slash3);
        ed3->getSymbols().emplace_back();
        ed3->getSymbols()[4].push_back(*sym20);
        ed3->getSymbols()[4].push_back(*sym21);
        ed3->getSymbols()[4].push_back(*sym22);
        ed3->getSymbols()[4].push_back(*sym23);
        ed3->getSymbols()[4].push_back(*sym24);
        ed3->getSymbols()[4].push_back(*sym25);
        ed3->getSymbols()[4].push_back(*sym26);
        ed3->getSymbols()[4].push_back(*sym27);
        ed3->getSymbols()[4].push_back(*sym_slash4);
        ed3->getSymbols().emplace_back();
        ed3->getSymbols()[5].push_back(*sym28);
        ed3->getSymbols()[5].push_back(*sym29);
        ed3->getSymbols()[5].push_back(*sym30);
        ed3->getSymbols()[5].push_back(*sym31);
        ed3->getSymbols()[5].push_back(*sym_slash5);
        ed3->getSymbols().emplace_back();
        ed3->getSymbols()[6].push_back(*sym32);
        ed3->getSymbols()[6].push_back(*sym_slash6);
        ed3->getSymbols().emplace_back();
        ed3->getSymbols()[7].push_back(*sym_slash7);
        ed3->getSymbols().emplace_back();
        ed3->getSymbols()[8].push_back(*sym33);
        ed3->getSymbols()[8].push_back(*sym34);
        ed3->getSymbols()[8].push_back(*sym35);
        ed3->getSymbols()[8].push_back(*sym36);
        ed3->getSymbols()[8].push_back(*sym37);
        ed3->getSymbols()[8].push_back(*sym38);
        ed3->getSymbols()[8].push_back(*sym39);
        ed3->getSymbols()[8].push_back(*sym40);
        ed3->getSymbols()[8].push_back(*sym41);
        ed3->getSymbols()[8].push_back(*sym42);
        ed3->getSymbols()[8].push_back(*sym_slash8);
        ed3->getSymbols().emplace_back();
        ed3->getSymbols()[9].push_back(*sym_slash9);
        ed3->getSymbols().emplace_back();
        ed3->getSymbols()[10].push_back(*sym43);
        ed3->getSymbols()[10].push_back(*sym_slash10);
        ed3->getSymbols().emplace_back();
        ed3->getSymbols()[11].push_back(*sym_slash11);
        ed3->getSymbols().emplace_back();
        ed3->getSymbols()[12].push_back(*sym_slash12);
        ed3->getSymbols().emplace_back();
        ed3->getSymbols()[13].push_back(*sym44);
        ed3->getSymbols()[13].push_back(*sym_slash13);
        ed3->getSymbols().emplace_back();
        ed3->getSymbols()[14].push_back(*sym_slash14);
        ed3->getSymbols().emplace_back();
        ed3->setCounter(60);
        ed3->setIdCounter(60);
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
    Symbol* t2 = new Symbol(char('t'), std::string{"0-12"}, std::vector<Identifier>{Identifier(11, 0), Identifier(3, 0), Identifier(5, 0)});
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


    SharedEditor *ed3 = new SharedEditor(server);
    Symbol *sym0 = new Symbol('0', "3-0", std::vector<Identifier>{Identifier(1,3)});
    Symbol *sym1 = new Symbol('1', "3-1", std::vector<Identifier>{Identifier(2,3)});
    Symbol *sym2 = new Symbol('2', "3-2", std::vector<Identifier>{Identifier(3,3)});
    Symbol *sym3 = new Symbol('3', "3-3", std::vector<Identifier>{Identifier(4,3)});
    Symbol *sym4 = new Symbol('4', "3-4", std::vector<Identifier>{Identifier(5,3)});
    Symbol *sym5 = new Symbol('5', "3-5", std::vector<Identifier>{Identifier(6,3)});
    Symbol *sym6 = new Symbol('6', "3-6", std::vector<Identifier>{Identifier(7,3)});
    Symbol *sym7 = new Symbol('7', "3-7", std::vector<Identifier>{Identifier(8,3)});
    Symbol *sym8 = new Symbol('8', "3-8", std::vector<Identifier>{Identifier(9,3)});
    Symbol *sym9 = new Symbol('9', "3-9", std::vector<Identifier>{Identifier(10,3), Identifier(2,3)});
    Symbol *sym_slash0 = new Symbol('\n', "3-10", std::vector<Identifier>{Identifier(11,3)});
    Symbol *sym10 = new Symbol('0', "3-11", std::vector<Identifier>{Identifier(11,3), Identifier(3,3)});
    Symbol *sym11 = new Symbol('1', "3-12", std::vector<Identifier>{Identifier(14,3)});
    Symbol *sym12 = new Symbol('2', "3-13", std::vector<Identifier>{Identifier(17,3)});
    Symbol *sym13 = new Symbol('3', "3-14", std::vector<Identifier>{Identifier(20,3), Identifier(10,3)});
    Symbol *sym14 = new Symbol('4', "3-15", std::vector<Identifier>{Identifier(20,3), Identifier(10,3), Identifier(1,3)});
    Symbol *sym15 = new Symbol('5', "3-16", std::vector<Identifier>{Identifier(20,3), Identifier(11,3)});
    Symbol *sym16 = new Symbol('6', "3-17", std::vector<Identifier>{Identifier(21,3)});
    Symbol *sym17 = new Symbol('7', "3-18", std::vector<Identifier>{Identifier(22,3)});
    Symbol *sym18 = new Symbol('8', "3-19", std::vector<Identifier>{Identifier(22,3), Identifier(1,3), Identifier(10,3)});
    Symbol *sym19 = new Symbol('9', "3-20", std::vector<Identifier>{Identifier(22,3), Identifier(2,3)});
    Symbol *sym_slash1 = new Symbol('\n', "3-21", std::vector<Identifier>{Identifier(22,3), Identifier(2,3), Identifier(1,3)});
    Symbol *sym_slash2 = new Symbol('\n', "3-22", std::vector<Identifier>{Identifier(22,3), Identifier(3,3)});
    Symbol *sym_slash3 = new Symbol('\n', "3-23", std::vector<Identifier>{Identifier(22,3), Identifier(3,3), Identifier(10,3)});
    Symbol *sym20 = new Symbol('0', "3-24", std::vector<Identifier>{Identifier(23,3), Identifier(9,3)});
    Symbol *sym21 = new Symbol('1', "3-25", std::vector<Identifier>{Identifier(23,3), Identifier(10,3)});
    Symbol *sym22 = new Symbol('2', "3-26", std::vector<Identifier>{Identifier(23,3), Identifier(10,3), Identifier(5,3)});
    Symbol *sym23 = new Symbol('3', "3-27", std::vector<Identifier>{Identifier(24,3), Identifier(8,3)});
    Symbol *sym24 = new Symbol('4', "3-28", std::vector<Identifier>{Identifier(24,3), Identifier(8,3), Identifier(8,3), Identifier(24,3)});
    Symbol *sym25 = new Symbol('5', "3-29", std::vector<Identifier>{Identifier(25,3)});
    Symbol *sym26 = new Symbol('6', "3-30", std::vector<Identifier>{Identifier(25,3), Identifier(6,3)});
    Symbol *sym27 = new Symbol('7', "3-31", std::vector<Identifier>{Identifier(25,3), Identifier(6,3), Identifier(1,3), Identifier(23,3), Identifier(1,3)});
    Symbol *sym_slash4 = new Symbol('\n', "3-32", std::vector<Identifier>{Identifier(25,3), Identifier(7,3)});
    Symbol *sym28 = new Symbol('0', "3-33", std::vector<Identifier>{Identifier(26,3), Identifier(11,3)});
    Symbol *sym29 = new Symbol('1', "3-34", std::vector<Identifier>{Identifier(26,3), Identifier(11,3), Identifier(3,3)});
    Symbol *sym30 = new Symbol('2', "3-35", std::vector<Identifier>{Identifier(26,3), Identifier(11,3), Identifier(4,3)});
    Symbol *sym31 = new Symbol('3', "3-36", std::vector<Identifier>{Identifier(26,3), Identifier(11,3), Identifier(5,3)});
    Symbol *sym_slash5 = new Symbol('\n', "3-37", std::vector<Identifier>{Identifier(26,3), Identifier(11,3), Identifier(7,3)});
    Symbol *sym32 = new Symbol('0', "3-38", std::vector<Identifier>{Identifier(26,3), Identifier(11,3), Identifier(11,3)});
    Symbol *sym_slash6 = new Symbol('\n', "3-39", std::vector<Identifier>{Identifier(26,3), Identifier(11,3), Identifier(14,3)});
    Symbol *sym_slash7 = new Symbol('\n', "3-40", std::vector<Identifier>{Identifier(26,3), Identifier(11,3), Identifier(18,3)});
    Symbol *sym33 = new Symbol('0', "3-41", std::vector<Identifier>{Identifier(26,3), Identifier(13,3)});
    Symbol *sym34 = new Symbol('1', "3-42", std::vector<Identifier>{Identifier(26,3), Identifier(20,3)});
    Symbol *sym35 = new Symbol('2', "3-43", std::vector<Identifier>{Identifier(27,3), Identifier(13,3)});
    Symbol *sym36 = new Symbol('3', "3-44", std::vector<Identifier>{Identifier(27,3), Identifier(13,3), Identifier(1,3)});
    Symbol *sym37 = new Symbol('4', "3-45", std::vector<Identifier>{Identifier(27,3), Identifier(13,3), Identifier(5,3)});
    Symbol *sym38 = new Symbol('5', "3-46", std::vector<Identifier>{Identifier(27,3), Identifier(13,3), Identifier(11,3)});
    Symbol *sym39 = new Symbol('6', "3-47", std::vector<Identifier>{Identifier(27,3), Identifier(13,3), Identifier(12,3)});
    Symbol *sym40 = new Symbol('7', "3-48", std::vector<Identifier>{Identifier(27,3), Identifier(13,3), Identifier(16,3)});
    Symbol *sym41 = new Symbol('8', "3-49", std::vector<Identifier>{Identifier(27,3), Identifier(13,3), Identifier(1,3), Identifier(4,3)});
    Symbol *sym42 = new Symbol('9', "3-50", std::vector<Identifier>{Identifier(27,3), Identifier(13,3), Identifier(1,3), Identifier(4,3), Identifier(1,3)});
    Symbol *sym_slash8 = new Symbol('\n', "3-51", std::vector<Identifier>{Identifier(27,3), Identifier(13,3), Identifier(1,3), Identifier(6,3)});
    Symbol *sym_slash9 = new Symbol('\n', "3-52", std::vector<Identifier>{Identifier(27,3), Identifier(13,3), Identifier(9,3)});
    Symbol *sym43 = new Symbol('0', "3-53", std::vector<Identifier>{Identifier(27,3), Identifier(14,3)});
    Symbol *sym_slash10 = new Symbol('\n', "3-54", std::vector<Identifier>{Identifier(28,3)});
    Symbol *sym_slash11 = new Symbol('\n', "3-55", std::vector<Identifier>{Identifier(28,3), Identifier(6,3), Identifier(9,3)});
    Symbol *sym_slash12 = new Symbol('\n', "3-56", std::vector<Identifier>{Identifier(28,3), Identifier(13,3)});
    Symbol *sym44 = new Symbol('0', "3-57", std::vector<Identifier>{Identifier(29,3), Identifier(17,3), Identifier(1,3), Identifier(4,3), Identifier(1,3)});
    Symbol *sym_slash13 = new Symbol('\n', "3-58", std::vector<Identifier>{Identifier(28,3), Identifier(18,3), Identifier(1,3), Identifier(2,3)});
    Symbol *sym_slash14 = new Symbol('\n', "3-59", std::vector<Identifier>{Identifier(29,3)});

};

TEST_F(SharedEditorTest, generateIdBetween) {
    int n1 = 0;
    int n2 = 10;
    int id1 = ed1->generateIdBetween(n1, n2, true);
    EXPECT_GE(id1, n1);
    EXPECT_LT(id1, n2);

    int n3 = 20;
    int n4 = 70;
    int id2 = ed1->generateIdBetween(n3, n4, false);
    EXPECT_GE(id2, n3);
    EXPECT_LT(id2, n4);

    int n5 = 2;
    int n6 = 7;
    int id3 = ed1->generateIdBetween(n5, n6, false);
    EXPECT_GE(id3, n5);
    EXPECT_LT(id3, n6);

    EXPECT_EQ(3, ed1->generateIdBetween(2, 4, true));
    EXPECT_EQ(3, ed1->generateIdBetween(2, 4, false));
    EXPECT_EQ(2, ed1->generateIdBetween(1, 3, true));

    EXPECT_THROW(ed1->generateIdBetween(n2, n1, true), std::range_error);
    EXPECT_THROW(ed1->generateIdBetween(n1, n1, true), std::range_error);
    EXPECT_THROW(ed1->generateIdBetween(-1, n1, true), std::invalid_argument);
    EXPECT_THROW(ed1->generateIdBetween(n1, -2, true), std::invalid_argument);
    EXPECT_THROW(ed1->generateIdBetween(-1, -2, true), std::invalid_argument);

}

TEST_F(SharedEditorTest, findPosBefore) {
    EXPECT_EQ(ed1->getSymbols()[2][4].getPosition(), ed1->findPosBefore(2, 5));
    EXPECT_EQ(std::vector<Identifier>{Identifier(0, 0)}, ed1->findPosBefore(0, 0));
    EXPECT_EQ(ed1->getSymbols()[1][4].getPosition(), ed1->findPosBefore(1, 5));
    EXPECT_EQ(ed1->getSymbols()[0][6].getPosition(), ed1->findPosBefore(0, 7));
    EXPECT_EQ(ed1->getSymbols()[0].back().getPosition(), ed1->findPosBefore(1, 0));

    ed1->getSymbols().clear();
    ed1->getSymbols().emplace_back();
    ed1->setCounter(0);
    EXPECT_EQ(std::vector<Identifier>{Identifier(0, ed1->getSiteId())}, ed1->findPosBefore(0, 0));
}

TEST_F(SharedEditorTest, findPosAfter) {
    EXPECT_EQ(ed1->getSymbols()[3][0].getPosition(), ed1->findPosAfter(3, 0));
    EXPECT_EQ(ed1->getSymbols()[0][0].getPosition(), ed1->findPosAfter(0, 0));
    EXPECT_EQ(ed1->getSymbols()[1][5].getPosition(), ed1->findPosAfter(1, 5));
    EXPECT_EQ(ed1->getSymbols()[0][7].getPosition(), ed1->findPosAfter(0, 7));
    EXPECT_EQ(ed1->getSymbols()[1][0].getPosition(), ed1->findPosAfter(0, 8));

    ed1->getSymbols().clear();
    ed1->getSymbols().emplace_back();
    ed1->setCounter(0);
    EXPECT_EQ(std::vector<Identifier>{Identifier(ed1->getBase(), ed1->getSiteId())}, ed1->findPosAfter(0, 0));
}

TEST_F(SharedEditorTest, generatePosBetween) {
    std::function<bool(std::vector<Identifier>, std::vector<Identifier>)> isLessThan = [](std::vector<Identifier> pos1, std::vector<Identifier> pos2){
        int min = 0;
        if (pos1.size() < pos2.size()) {
            min = pos1.size();
        } else {
            min = pos2.size();
        }
        for (int i = 0; i < min; i++) {
            if (pos1[i] < pos2[i]) {
                return true;
            } else if (pos2[i] < pos1[i]) {
                return false;
            }
        }
        return pos1.size() < pos2.size();
    };

    EXPECT_EQ(Identifier(1, 0), ed1->generatePosBetween(std::vector<Identifier>{Identifier(0, 0)}, std::vector<Identifier>{Identifier(2, 0)}, {}, 0)[0]);
    EXPECT_GT(ed1->generatePosBetween(std::vector<Identifier>{Identifier(0, 0), Identifier(5, 0)}, std::vector<Identifier>{Identifier(1, 0), Identifier(7, 0)}, {}, 0)[1].getDigit(), 5);
    EXPECT_GT(ed1->generatePosBetween(std::vector<Identifier>{Identifier(2, 0), Identifier(5, 0), Identifier(5, 0)}, std::vector<Identifier>{Identifier(2, 0), Identifier(6, 0)}, {}, 0)[2].getDigit(), Identifier(5, 0).getDigit());
    EXPECT_LT(ed1->generatePosBetween(std::vector<Identifier>{Identifier(5, 0), Identifier(4, 0)}, std::vector<Identifier>{Identifier(5, 0), Identifier(4, 0), Identifier(7, 0)}, {}, 0)[2], Identifier(7, 0));
    EXPECT_LT(ed1->generatePosBetween(std::vector<Identifier>{Identifier(19, 0), Identifier(8, 0), Identifier(2, 0)}, std::vector<Identifier>{Identifier(19, 0), Identifier(8, 0), Identifier(2, 0), Identifier(3, 0)}, {}, 0)[3], Identifier(3, 0));
    EXPECT_GT(ed1->generatePosBetween(std::vector<Identifier>{Identifier(19, 0), Identifier(8, 0), Identifier(2, 0)}, std::vector<Identifier>{Identifier(19, 0), Identifier(8, 0), Identifier(2, 0), Identifier(1, 0)}, {}, 0)[4].getDigit(), -1);

    EXPECT_THROW(ed1->generatePosBetween({}, std::vector<Identifier>{Identifier(2, 0)}, {}, 0), std::invalid_argument);
    EXPECT_THROW(ed1->generatePosBetween(std::vector<Identifier>{Identifier(1, 0)}, std::vector<Identifier>{Identifier(2, 0)}, {}, -1), std::invalid_argument);
    ed1->setSiteId(1);
    EXPECT_EQ(ed1->generatePosBetween(std::vector<Identifier>{Identifier(0, 1)}, std::vector<Identifier>{Identifier(0, 0), Identifier(5, 0)}, {}, 0)[0], Identifier(0, 0));
    EXPECT_LT(ed1->generatePosBetween(std::vector<Identifier>{Identifier(0, 1)}, std::vector<Identifier>{Identifier(0, 0), Identifier(5, 0)}, {}, 0)[1], Identifier(5, 0));
    EXPECT_TRUE(isLessThan(ed1->generatePosBetween(std::vector<Identifier>{Identifier(0, 1)}, std::vector<Identifier>{Identifier(0, 0), Identifier(5, 0)}, {}, 0), std::vector<Identifier>{Identifier(0, 0), Identifier(5, 0)}));

    ed1->setSiteId(0);
    EXPECT_EQ(ed1->generatePosBetween(std::vector<Identifier>{Identifier(31, 1), Identifier(5, 1)}, std::vector<Identifier>{Identifier(32, 0)}, {}, 0)[0], Identifier(31, 1));
    EXPECT_LT(Identifier(5, 1), ed1->generatePosBetween(std::vector<Identifier>{Identifier(31, 1), Identifier(5, 1)}, std::vector<Identifier>{Identifier(32, 0)}, {}, 0)[1]);
    EXPECT_TRUE(isLessThan(ed1->generatePosBetween(std::vector<Identifier>{Identifier(31, 1), Identifier(5, 1)}, std::vector<Identifier>{Identifier(32, 0)}, {}, 0), std::vector<Identifier>{Identifier(32, 0)}));

    EXPECT_EQ(ed1->generatePosBetween(std::vector<Identifier>{Identifier(0, 0)}, std::vector<Identifier>{Identifier(0, 1), Identifier(5, 1)}, {}, 0)[0], Identifier(0, 0));
    EXPECT_TRUE(isLessThan(ed1->generatePosBetween(std::vector<Identifier>{Identifier(0, 0)}, std::vector<Identifier>{Identifier(0, 1), Identifier(5, 1)}, {}, 0), std::vector<Identifier>{Identifier(0, 1), Identifier(5, 1)}));
    EXPECT_TRUE(!isLessThan(std::vector<Identifier>{Identifier(8, 0)}, std::vector<Identifier>{Identifier(0, 1), Identifier(5, 1)}));
}

TEST_F(SharedEditorTest, insertSymbolNotCRLF) {

    Symbol s5('x', "0-32", std::vector<Identifier>{Identifier(28, 0)});
    ed1->insertSymbol(4, 0, s5);
    EXPECT_EQ(ed1->getSymbols()[3].size(), 9);
    EXPECT_EQ(ed1->getSymbols()[4].size(), 1);
    EXPECT_EQ(*e1, ed1->getSymbols()[3][0]);
    EXPECT_EQ(*m2, ed1->getSymbols()[3][1]);
    EXPECT_EQ(*a4, ed1->getSymbols()[3][2]);
    EXPECT_EQ(*n4, ed1->getSymbols()[3][3]);
    EXPECT_EQ(*u1, ed1->getSymbols()[3][4]);
    EXPECT_EQ(*e2, ed1->getSymbols()[3][5]);
    EXPECT_EQ(*l1, ed1->getSymbols()[3][6]);
    EXPECT_EQ(*e3, ed1->getSymbols()[3][7]);
    EXPECT_EQ(*slash4, ed1->getSymbols()[3][8]);
    EXPECT_EQ(s5, ed1->getSymbols()[4][0]);

    Symbol s10('x', "0-33", std::vector<Identifier>{Identifier(0, 0), Identifier(5, 0)});
    ed1->insertSymbol(0, 0, s10);
    EXPECT_EQ(ed1->getSymbols()[0].size(), 9);
    EXPECT_EQ(s10, ed1->getSymbols()[0][0]);
    EXPECT_EQ(*a1, ed1->getSymbols()[0][1]);
    EXPECT_EQ(*n1, ed1->getSymbols()[0][2]);
    EXPECT_EQ(*t1, ed1->getSymbols()[0][3]);
    EXPECT_EQ(*o1, ed1->getSymbols()[0][4]);
    EXPECT_EQ(*n2, ed1->getSymbols()[0][5]);
    EXPECT_EQ(*i1, ed1->getSymbols()[0][6]);
    EXPECT_EQ(*o2, ed1->getSymbols()[0][7]);
    EXPECT_EQ(*slash1, ed1->getSymbols()[0][8]);


    Symbol s2('x', "0-34", std::vector<Identifier>{Identifier(27, 0), Identifier(8, 0), Identifier(3, 0)});
    ed1->insertSymbol(3, 8, s2);
    EXPECT_EQ(ed1->getSymbols()[3].size(), 10);
    EXPECT_EQ(*e1, ed1->getSymbols()[3][0]);
    EXPECT_EQ(*m2, ed1->getSymbols()[3][1]);
    EXPECT_EQ(*a4, ed1->getSymbols()[3][2]);
    EXPECT_EQ(*n4, ed1->getSymbols()[3][3]);
    EXPECT_EQ(*u1, ed1->getSymbols()[3][4]);
    EXPECT_EQ(*e2, ed1->getSymbols()[3][5]);
    EXPECT_EQ(*l1, ed1->getSymbols()[3][6]);
    EXPECT_EQ(*e3, ed1->getSymbols()[3][7]);
    EXPECT_EQ(s2, ed1->getSymbols()[3][8]);
    EXPECT_EQ(*slash4, ed1->getSymbols()[3][9]);

    Symbol s3('x', "0-35", std::vector<Identifier>{Identifier(19, 0), Identifier(8, 0), Identifier(2, 0), Identifier(2, 0)});
    ed1->insertSymbol(2, 5, s3);
    EXPECT_EQ(ed1->getSymbols()[2].size(), 7);
    EXPECT_EQ(s3, ed1->getSymbols()[2][5]);
    EXPECT_EQ(*m1, ed1->getSymbols()[2][0]);
    EXPECT_EQ(*a3, ed1->getSymbols()[2][1]);
    EXPECT_EQ(*r1, ed1->getSymbols()[2][2]);
    EXPECT_EQ(*c1, ed1->getSymbols()[2][3]);
    EXPECT_EQ(*o5, ed1->getSymbols()[2][4]);
    EXPECT_EQ(*slash3, ed1->getSymbols()[2][6]);

    Symbol s4('x', "0-36", std::vector<Identifier>{Identifier(7, 0), Identifier(2, 0), Identifier(3, 0)});
    ed1->insertSymbol(1, 0, s4);
    EXPECT_EQ(ed1->getSymbols()[1].size(), 10);
    EXPECT_EQ(s4, ed1->getSymbols()[1][0]);
    EXPECT_EQ(*a2, ed1->getSymbols()[1][1]);
    EXPECT_EQ(*g1, ed1->getSymbols()[1][2]);
    EXPECT_EQ(*o3, ed1->getSymbols()[1][3]);
    EXPECT_EQ(*s1, ed1->getSymbols()[1][4]);
    EXPECT_EQ(*t2, ed1->getSymbols()[1][5]);
    EXPECT_EQ(*i2, ed1->getSymbols()[1][6]);
    EXPECT_EQ(*n3, ed1->getSymbols()[1][7]);
    EXPECT_EQ(*o4, ed1->getSymbols()[1][8]);
    EXPECT_EQ(*slash2, ed1->getSymbols()[1][9]);

    ed1->getSymbols().clear();
    ed1->getSymbols().emplace_back();
    ed1->setCounter(0);
    ed1->insertSymbol(0, 0, s4);
    EXPECT_EQ(ed1->getSymbols().size(), 1);
    EXPECT_EQ(ed1->getSymbols()[0].size(), 1);
    EXPECT_EQ(ed1->getSymbols()[0][0], s4);
}

TEST_F(SharedEditorTest, insertSymbolCRLF) {

    Symbol s5('\n', "0-37", std::vector<Identifier>{Identifier(29, 0)});
    ed1->insertSymbol(4, 0, s5);
    EXPECT_EQ(ed1->getSymbols()[3].size(), 9);
    EXPECT_EQ(ed1->getSymbols()[4].size(), 1);
    EXPECT_EQ(s5, ed1->getSymbols()[4][0]);
    EXPECT_EQ(*e1, ed1->getSymbols()[3][0]);
    EXPECT_EQ(*m2, ed1->getSymbols()[3][1]);
    EXPECT_EQ(*a4, ed1->getSymbols()[3][2]);
    EXPECT_EQ(*n4, ed1->getSymbols()[3][3]);
    EXPECT_EQ(*u1, ed1->getSymbols()[3][4]);
    EXPECT_EQ(*e2, ed1->getSymbols()[3][5]);
    EXPECT_EQ(*l1, ed1->getSymbols()[3][6]);
    EXPECT_EQ(*e3, ed1->getSymbols()[3][7]);
    EXPECT_EQ(*slash4, ed1->getSymbols()[3][8]);

    Symbol s2('\n', "0-34", std::vector<Identifier>{Identifier(27, 0), Identifier(8, 0), Identifier(3, 0)});
    ed1->insertSymbol(3, 8, s2);
    EXPECT_EQ(ed1->getSymbols()[3].size(), 9);
    EXPECT_EQ(ed1->getSymbols()[4].size(), 1);
    EXPECT_EQ(*e1, ed1->getSymbols()[3][0]);
    EXPECT_EQ(*m2, ed1->getSymbols()[3][1]);
    EXPECT_EQ(*a4, ed1->getSymbols()[3][2]);
    EXPECT_EQ(*n4, ed1->getSymbols()[3][3]);
    EXPECT_EQ(*u1, ed1->getSymbols()[3][4]);
    EXPECT_EQ(*e2, ed1->getSymbols()[3][5]);
    EXPECT_EQ(*l1, ed1->getSymbols()[3][6]);
    EXPECT_EQ(*e3, ed1->getSymbols()[3][7]);
    EXPECT_EQ(s2, ed1->getSymbols()[3][8]);
    EXPECT_EQ(*slash4, ed1->getSymbols()[4][0]);
    EXPECT_EQ(s5, ed1->getSymbols()[5][0]);

    Symbol s3('\n', "0-35", std::vector<Identifier>{Identifier(17, 0), Identifier(5, 0)});
    ed1->insertSymbol(2, 3, s3);
    EXPECT_EQ(ed1->getSymbols()[2].size(), 4);
    EXPECT_EQ(ed1->getSymbols()[3].size(), 3);
    EXPECT_EQ(*m1, ed1->getSymbols()[2][0]);
    EXPECT_EQ(*a3, ed1->getSymbols()[2][1]);
    EXPECT_EQ(*r1, ed1->getSymbols()[2][2]);
    EXPECT_EQ(s3, ed1->getSymbols()[2][3]);
    EXPECT_EQ(*c1, ed1->getSymbols()[3][0]);
    EXPECT_EQ(*o5, ed1->getSymbols()[3][1]);
    EXPECT_EQ(*slash3, ed1->getSymbols()[3][2]);

    Symbol s4('\n', "0-36", std::vector<Identifier>{Identifier(7, 0), Identifier(2, 0), Identifier(3, 0)});
    ed1->insertSymbol(1, 0, s4);
    EXPECT_EQ(ed1->getSymbols()[1].size(), 1);
    EXPECT_EQ(ed1->getSymbols()[2].size(), 9);
    EXPECT_EQ(s4, ed1->getSymbols()[1][0]);
    EXPECT_EQ(*a2, ed1->getSymbols()[2][0]);
    EXPECT_EQ(*g1, ed1->getSymbols()[2][1]);
    EXPECT_EQ(*o3, ed1->getSymbols()[2][2]);
    EXPECT_EQ(*s1, ed1->getSymbols()[2][3]);
    EXPECT_EQ(*t2, ed1->getSymbols()[2][4]);
    EXPECT_EQ(*i2, ed1->getSymbols()[2][5]);
    EXPECT_EQ(*n3, ed1->getSymbols()[2][6]);
    EXPECT_EQ(*o4, ed1->getSymbols()[2][7]);
    EXPECT_EQ(*slash2, ed1->getSymbols()[2][8]);

    Symbol s10('\n', "0-33", std::vector<Identifier>{Identifier(0, 0), Identifier(5, 0)});
    ed1->insertSymbol(0 ,0, s10);
    EXPECT_EQ(ed1->getSymbols()[0].size(), 1);
    EXPECT_EQ(ed1->getSymbols()[1].size(), 8);
    EXPECT_EQ(s10, ed1->getSymbols()[0][0]);
    EXPECT_EQ(*a1, ed1->getSymbols()[1][0]);
    EXPECT_EQ(*n1, ed1->getSymbols()[1][1]);
    EXPECT_EQ(*t1, ed1->getSymbols()[1][2]);
    EXPECT_EQ(*o1, ed1->getSymbols()[1][3]);
    EXPECT_EQ(*n2, ed1->getSymbols()[1][4]);
    EXPECT_EQ(*i1, ed1->getSymbols()[1][5]);
    EXPECT_EQ(*o2, ed1->getSymbols()[1][6]);
    EXPECT_EQ(*slash1, ed1->getSymbols()[1][7]);

    ed1->getSymbols().clear();
    ed1->getSymbols().emplace_back();
    ed1->setCounter(0);
    ed1->insertSymbol(0, 0, s10);
    EXPECT_EQ(ed1->getSymbols().size(), 2);
    EXPECT_EQ(ed1->getSymbols()[0][0], s10);
}

TEST_F(SharedEditorTest, localInsertNotCRLF) {

    EXPECT_THROW(ed1->localInsert(-1, 0, 'x'), std::out_of_range);
    EXPECT_THROW(ed1->localInsert(20, 0, 'x'), std::out_of_range);
    EXPECT_THROW(ed1->localInsert(0, -1, 'x'), std::out_of_range);
    EXPECT_THROW(ed1->localInsert(0, 90, 'x'), std::out_of_range);

    ed1->localInsert(3, 9, 'x');
    EXPECT_EQ('x', ed1->getSymbols()[4][0].getC());
    EXPECT_EQ('\n', ed1->getSymbols()[3][8].getC());

    ed1->localInsert(0, 0, 'y');
    EXPECT_EQ('y', ed1->getSymbols()[0][0].getC());

    ed1->localInsert(3, 8, 'z');
    EXPECT_EQ('z', ed1->getSymbols()[3][8].getC());

    ed1->localInsert(2, 5, 'k');
    EXPECT_EQ('k', ed1->getSymbols()[2][5].getC());

    ed1->localInsert(1, 0, 'q');
    EXPECT_EQ('q', ed1->getSymbols()[1][0].getC());

    ed1->getSymbols().clear();
    ed1->getSymbols().emplace_back();
    ed1->setCounter(0);
    ed1->localInsert(0, 0, 'a');
    EXPECT_EQ(ed1->getSymbols().size(), 1);
    EXPECT_EQ(ed1->getSymbols()[0][0].getC(), 'a');

    ed1->localInsert(0, 1, 'q');
    EXPECT_EQ('q', ed1->getSymbols()[0][1].getC());
}

TEST_F(SharedEditorTest, localInsertCRLF) {

    ed1->localInsert(3, 9, '\n');
    EXPECT_EQ('\n', ed1->getSymbols()[4][0].getC());
    EXPECT_EQ('\n', ed1->getSymbols()[3][8].getC());

    ed1->localInsert(3, 8, '\n');
    EXPECT_EQ('\n', ed1->getSymbols()[3][8].getC());
    EXPECT_EQ('\n', ed1->getSymbols()[4][0].getC());

    ed1->localInsert(2, 3, '\n');
    EXPECT_EQ('\n', ed1->getSymbols()[2][3].getC());
    EXPECT_EQ('c', ed1->getSymbols()[3][0].getC());

    ed1->localInsert(1, 0, '\n');
    EXPECT_EQ('\n', ed1->getSymbols()[1][0].getC());
    EXPECT_EQ('a', ed1->getSymbols()[2][0].getC());

    ed1->localInsert(0, 0, '\n');
    EXPECT_EQ('\n', ed1->getSymbols()[0][0].getC());
    EXPECT_EQ('a', ed1->getSymbols()[1][0].getC());

    ed1->getSymbols().clear();
    ed1->getSymbols().emplace_back();
    ed1->setCounter(0);
    ed1->localInsert(0, 0, '\n');
    EXPECT_EQ(ed1->getSymbols().size(), 2);
    EXPECT_EQ(ed1->getSymbols()[0][0].getC(), '\n');
}

TEST_F(SharedEditorTest, eraseSingleLine) {
    ed1->eraseSingleLine(3, 5, 3, 8);
    EXPECT_EQ(ed1->getSymbols()[3].size(), 5);
    EXPECT_EQ(ed1->getSymbols().size(), 5);
    EXPECT_EQ(*e1, ed1->getSymbols()[3][0]);
    EXPECT_EQ(*m2, ed1->getSymbols()[3][1]);
    EXPECT_EQ(*a4, ed1->getSymbols()[3][2]);
    EXPECT_EQ(*n4, ed1->getSymbols()[3][3]);
    EXPECT_EQ(*u1, ed1->getSymbols()[3][4]);

    ed1->eraseSingleLine(2, 0, 2, 2);
    EXPECT_EQ(ed1->getSymbols().size(), 5);
    EXPECT_EQ(*c1, ed1->getSymbols()[2][0]);
    EXPECT_EQ(*o5, ed1->getSymbols()[2][1]);
    EXPECT_EQ(*slash3, ed1->getSymbols()[2][2]);

    ed1->eraseSingleLine(1, 2, 1, 5);
    EXPECT_EQ(ed1->getSymbols().size(), 5);
    EXPECT_EQ(*a2, ed1->getSymbols()[1][0]);
    EXPECT_EQ(*g1, ed1->getSymbols()[1][1]);
    EXPECT_EQ(*n3, ed1->getSymbols()[1][2]);
    EXPECT_EQ(*o4, ed1->getSymbols()[1][3]);
    EXPECT_EQ(*slash2, ed1->getSymbols()[1][4]);

    ed1->eraseSingleLine(0, 3, 0, 3);
    EXPECT_EQ(ed1->getSymbols().size(), 5);
    EXPECT_EQ(*a1, ed1->getSymbols()[0][0]);
    EXPECT_EQ(*n1, ed1->getSymbols()[0][1]);
    EXPECT_EQ(*t1, ed1->getSymbols()[0][2]);
    EXPECT_EQ(*n2, ed1->getSymbols()[0][3]);
    EXPECT_EQ(*i1, ed1->getSymbols()[0][4]);
    EXPECT_EQ(*o2, ed1->getSymbols()[0][5]);
    EXPECT_EQ(*slash1, ed1->getSymbols()[0][6]);

    ed1->eraseSingleLine(0, 0, 0, 0);
    EXPECT_EQ(ed1->getSymbols().size(), 5);
    EXPECT_EQ(*n1, ed1->getSymbols()[0][0]);
    EXPECT_EQ(*t1, ed1->getSymbols()[0][1]);
    EXPECT_EQ(*n2, ed1->getSymbols()[0][2]);
    EXPECT_EQ(*i1, ed1->getSymbols()[0][3]);
    EXPECT_EQ(*o2, ed1->getSymbols()[0][4]);
    EXPECT_EQ(*slash1, ed1->getSymbols()[0][5]);
}

TEST_F(SharedEditorTest, eraseMultipleLines) {
    ed1->eraseMultipleLines(2, 3, 3, 5);
    EXPECT_EQ(ed1->getSymbols().size(), 5);
    EXPECT_EQ(*m1, ed1->getSymbols()[2][0]);
    EXPECT_EQ(*a3, ed1->getSymbols()[2][1]);
    EXPECT_EQ(*r1, ed1->getSymbols()[2][2]);
    EXPECT_EQ(*l1, ed1->getSymbols()[3][0]);
    EXPECT_EQ(*e3, ed1->getSymbols()[3][1]);
    EXPECT_EQ(*slash4, ed1->getSymbols()[3][2]);

    ed1->eraseMultipleLines(0, 0, 2, 2);
    EXPECT_EQ(ed1->getSymbols().size(), 4);
    EXPECT_TRUE(ed1->getSymbols()[0].empty());
    EXPECT_TRUE(ed1->getSymbols()[1].empty());
    EXPECT_TRUE(ed1->getSymbols()[3].empty());
    EXPECT_EQ(*l1, ed1->getSymbols()[2][0]);
    EXPECT_EQ(*e3, ed1->getSymbols()[2][1]);
    EXPECT_EQ(*slash4, ed1->getSymbols()[2][2]);
}

TEST_F(SharedEditorTest, eraseMultipleLinesBoundaries) {
    ed1->eraseMultipleLines(2, 3, 3, 8);
    EXPECT_EQ(ed1->getSymbols().size(), 5);
    EXPECT_EQ(*m1, ed1->getSymbols()[2][0]);
    EXPECT_EQ(*a3, ed1->getSymbols()[2][1]);
    EXPECT_EQ(*r1, ed1->getSymbols()[2][2]);

}

TEST_F(SharedEditorTest, localEraseMultipleLineBoundaries) {
    ed1->getSymbols().clear();
    ed1->getSymbols().emplace_back();
    ed1->setCounter(0);
    ed1->getSymbols()[0].push_back(*a1);
    ed1->getSymbols()[0].push_back(*n1);
    ed1->getSymbols()[0].push_back(*t1);
    ed1->getSymbols()[0].push_back(*o1);
    ed1->getSymbols()[0].push_back(*n2);
    ed1->getSymbols()[0].push_back(*i1);
    ed1->getSymbols()[0].push_back(*o2);
    ed1->getSymbols()[0].push_back(*slash1);
    ed1->getSymbols().emplace_back();
    ed1->getSymbols()[1].push_back(*a2);
    ed1->getSymbols()[1].push_back(*g1);
    ed1->getSymbols()[1].push_back(*o3);
    ed1->getSymbols()[1].push_back(*s1);
    ed1->getSymbols()[1].push_back(*t2);
    ed1->getSymbols()[1].push_back(*i2);
    ed1->getSymbols()[1].push_back(*n3);
    ed1->getSymbols()[1].push_back(*o4);
    ed1->localErase(0, 0, 1, 7);
    EXPECT_EQ(ed1->getSymbols().size(), 1);

    ed1->getSymbols().clear();
    ed1->getSymbols().emplace_back();
    ed1->setCounter(0);
    ed1->getSymbols()[0].push_back(*a1);
    ed1->getSymbols()[0].push_back(*n1);
    ed1->getSymbols()[0].push_back(*t1);
    ed1->getSymbols()[0].push_back(*o1);
    ed1->getSymbols()[0].push_back(*n2);
    ed1->getSymbols()[0].push_back(*i1);
    ed1->getSymbols()[0].push_back(*o2);
    ed1->getSymbols()[0].push_back(*slash1);
    ed1->getSymbols().emplace_back();
    ed1->getSymbols()[1].push_back(*a2);
    ed1->getSymbols()[1].push_back(*g1);
    ed1->getSymbols()[1].push_back(*o3);
    ed1->getSymbols()[1].push_back(*s1);
    ed1->getSymbols()[1].push_back(*t2);
    ed1->getSymbols()[1].push_back(*i2);
    ed1->getSymbols()[1].push_back(*n3);
    ed1->getSymbols()[1].push_back(*o4);
    ed1->getSymbols()[1].push_back(*slash2);
    ed1->localErase(0, 0, 1, 8);
    EXPECT_EQ(ed1->getSymbols().size(), 1);
}

TEST_F(SharedEditorTest, localEraseSingleLine) {

    EXPECT_THROW(ed1->localErase(10, 0, 0, 0), std::invalid_argument);
    EXPECT_THROW(ed1->localErase(0, 2, 0, 1), std::invalid_argument);
    EXPECT_THROW(ed1->localErase(-1, 2, 0, 1), std::out_of_range);
    EXPECT_THROW(ed1->localErase(0, -1, 0, 1), std::out_of_range);


    ed1->localErase(3, 0, 3, 8);
    EXPECT_EQ(ed1->getSymbols().size(), 4);

    ed1->localErase(1, 8, 1, 8);
    EXPECT_EQ(ed1->getSymbols().size(), 3);
    EXPECT_EQ(*a2, ed1->getSymbols()[1][0]);
    EXPECT_EQ(*g1, ed1->getSymbols()[1][1]);
    EXPECT_EQ(*o3, ed1->getSymbols()[1][2]);
    EXPECT_EQ(*s1, ed1->getSymbols()[1][3]);
    EXPECT_EQ(*t2, ed1->getSymbols()[1][4]);
    EXPECT_EQ(*i2, ed1->getSymbols()[1][5]);
    EXPECT_EQ(*n3, ed1->getSymbols()[1][6]);
    EXPECT_EQ(*o4, ed1->getSymbols()[1][7]);
    EXPECT_EQ(*m1, ed1->getSymbols()[1][8]);
    EXPECT_EQ(*a3, ed1->getSymbols()[1][9]);
    EXPECT_EQ(*r1, ed1->getSymbols()[1][10]);
    EXPECT_EQ(*c1, ed1->getSymbols()[1][11]);
    EXPECT_EQ(*o5, ed1->getSymbols()[1][12]);
    EXPECT_EQ(*slash3, ed1->getSymbols()[1][13]);

    ed1->localErase(0, 0, 0, 7);
    EXPECT_EQ(ed1->getSymbols().size(), 2);
    EXPECT_EQ(*a2, ed1->getSymbols()[0][0]);
    EXPECT_EQ(*g1, ed1->getSymbols()[0][1]);
    EXPECT_EQ(*o3, ed1->getSymbols()[0][2]);
    EXPECT_EQ(*s1, ed1->getSymbols()[0][3]);
    EXPECT_EQ(*t2, ed1->getSymbols()[0][4]);
    EXPECT_EQ(*i2, ed1->getSymbols()[0][5]);
    EXPECT_EQ(*n3, ed1->getSymbols()[0][6]);
    EXPECT_EQ(*o4, ed1->getSymbols()[0][7]);
    EXPECT_EQ(*m1, ed1->getSymbols()[0][8]);
    EXPECT_EQ(*a3, ed1->getSymbols()[0][9]);
    EXPECT_EQ(*r1, ed1->getSymbols()[0][10]);
    EXPECT_EQ(*c1, ed1->getSymbols()[0][11]);
    EXPECT_EQ(*o5, ed1->getSymbols()[0][12]);
    EXPECT_EQ(*slash3, ed1->getSymbols()[0][13]);

    ed1->localErase(0, 0, 0, 13);
    EXPECT_EQ(ed1->getSymbols().size(), 1);

    ed1->localErase(0, 0, 0, 0);
    EXPECT_EQ(ed1->getSymbols().size(), 1);
    EXPECT_TRUE(ed1->getSymbols()[0].empty());
}

TEST_F(SharedEditorTest, localEraseMultipleLine) {
    ed1->localErase(1, 8, 3, 8);
    EXPECT_EQ(ed1->getSymbols().size(), 2);
    EXPECT_EQ(*a2, ed1->getSymbols()[1][0]);
    EXPECT_EQ(*g1, ed1->getSymbols()[1][1]);
    EXPECT_EQ(*o3, ed1->getSymbols()[1][2]);
    EXPECT_EQ(*s1, ed1->getSymbols()[1][3]);
    EXPECT_EQ(*t2, ed1->getSymbols()[1][4]);
    EXPECT_EQ(*i2, ed1->getSymbols()[1][5]);
    EXPECT_EQ(*n3, ed1->getSymbols()[1][6]);
    EXPECT_EQ(*o4, ed1->getSymbols()[1][7]);

    ed1->localErase(0, 7, 1, 0);
    EXPECT_EQ(ed1->getSymbols().size(), 1);
    EXPECT_EQ(*a1, ed1->getSymbols()[0][0]);
    EXPECT_EQ(*n1, ed1->getSymbols()[0][1]);
    EXPECT_EQ(*t1, ed1->getSymbols()[0][2]);
    EXPECT_EQ(*o1, ed1->getSymbols()[0][3]);
    EXPECT_EQ(*n2, ed1->getSymbols()[0][4]);
    EXPECT_EQ(*i1, ed1->getSymbols()[0][5]);
    EXPECT_EQ(*o2, ed1->getSymbols()[0][6]);
    EXPECT_EQ(*g1, ed1->getSymbols()[0][7]);
    EXPECT_EQ(*o3, ed1->getSymbols()[0][8]);
    EXPECT_EQ(*s1, ed1->getSymbols()[0][9]);
    EXPECT_EQ(*t2, ed1->getSymbols()[0][10]);
    EXPECT_EQ(*i2, ed1->getSymbols()[0][11]);
    EXPECT_EQ(*n3, ed1->getSymbols()[0][12]);
    EXPECT_EQ(*o4, ed1->getSymbols()[0][13]);

    ed1->getSymbols().back().push_back(Symbol(char('\n'), std::string{"0-32"}, std::vector<Identifier>{Identifier(16, 0)}));
    ed1->getSymbols().emplace_back();
    ed1->getSymbols().back().push_back(Symbol(char('x'), std::string{"0-33"}, std::vector<Identifier>{Identifier(18, 0)}));
    ed1->setCounter(ed1->getCounter()+2);
    ed1->localErase(0, 0, 1, 0);
    EXPECT_EQ(ed1->getSymbols().size(), 1);
}

TEST_F(SharedEditorTest, localEraseMultipleLineEditor) {
    ed1->getSymbols().erase(ed1->getSymbols().end());
    ed1->getSymbols().back().erase(ed1->getSymbols().back().end());

    ed1->localErase(2, 0, 3, 7);
    EXPECT_EQ(ed1->getSymbols().size(), 3);
}


TEST_F(SharedEditorTest, remoteInsert) {
    Symbol s13('x', "1-1", std::vector<Identifier>{Identifier(28, 1)});
    ed1->remoteInsert(s13);
    EXPECT_EQ(ed1->getSymbols()[4][0], s13);

    Symbol s11('t', "1-2", std::vector<Identifier>{Identifier(27, 0), Identifier(8, 0), Identifier(9, 1)});
    ed1->remoteInsert(s11);
    EXPECT_EQ(ed1->getSymbols()[4][0], s11);
    EXPECT_EQ(ed1->getSymbols()[4][1], s13);

    Symbol s12('w', "1-3", std::vector<Identifier>{Identifier(27, 0), Identifier(8, 0), Identifier(1, 1)});
    ed1->remoteInsert(s12);
    EXPECT_EQ(ed1->getSymbols()[3][8], s12);
    EXPECT_EQ(ed1->getSymbols()[3][9], *slash4);
    EXPECT_EQ(ed1->getSymbols()[4][0], s11);
    EXPECT_EQ(ed1->getSymbols()[4][1], s13);

    int numLines = ed1->getSymbols().size();
    int numSymbolsInLine3 = ed1->getSymbols()[3].size();
    int numSymbolsInLine4 = ed1->getSymbols()[4].size();
    ed1->remoteInsert(s12);
    EXPECT_EQ(ed1->getSymbols()[3][8], s12);
    EXPECT_EQ(ed1->getSymbols()[3][9], *slash4);
    EXPECT_EQ(ed1->getSymbols()[4][0], s11);
    EXPECT_EQ(ed1->getSymbols()[4][1], s13);
    EXPECT_EQ(ed1->getSymbols().size(), numLines);
    EXPECT_EQ(ed1->getSymbols()[3].size(), numSymbolsInLine3);
    EXPECT_EQ(ed1->getSymbols()[4].size(), numSymbolsInLine4);


    Symbol s2('\n', "1-4", std::vector<Identifier>{Identifier(26, 1)});
    ed1->remoteInsert(s2);
    EXPECT_EQ(ed1->getSymbols().size(), 6);
    EXPECT_EQ(ed1->getSymbols()[3][6], *l1);
    EXPECT_EQ(ed1->getSymbols()[3][7], s2);
    EXPECT_EQ(ed1->getSymbols()[4][0], *e3);
    EXPECT_EQ(ed1->getSymbols()[4][1], s12);
    EXPECT_EQ(ed1->getSymbols()[4][2], *slash4);

    Symbol s3('z', "1-5", std::vector<Identifier>{Identifier(20, 1)});
    ed1->remoteInsert(s3);
    EXPECT_EQ(ed1->getSymbols()[3][0], s3);
    EXPECT_EQ(ed1->getSymbols()[3][1], *e1);

    Symbol s4('k', "1-6", std::vector<Identifier>{Identifier(19, 0), Identifier(8, 0), Identifier(2, 0), Identifier(1, 1)});
    ed1->remoteInsert(s4);
    EXPECT_LT(ed1->getSymbols()[2][4], ed1->getSymbols()[2][5]);
    EXPECT_LT(ed1->getSymbols()[2][5], ed1->getSymbols()[2][6]);
    EXPECT_EQ(ed1->getSymbols()[2][4], *o5);
    EXPECT_EQ(ed1->getSymbols()[2][5], s4);
    EXPECT_EQ(ed1->getSymbols()[2][6], *slash3);

    Symbol s6('q', "1-7", std::vector<Identifier>{Identifier(15, 0), Identifier(8, 1)});
    ed1->remoteInsert(s6);
    EXPECT_LT(ed1->getSymbols()[1][8], ed1->getSymbols()[2][0]);
    EXPECT_LT(ed1->getSymbols()[2][0], ed1->getSymbols()[2][1]);
    EXPECT_EQ(ed1->getSymbols()[2][0], s6);
    EXPECT_EQ(ed1->getSymbols()[2][1], *m1);

    Symbol s7('p', "1-8", std::vector<Identifier>{Identifier(3, 0), Identifier(5, 1)});
    ed1->remoteInsert(s7);
    EXPECT_EQ(ed1->getSymbols()[0][2], *t1);
    EXPECT_EQ(ed1->getSymbols()[0][3], s7);

    Symbol s5('l', "1-9", std::vector<Identifier>{Identifier(0, 0), Identifier(4, 1)});
    ed1->remoteInsert(s5);
    EXPECT_EQ(ed1->getSymbols()[0][0], s5);
    EXPECT_EQ(ed1->getSymbols()[0][1], *a1);

    Symbol s8('t', "1-10", std::vector<Identifier>{Identifier(0, 0), Identifier(4, 0)});
    ed1->remoteInsert(s8);
    EXPECT_EQ(ed1->getSymbols()[0][0], s8);
    EXPECT_EQ(ed1->getSymbols()[0][1], s5);

    int numLines2 = ed1->getSymbols().size();
    int numSymbolsInLine0 = ed1->getSymbols()[0].size();
    ed1->remoteInsert(s8);
    EXPECT_EQ(ed1->getSymbols()[0][0], s8);
    EXPECT_EQ(ed1->getSymbols()[0][1], s5);
    EXPECT_EQ(ed1->getSymbols().size(), numLines2);
    EXPECT_EQ(ed1->getSymbols()[0].size(), numSymbolsInLine0);

    ed1->getSymbols().clear();
    ed1->getSymbols().emplace_back();
    ed1->setCounter(0);
    Symbol s9('a', "1-11", std::vector<Identifier>{Identifier(30, 1)});
    ed1->remoteInsert(s9);
    EXPECT_EQ(ed1->getSymbols().size(), 1);
    EXPECT_EQ(ed1->getSymbols()[0][0], s9);

    ed1->getSymbols().clear();
    ed1->getSymbols().emplace_back();
    ed1->setCounter(0);
    Symbol s10('\n', "1-12", std::vector<Identifier>{Identifier(30, 1)});
    ed1->remoteInsert(s10);
    EXPECT_EQ(ed1->getSymbols().size(), 2);
    EXPECT_EQ(ed1->getSymbols()[0][0], s10);
}

TEST_F(SharedEditorTest, remoteInsertBetweenConflicts) {
    Symbol s2('x', "1-1", std::vector<Identifier>{Identifier(24, 0), Identifier(5, 0), Identifier(6, 1)});
    ed1->remoteInsert(s2);
    EXPECT_EQ(ed1->getSymbols()[3][4], *u1);
    EXPECT_EQ(ed1->getSymbols()[3][5], s2);
    EXPECT_EQ(ed1->getSymbols()[3][6], *e2);

    Symbol s3('y', "1-2", std::vector<Identifier>{Identifier(24, 0), Identifier(5, 0), Identifier(6, 0), Identifier(4, 1)});
    ed1->remoteInsert(s3);
    EXPECT_EQ(ed1->getSymbols()[3][5], s3);
    EXPECT_EQ(ed1->getSymbols()[3][6], s2);
}

TEST_F(SharedEditorTest, remoteErase) {
    ed1->remoteErase(*slash4);
    EXPECT_EQ(ed1->getSymbols()[3].size(), 8);
    EXPECT_EQ(ed1->getSymbols()[3][7], *e3);

    ed1->remoteErase(*u1);
    EXPECT_EQ(ed1->getSymbols()[3].size(), 7);
    EXPECT_EQ(ed1->getSymbols()[3][3], *n4);
    EXPECT_EQ(ed1->getSymbols()[3][4], *e2);

    ed1->remoteErase(*u1);
    EXPECT_EQ(ed1->getSymbols()[3].size(), 7);
    EXPECT_EQ(ed1->getSymbols()[3][3], *n4);
    EXPECT_EQ(ed1->getSymbols()[3][4], *e2);

    ed1->remoteErase(*slash3);
    EXPECT_EQ(ed1->getSymbols()[2].size(), 12);
    EXPECT_EQ(ed1->getSymbols()[2][4], *o5);
    EXPECT_EQ(ed1->getSymbols()[2][5], *e1);

    ed1->remoteErase(*a1);
    EXPECT_EQ(ed1->getSymbols()[0].size(), 7);
    EXPECT_EQ(ed1->getSymbols()[0][0], *n1);

    ed1->remoteErase(*a2);
    EXPECT_EQ(ed1->getSymbols()[0].size(), 7);
    EXPECT_EQ(ed1->getSymbols()[1].size(), 8);
    EXPECT_EQ(ed1->getSymbols()[0][6], *slash1);
    EXPECT_EQ(ed1->getSymbols()[1][0], *g1);

    ed1->getSymbols().clear();
    ed1->getSymbols().emplace_back();
    ed1->setCounter(0);
    Symbol s10('\n', "1-41", std::vector<Identifier>{Identifier(30, 1)});
    ed1->remoteErase(s10);
    EXPECT_EQ(ed1->getSymbols().size(), 1);

    ed1->getSymbols()[0].push_back(s10);
    ed1->setCounter(1);
    ed1->getSymbols().emplace_back();
    ed1->remoteErase(s10);
    EXPECT_EQ(ed1->getSymbols().size(), 1);

    ed1->getSymbols()[0].push_back(*a1);
    ed1->setCounter(1);
    ed1->remoteErase(*a1);
    EXPECT_EQ(ed1->getSymbols().size(), 1);
}

TEST_F(SharedEditorTest, eraseMultipleLinesCase1) {
    ed3->eraseMultipleLines(9, 0, 11, 0);
    EXPECT_EQ(ed3->getSymbols().size(), 15);
    EXPECT_EQ(ed3->getSymbols()[8].back(), *sym_slash8);
    EXPECT_EQ(ed3->getSymbols()[11][0], *sym_slash12);
    EXPECT_EQ(ed3->getSymbols()[12][0], *sym44);
    EXPECT_EQ(ed3->getSymbols()[12][1], *sym_slash13);
    EXPECT_EQ(ed3->getSymbols()[13][0], *sym_slash14);
}

TEST_F(SharedEditorTest, localEraseMultipleLinesCase1) {
    ed3->localErase(9, 0, 11, 0);
    EXPECT_EQ(ed3->getSymbols().size(), 13);
    EXPECT_EQ(ed3->getSymbols()[8].back(), *sym_slash8);
    EXPECT_EQ(ed3->getSymbols()[9][0], *sym_slash12);
    EXPECT_EQ(ed3->getSymbols()[10][0], *sym44);
    EXPECT_EQ(ed3->getSymbols()[10][1], *sym_slash13);
    EXPECT_EQ(ed3->getSymbols()[11][0], *sym_slash14);
}

TEST_F(SharedEditorTest, eraseMultipleLinesCase2) {
    ed3->eraseMultipleLines(9, 0, 12, 0);
    EXPECT_EQ(ed3->getSymbols().size(), 14);
    EXPECT_EQ(ed3->getSymbols()[8].back(), *sym_slash8);
    EXPECT_EQ(ed3->getSymbols()[11][0], *sym44);
    EXPECT_EQ(ed3->getSymbols()[11][1], *sym_slash13);
    EXPECT_EQ(ed3->getSymbols()[12][0], *sym_slash14);
}

TEST_F(SharedEditorTest, localEraseMultipleLinesCase2) {
    ed3->localErase(9, 0, 12, 0);
    EXPECT_EQ(ed3->getSymbols().size(), 12);
    EXPECT_EQ(ed3->getSymbols()[8].back(), *sym_slash8);
    EXPECT_EQ(ed3->getSymbols()[9][0], *sym44);
    EXPECT_EQ(ed3->getSymbols()[9][1], *sym_slash13);
    EXPECT_EQ(ed3->getSymbols()[10][0], *sym_slash14);
}

TEST_F(SharedEditorTest, eraseMultipleLinesCase3) {
    ed3->eraseMultipleLines(9, 0, 13, 0);
    EXPECT_EQ(ed3->getSymbols().size(), 13);
    EXPECT_EQ(ed3->getSymbols()[8].back(), *sym_slash8);
    EXPECT_EQ(ed3->getSymbols()[10][0], *sym_slash13);
    EXPECT_EQ(ed3->getSymbols()[11][0], *sym_slash14);
}

TEST_F(SharedEditorTest, localEraseMultipleLinesCase3) {
    ed3->localErase(9, 0, 13, 0);
    EXPECT_EQ(ed3->getSymbols().size(), 12);
    EXPECT_EQ(ed3->getSymbols()[8].back(), *sym_slash8);
    EXPECT_EQ(ed3->getSymbols()[9][0], *sym_slash13);
    EXPECT_EQ(ed3->getSymbols()[10][0], *sym_slash14);
}

TEST_F(SharedEditorTest, eraseMultipleLinesCase4) {
    ed3->eraseMultipleLines(9, 0, 13, 1);
    EXPECT_EQ(ed3->getSymbols().size(), 13);
    EXPECT_EQ(ed3->getSymbols()[8].back(), *sym_slash8);
    EXPECT_EQ(ed3->getSymbols()[11][0], *sym_slash14);

}

TEST_F(SharedEditorTest, localEraseMultipleLinesCase4) {
    ed3->localErase(9, 0, 13, 1);
    EXPECT_EQ(ed3->getSymbols().size(), 11);
    EXPECT_EQ(ed3->getSymbols()[8].back(), *sym_slash8);
    EXPECT_EQ(ed3->getSymbols()[9][0], *sym_slash14);

}

TEST_F(SharedEditorTest, eraseMultipleLinesCase5) {
    ed3->eraseMultipleLines(0, 10, 2, 0);
    EXPECT_EQ(ed3->getSymbols().size(), 15);
    EXPECT_EQ(ed3->getSymbols()[0][9], *sym9);
    EXPECT_EQ(ed3->getSymbols()[2][0], *sym_slash3);
    EXPECT_EQ(ed3->getSymbols()[3][0], *sym20);
}

TEST_F(SharedEditorTest, localEraseMultipleLinesCase5) {
    ed3->localErase(0, 10, 2, 0);
    EXPECT_EQ(ed3->getSymbols().size(), 13);
    EXPECT_EQ(ed3->getSymbols()[0][9], *sym9);
    EXPECT_EQ(ed3->getSymbols()[0][10], *sym_slash3);
    EXPECT_EQ(ed3->getSymbols()[1][0], *sym20);
}

TEST_F(SharedEditorTest, eraseMultipleLinesCase6) {
    ed3->eraseMultipleLines(2, 0, 3, 0);
    EXPECT_EQ(ed3->getSymbols().size(), 16);
    EXPECT_EQ(ed3->getSymbols()[1].back(), *sym_slash1);
    EXPECT_EQ(ed3->getSymbols()[4][0], *sym20);
    EXPECT_EQ(ed3->getSymbols()[4][1], *sym21);
    EXPECT_EQ(ed3->getSymbols()[4][2], *sym22);
    EXPECT_EQ(ed3->getSymbols()[4][3], *sym23);
}

TEST_F(SharedEditorTest, localEraseMultipleLinesCase6) {
    ed3->localErase(2, 0, 3, 0);
    EXPECT_EQ(ed3->getSymbols().size(), 14);
    EXPECT_EQ(ed3->getSymbols()[1].back(), *sym_slash1);
    EXPECT_EQ(ed3->getSymbols()[2][0], *sym20);
    EXPECT_EQ(ed3->getSymbols()[2][1], *sym21);
    EXPECT_EQ(ed3->getSymbols()[2][2], *sym22);
    EXPECT_EQ(ed3->getSymbols()[2][3], *sym23);
}

TEST_F(SharedEditorTest, eraseMultipleLinesCase7) {
    ed3->eraseMultipleLines(1, 0, 3, 0);
    EXPECT_EQ(ed3->getSymbols().size(), 15);
    EXPECT_EQ(ed3->getSymbols()[0].back(), *sym_slash0);
    EXPECT_EQ(ed3->getSymbols()[3][0], *sym20);
    EXPECT_EQ(ed3->getSymbols()[3][1], *sym21);
    EXPECT_EQ(ed3->getSymbols()[3][2], *sym22);
}

TEST_F(SharedEditorTest, localEraseMultipleLinesCase7) {
    ed3->localErase(1, 0, 3, 0);
    EXPECT_EQ(ed3->getSymbols().size(), 13);
    EXPECT_EQ(ed3->getSymbols()[0].back(), *sym_slash0);
    EXPECT_EQ(ed3->getSymbols()[1][0], *sym20);
    EXPECT_EQ(ed3->getSymbols()[1][1], *sym21);
    EXPECT_EQ(ed3->getSymbols()[1][2], *sym22);
}

TEST_F(SharedEditorTest, eraseMultipleLinesCase8) {
    ed3->eraseMultipleLines(6, 1, 8, 10);
    EXPECT_EQ(ed3->getSymbols().size(), 15);
    EXPECT_EQ(ed3->getSymbols()[5].back(), *sym_slash5);
    EXPECT_EQ(ed3->getSymbols()[6][0], *sym32);
    EXPECT_EQ(ed3->getSymbols()[8][0], *sym_slash9);
    EXPECT_EQ(ed3->getSymbols()[9][0], *sym43);
    EXPECT_EQ(ed3->getSymbols()[9][1], *sym_slash10);
}

TEST_F(SharedEditorTest, localEraseMultipleLinesCase8) {
    ed3->localErase(6, 1, 8, 10);
    EXPECT_EQ(ed3->getSymbols().size(), 13);
    EXPECT_EQ(ed3->getSymbols()[5].back(), *sym_slash5);
    EXPECT_EQ(ed3->getSymbols()[6][0], *sym32);
    EXPECT_EQ(ed3->getSymbols()[6][1], *sym_slash9);
    EXPECT_EQ(ed3->getSymbols()[7][0], *sym43);
    EXPECT_EQ(ed3->getSymbols()[7][1], *sym_slash10);
}

TEST_F(SharedEditorTest, eraseMultipleLinesCase9) {
    ed3->eraseMultipleLines(6, 1, 8, 9);
    EXPECT_EQ(ed3->getSymbols().size(), 15);
    EXPECT_EQ(ed3->getSymbols()[6][0], *sym32);
    EXPECT_EQ(ed3->getSymbols()[7][0], *sym_slash8);
    EXPECT_EQ(ed3->getSymbols()[8][0], *sym_slash9);
    EXPECT_EQ(ed3->getSymbols()[9][0], *sym43);
}

TEST_F(SharedEditorTest, localEraseMultipleLinesCase9) {
    ed3->localErase(6, 1, 8, 9);
    EXPECT_EQ(ed3->getSymbols().size(), 14);
    EXPECT_EQ(ed3->getSymbols()[6][0], *sym32);
    EXPECT_EQ(ed3->getSymbols()[6][1], *sym_slash8);
    EXPECT_EQ(ed3->getSymbols()[7][0], *sym_slash9);
    EXPECT_EQ(ed3->getSymbols()[8][0], *sym43);
}

TEST_F(SharedEditorTest, eraseMultipleLinesCase10) {
    ed3->eraseMultipleLines(6, 1, 11, 0);
    EXPECT_EQ(ed3->getSymbols().size(), 12);
    EXPECT_EQ(ed3->getSymbols()[6][0], *sym32);
    EXPECT_EQ(ed3->getSymbols()[8][0], *sym_slash12);
    EXPECT_EQ(ed3->getSymbols()[9][0], *sym44);
    EXPECT_EQ(ed3->getSymbols()[9][1], *sym_slash13);
    EXPECT_EQ(ed3->getSymbols()[10][0], *sym_slash14);
}

TEST_F(SharedEditorTest, localEraseMultipleLinesCase10) {
    ed3->localErase(6, 1, 11, 0);
    EXPECT_EQ(ed3->getSymbols().size(), 10);
    EXPECT_EQ(ed3->getSymbols()[6][0], *sym32);
    EXPECT_EQ(ed3->getSymbols()[6][1], *sym_slash12);
    EXPECT_EQ(ed3->getSymbols()[7][0], *sym44);
    EXPECT_EQ(ed3->getSymbols()[7][1], *sym_slash13);
    EXPECT_EQ(ed3->getSymbols()[8][0], *sym_slash14);
}

TEST_F(SharedEditorTest, eraseMultipleLinesCase11) {
    ed3->eraseMultipleLines(10, 0, 13, 0);
    EXPECT_EQ(ed3->getSymbols().size(), 14);
    EXPECT_EQ(ed3->getSymbols()[9].back(), *sym_slash9);
    EXPECT_EQ(ed3->getSymbols()[11][0], *sym_slash13);
    EXPECT_EQ(ed3->getSymbols()[12][0], *sym_slash14);
}

TEST_F(SharedEditorTest, localEraseMultipleLinesCase11) {
    ed3->localErase(10, 0, 13, 0);
    EXPECT_EQ(ed3->getSymbols().size(), 13);
    EXPECT_EQ(ed3->getSymbols()[9].back(), *sym_slash9);
    EXPECT_EQ(ed3->getSymbols()[10][0], *sym_slash13);
    EXPECT_EQ(ed3->getSymbols()[11][0], *sym_slash14);
}

TEST_F(SharedEditorTest, eraseMultipleLinesCase12) {
    ed3->eraseMultipleLines(10, 1, 14, 0);
    EXPECT_EQ(ed3->getSymbols().size(), 13);
    EXPECT_EQ(ed3->getSymbols()[10].back(), *sym43);
}

TEST_F(SharedEditorTest, localEraseMultipleLinesCase12) {
    ed3->localErase(10, 1, 14, 0);
    EXPECT_EQ(ed3->getSymbols().size(), 11);
    EXPECT_EQ(ed3->getSymbols()[10].back(), *sym43);
}

TEST_F(SharedEditorTest, eraseMultipleLinesCase13) {
    ed3->eraseMultipleLines(10, 0, 14, 0);
    EXPECT_EQ(ed3->getSymbols().size(), 13);
    EXPECT_EQ(ed3->getSymbols()[9].back(), *sym_slash9);
}

TEST_F(SharedEditorTest, localEraseMultipleLinesCase13) {
    ed3->localErase(10, 0, 14, 0);
    EXPECT_EQ(ed3->getSymbols().size(), 11);
    EXPECT_EQ(ed3->getSymbols()[9].back(), *sym_slash9);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
