#include <stdio.h>

void Swap(int* pi, int* pj)
{
	int tmp = *pi;
	*pi = *pj;
	*pj = tmp;
}

//����ǵ��˿��� �������
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int begin = left;
	int end = right;
	//keyi�����ұߣ���Ҫ����߿�ʼ��
	int keyi = end;
	int key = a[keyi];

	while (begin < end)
	{
		//��Ϊ���Ǵ�С������ 
		//����߿�ʼ�� �Ҵ�
		while (begin < end && a[begin] <= key)
			begin++;
		a[end] = a[begin];

		//���ұ߿�ʼ�� ��С
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