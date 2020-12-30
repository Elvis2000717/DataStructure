#include <stdio.h>
#include <stdlib.h>
#include <vld.h>

void main()
{
	int a = 0;
	int b = 1;
	int res = a && ++b; //¶ÌÂ·ÔËËã

	printf("res = %d\n", res);
	printf("b = %d\n", b);
}