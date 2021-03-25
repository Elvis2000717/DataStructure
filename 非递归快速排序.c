void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);

		int prev = begin - 1;
		int cur = begin;

		//实行三数取中的优化
		int mid = GetMidIndex(a, begin, end);
		Swap(&a[mid], &a[end]);
		int keyi = end;

		while (cur != keyi)
		{
			if (a[cur] < a[keyi] && ++prev != cur)
			{
				Swap(&a[cur], &a[prev]);
			}
			cur++;
		}
		Swap(&a[++prev], &a[keyi]);
		keyi = prev;

		//[begin,keyi-1]keyi[keyi+1,end]
		if (keyi + 1 < end)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, end);
		}
		if (begin < keyi - 1)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, begin);
		}
	}

	StackDestory(&st);
}