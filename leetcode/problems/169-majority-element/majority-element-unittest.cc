#include <gtest/gtest.h>

#include "majority-element.h"

using namespace major_elem;

TEST(major_elem, one)
{
    Solution s;
    EXPECT_EQ(s.majorityElement({0}), 0);
    EXPECT_EQ(s.majorityElement({100}), 100);
    EXPECT_EQ(s.majorityElement({-100}), -100);
}

TEST(major_elem, basic)
{
    Solution s;
    EXPECT_EQ(s.majorityElement({-100, -100, -100, 2, 2}), -100);
    EXPECT_EQ(s.majorityElement({100, 100, 100, 2, 2}), 100);
}

TEST(major_elem, equal)
{
    Solution s;
    EXPECT_EQ(s.majorityElement({-100, -100, -100, 2, 2, 2}), -100);
    EXPECT_EQ(s.majorityElement({100, 2, 100, 2, 100, 2}), 100);
}

TEST(major_elem, interval)
{
    Solution s;
    EXPECT_EQ(s.majorityElement({100, 2, 100, 2, 100, 2, 100}), 100);
    EXPECT_EQ(s.majorityElement({100, 2, 100, 2, 100, 2, 2}), 2);
    EXPECT_EQ(s.majorityElement({100, 100, 2, 2, 100, 100, 2, 2, 100, 100, 2, 2, 2}), 2);
}

TEST(major_elem, multiple)
{
    Solution s;
    EXPECT_EQ(s.majorityElement({100, 2, 3, 3, 100, 2, 3, 3, 100, 2, 3, 3, 100, 4, 3, 3}), 3);
    EXPECT_EQ(s.majorityElement({100, 2, 100, 2, 100, 2, 3, 3, 3, 3, 3, 3}), 3);
    EXPECT_EQ(s.majorityElement({100, 3, 3, 2, 100, 3, 3, 2, 100, 3, 3, 2,
                3, 4, 3, 4, 3, 4, 3, 4, 3, 4, 3, 4}), 3);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
