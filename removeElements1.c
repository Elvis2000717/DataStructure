struct ListNode* removeElements(struct ListNode* head, int val){
	////�ж�����Ϊ��
	//if (head == NULL)
	//{
	//	return head;
	//}

	////������ͷ���ǰ������һ����Ϊval��ֵ
	//while (head != NULL && head->val == val)
	//{
	//	if (head->next == NULL)
	//	{
	//		head->next = NULL;
	//		head = NULL;
	//		return head;
	//	}
	//	head = head->next;

	//	if (head->next == NULL)
	//	{
	//		head = NULL;
	//		return head
	//	}
	//	head = head->next;
	//}

	//struct ListNode* a = head;
	//struct ListNode* b = head;
	//struct ListNode* c = NULL;
	
	
	
	
	if (head == NULL)
	{
		return head;
	}
	
	struct ListNode* newhead = NULL;
	struct ListNode* tail = NULL;
	struct ListNode* cur = head;

	while (cur)
	{
		struct ListNode* next = cur->next;
		if (cur->val != val)
		{
			if (newhead == NULL)
			{
				newhead = tail = cur;
			}
			else
			{
				tail->next = cur;
				tail = cur;
			}
		}
		else
		{
			free(cur);
		}

		cur = next;
	}

	if (tail)
	{
		tail->next = NULL;
	}

	return newhead;
}