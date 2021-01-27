int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
	//计算K是一个几位数
	int num = K;
	int KSize = 0;
	while (num)
	{
		num /= 10;
		KSize++;
	}

	//判断内存应该创建多大
	int n = KSize > ASize ? KSize + 1 : ASize + 1;

	//创建内存
	int* str = malloc(sizeof(int)*n);

	int KNum = 0;//某一位K的值
	int Ai = ASize - 1;//A中数组的下标
	int next = 0;//进位
	int i = 0;//str的下标
	while (K > 0 || Ai >= 0)
	{
		//计算某一位K的值
		KNum = K % 10;
		K /= 10;

		int ANum = 0;//某一位A的值
		//计算某一位A的值
		if (Ai >= 0)
		{
			ANum = A[Ai];
			Ai--;
		}

		//判断是否进位
		int ret = KNum + ANum + next;
		if (ret >= 10)
		{
			ret %= 10;
			next = 1;
		}
		else
		{
			next = 0;
		}

		//将每一位的值传进str
		str[i] = ret;
		i++;
	}

	//最高位进位
	if (next == 1)
	{
		str[i] = 1;
		i++;
	}

	//控制输出元素个数
	*returnSize = i;

	//逆置
	int left = 0;
	int right = i - 1;
	while (left <= right)
	{
		int tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;
		left++;
		right--;
	}

	return str;
}