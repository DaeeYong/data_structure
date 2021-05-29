#include<stdio.h>
#include<stdlib.h>
#include "LQueue.h"

void QInit(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}
int QIsEmpty(Queue* pq)
{
	if (pq->front == NULL) return TRUE;
	else return FALSE;
}
void Enqueue(Queue* pq, Data data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = data;
	NewNode->next = NULL;
	if (QIsEmpty(pq))
	{
		pq->front = NewNode;
		pq->rear = NewNode;
	}
	else
	{
		pq->rear->next = NewNode;
		pq->rear = NewNode;
	}
}
Data Dequeue(Queue* pq)
{
	Node* delNode;
	Data data;
	if (QIsEmpty(pq))
	{
		printf("Queue is empty! \n");
		exit(-1);
	}
	delNode = pq->front;
	data = pq->front->data;
	pq->front = pq->front->next;

	free(delNode);
	return data;
}

Data QPeek(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue is empty! \n");
		exit(-1);
	}
	return pq->front->data;
}