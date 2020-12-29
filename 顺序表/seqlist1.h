#ifndef _SEQLIST_H_
#define _SQLIST_H_

#include "common.h"

#define SEQLIST_DEFAULT_SIZE 8

//����˳���Ľṹ
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
void SeqListPopFront(SeqList *plist);
void SeqListClear(SeqList *plist);
bool SeqListInsertByPos(SeqList *plist, int pos, ElemType x);
void SeqListSort(SeqList *plist);
size_t SeqListCapacity(SeqList *plist);
void SeqListInsertByVal(SeqList *plist, ElemType x);
void SeqListErasePos(SeqList *plist, int pos);

int SeqListFind(SeqList *plist, ElemType key);
void SeqListEraseVal(SeqList *plist, ElemType key);
void SeqListReverse(SeqList *plist);
///////////////////////////////////////////////////////////////////////
bool IsFull(SeqList *plist)
{
	//���Խṹ�岻��Ϊ�գ�����ṹ��Ϊ�գ���ô��Ҳ�Ͳ�����
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
		printf("˳���������%d����β������.\n", x);
		return;
	}
	plist->base[plist->size++] = x;

}

void SeqListPushFront(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	//����
	if (IsEmpty(plist))
	{
		printf("˳���������%d����ͷ������.\n", x);
		return;
	}
	//ͷ��
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
	//�п�
	if (IsEmpty(plist))
	{
		printf("˳����ѿգ����ܽ���β��ɾ��.\n");
		return;
	}
	//ֻҪ����Ԫ�ظ������Ǿ���Ϊɾ������
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
		printf("˳���������%d������%dλ�ò���.\n", x, pos);
		return false;
	}
	if (pos<0 || pos>plist->size)
	{
		printf("Ҫ�����λ��%d�ǷǷ�λ�ã�%d���ܲ���.\n", pos, x);
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

size_t SeqListCapacity(SeqList *plist)
{
	assert(plist != NULL);
	return plist->capacity;
}

void SeqListPopFront(SeqList *plist)
{
	assert(plist != NULL);
	//�п�
	if (IsEmpty(plist))
	{
		printf("˳����ѿգ����ܽ���ͷ��ɾ��.\n");
		return;
	}

	for (size_t i = 0; i < plist->size; i++)
	{
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
}

void SeqListInsertByVal(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist))
	{
		printf("˳���������%d���ܱ�����.\n", x);
		return;
	}
#if 0
	size_t pos = 0;
	//���Ҳ����λ��
	while (pos < plist->size && x > plist->base[pos])
	{
		pos++;
	}
	for (size_t i = plist->size; i > pos; i--)
	{
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[pos] = x;

	plist->size++;
#endif

	size_t end = plist->size - 1;
	while (end >= 0 && x<plist->base[end])
	{
		plist->base[end + 1] = plist->base[end];
		end--;
	}
	plist->base[end+1] = x;
	plist->size++;
}

void SeqListErasePos(SeqList *plist, int pos)
{
	assert(plist != NULL);
	if (IsFull(plist))
	{
		printf("˳���������������%dλ��ɾ������.\n", pos);
		return;
	}

	//�ж�λ���Ƿ�Ϸ�
	if (pos < 0 && pos >= plist->size)
	{
		printf("ɾ����λ�÷Ƿ�������ɾ������.\n");
		return;
	}

	for (size_t i = pos; i < plist->size; i++)
	{
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
}

int SeqListFind(SeqList *plist, ElemType key)
{
	assert(plist != NULL);
	int pos = 0;
	while (pos<plist->size && key != plist->base[pos])
	{
		pos++;
	}
	if (pos == plist->size)
	{
		pos = -1;
	}
	return pos;
}

void SeqListEraseVal(SeqList *plist, ElemType key)
{
	assert(plist != NULL);
	int pos = SeqListFind(plist, key);
	if (pos == -1)
	{
		return;
	}
	SeqListErasePos(plist, pos);
}

void SeqListReverse(SeqList *plist)
{
	assert(plist != NULL);
	if (plist->size == 1)
		return;
	int start = 0, end = plist->size - 1;
	while (start < end)
	{
		Swap(&plist->base[start], &plist->base[end]);
		start++;
		end--;
	}
}

#endif /*_SQLIST_H_*/