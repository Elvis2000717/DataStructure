typedef char SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int top;
	int capacity;
}Stack;

//栈的初始化
void StackInit(Stack* pst);
//栈的销毁
void StackDestory(Stack* pst);
//增加栈顶元素
void StackPush(Stack* pst, SLDataType x);
//移除栈顶元素
void StackPop(Stack* pst);
//返回栈中元素的数目
int StackSize(Stack* pst);
//返回栈顶元素
SLDataType StackTop(Stack* pst);
//栈内判空
int StackEmpty(Stack* pst);

//栈的初始化
void StackInit(Stack* pst)
{
	assert(pst);

	pst->a = (SLDataType*)malloc(sizeof(SLDataType)* 4);
	pst->top = 0;
	pst->capacity = 4;
}

//栈的销毁
void StackDestory(Stack* pst)
{
	assert(pst);

	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}

//增加栈顶元素
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

//移除栈顶元素
void StackPop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));

	pst->top--;
}

//返回栈中元素的数目
int StackSize(Stack* pst)
{
	assert(pst);

	return pst->top;
}

//返回栈顶元素
SLDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));
	return pst->a[pst->top - 1];
}

//栈内判空
int StackEmpty(Stack* pst)
{
	assert(pst);

	return pst->top == 0 ? 1 : 0;
}

bool isValid(char * s)
{
	Stack st;
	StackInit(&st);
	while (*s)
	{
		if (*s == '[' || *s == '(' || *s == '{')
		{
			StackPush(&st, *s);
			++s;
		}
		else
		{
			if (StackEmpty(&st))
			{
				return false;
			}
			char top = StackTop(&st);
			StackPop(&st);
			if (*s == ']' && top != '[')
			{
				StackDestory(&st);
				return false;
			}

			if (*s == '}' && top != '{')
			{
				StackDestory(&st);
				return false;
			}

			if (*s == ')' && top != '(')
			{
				StackDestory(&st);
				return false;
			}

			++s;
		}
	}

	if (StackEmpty(&st))
	{
		StackDestory(&st);
		return true;
	}

	StackDestory(&st);
	return false;
}