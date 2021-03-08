#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int top;
	int capacity;
}Stack;

//ջ�ĳ�ʼ��
void StackInit(Stack* pst);
//ջ������
void StackDestory(Stack* pst);
//����ջ��Ԫ��
void StackPush(Stack* pst, SLDataType x);
//�Ƴ�ջ��Ԫ��
void StackPop(Stack* pst);
//����ջ��Ԫ�ص���Ŀ
int StackSize(Stack* pst);
//����ջ��Ԫ��
SLDataType StackTop(Stack* pst);
//ջ���п�
int StackEmpty(Stack* pst);
