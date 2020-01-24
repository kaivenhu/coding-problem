#ifndef INTERSECTION_OF_TWO_LINKED_LISTS
#define INTERSECTION_OF_TWO_LINKED_LISTS

#include <coding/linklist.h>

using namespace coding::linklist;

namespace inter_list {

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
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB);
};

}

#endif /* INTERSECTION_OF_TWO_LINKED_LISTS */
