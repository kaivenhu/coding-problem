#ifndef PALINDROME_LINKED_LIST
#define PALINDROME_LINKED_LIST

#include <coding/linklist.h>

using namespace coding::linklist;

namespace palindrome_list {

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head);
};

}

#endif /* PALINDROME_LINKED_LIST */
