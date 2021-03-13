#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int HPDateType;

typedef struct Heap
{
	HPDateType* a;
	int size;
	int capacity;
}Heap;

void HeapInit(Heap* php, HPDateType* a, int n);
void HeapDestory(Heap* php);
void HeapPush(Heap* php, HPDateType x);
void HeapPop(Heap* php);
int HeapSize(Heap* php);
int HeapEmpty(Heap* php);
HPDateType HeapTop(Heap* php);

void Swap(int* p1, int* p2);
//ָ�� �ѵĴ�С ���ڵ���±�
void AdjustDown(int* a, int n, int root);