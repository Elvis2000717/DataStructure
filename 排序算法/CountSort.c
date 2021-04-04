#include <stdio.h>

void CountSort(int* a, int n)
{
	int min = a[0];
	int max = a[0];
	//找到数组的最大最小值确定取值范围
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	//计算取值范围 开辟空间的大小
	int range = max - min + 1;
	//开辟一个空间 大小为range
	int* countArr = (int*)malloc(sizeof(int)*range);
	//数组初始化 全部从0开始
	memset(countArr, 0, sizeof(int)*range);

	//统计元素出现的次数
	for (int i = 0; i < n; i++)
	{
		countArr[a[i] - min]++;
	}

	//排序
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		while (countArr[i]--)
		{
			a[k++] = i + min;
		}
	}
}

void PrintSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 6, 4, 3, 9, 6, 4, 3, 1, 2, 0 };
	CountSort(arr, sizeof(arr) / sizeof(int));
	PrintSort(arr, sizeof(arr) / sizeof(int));

	return 0;
}