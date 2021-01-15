#ifndef _SLIST_H_
#define _SLIST_H_

#include "common.h";
typedef struct SListNode
{
	ElemType data;
	struct SListNode *next;
}SListNode;

//不带头结点的单链表
typedef SListNode* SList;

void SListInit(SList *phead);
void SListPushBack(SList *phead, ElemType x);
void SListPushFront();
void SListShow(SList *phead);
///////////////////////////////////////////////////////////////////////////

void SListInit(SList *phead)
{
	assert(phead != NULL);
	*phead = NULL;
}

void SListPushBack(SList *phead, ElemType x)
{
	assert(phead != NULL);
	SListNode *s = (SListNode *)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;

	//链接节点
	SListNode *p = *phead;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = s;
	//if (p == NULL) // 插入的节点为第一个节点
	//{
	//	*phead = s;
	//}
	//else
	//{
	//	while (p->next != NULL)
	//	{
	//		p = p->next;
	//	}
	//	p->next = s;
	//}
}

void SListShow(SList *phead)
{
	assert(phead != NULL);
	SListNode *p = *phead;
	while (p != NULL)
	{
		printf("%d->", p->data);
	}
}

#endif