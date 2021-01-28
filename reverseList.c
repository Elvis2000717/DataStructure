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