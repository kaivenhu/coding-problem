#include "palindrome-linked-list.h"

namespace palindrome_list {

bool Solution::isPalindrome(ListNode* head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *prevNode = nullptr;
    ListNode *nextNode = nullptr;
    ListNode *middleNode = nullptr;
    bool isPalindrome = true;
    while (nullptr != fast && nullptr != fast->next) {
        fast = fast->next->next;
        nextNode = slow->next;
        slow->next = prevNode;
        prevNode = slow;
        slow = nextNode;
    }
    middleNode = prevNode;
    prevNode = slow;
    if (nullptr != fast) {
        slow = slow->next;
    }
    while (nullptr != middleNode && nullptr != slow) {
        if (middleNode->val != slow->val) {
            isPalindrome = false;
        }
        nextNode = middleNode->next;
        middleNode->next = prevNode;
        prevNode = middleNode;
        middleNode = nextNode;
        slow = slow->next;
    }
    return isPalindrome;
}

}
