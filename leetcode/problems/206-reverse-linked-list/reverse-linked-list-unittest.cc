#include <gtest/gtest.h>
#include <coding/linklist.h>

#include "reverse-linked-list.h"

using namespace reverse;

TEST(reverse, basic)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1, 2, 3, 4, 5}, &head);
    head = s.reverseList(head);
    EXPECT_TRUE(IsLinkListEqual(head, {5, 4, 3, 2, 1}));
    FreeLinkList(&head);
}

TEST(reverse, two_node)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1, 2}, &head);
    head = s.reverseList(head);
    EXPECT_TRUE(IsLinkListEqual(head, {2, 1}));
    FreeLinkList(&head);
}

TEST(reverse, one_node)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1}, &head);
    head = s.reverseList(head);
    EXPECT_TRUE(IsLinkListEqual(head, {1}));
    FreeLinkList(&head);
}

TEST(reverse, empty)
{
    Solution s;
    ListNode *head = nullptr;
    head = s.reverseList(head);
    EXPECT_TRUE(IsLinkListEqual(head, nullptr));
    FreeLinkList(&head);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
