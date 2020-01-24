#include <gtest/gtest.h>
#include <coding/linklist.h>

#include "middle-linked-list.h"

using namespace coding::linklist;
using namespace middle_list;

TEST(middle_list, test_1)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1, 2, 3, 4, 5}, &head);
    auto middle = s.middleNode(head);
    EXPECT_TRUE(IsLinkListEqual(middle, {3, 4, 5}));
    FreeLinkList(&head);
}

TEST(middle_list, test_2)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1, 2, 3, 4}, &head);
    auto middle = s.middleNode(head);
    EXPECT_TRUE(IsLinkListEqual(middle, {3, 4}));
    FreeLinkList(&head);
}

TEST(middle_list, only_1)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1}, &head);
    auto middle = s.middleNode(head);
    EXPECT_TRUE(IsLinkListEqual(middle, {1}));
    FreeLinkList(&head);
}

TEST(middle_list, only_2)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1, 2}, &head);
    auto middle = s.middleNode(head);
    EXPECT_TRUE(IsLinkListEqual(middle, {2}));
    FreeLinkList(&head);
}

TEST(middle_list, empty)
{
    Solution s;
    ListNode *head = nullptr;
    auto middle = s.middleNode(head);
    EXPECT_TRUE(IsLinkListEqual(middle, nullptr));
    FreeLinkList(&head);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
