#ifndef REVERSE_LINKED_LIST_II_H_
#define REVERSE_LINKED_LIST_II_H_
#include <coding/linklist.h>

using namespace coding::linklist;

namespace reverse
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
    ListNode* reverseBetween(ListNode* head, int left, int right);
};

}  // namespace reverse

#endif /* REVERSE_LINKED_LIST_II_H_ */
