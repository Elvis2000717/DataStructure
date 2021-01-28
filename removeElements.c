struct ListNode* removeElements(struct ListNode* head, int val){
	if (head == NULL)
	{
		return head;
	}
	while (head != NULL && head->val == val)
	{
		if (head->next == NULL)
		{
			head->next = NULL;
			head = NULL;
			return head;
		}
		head = head->next;
	}

	//快
	struct ListNode* a = head->next;
	//慢
	struct ListNode* b = head;
	while (a != NULL)
	{
		//判断是否是目标值
		if (a->val == val)
		{
			struct ListNode* c = a->next;
			b->next = c;
			a->next = NULL;
			free(a);
			a = c;
		}
		else
		{
			b = a;
			a = a->next;
		}
	}
	return head;
}