#include "merge-two-sorted-list.h"

namespace merge_list {

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode head = ListNode(-1);
    ListNode *preNode = &head;
    ListNode *cur_1 = l1;
    ListNode *cur_2 = l2;
    while (nullptr != cur_1) {
        while (nullptr != cur_2) {
            if (cur_1->val < cur_2->val) {
                break;
            } else {
                preNode->next = cur_2;
                preNode = preNode->next;
                cur_2 = cur_2->next;
            }
        }
        preNode->next = cur_1;
        preNode = preNode->next;
        cur_1 = cur_1->next;
    }
    while (nullptr != cur_2) {
        preNode->next = cur_2;
        preNode = preNode->next;
        cur_2 = cur_2->next;
    }

    return head.next;
}

}
