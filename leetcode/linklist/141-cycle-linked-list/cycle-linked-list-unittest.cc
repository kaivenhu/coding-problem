#include <vector>
#include <iostream>

#include <gtest/gtest.h>
#include <coding/linklist.h>

#include "cycle-linked-list.h"

using namespace coding::linklist;
using namespace std;
using namespace cyclelinklist;

bool test(const vector<int> &vec, int pos)
{
    Solution s;
    ListNode *head = nullptr;
    MackCycleLinkList(vec, pos, &head);
    bool ans = s.hasCycle(head);
    FreeCycleLinkList(vec.size(), &head);
    return ans;
}

TEST(CycleLinkList, testcase_1)
{
    EXPECT_FALSE(test({}, -1));
    EXPECT_TRUE(test({3,2,0,-4}, 1));
    EXPECT_FALSE(test({3,2,0,-4}, -1));
    EXPECT_TRUE(test({1}, 0));
    EXPECT_TRUE(test({1,2}, 0));
    EXPECT_TRUE(test({1,2, 3}, 0));
    EXPECT_FALSE(test({1,2, 3}, -1));
    EXPECT_FALSE(test({1}, -1));
    EXPECT_FALSE(test({1,2, 3, 1, 2, 3, 4, 5, 1, 3, 5, 6, 2, 4, 6, 7, -4}, -1));
    EXPECT_TRUE(test({1,2, 3, 1, 2, 3, 4, 5, 1, 3, 5, 6, 2, 4, 6, 7, -4}, 16));
    EXPECT_TRUE(test({1,2, 3}, 2));
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
