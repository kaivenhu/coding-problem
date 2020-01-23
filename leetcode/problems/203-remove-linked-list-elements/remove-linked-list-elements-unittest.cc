#include <gtest/gtest.h>
#include <coding/linklist.h>

#include "remove-linked-list-elements.h"

using namespace coding::linklist;
using namespace remove_list;

TEST(remove_list, basic)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({5, 5, 5, 1, 2, 3, 4, 5, 5, 5, 4, 4, 5, 5}, &head);
    head = s.removeElements(head, 5);
    EXPECT_TRUE(IsLinkListEqual(head, {1, 2, 3, 4, 4, 4}));
    FreeLinkList(&head);
}

TEST(remove_list, nodelete)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({5, 5, 5, 1, 2, 3, 4, 5, 5, 5, 4, 4, 5, 5}, &head);
    head = s.removeElements(head, 6);
    EXPECT_TRUE(IsLinkListEqual(head, {5, 5, 5, 1, 2, 3, 4, 5, 5, 5, 4, 4, 5, 5}));
    FreeLinkList(&head);
}

TEST(remove_list, delete2empty)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({5, 5, 5, 5}, &head);
    head = s.removeElements(head, 5);
    EXPECT_TRUE(IsLinkListEqual(head, nullptr));
    FreeLinkList(&head);
}

TEST(remove_list, empty)
{
    Solution s;
    ListNode *head = nullptr;
    head = s.removeElements(head, 6);
    EXPECT_TRUE(IsLinkListEqual(head, nullptr));
    FreeLinkList(&head);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
