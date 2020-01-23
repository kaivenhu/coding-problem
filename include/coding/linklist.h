#ifndef CODING_LINKLIST_H_
#define CODING_LINKLIST_H_
#include <vector>
#include <gtest/gtest.h>


namespace coding{
namespace linklist {

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void Vec2LinkList(const std::vector<int> &vec, ListNode **head);
void FreeLinkList(ListNode **head);

void MackCycleLinkList(const std::vector<int> &vec, int pos, ListNode **head);
void FreeCycleLinkList(int size, ListNode **head);

::testing::AssertionResult
IsLinkListEqual(ListNode *answer, ListNode *expect);

::testing::AssertionResult
IsLinkListEqual(ListNode *answer, const std::vector<int> &expect);

}
}

#endif /* CODING_LINKLIST_H_ */
