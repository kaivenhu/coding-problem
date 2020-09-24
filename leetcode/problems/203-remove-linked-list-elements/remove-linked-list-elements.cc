#include "remove-linked-list-elements.h"

namespace remove_list {

ListNode* Solution::removeElements(ListNode* head, int val)
{
    ListNode **cur = &head;

    while (nullptr != *cur) {
        if (val == (*cur)->val) {
            auto tmp = (*cur);
            *cur = (*cur)->next;
            free(tmp);
        } else {
            cur = &((*cur)->next);
        }
    }
    return head;
    /*
    ListNode *curNode = head;
    ListNode *lastNode = nullptr;

    while (nullptr != curNode) {
        if (val == curNode->val) {
            if (nullptr == lastNode) {
                head = curNode->next;
            } else {
                lastNode->next = curNode->next;
            }
            auto tmp = curNode;
            curNode = curNode->next;
            free(tmp);
        } else {
            lastNode = curNode;
            curNode = curNode->next;
        }
    }
    return head;
    */
}

}
