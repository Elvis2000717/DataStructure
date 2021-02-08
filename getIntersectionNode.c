struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	int lenA = 0, lenB = 0;
	struct ListNode* curA = headA;
	struct ListNode* curB = headB;

	while (curA)
	{
		curA = curA->next;
		lenA++;
	}

	while (curB)
	{
		curB = curB->next;
		lenB++;
	}

	if (curA != curB)
	{
		return NULL;
	}

	int n = abs(lenA - lenB);
	curA = headA;
	curB = headB;
	while (n--)
	{
		if (lenA > lenB)
		{
			curA = curA->next;
		}
		if (lenA < lenB)
		{
			curB = curB->next;
		}
	}

	while (curA != curB)
	{
		curA = curA->next;
		curB = curB->next;
	}

	return curA;
}