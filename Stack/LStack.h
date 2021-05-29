#ifndef __LSTACK__H_
#define __LSTACK__H_
#include "BTree.h"
#define TRUE 1
#define FALSE 0

#define STACK_LEN 100
typedef BTreeNode* Data;

typedef struct _node
{
	Data data;
	struct _node* next;
}Node;

typedef struct _stack
{
	Node* head;
}Stack;

void SInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

#endif
