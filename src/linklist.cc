#include <cstdlib>
#include <string>

#include <gtest/gtest.h>
#include <coding/linklist.h>

namespace coding {
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

::testing::AssertionResult
IsLinkListEqual(ListNode *answer, ListNode *expect)
{
    ::testing::AssertionResult result = ::testing::AssertionFailure();
    int idx = 0;
    bool is_failure = false;
    ListNode *cur_ans = answer;
    ListNode *cur_exp = expect;
    for (; nullptr != cur_ans && nullptr != cur_exp;
            cur_ans = cur_ans->next, cur_exp = cur_exp->next) {
        if (cur_ans->val != cur_exp->val) {
            is_failure = true;
            break;
        }
        ++idx;
    }
    if (is_failure
        || (nullptr != cur_ans || nullptr != cur_exp)) {
        result << "Difference found: "
            << ((nullptr != cur_ans) ? std::to_string(cur_ans->val) : "NULL")
            << " != "
            << ((nullptr != cur_exp) ? std::to_string(cur_exp->val) : "NULL")
            << ", @" << idx;
        return result;
    }
    return ::testing::AssertionSuccess();
}

::testing::AssertionResult
IsLinkListEqual(ListNode *answer, const std::vector<int> &expect)
{
    ListNode *expect_list = nullptr;
    ::testing::AssertionResult result = ::testing::AssertionFailure();
    Vec2LinkList(expect, &expect_list);
    result = IsLinkListEqual(answer, expect_list);
    FreeLinkList(&expect_list);
    return result;
}

}
}
