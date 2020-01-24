#include <gtest/gtest.h>
#include <coding/linklist.h>

#include "palindrome-linked-list.h"

using namespace coding::linklist;
using namespace palindrome_list;

TEST(palindrome_list, true_case)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1, 2, 3, 2, 1}, &head);
    EXPECT_TRUE(s.isPalindrome(head));
    FreeLinkList(&head);
    Vec2LinkList({1, 2, 2, 1}, &head);
    EXPECT_TRUE(s.isPalindrome(head));
    FreeLinkList(&head);
    Vec2LinkList({1, 2, 1}, &head);
    EXPECT_TRUE(s.isPalindrome(head));
    FreeLinkList(&head);
    Vec2LinkList({1, 2, 1, 1, 2, 1}, &head);
    EXPECT_TRUE(s.isPalindrome(head));
    FreeLinkList(&head);
}

TEST(palindrome_list, false_case)
{
    Solution s;
    ListNode *head = nullptr;
    Vec2LinkList({1, 2}, &head);
    EXPECT_FALSE(s.isPalindrome(head));
    FreeLinkList(&head);
    Vec2LinkList({1, 2, 3}, &head);
    EXPECT_FALSE(s.isPalindrome(head));
    FreeLinkList(&head);
    Vec2LinkList({1, 2, 2, 3}, &head);
    EXPECT_FALSE(s.isPalindrome(head));
    FreeLinkList(&head);
}

TEST(palindrome_list, corner_case)
{
    Solution s;
    ListNode *head = nullptr;
    EXPECT_TRUE(s.isPalindrome(head));
    FreeLinkList(&head);
    Vec2LinkList({1, 1}, &head);
    EXPECT_TRUE(s.isPalindrome(head));
    FreeLinkList(&head);
    Vec2LinkList({1}, &head);
    EXPECT_TRUE(s.isPalindrome(head));
    FreeLinkList(&head);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
