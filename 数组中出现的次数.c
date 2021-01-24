#include <stdio.h>

int* singleNumbers(int* nums, int numsSize, int* returnSize){
	//得到两个数异或的结果
	int s = 0;
	for (int i = 0; i < numsSize; i++)
	{
		s ^= nums[i];
	}

	//n 是计数这两个数哪一位不同
	int n = 1;
	while (s & 1 != 1)
	{
		s = s >> 1;
		n++;
	}

	//下一步数组按位分类的标准
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