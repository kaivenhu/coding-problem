#ifndef SWAP_NODES_IN_PAIRS_H_
#define SWAP_NODES_IN_PAIRS_H_
#include <coding/linklist.h>

namespace swappairs
{
using namespace coding::linklist;
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
class Solution
{
public:
    ListNode *swapPairs(ListNode *head);
};


}  // namespace swappairs

#endif /* SWAP_NODES_IN_PAIRS_H_ */
