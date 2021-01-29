struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
	// write code here
	struct ListNode* a = pListHead;//¿ì
	struct ListNode* b = pListHead;//Âı
	if (pListHead == NULL || k == 0)
	{
		return NULL;
	}
	if (k == 1)
	{
		if (a == NULL)
		{
			return NULL;
		}
		while (a->next != NULL)
		{
			a = a->next;
		}

		return a;
	}

	while (k > 1)
	{
		if (a->next == NULL)
		{
			return NULL;
		}
		a = a->next;
		k--;
	}

	while (a->next != NULL)
	{
		a = a->next;
		b = b->next;
	}
	return b;
}