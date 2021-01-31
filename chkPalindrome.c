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

		//struct ListNode* head;
		//head = slow;
		//struct ListNode* tail = head->next;//a
		//struct ListNode* cur = head->next;//c

		//while (tail)
		//{
		//	cur = cur->next;
		//	tail->next = head;
		//	head = tail;
		//	tail = cur;
		//}
		//

		//tail = head;
		//cur = A;
		struct ListNode* part1 = A, *part2 = reverseList(slow);

		/*while (tail && cur)
		{
			if (tail->val != cur->val)
			{
				return false;
			}
			tail = tail->next;
			cur = cur->next;
		}
		return true;*/
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