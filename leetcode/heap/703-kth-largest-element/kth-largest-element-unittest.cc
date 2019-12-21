#include <vector>

#include <gtest/gtest.h>

#include "kth-largest-element.h"

using namespace klargest;
using std::vector;

TEST(KthLargest, testcase_1)
{
    vector<int> test = {4,5,8,2};
    KthLargest largest(3, test);
    EXPECT_EQ(4, largest.add(3));
    EXPECT_EQ(5, largest.add(5));
    EXPECT_EQ(5, largest.add(10));
    EXPECT_EQ(8, largest.add(9));
    EXPECT_EQ(8, largest.add(4));
}

TEST(KthLargest, testcase_2)
{
    vector<int> test = {4};
    KthLargest largest(1, test);
    EXPECT_EQ(4, largest.add(3));
    EXPECT_EQ(4, largest.add(2));
    EXPECT_EQ(9, largest.add(9));
    EXPECT_EQ(9, largest.add(9));
    EXPECT_EQ(9, largest.add(9));
    EXPECT_EQ(9, largest.add(9));
    EXPECT_EQ(9, largest.add(9));
    EXPECT_EQ(10, largest.add(10));
    EXPECT_EQ(11, largest.add(11));
}

TEST(KthLargest, testcase_3)
{
    vector<int> test = {7,6,5,4,3,2,1,0,-1,-2};
    KthLargest largest(6, test);
    EXPECT_EQ(2, largest.add(-1));
    EXPECT_EQ(3, largest.add(3));
    EXPECT_EQ(3, largest.add(3));
    EXPECT_EQ(3, largest.add(5));
    EXPECT_EQ(3, largest.add(2));
    EXPECT_EQ(4, largest.add(5));
    EXPECT_EQ(5, largest.add(5));
}

TEST(KthLargest, testcase_4)
{
    vector<int> test = {};
    KthLargest largest(1, test);
    EXPECT_EQ(-1, largest.add(-1));
    EXPECT_EQ(5, largest.add(5));
    EXPECT_EQ(5, largest.add(5));
}

TEST(KthLargest, testcase_5)
{
    vector<int> test = {1, 2, 3, 4, 5, 6};
    KthLargest largest(7, test);
    EXPECT_EQ(-1, largest.add(-1));
    EXPECT_EQ(1, largest.add(5));
    EXPECT_EQ(2, largest.add(5));
}

TEST(KthLargest, testcase_6)
{
    vector<int> test = {5, -1};
    KthLargest largest(3, test);
    EXPECT_EQ(-1, largest.add(2));
    EXPECT_EQ(1, largest.add(1));
    EXPECT_EQ(1, largest.add(-1));
    EXPECT_EQ(2, largest.add(3));
    EXPECT_EQ(3, largest.add(4));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
