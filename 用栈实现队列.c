typedef int SLDataType;
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

typedef struct {
	Stack popST;
	Stack pushST;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->pushST);
	StackInit(&q->popST);

	return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	//1.如果为空
	//2.如果不为空
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	int top = StackTop(&obj->popST);
	StackPop(&obj->popST);

	return top;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}

	return StackTop(&obj->popST);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
}

void myQueueFree(MyQueue* obj) {
	StackDestory(&obj->pushST);
	StackDestory(&obj->popST);

	free(obj);
	//置空也不会把实参置空，无意义
}