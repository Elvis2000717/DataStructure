void ShellSort(int* a, int n)
{
	printf("原数组->", gap);
	PrintArray(a, n);

	int gap = n;//间隔
	while (gap > 1)
	{
		gap = gap / 3 + 1;//保证最后一趟一定为1
		for (int i = 0; i < n - gap; i++)
		{
			int end = 0;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}

			a[end + gap] = tmp;
		}
		printf("gap:%d->", gap);
		PrintArray(a, n);
	}
}