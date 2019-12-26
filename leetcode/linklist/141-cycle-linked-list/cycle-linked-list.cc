#include <iostream>

#include "cycle-linked-list.h"

using std::cout;
using std::endl;

namespace cyclelinklist {

bool Solution::hasCycle(ListNode *head)
{
    if (!head) {
        return false;
    }
    for (ListNode *quick = head->next, *slow = head;
            nullptr != quick && nullptr != quick->next;
            quick = quick->next->next, slow = slow->next) {
        if (quick == slow) {
            return true;
        }
        if (quick->next == slow) {
            return true;
        }
    }
    return false;
}


}
