struct Node* copyRandomList(struct Node* head) {
	struct Node* cur = head;
	struct Node* next = cur;

	while (cur)
	{
		next = cur->next;
		struct Node* node = (struct Node*)malloc(sizeof(struct Node));
		node->val = cur->val;
		cur->next = node;
		node->next = next;
		cur = next;
	}

	cur = head;
	while (cur)
	{
		if (cur->random == NULL)
		{
			cur->next->random = NULL;
		}
		else
		{
			cur->next->random = cur->random->next;
		}
		cur = cur->next->next;
	}

	cur = head;
	struct Node* newhead = NULL;
	struct Node* newtail = NULL;
	while (cur)
	{
		struct Node* copy = cur->next;
		struct Node* next = copy->next;
		if (newhead == NULL)
		{
			newhead = newtail = copy;
		}
		else
		{
			newtail->next = copy;
			newtail = copy;
		}
		cur->next = next;
		cur = next;
	}


	return newhead;
}