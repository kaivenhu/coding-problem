#include "remove-duplicates-sorted-list.h"

namespace remove_duplicate {

ListNode* Solution::deleteDuplicates(ListNode* head)
{
    for (ListNode *cur = head;
            nullptr != cur && nullptr != cur->next;) {
        if (cur->val == cur->next->val) {
            auto tmp = cur->next;
            cur->next = cur->next->next;
            free (tmp);
        } else {
            cur = cur->next;
        }
    }
    return head;
}

}
