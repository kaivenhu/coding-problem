#include <gtest/gtest.h>
#include <coding/linklist.h>

#include "reverse-linked-list-ii.h"

using namespace reverse;

TEST(reverse, basic)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1, 2, 3, 4, 5}, &head);
    head = s.reverseBetween(head, 2, 4);
    EXPECT_TRUE(IsLinkListEqual(head, {1, 4, 3, 2, 5}));
    FreeLinkList(&head);
}

TEST(reverse, total)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1, 2, 3, 4, 5}, &head);
    head = s.reverseBetween(head, 1, 5);
    EXPECT_TRUE(IsLinkListEqual(head, {5, 4, 3, 2, 1}));
    FreeLinkList(&head);
}

TEST(reverse, one)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1}, &head);
    head = s.reverseBetween(head, 1, 1);
    EXPECT_TRUE(IsLinkListEqual(head, {1}));
    FreeLinkList(&head);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
