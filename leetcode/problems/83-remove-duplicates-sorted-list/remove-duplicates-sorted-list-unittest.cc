#include <gtest/gtest.h>
#include <coding/linklist.h>

#include "remove-duplicates-sorted-list.h"

using namespace coding::linklist;
using namespace remove_duplicate;

TEST(remove_duplicate, basic)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1, 1, 2, 3, 3, 3, 4, 2, 2, 2}, &head);
    head = s.deleteDuplicates(head);
    EXPECT_TRUE(IsLinkListEqual(head, {1, 2, 3, 4, 2}));
    FreeLinkList(&head);
}

TEST(remove_duplicate, test)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1, 1, 2}, &head);
    head = s.deleteDuplicates(head);
    EXPECT_TRUE(IsLinkListEqual(head, {1, 2}));
    FreeLinkList(&head);
}

TEST(remove_duplicate, onlyone)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1, 1, 1, 1, 1, 1, 1, 1}, &head);
    head = s.deleteDuplicates(head);
    EXPECT_TRUE(IsLinkListEqual(head, {1}));
    FreeLinkList(&head);
}

TEST(remove_duplicate, empty)
{
    Solution s;
    ListNode *head = nullptr;
    head = s.deleteDuplicates(head);
    EXPECT_TRUE(IsLinkListEqual(head, nullptr));
    FreeLinkList(&head);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
