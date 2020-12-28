#include <stdio.h>
#include <stdlib.h>
#include <vld.h>

void main()
{
	int *p = (int*)malloc(sizeof(int));
	*p = 100;
	free(p);
}