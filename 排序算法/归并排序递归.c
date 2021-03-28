#include <stdio.h>

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left == right)
		return;

	//int mid = (left + right) >> 1;//有溢出风险
	int mid = left + ((right - left) >> 1);

	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = begin1;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];

	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	//拷回原数组
	int j = left;
	while (j <= right)
	{
		a[j] = tmp[j];
		j++;
	}
}

void MergeSort(int* a, int n)
{
	int* tmp = malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

void TestMergeSort()
{
	int a[] = { 9, 4, 6, 3, 2, 7, 7, 9, 1, 4, 5 };
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
	TestMergeSort();

	return 0;
}