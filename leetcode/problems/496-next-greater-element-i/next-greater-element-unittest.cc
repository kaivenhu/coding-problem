#include <vector>

#include <gtest/gtest.h>

#include "next-greater-element.h"

using namespace solution;
using std::vector;

TEST(NexGreaterElement, testcase_1)
{
    Solution s;
    auto ans = s.nextGreaterElement({4,1,2}, {1,3,4,2});
    vector<int> expect = {-1,3,-1};

    ASSERT_EQ(expect.size(), ans.size());

    for (unsigned int i = 0; i < expect.size(); ++i) {
        EXPECT_EQ(expect[i], ans[i]);
    }
}

TEST(NexGreaterElement, testcase_2)
{
    Solution s;
    auto ans = s.nextGreaterElement({2,4}, {1,2,3,4});
    vector<int> expect = {3,-1};

    ASSERT_EQ(expect.size(), ans.size());

    for (unsigned int i = 0; i < expect.size(); ++i) {
        EXPECT_EQ(expect[i], ans[i]);
    }
}

TEST(NexGreaterElement, testcase_3)
{
    Solution s;
    auto ans = s.nextGreaterElement({}, {});
    vector<int> expect = {};

    ASSERT_EQ(expect.size(), ans.size());

    for (unsigned int i = 0; i < expect.size(); ++i) {
        EXPECT_EQ(expect[i], ans[i]);
    }
}

TEST(NexGreaterElement, testcase_4)
{
    Solution s;
    auto ans = s.nextGreaterElement({3,2,96}, {3, 2, 4,100,99,98,97,96});
    vector<int> expect = {4,4,-1};

    ASSERT_EQ(expect.size(), ans.size());

    for (unsigned int i = 0; i < expect.size(); ++i) {
        EXPECT_EQ(expect[i], ans[i]);
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
