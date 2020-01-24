#include "intersection-of-two-linked-lists.h"

namespace inter_list {

ListNode* Solution::getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *curA = headA;
    ListNode *curB = headB;
    ListNode *ret = nullptr;
    bool isATurn = false;
    bool isBTurn = false;
    if (nullptr == curA || nullptr == curB) {
        return nullptr;
    }
    while (nullptr != curA || nullptr != curB) {
        if (curA == curB) {
            ret = curA;
            break;
        }
        curA = curA->next;
        curB = curB->next;
        if (nullptr == curA && !isATurn) {
            curA = headB;
            isATurn = true;
        }
        if (nullptr == curB && !isBTurn) {
            curB = headA;
            isBTurn = true;
        }
    }
    return ret;
}

}
