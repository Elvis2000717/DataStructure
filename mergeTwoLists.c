struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	struct ListNode* p1 = l1;
	struct ListNode* p2 = l2;
	if (p1 == NULL && p2 == NULL)
	{
		return NULL;
	}
	if (p1 == NULL)
	{
		return p2;
	}
	if (p1 == NULL || p2 == NULL)
	{
		return p1;
	}

	struct ListNode* head;
	struct ListNode* tail;

	if (p1->val <= p2->val)
	{
		head = p1;
		tail = p1;
		p1 = p1->next;
	}
	else
	{
		head = p2;
		tail = p2;
		p2 = p2->next;
	}

	while (p1 != NULL && p2 != NULL)
	{

		if (p1->val <= p2->val)
		{
			tail->next = p1;
			tail = tail->next;
			p1 = p1->next;
		}
		else
		{
			tail->next = p2;
			tail = tail->next;
			p2 = p2->next;
		}
	}

	if (p1 == NULL)
	{
		tail->next = p2;
	}
	else
	{
		tail->next = p1;
	}

	return head;
}