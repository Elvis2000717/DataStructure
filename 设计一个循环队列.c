typedef struct {
	int* a;
	int front;
	int rear;
	int k;
} MyCircularQueue;

bool myCircularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	//多开一个空间区分空和满的区别
	q->a = (int*)malloc(sizeof(int)*(k + 1));
	q->front = q->rear = 0;
	q->k = k;

	return q;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}
	obj->a[obj->rear] = value;
	++obj->rear;
	if (obj->rear == obj->k + 1)
	{
		obj->rear = 0;
	}
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}
	++obj->front;
	if (obj->front == obj->k + 1)
	{
		obj->front = 0;
	}

	return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	else
	{
		return obj->a[obj->front];
	}
}

int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	int prev = obj->rear - 1;
	if (obj->rear == 0)
	{
		prev = obj->k;
	}
	return obj->a[prev];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
	int next = obj->rear + 1;
	if (next == obj->k+1)
	{
		next = 0;
	}
	if (next == obj->front)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->a);
	free(obj);
}

/**
* Your MyCircularQueue struct will be instantiated and called as such:
* MyCircularQueue* obj = myCircularQueueCreate(k);
* bool param_1 = myCircularQueueEnQueue(obj, value);

* bool param_2 = myCircularQueueDeQueue(obj);

* int param_3 = myCircularQueueFront(obj);

* int param_4 = myCircularQueueRear(obj);

* bool param_5 = myCircularQueueIsEmpty(obj);

* bool param_6 = myCircularQueueIsFull(obj);

* myCircularQueueFree(obj);
*/