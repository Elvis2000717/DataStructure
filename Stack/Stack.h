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

//栈的初始化
void StackInit(Stack* pst);
//栈的销毁
void StackDestory(Stack* pst);
//增加栈顶元素
void StackPush(Stack* pst, SLDataType x);
//移除栈顶元素
void StackPop(Stack* pst);
//返回栈中元素的数目
int StackSize(Stack* pst);
//返回栈顶元素
SLDataType StackTop(Stack* pst);
//栈内判空
int StackEmpty(Stack* pst);
