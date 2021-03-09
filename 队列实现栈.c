typedef int QDataType;
//链式结构：表示队列
typedef struct QueueNode
{
	QDataType data;
	struct QListNode* next;
}QueueNode;

//队列的结构
typedef struct Queue
{
	QueueNode* front;
	QueueNode* rear;
}Queue;

//队列的初始化
void QueueInit(Queue* pq);

//入队操作
void QueuePush(Queue* pq, QDataType data);

//出队操作
void QueuePop(Queue* pq);

//获取队列头元素
QDataType QueueFront(Queue* pq);

//获取队列尾元素
QDataType QueueBack(Queue* pq);

//获取队列中有效元素个数
int QueueSize(Queue* pq);

//队列判空
int QueueEmpty(Queue* pq);

//队列销毁
void QueueDestory(Queue* pq);

//队列的初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->front = pq->rear = NULL;
}

//入队操作
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->data = x;
	newnode->next = NULL;

	if (pq->rear == NULL)
	{
		pq->front = pq->rear = newnode;
	}
	else
	{
		pq->rear->next = newnode;
		pq->rear = newnode;
	}
}

//出队操作
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	//1.只有一个节点
	//2.有多个节点
	if (pq->front == pq->rear)
	{
		free(pq->front);
		pq->front = pq->rear = NULL;
	}
	else
	{
		QueueNode* next = pq->front->next;
		free(pq->front);
		pq->front = next;
	}
}

//获取队列头元素
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->front->data;
}

//获取队列尾元素
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->rear->data;
}

//获取队列中有效元素个数
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QueueNode* cur = pq->front;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}

//队列判空
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->front == NULL ? 1 : 0;
}

//队列销毁
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->front;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->front = pq->rear = NULL;
}

typedef struct {
	QueueNode q1;
	QueueNode q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);

	return pst;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	//如果q1不为空，我们就可以在q1中进行插入
	//如果q1为空，我们就默认在q2中有数据，可以在q2中进行插入，但实际情况中q2不一定有数据，比如队列本身就为空
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	Queue* emptyQ = &obj->q1;
	Queue* nonemptyQ = &obj->q2;
	
	//将空指针emptyQ永远指向空的那个队列
	//将nonemptyQ指向非空的那个队列
	if (!QueueEmpty(&obj->q1))
	{
		emptyQ = &obj->q2;
		nonemptyQ = &obj->q1;
	}

	while (QueueSize(nonemptyQ) > 1)
	{
		QueuePush(emptyQ, QueueFront(nonemptyQ));
		QueuePop(nonemptyQ);
	}

	//找到那个待移除的元素
	int top = QueueFront(nonemptyQ);
	//头删，把那个元素删除
	QueuePop(nonemptyQ);

	return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestory(&obj->q1);
	QueueDestory(&obj->q2);

	free(obj);
}

/**
* Your MyStack struct will be instantiated and called as such:
* MyStack* obj = myStackCreate();
* myStackPush(obj, x);

* int param_2 = myStackPop(obj);

* int param_3 = myStackTop(obj);

* bool param_4 = myStackEmpty(obj);

* myStackFree(obj);
*/