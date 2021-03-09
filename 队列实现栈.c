typedef int QDataType;
//��ʽ�ṹ����ʾ����
typedef struct QueueNode
{
	QDataType data;
	struct QListNode* next;
}QueueNode;

//���еĽṹ
typedef struct Queue
{
	QueueNode* front;
	QueueNode* rear;
}Queue;

//���еĳ�ʼ��
void QueueInit(Queue* pq);

//��Ӳ���
void QueuePush(Queue* pq, QDataType data);

//���Ӳ���
void QueuePop(Queue* pq);

//��ȡ����ͷԪ��
QDataType QueueFront(Queue* pq);

//��ȡ����βԪ��
QDataType QueueBack(Queue* pq);

//��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* pq);

//�����п�
int QueueEmpty(Queue* pq);

//��������
void QueueDestory(Queue* pq);

//���еĳ�ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->front = pq->rear = NULL;
}

//��Ӳ���
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

//���Ӳ���
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	//1.ֻ��һ���ڵ�
	//2.�ж���ڵ�
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

//��ȡ����ͷԪ��
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->front->data;
}

//��ȡ����βԪ��
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->rear->data;
}

//��ȡ��������ЧԪ�ظ���
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

//�����п�
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->front == NULL ? 1 : 0;
}

//��������
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
	//���q1��Ϊ�գ����ǾͿ�����q1�н��в���
	//���q1Ϊ�գ����Ǿ�Ĭ����q2�������ݣ�������q2�н��в��룬��ʵ�������q2��һ�������ݣ�������б����Ϊ��
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
	
	//����ָ��emptyQ��Զָ��յ��Ǹ�����
	//��nonemptyQָ��ǿյ��Ǹ�����
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

	//�ҵ��Ǹ����Ƴ���Ԫ��
	int top = QueueFront(nonemptyQ);
	//ͷɾ�����Ǹ�Ԫ��ɾ��
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