void Reverse(int left, int right, int* nums)
{
	//逆置函数
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
	//如果元素数小于旋转数，说明旋转大于一圈
	if (numsSize <= k)
	{
		k %= numsSize;
	}
	//三段逆置
	Reverse(0, numsSize - k - 1, nums);
	Reverse(numsSize - k, numsSize - 1, nums);
	Reverse(0, numsSize - 1, nums);
}