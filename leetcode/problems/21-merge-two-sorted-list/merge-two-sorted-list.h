#ifndef MERGE_TWO_SORTED_LIST
#define MERGE_TWO_SORTED_LIST

#include <coding/linklist.h>

using namespace coding::linklist;

namespace merge_list {

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
};

}

#endif /* MERGE_TWO_SORTED_LIST */
