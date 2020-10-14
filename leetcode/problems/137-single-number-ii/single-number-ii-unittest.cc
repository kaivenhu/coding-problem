#include <gtest/gtest.h>

#include "single-number-ii.h"

using namespace bitwise;

TEST(bitwise, basic)
{
    EXPECT_EQ(3, Solution::singleNumber({2, 2, 3, 2}));
    EXPECT_EQ(99, Solution::singleNumber({0, 1, 0, 1, 0, 1, 99}));
    EXPECT_EQ(0, Solution::singleNumber({1, 1, 1, 0}));
    EXPECT_EQ(999, Solution::singleNumber({999}));
    EXPECT_EQ(0xF, Solution::singleNumber(
                       {0xFF, 0xFF, 0xFFF, 0xFFF, 0xFF, 0xFFF, 0xF}));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
