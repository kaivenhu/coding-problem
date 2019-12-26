#include <cstdlib>

#include <coding/linklist.h>

namespace coding{
namespace linklist {

void Vec2LinkList(const std::vector<int> &vec, ListNode **head)
{
    ListNode *rear = nullptr;
    FreeLinkList(head);

    for (auto &val : vec) {
        ListNode *node = (ListNode *) calloc(1, sizeof(ListNode));
        node->val = val;
        node->next = nullptr;
        if (nullptr == (*head)) {
            (*head) = node;
            rear = node;
        } else {
            rear->next = node;
            rear = node;
        }
    }
}

void FreeLinkList(ListNode **head)
{
    while (nullptr != (*head)) {
        auto tmp = (*head);
        (*head) = (*head)->next;
        free(tmp);
    }
}

void FreeCycleLinkList(int size, ListNode **head)
{
    for (int i = 0; i < size && nullptr != (*head); ++i) {
        auto tmp = (*head);
        (*head) = (*head)->next;
        free(tmp);
    }
}

void MackCycleLinkList(const std::vector<int> &vec, int pos, ListNode **head)
{
    FreeLinkList(head);
    Vec2LinkList(vec, head);
    if (0 > pos) {
        return;
    }
    ListNode *cycle_pos = nullptr;
    ListNode *node = nullptr;
    ListNode *tail_node = nullptr;
    int i = 0;
    for (node = (*head); nullptr != node; node = node->next, ++i) {
        if (i == pos) {
            cycle_pos = node;
        }
        tail_node = node;
    }
    tail_node->next = cycle_pos;
}

}
}
