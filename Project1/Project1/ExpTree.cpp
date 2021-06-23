#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<ctype.h>
//#include"LStack.h"
#include"ExpTree.h"
void ShowNodeData(int data)
{
	if (0 <= data && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);
}
BTreeNode* MakeExpTree(const char exp[])
{
	Stack stack;
	SInit(&stack);

	BTreeNode* pnode;
	int ExpLen = strlen(exp);
	for (int i = 0; i < ExpLen; i++)
	{
		pnode = MakeBTreeNode();

		if (isdigit(exp[i]))
		{
			SetData(pnode, exp[i] - '0');
		}
		else
		{
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}
		SPush(&stack, pnode);
	}
	return SPop(&stack);
}
void ShowPrefixTypeExp(BTreeNode* bt)
{
	PreorderTraverse(bt, ShowNodeData);
}
void ShowInfixTypeExp(BTreeNode* bt)
{
	InorderTraverse(bt, ShowNodeData);
}
void ShowPostfixtypeExp(BTreeNode* bt)
{
	PostorderTraverse(bt, ShowNodeData);
}
int EvaluateTree(BTreeNode* bt);

