int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
	//����K��һ����λ��
	int num = K;
	int KSize = 0;
	while (num)
	{
		num /= 10;
		KSize++;
	}

	//�ж��ڴ�Ӧ�ô������
	int n = KSize > ASize ? KSize + 1 : ASize + 1;

	//�����ڴ�
	int* str = malloc(sizeof(int)*n);

	int KNum = 0;//ĳһλK��ֵ
	int Ai = ASize - 1;//A��������±�
	int next = 0;//��λ
	int i = 0;//str���±�
	while (K > 0 || Ai >= 0)
	{
		//����ĳһλK��ֵ
		KNum = K % 10;
		K /= 10;

		int ANum = 0;//ĳһλA��ֵ
		//����ĳһλA��ֵ
		if (Ai >= 0)
		{
			ANum = A[Ai];
			Ai--;
		}

		//�ж��Ƿ��λ
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

		//��ÿһλ��ֵ����str
		str[i] = ret;
		i++;
	}

	//���λ��λ
	if (next == 1)
	{
		str[i] = 1;
		i++;
	}

	//�������Ԫ�ظ���
	*returnSize = i;

	//����
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