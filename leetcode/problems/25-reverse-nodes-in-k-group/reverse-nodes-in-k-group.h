#ifndef REVERSE_NODES_IN_K_GROUP_H_
#define REVERSE_NODES_IN_K_GROUP_H_
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
    ListNode* reverseKGroup(ListNode* head, int k);
};

}  // namespace reverse

#endif /* REVERSE_NODES_IN_K_GROUP_H_ */
