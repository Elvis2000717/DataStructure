#include <stdio.h>

void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//childָ�����Һ�������С����һ��
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

//����
void HeadSort(int* a, int n)
{
	//�������˶�
	//����ʱ�临�Ӷ�O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	//ÿ��ѡ��ʣ���������ģ��Ӻ���ǰ��
	//O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		int tmp = a[end];
		a[end] = a[0];
		a[0] = tmp;

		//ѡ����С����
		AdjustDown(a, end, 0);
		end--;
	}
}

int main()
{
	//��������鹹���ɶ�
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	//AdjustDown(a, sizeof(a) / sizeof(int), 0);

	//���齨���㷨
	//�ӵ����ĵ�һ����Ҷ�ӽڵ��λ�ÿ�ʼ����������ʼ��
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