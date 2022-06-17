#include "remove-duplicates-from-sorted-list-ii.h"

namespace remove_duplicate
{

ListNode* Solution::deleteDuplicates(ListNode* head) {
	ListNode **cur = &head;
	while (*cur) {
		ListNode *last = (*cur)->next;
		while (last && last->val == (*cur)->val) {
			ListNode *tmp = last;
			last = last->next;
			free(tmp);
		}
		if ((*cur)->next != last) {
			ListNode *tmp = *cur;
			*cur = last;
			free(tmp);
		} else {
			cur = &(*cur)->next;
		}
	}
	return head;
}

}  // namespace sorted_list
