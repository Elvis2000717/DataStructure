#include <stdio.h>

void CountSort(int* a, int n)
{
	int min = a[0];
	int max = a[0];
	//�ҵ�����������Сֵȷ��ȡֵ��Χ
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

	//����ȡֵ��Χ ���ٿռ�Ĵ�С
	int range = max - min + 1;
	//����һ���ռ� ��СΪrange
	int* countArr = (int*)malloc(sizeof(int)*range);
	//�����ʼ�� ȫ����0��ʼ
	memset(countArr, 0, sizeof(int)*range);

	//ͳ��Ԫ�س��ֵĴ���
	for (int i = 0; i < n; i++)
	{
		countArr[a[i] - min]++;
	}

	//����
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