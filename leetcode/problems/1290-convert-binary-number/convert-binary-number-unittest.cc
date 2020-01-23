#include <vector>
#include <iostream>

#include <gtest/gtest.h>
#include <coding/linklist.h>

#include "convert-binary-number.h"

using namespace coding::linklist;
using namespace std;
using namespace binarynumber;

int test(const vector<int> &vec)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList(vec, &head);
    int ans = s.getDecimalValue(head);
    FreeLinkList(&head);
    return ans;
}

TEST(StoneWeight, testcase_1)
{
    EXPECT_EQ(0, test({0}));
    EXPECT_EQ(1, test({1}));
    EXPECT_EQ(18880, test({1,0,0,1,0,0,1,1,1,0,0,0,0,0,0}));
    EXPECT_EQ(1, test({0, 0, 1}));
    EXPECT_EQ(1073741823, test({1, 1, 1, 1, 1 , 1, 1, 1, 1, 1 , 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1 , 1, 1, 1, 1, 1 , 1, 1, 1, 1, 1}));
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
