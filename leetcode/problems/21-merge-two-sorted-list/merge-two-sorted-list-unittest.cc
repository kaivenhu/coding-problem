#include <gtest/gtest.h>
#include <coding/linklist.h>

#include "merge-two-sorted-list.h"

using namespace coding::linklist;
using namespace merge_list;

TEST(merge_list, basic)
{
    Solution s;
    ListNode *head_1 = nullptr;
    ListNode *head_2 = nullptr;
    Vec2LinkList({1, 2, 4}, &head_1);
    Vec2LinkList({1, 3, 4}, &head_2);
    auto head = s.mergeTwoLists(head_1, head_2);
    EXPECT_TRUE(IsLinkListEqual(head, {1, 1, 2, 3, 4, 4}));
    FreeLinkList(&head);
}

TEST(merge_list, test_1)
{
    Solution s;
    ListNode *head_1 = nullptr;
    ListNode *head_2 = nullptr;
    Vec2LinkList({1, 1, 1, 1, 1, 2, 3}, &head_1);
    Vec2LinkList({1, 3, 4}, &head_2);
    auto head = s.mergeTwoLists(head_1, head_2);
    EXPECT_TRUE(IsLinkListEqual(head, {1, 1, 1, 1, 1, 1, 2, 3, 3, 4}));
    FreeLinkList(&head);
}

TEST(merge_list, test_2)
{
    Solution s;
    ListNode *head_1 = nullptr;
    ListNode *head_2 = nullptr;
    Vec2LinkList({1, 3, 4}, &head_1);
    Vec2LinkList({1, 1, 1, 1, 1, 2, 3}, &head_2);
    auto head = s.mergeTwoLists(head_1, head_2);
    EXPECT_TRUE(IsLinkListEqual(head, {1, 1, 1, 1, 1, 1, 2, 3, 3, 4}));
    FreeLinkList(&head);
}

TEST(merge_list, empty)
{
    Solution s;
    ListNode *head_1 = nullptr;
    ListNode *head_2 = nullptr;
    auto head = s.mergeTwoLists(head_1, head_2);
    EXPECT_TRUE(IsLinkListEqual(head, nullptr));
    FreeLinkList(&head);
}

TEST(merge_list, one_empty_1)
{
    Solution s;
    ListNode *head_1 = nullptr;
    ListNode *head_2 = nullptr;
    Vec2LinkList({1, 3, 4}, &head_1);
    auto head = s.mergeTwoLists(head_1, head_2);
    EXPECT_TRUE(IsLinkListEqual(head, {1, 3, 4}));
    FreeLinkList(&head);
}

TEST(merge_list, one_empty_2)
{
    Solution s;
    ListNode *head_1 = nullptr;
    ListNode *head_2 = nullptr;
    Vec2LinkList({1, 3, 4}, &head_2);
    auto head = s.mergeTwoLists(head_1, head_2);
    EXPECT_TRUE(IsLinkListEqual(head, {1, 3, 4}));
    FreeLinkList(&head);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
