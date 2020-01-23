#include <gtest/gtest.h>

#include "valid_pair.h"

TEST (ValidParenthesesTest, basic) {
    Solution s;
    EXPECT_TRUE(s.isValid("()[]{}"));
    EXPECT_TRUE(s.isValid("{()[]{}}[()]"));
    EXPECT_FALSE(s.isValid("{()]{}}[()]"));
    EXPECT_FALSE(s.isValid("]"));
    EXPECT_TRUE(s.isValid(""));
}

TEST (ValidParenthesesTest, testcase) {
    Solution s;
    EXPECT_TRUE(s.isValid("()"));
    EXPECT_TRUE(s.isValid("()[]{}"));
    EXPECT_FALSE(s.isValid("(]"));
    EXPECT_FALSE(s.isValid("([)]"));
    EXPECT_TRUE(s.isValid("{[]}"));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
