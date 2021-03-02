class Solution {
public:
	int jumpFloor(int number) {
		int f1 = 1;
		int f2 = 2;
		int f;
		if (number == 0)
		{
			return 0;
		}
		if (number == 1)
		{
			return f1;
		}
		if (number == 2)
		{
			return f2;
		}
		for (int i = 3; i <= number; i++)
		{
			f = f1 + f2;
			f1 = f2;
			f2 = f;
		}
		return f;
	}
};