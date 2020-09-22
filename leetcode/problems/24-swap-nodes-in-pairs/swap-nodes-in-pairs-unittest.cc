#include <coding/linklist.h>
#include <gtest/gtest.h>

#include "swap-nodes-in-pairs.h"

using namespace coding::linklist;
using namespace swappairs;

TEST(swappairs, empty)
{
    Solution s;
    ListNode *head = nullptr;
    head = s.swapPairs(head);
    EXPECT_TRUE(nullptr == head);
}

TEST(swappairs, one)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1}, &head);
    head = s.swapPairs(head);
    EXPECT_TRUE(IsLinkListEqual(head, {1}));
    FreeLinkList(&head);
}

TEST(swappairs, plural)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1, 2, 3, 4}, &head);
    head = s.swapPairs(head);
    EXPECT_TRUE(IsLinkListEqual(head, {2, 1, 4, 3}));
    FreeLinkList(&head);
}

TEST(swappairs, singular)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1, 2, 3, 4, 5}, &head);
    head = s.swapPairs(head);
    EXPECT_TRUE(IsLinkListEqual(head, {2, 1, 4, 3, 5}));
    FreeLinkList(&head);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
