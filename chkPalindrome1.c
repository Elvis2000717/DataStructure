class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		struct ListNode* fast, *slow;
		fast = slow = A;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		struct ListNode* part1 = A, *part2 = reverseList(slow);

		while (part1 && part2)
		{
			if (part1->val != part2->val)
			{
				return false;
			}
			part1 = part1->next;
			part2 = part2->next;
		}
		return true;
	}
	struct ListNode* reverseList(struct ListNode* head){
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		struct ListNode* a = head->next;
		struct ListNode* b = head;
		struct ListNode* c = a;

		b->next = NULL;
		while (a != NULL)
		{
			c = c->next;
			a->next = b;
			b = a;
			a = c;
		}
		return b;
	}
};