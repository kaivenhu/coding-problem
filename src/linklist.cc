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

}
}
