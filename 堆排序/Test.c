#include <stdio.h>

void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//child指向左右孩子中最小的那一个
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			int tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;

			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//升序
void HeadSort(int* a, int n)
{
	//建立出了堆
	//建堆时间复杂度O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	//每次选出剩下数中最大的，从后往前放
	//O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		int tmp = a[end];
		a[end] = a[0];
		a[0] = tmp;

		//选出次小的数
		AdjustDown(a, end, 0);
		end--;
	}
}

int main()
{
	//把这个数组构建成堆
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	//AdjustDown(a, sizeof(a) / sizeof(int), 0);

	//数组建堆算法
	//从倒数的第一个非叶子节点的位置开始，从子树开始调
	int n = sizeof(a) / sizeof(int);
	/*for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}*/

	HeadSort(a, n);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}