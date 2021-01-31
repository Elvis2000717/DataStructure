struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
	struct ListNode* fast = pListHead;
	struct ListNode* slow = pListHead;

	if (pListHead == NULL || k <= 0)
	{
		return NULL;
	}

	while (k > 1)
	{
		if (fast->next == NULL)
		{
			return NULL;
		}
		fast = fast->next;
		k--;
	}

	while (fast->next != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}