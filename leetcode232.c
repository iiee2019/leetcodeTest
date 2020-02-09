#define MAXSIZE 100
/** Initialize your data structure here. */
struct Stack {
	int top;
	int data[MAXSIZE];
};
typedef struct Stack MyStack;
struct Queue {
	MyStack S1;
	MyStack S2;
};
typedef struct Queue MyQueue;
/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* tmpQueue = malloc(sizeof( MyQueue));
	if (!tmpQueue){
		return tmpQueue;
    }
	tmpQueue->S1.top = -1;
	tmpQueue->S2.top = -1;
	return tmpQueue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	if (obj->S1.top < MAXSIZE) {
		while (obj->S1.top!=-1)
		{
			obj->S2.data[++(obj->S2.top)] = obj->S1.data[(obj->S1.top)--];
		}
		obj->S1.data[++(obj->S1.top)] = x;
		while (obj->S2.top!=-1)
		{
			obj->S1.data[++(obj->S1.top)] = obj->S2.data[(obj->S2.top)--];
		}
	}
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	if (obj->S1.top != -1){
		return obj->S1.data[(obj->S1.top)--];
    }
    return NULL;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (obj->S1.top != -1){
		return obj->S1.data[obj->S1.top];
    }
    return NULL;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return obj->S1.top == -1;
}

void myQueueFree(MyQueue* obj) {
	
	free(obj);
}
