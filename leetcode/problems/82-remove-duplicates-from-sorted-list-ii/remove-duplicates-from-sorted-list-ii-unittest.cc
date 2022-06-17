#include <gtest/gtest.h>
#include <coding/linklist.h>

#include "remove-duplicates-from-sorted-list-ii.h"

using namespace coding::linklist;
using namespace remove_duplicate;

TEST(remove_duplicate, basic)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1, 1, 2, 3, 3, 3, 4, 2, 2, 2}, &head);
    head = s.deleteDuplicates(head);
    EXPECT_TRUE(IsLinkListEqual(head, {2, 4}));
    FreeLinkList(&head);
}

TEST(remove_duplicate, multiple)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1, 1, 2}, &head);
    head = s.deleteDuplicates(head);
    EXPECT_TRUE(IsLinkListEqual(head, {2}));
    FreeLinkList(&head);
    head = nullptr;
    Vec2LinkList({1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 6, 7}, &head);
    head = s.deleteDuplicates(head);
    EXPECT_TRUE(IsLinkListEqual(head, {1, 5, 6, 7}));
    FreeLinkList(&head);
}

TEST(remove_duplicate, empty)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1, 1, 1, 1, 1, 1, 1, 1}, &head);
    head = s.deleteDuplicates(head);
    EXPECT_TRUE(IsLinkListEqual(head, {}));
    FreeLinkList(&head);
    head = nullptr;
    Vec2LinkList({1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4}, &head);
    head = s.deleteDuplicates(head);
    EXPECT_TRUE(IsLinkListEqual(head, {}));
    FreeLinkList(&head);
    head = nullptr;
    head = s.deleteDuplicates(head);
    EXPECT_TRUE(IsLinkListEqual(head, {}));
    FreeLinkList(&head);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
