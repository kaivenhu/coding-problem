#include "swap-nodes-in-pairs.h"

namespace swappairs
{
ListNode *Solution::swapPairs(ListNode *head)
{
    for (ListNode **cur = &head; nullptr != (*cur) && nullptr != (*cur)->next;
         cur = &((*cur)->next->next)) {
        ListNode *tmp = *cur;
        *cur = (*cur)->next;
        tmp->next = (*cur)->next;
        (*cur)->next = tmp;
    }
    return head;
}

}  // namespace swappairs
