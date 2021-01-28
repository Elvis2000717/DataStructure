struct ListNode* middleNode(struct ListNode* head){
	if (head == NULL)
	{
		return head;
	}
	struct ListNode* a = head;
	struct ListNode* b = head;
	while (1)
	{
		if (a->next != NULL)
		{
			a = a->next;
			b = b->next;
		}
		else
		{
			return b;
		}
		if (a->next != NULL)
		{
			a = a->next;
		}
		else
		{
			return b;
		}
	}
}