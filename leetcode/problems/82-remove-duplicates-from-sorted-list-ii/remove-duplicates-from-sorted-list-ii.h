#ifndef REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H_
#define REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H_

#include <coding/linklist.h>

using namespace coding::linklist;

namespace remove_duplicate
{

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head);
};

}  // namespace sorted_list

#endif /* REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H_ */
