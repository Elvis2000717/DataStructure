#include "Stack.h"

//ջ�ĳ�ʼ��
void StackInit(Stack* pst)
{
	assert(pst);

	pst->a = (SLDataType*)malloc(sizeof(SLDataType)* 4);
	pst->top = 0;
	pst->capacity = 4;
}

//ջ������
void StackDestory(Stack* pst)
{
	assert(pst);

	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}

//����ջ��Ԫ��
void StackPush(Stack* pst, SLDataType x)
{
	assert(pst);

	if (pst->top == pst->capacity)
	{
		SLDataType* tmp = realloc(pst->a, pst->capacity * 2 * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("relloc fail\n");
			exit(-1);
		}
		pst->a = tmp;
		pst->capacity *= 2;
	}
	pst->a[pst->top] = x;
	pst->top++;
}

//�Ƴ�ջ��Ԫ��
void StackPop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));

	pst->top--;
}

//����ջ��Ԫ�ص���Ŀ
int StackSize(Stack* pst)
{
	assert(pst);

	return pst->top;
}

//����ջ��Ԫ��
SLDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));
	return pst->a[pst->top - 1];
}

//ջ���п�
int StackEmpty(Stack* pst)
{
	assert(pst);

	return pst->top == 0 ? 1 : 0;
}