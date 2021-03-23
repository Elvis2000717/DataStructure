void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;

	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		Swap(&a[begin], &a[mini]);

		//���maxi��begin�ص��ͻ�������ν���
		if (maxi == begin)
		{
			maxi = mini;
		}

		Swap(&a[end], &a[maxi]);

		begin++;
		end--;
	}
}