#include <vector>

#include <gtest/gtest.h>

#include "last-stone-weight.h"

using namespace stoneweight;
using std::vector;

TEST(StoneWeight, testcase_1)
{
    Solution s;
    EXPECT_EQ(1, s.lastStoneWeight({2,7,4,1,8,1}));
    EXPECT_EQ(0, s.lastStoneWeight({1,999,1000}));
    EXPECT_EQ(997, s.lastStoneWeight({1,999,1000, 1001}));
    EXPECT_EQ(1, s.lastStoneWeight({1}));
    EXPECT_EQ(1, s.lastStoneWeight({1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
