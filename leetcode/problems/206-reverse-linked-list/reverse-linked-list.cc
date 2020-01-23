#include "reverse-linked-list.h"

namespace reverse {

ListNode* Solution::reverseList(ListNode *head)
{
    if (nullptr == head || nullptr == head->next) {
        return head;
    }
    auto newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
    /*
    ListNode *curNode = nullptr;
    ListNode *nextNode = nullptr;
    ListNode *lastNode = nullptr;

    for (curNode = head; nullptr != curNode;) {
        nextNode = curNode->next;
        curNode->next = lastNode;
        lastNode = curNode;
        curNode = nextNode;
    }
    return lastNode;
    */
}

}
