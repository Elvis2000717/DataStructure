#include <stdio.h>

void Swap(int* pi, int* pj)
{
	int tmp = *pi;
	*pi = *pj;
	*pj = tmp;
}

//这个是单趟快排 方便理解
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int begin = left;
	int end = right;
	//keyi定在右边，需要从左边开始找
	int keyi = end;
	int key = a[keyi];

	while (begin < end)
	{
		//因为我们从小往大排 
		//从左边开始找 找大
		while (begin < end && a[begin] <= key)
			begin++;
		a[end] = a[begin];

		//从右边开始找 找小
		while (begin < end && a[end] >= key)
			end--;
		a[begin] = a[end];

	}
	a[end] = key;

	QuickSort(a, left, end - 1);
	QuickSort(a, end + 1, right);
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
	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	PrintSort(arr, sizeof(arr) / sizeof(int));

	return 0;
}