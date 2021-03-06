#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

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