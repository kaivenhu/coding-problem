#ifndef REVERSE_LINKED_LIST
#define REVERSE_LINKED_LIST
#include <coding/linklist.h>

using namespace coding::linklist;

namespace reverse {

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
    ListNode* reverseList(ListNode* head);
};

}

#endif /* REVERSE_LINKED_LIST */
