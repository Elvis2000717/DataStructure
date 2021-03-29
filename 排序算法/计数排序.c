#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i]>max)
		{
			max = a[i];
		}
	}
	int range = max - min + 1;
	int* countArr = (int*)malloc(sizeof(int)*range);
	memset(countArr, 0, sizeof(int)*range);

	//统计次数
	for (int i = 0; i < n; i++)
	{
		countArr[a[i] - min]++;
	}

	//排序
	int k = 0;
	for (int j = 0; j < range; j++)
	{
		while (countArr[j]--)
		{
			a[k++] = j + min;
		}
	}
}

void TestCountSort()
{
	int a[] = { 9, 4, 6, 3, 2, 7, 7, 9, 1, 4, 5 };
	CountSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
	TestCountSort();
	return 0;
}