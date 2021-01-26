void Reverse(int left, int right, int* nums)
{
	//���ú���
	while (left <= right)
	{
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		left++;
		right--;
	}
}

void rotate(int* nums, int numsSize, int k){
	//���Ԫ����С����ת����˵����ת����һȦ
	if (numsSize <= k)
	{
		k %= numsSize;
	}
	//��������
	Reverse(0, numsSize - k - 1, nums);
	Reverse(numsSize - k, numsSize - 1, nums);
	Reverse(0, numsSize - 1, nums);
}