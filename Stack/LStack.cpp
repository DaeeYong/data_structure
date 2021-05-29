#include<stdlib.h>
#include<stdio.h>
#include"LStack.h"

void SInit(Stack* pstack)
{
	pstack->head = NULL;
}
int SIsEmpty(Stack* pstack)
{
	if (pstack->head == NULL) return TRUE;
	else return FALSE;
}
void SPush(Stack* pstack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pstack->head;
	pstack->head = newNode;
}
Data SPop(Stack* pstack)
{
	if (SIsEmpty(pstack)) {
		printf("Stack is empty!");
		exit(-1);
	}

	Data rdata;
	Node* rNode = pstack->head;
	rdata = pstack->head->data;
	pstack->head = pstack->head->next;
	free(rNode);
	return rdata;
}
Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack)) {
		printf("Stack is empty!");
		exit(-1);
	}
	
	return pstack->head->data;
}