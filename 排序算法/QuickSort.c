#include <stdio.h>

void Swap(int* pi, int* pj)
{
	int tmp = *pi;
	*pi = *pj;
	*pj = tmp;
}

//这个是单趟快排 方便理解
void QuickSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	//keyi定在右边，需要从左边开始找
	int keyi = end;

	while (begin < end)
	{
		//因为我们从小往大排 
		//从左边开始找 找大
		while (begin < end && a[begin] <= a[keyi])
		{
			begin++;
		}

		//从右边开始找 找小
		while (begin < end && a[end] >= a[keyi])
		{
			end--;
		}

		//找到了 大的和小的交换
		//没找到 因为begin和end指的一样 交换也不影响
		Swap(&a[begin], &a[end]);
	}
	//把a[keyi]放在数组的中间，左边比a[keyi]小，右边比a[keyi]大
	Swap(&a[keyi], &a[begin]);

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
	int arr[] = { 6, 4, 3, 9, 6, 4, 3, 1, 2, 5 };
	QuickSort(arr, sizeof(arr) / sizeof(int));
	PrintSort(arr, sizeof(arr) / sizeof(int));

	return 0;
}