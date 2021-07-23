#include <gtest/gtest.h>

#include "reverse-nodes-in-k-group.h"

using namespace reverse;

TEST(reverse, basic)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1, 2, 3, 4, 5, 6}, &head);
    head = s.reverseKGroup(head, 2);
    EXPECT_TRUE(IsLinkListEqual(head, {2, 1, 4, 3, 6, 5}));
    FreeLinkList(&head);
}

TEST(reverse, one)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1, 2, 3, 4, 5, 6}, &head);
    head = s.reverseKGroup(head, 1);
    EXPECT_TRUE(IsLinkListEqual(head, {1, 2, 3, 4, 5, 6}));
    FreeLinkList(&head);
}

TEST(reverse, remain_1)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1, 2, 3, 4, 5}, &head);
    head = s.reverseKGroup(head, 2);
    EXPECT_TRUE(IsLinkListEqual(head, {2, 1, 4, 3, 5}));
    FreeLinkList(&head);
}

TEST(reverse, remain_2)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1, 2, 3, 4, 5, 6, 7, 8}, &head);
    head = s.reverseKGroup(head, 3);
    EXPECT_TRUE(IsLinkListEqual(head, {3, 2, 1, 6, 5, 4, 7, 8}));
    FreeLinkList(&head);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
