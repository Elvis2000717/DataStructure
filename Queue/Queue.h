#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

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