#ifndef _SEQLIST_H_
#define _SQLIST_H_

#include "common.h"

#define SEQLIST_DEFAULT_SIZE 8

//定义顺序表的结构
typedef struct SeqList
{
	ElemType *base;
	size_t capacity;
	size_t size;
}SeqList;

void SeqListInit(SeqList *plist);
void SeqListDestroy(SeqList *plist);
void SeqListPushBack(SeqList *plist, ElemType x);
void SeqListPushFront(SeqList *plist, ElemType x);
void SeqListShow(SeqList *plist);
size_t SeqListLength(SeqList *plist);

void SeqListPopBack(SeqList *plist);
void SeqListClear(SeqList *plist);
bool SeqListInsertByPos(SeqList *plist, int pos, ElemType x);
void SeqListSort(SeqList *plist);
///////////////////////////////////////////////////////////////////////
bool IsFull(SeqList *plist)
{
	//断言结构体不能为空，如果结构体为空，那么表也就不存在
	assert(plist != NULL);
	return plist->size >= plist->capacity;
}

bool IsEmpty(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size == 0;
}

void SeqListInit(SeqList *plist)
{
	plist->capacity = SEQLIST_DEFAULT_SIZE;
	plist->base = (ElemType*)malloc(sizeof(ElemType)* plist->capacity);
	plist->size = 0;
}

void SeqListDestroy(SeqList *plist)
{
	assert(plist != NULL);
	free(plist->base);
	plist->base = NULL;
	plist->capacity = plist->size = 0;
}

void SeqListPushBack(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist))
	{
		printf("顺序表已满，%d不能尾部插入.\n", x);
		return;
	}
	plist->base[plist->size++] = x;

}

void SeqListPushFront(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	//判满
	if (IsEmpty(plist))
	{
		printf("顺序表已满，%d不能头部插入.\n", x);
		return;
	}
	//头插
	for (int i = plist->size; i > 0; i--)
	{
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[0] = x;
	plist->size++;
}

void SeqListShow(SeqList *plist)
{
	assert(plist != NULL);
	for (size_t i = 0; i < plist->size; i++)
	{
		printf("%d ", plist->base[i]);
	}
	printf("\n");
}

size_t SeqListLength(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size;
}

void SeqListPopBack(SeqList *plist)
{
	assert(plist != NULL);
	//判空
	if (IsEmpty(plist))
	{
		printf("顺序表已空，不能进行尾部删除.\n");
		return;
	}
	//只要减少元素个数我们就认为删除掉了
	plist->size--;
}

void SeqListClear(SeqList *plist)
{
	assert(plist != NULL);
	plist->size = 0;
}

bool SeqListInsertByPos(SeqList *plist, int pos, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist))
	{
		printf("顺序表溢满，%d不能在%d位置插入.\n", x, pos);
		return false;
	}
	if (pos<0 || pos>plist->size)
	{
		printf("要插入的位置%d是非法位置，%d不能插入.\n", pos, x);
		return false;
	}
	for (size_t i = plist->size; i > pos; i--)
	{
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[pos] = x;
	plist->size++;

	return true;
}

void SeqListSort(SeqList *plist)
{
	assert(plist != NULL);
	for (size_t i = 0; i < plist->size - 1; i++)
	{
		for (size_t j = 0; j < plist->size - i - 1; j++)
		{
			if (plist->base[j] > plist->base[j+1])
			{
				Swap(&plist->base[j], &plist->base[j + 1]);
			}
		}
	}
}

#endif /*_SQLIST_H_*/