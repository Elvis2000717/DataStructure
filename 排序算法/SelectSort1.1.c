#include <stdio.h>

void Swap(int* pi, int* pj)
{
	int tmp = *pi;
	*pi = *pj;
	*pj = tmp;
}

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
			if (a[i]>a[maxi])
			{
				maxi = i;
			}
		}
		Swap(&a[begin], &a[mini]);

		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}

int* sortArray(int* nums, int numsSize, int* returnSize){
	*returnSize = numsSize;
	SelectSort(nums, numsSize);
	return nums;
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
	//sortArray 是对外的接口
	//SelectSort 是选择排序的主体
	int arr[] = { 6, 4, 3, 9, 6, 4, 3, 1, 2, 0 };
	SelectSort(arr, sizeof(arr) / sizeof(int));
	PrintSort(arr, sizeof(arr) / sizeof(int));

	return 0;
}