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

void SListInit();
void SListPushBack();
void SListPushFront();
///////////////////////////////////////////////////////////////////////////


#endif