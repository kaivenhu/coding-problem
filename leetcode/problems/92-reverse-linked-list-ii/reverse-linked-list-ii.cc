#include "reverse-linked-list-ii.h"

namespace reverse
{

ListNode* Solution::reverseBetween(ListNode* head, int left, int right)
{
    if (right <= 1)
        return head;
    auto btw_start = reverseBetween(head->next, left - 1, right - 1);

    if (1 >= left) {
        auto tmp = head->next->next;
        head->next->next = head;
        head->next = tmp;
    } else {
        head->next = btw_start;
        btw_start = head;
    }
    return btw_start;
}

}  // namespace reverse
