#include "convert-binary-number.h"

namespace binarynumber {

int Solution::getDecimalValue(ListNode *head)
{
    int val = 0;
    for (ListNode *node = head; nullptr != node; node = node->next) {
        val <<= 1;
        val |= node->val;
    }
    return val;
}


}
