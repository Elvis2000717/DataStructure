class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		ListNode* cur = pHead;
		ListNode* shead, *stail, *mshead, *mtail;
		shead = (ListNode*)malloc(sizeof(ListNode));
		stail = shead;
		mshead = (ListNode*)malloc(sizeof(ListNode));
		mtail = mshead;
		stail->next = NULL;
		mtail->next = NULL;

		while (cur)
		{
			if (cur->val < x)
			{
				stail->next = cur;
				stail = stail->next;
			}
			else
			{
				mtail->next = cur;	
				mtail = mtail->next;
			}
			cur = cur->next;
		}
		stail->next = mshead->next;
		mtail->next = NULL;
		free(mshead);
		ListNode* h = (ListNode*)malloc(sizeof(ListNode));
		h = shead->next;
		free(shead);

		return h;
	}
};