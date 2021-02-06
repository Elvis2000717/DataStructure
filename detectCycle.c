struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode * fast = head;
	struct ListNode * slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			struct ListNode* slowHead = head;
			while (slow != slowHead)
			{
				slow = slow->next;
				slowHead = slowHead->next;
			}
			return slow;
		}
	}

	return NULL;
}