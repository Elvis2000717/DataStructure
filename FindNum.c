#include <stdio.h>

int FindNum(int str[],int len)
{
	int s = 0;

	for (int i = 0; i < len; i++)
	{
		s ^= i;
		s ^= str[i];
	}
	s ^= len;
	return s;
}

int main()
{
	int str[] = { 1, 9, 8, 7, 6, 4, 3, 2, 10 , 0};
	printf("%d", FindNum(&str, sizeof(str) / sizeof(int)));
	return 0;
}