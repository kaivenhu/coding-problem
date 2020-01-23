#ifndef REMOVE_DUPLICATES_SORTED_LIST
#define REMOVE_DUPLICATES_SORTED_LIST

#include <coding/linklist.h>

using namespace coding::linklist;

namespace remove_duplicate {

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
    ListNode* deleteDuplicates(ListNode* head);
};

}

#endif /* REMOVE_DUPLICATES_SORTED_LIST */
