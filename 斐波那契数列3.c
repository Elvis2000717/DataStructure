class Solution {
public:
	int Fibonacci(int n) {
		int f2 = 0;
		int f1 = 1;
		int f;
		if (n <= 1)
		{
			return n;
		}
		for (int i = 2; i <= n; i++)
		{
			f = f1 + f2;
			f2 = f1;
			f1 = f;
		}
		return f;
	}
};