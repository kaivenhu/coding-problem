#include <gtest/gtest.h>

#include "backspace-compare.h"

using namespace solution;

TEST(BackspaceCompare, testcase_1)
{
    Solution s;
    EXPECT_TRUE(s.backspaceCompare("ab#c", "ad#c"));
    EXPECT_TRUE(s.backspaceCompare("ab##", "c#d#"));
    EXPECT_TRUE(s.backspaceCompare("a##c", "#a#c"));
    EXPECT_FALSE(s.backspaceCompare("a#c", "b"));
}

TEST(BackspaceCompare, testcase_2)
{
    Solution s;
    EXPECT_TRUE(s.backspaceCompare("a######ab#c", "a#ad#c"));
    EXPECT_TRUE(s.backspaceCompare("##", "a#"));
    EXPECT_TRUE(s.backspaceCompare("", "#"));
    EXPECT_FALSE(s.backspaceCompare("a#a#a#a#a#c", ""));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
