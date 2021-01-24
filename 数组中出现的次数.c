#include <stdio.h>

int* singleNumbers(int* nums, int numsSize, int* returnSize){
	//�õ����������Ľ��
	int s = 0;
	for (int i = 0; i < numsSize; i++)
	{
		s ^= nums[i];
	}

	//n �Ǽ�������������һλ��ͬ
	int n = 1;
	while (s & 1 != 1)
	{
		s = s >> 1;
		n++;
	}

	//��һ�����鰴λ����ı�׼
	int a = 1;
	while (n>1)
	{
		a = a << 1;
		n--;
	}

	returnSize[0] = 0;
	returnSize[1] = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (a & nums[i])
		{
			returnSize[0] ^= nums[i];
		}
		else
		{
			returnSize[1] ^= nums[i];
		}
	}

	return returnSize;
}

int main()
{
	int str[] = { 4, 1, 4, 6 };
	int arr[2];
	singleNumbers(&str, sizeof(str)/sizeof(int), &arr);
	for (int i = 0; i < 2; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}