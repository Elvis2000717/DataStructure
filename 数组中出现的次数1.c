#include <stdio.h>
#include <stdlib.h>

int* singleNumbers(int* nums, int numsSize, int* returnSize){
	int *res = (int *)malloc(sizeof(int)* 2);
	*returnSize = 2;
	if (numsSize == 2){
		return nums;
	}
	int s = 0;
	for (int i = 0; i < numsSize; i++)
	{
		s ^= nums[i];
	}
	//n 是计数这两个数哪一位不同
	int n = 0;
	while ((s & 1) == 0)
	{
		s = s >> 1;
		n++;
	}
	int s1 = 0;
	int s2 = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if ((nums[i] >> n) & 1)
		{
			s1 ^= nums[i];
		}
		else
		{
			s2 ^= nums[i];
		}
	}
	res[0] = s1;
	res[1] = s2;
	return res;
}

int main()
{
	int str[] = { 4, 1, 4, 6 };
	int arr[2];
	singleNumbers(&str, sizeof(str)/sizeof(int), arr);
	for (int i = 0; i < 2; i++)
	{
		printf("%d\n", str[i]);
	}

	return 0;
}