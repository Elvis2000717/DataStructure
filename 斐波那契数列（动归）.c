class Solution {
public:
	int Fibonacci(int n) {
		//����
		vector<int> F(n + 1, 0);
		//��ʼ��
		F[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			F[i] = F[i - 1] + F[i - 2];
		}
		return F[n];
	}
};