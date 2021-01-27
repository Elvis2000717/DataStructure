#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x){
	if (0 <= x && x < 10)
	{
		return true;
	}
	if (x < 0 || x % 10 == 0)
	{
		return false;
	}

	int num = x;
	int n = 0;
	while (num)
	{
		num /= 10;
		n++;
	}

	num = x;
	int a = 0;
	if (n % 2 == 0)
	{
		while (n / 2)
		{
			a = num % 10 + a;
			num /= 10;
			n -= 2;
			a *= 10;
		}
	}
	if (n % 2 == 1)
	{
		while (n / 2 >= 1)
		{
			a = num % 10 + a;
			num /= 10;
			n -= 2;
			a *= 10;
		}
		num /= 10;
	}
	if ((a /= 10) == num)
	{
		return true;
	}

	return false;
}

int main()
{
	if (isPalindrome(-1221))
	{
		printf("true");
	}
	else
	{
		printf("false");
	}

	return 0;
}