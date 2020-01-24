#ifndef MIDDLE_LINKED_LIST
#define MIDDLE_LINKED_LIST

#include <coding/linklist.h>

using namespace coding::linklist;

namespace middle_list {

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
    ListNode* middleNode(ListNode* head);
};

}

#endif /* MIDDLE_LINKED_LIST */
