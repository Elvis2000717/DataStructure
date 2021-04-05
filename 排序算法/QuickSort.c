#include <stdio.h>

void Swap(int* pi, int* pj)
{
	int tmp = *pi;
	*pi = *pj;
	*pj = tmp;
}

//����ǵ��˿��� �������
void QuickSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	//keyi�����ұߣ���Ҫ����߿�ʼ��
	int keyi = end;

	while (begin < end)
	{
		//��Ϊ���Ǵ�С������ 
		//����߿�ʼ�� �Ҵ�
		while (begin < end && a[begin] <= a[keyi])
		{
			begin++;
		}

		//���ұ߿�ʼ�� ��С
		while (begin < end && a[end] >= a[keyi])
		{
			end--;
		}

		//�ҵ��� ��ĺ�С�Ľ���
		//û�ҵ� ��Ϊbegin��endָ��һ�� ����Ҳ��Ӱ��
		Swap(&a[begin], &a[end]);
	}
	//��a[keyi]����������м䣬��߱�a[keyi]С���ұ߱�a[keyi]��
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