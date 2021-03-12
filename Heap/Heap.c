#include "Heap.h"

void HeapInit(Heap* php, HPDateType* a, int n)
{
	assert(php);
	php->a = (HPDateType)malloc(sizeof(HPDateType)*n);
	if (php->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	for (int i = 0; i < n; i++)
	{
		php->a[i] = a[i];
	}

	php->size = n;
	php->capacity = n;

}

void HeapDestory(Heap* php)
{
	assert(php);

	free(php->a);
	php->a = NULL;
	php->capacity = php->size = 0;
}

void HeapPush(Heap* php, HPDateType x)
{
	if (php->size == php->capacity)
	{
		//void* realloc (void* ptr, size_t size);
		HPDateType* tmp = realloc(php->a, (php->capacity) * 2);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
	}

	php->a[php->size] = x;
	php->size++;
}

//和最后一个元素交换，然后删除最后一个元素，把堆顶元素向下调整
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->size > 0);

	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	//指针 堆的大小 根节点的下标
	AdjustDown(php->a, php->size, 0);
}

int HeapSize(Heap* php)
{
	assert(php);
	return php->size;
}

int HeapEmpty(Heap* php)
{
	assert(php);
	return php->size == 0 ? 1 : 0;
}

HPDateType HeapTop(Heap* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//n是大小 size
//root是根节点的下标
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;

	while (child < n)
	{
		//在不完全二叉树中，最后一个节点是其父节点的左孩子，用来判断是否有右孩子
		//child指向左右孩子中最小的那个
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			Swap(a[child], a[parent]);

			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}