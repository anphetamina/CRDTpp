//
// Created by asant on 12/03/2020.
//

#include "gtest/gtest.h"
#include "SharedEditor.h"


class SharedEditorTest : public ::testing::Test {

protected:
    virtual void SetUp() {

    }
    virtual void TearDown() {

    }
};

TEST(SharedEditorTest, Test1){


    ASSERT_EQ(1,0);
    EXPECT_EQ(1,1);
}


TEST(SharedEditorTest, Test2){


    ASSERT_EQ(1,0);
}