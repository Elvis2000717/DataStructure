#include "Queue.h"

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