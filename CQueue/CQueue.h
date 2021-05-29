#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100
typedef int Data;

typedef struct _queue
{
	int front;
	int rear;
	Data QueArr[QUE_LEN];
}CQueue;

typedef CQueue Queue;

void QInit(Queue* pq);
int QIsEmpty(Queue* pq);
void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);

#endif
