bool hasCycle(struct ListNode *head) {
	struct ListNode *fast = head, *slow = head;
	while (fast != NULL && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return true;
		}
	}
	return false;
}