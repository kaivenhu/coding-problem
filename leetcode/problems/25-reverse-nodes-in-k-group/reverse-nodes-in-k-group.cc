#include "reverse-nodes-in-k-group.h"

namespace reverse
{

ListNode* Solution::reverseKGroup(ListNode* head, int k)
{
    if (!head || k == 1)
        return head;

    ListNode **end_pos = nullptr;
    ListNode *new_head = nullptr;
    ListNode **head_post = &new_head;
    ListNode *cur = head;
    ListNode *prev = nullptr;
    int i = 1;

    while (cur) {
        auto mod = i % k;
        if (mod == 1) {
            end_pos = &(cur->next);
            prev = nullptr;
        } else if (mod == 0) {
            *head_post = cur;
            head_post = end_pos;
        }
        auto next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        i++;
    }

    if ((i % k) == 1) {
        return new_head;
    }

    cur = prev;
    prev = nullptr;
    while (cur) {
        auto next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head_post = prev;
    return new_head;
}

}  // namespace reverse
