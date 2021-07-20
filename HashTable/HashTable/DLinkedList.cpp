#include<stdio.h>
#include<stdlib.h>
#include"DLinkedList.h"

void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}
void FInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->Data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->head->next == NULL) return FALSE;

	plist->before = plist->head;
	plist->cur = plist->before->next;

	*pdata = plist->cur->Data;
	return TRUE;
}
int LNext(List* plist, LData* pdata)
{
	if (plist->cur->next == NULL) return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->Data;
	return TRUE;
}

LData LRemove(List* plist)
{
	Node* rpos = plist->cur;
	LData rdata = rpos->Data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}
int count(List* plist)
{
	return plist->numOfData;
}

void SInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->Data = data;

	Node* pred = plist->head;

	while (pred->next != NULL && plist->comp(data, pred->next->Data) != 0)
	{
		pred = pred->next;
	}
	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;
}
void setSortRule(List* plist, Compare comp)
{
	plist->comp = comp;
}
