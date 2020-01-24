#include "middle-linked-list.h"

namespace middle_list {

ListNode* Solution::middleNode(ListNode* head)
{
    ListNode *fast = head, *slow = head;
    while (nullptr != fast && nullptr != fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

}
