#include<stdlib.h>
#include<stdio.h>
#include"BTree.h"

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}
BTData GetData(BTreeNode* bt)
{
	return bt->data;
}
void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}
BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}
BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}
void MakeLeftSubTree(BTreeNode* root, BTreeNode* sub)
{
	if (root->left != NULL) DeleteTree(root->left);
	root->left = sub;
}
void MakeRightSubTree(BTreeNode* root, BTreeNode* sub)
{
	if (root->right != NULL) DeleteTree(root->right);
	root->right = sub;
}
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL) return;

	InorderTraverse(bt->left,action);
	action(bt->data);
	InorderTraverse(bt->right,action);
}
void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL) return;
	action(bt->data);
	PreorderTraverse(bt->left,action);
	PreorderTraverse(bt->right,action);
}
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL) return;
	PostorderTraverse(bt->left,action);
	PostorderTraverse(bt->right,action);
	action(bt->data);
}
void DeleteTree(BTreeNode* bt)
{
	if (bt == NULL) return;
	DeleteTree(bt->left);
	DeleteTree(bt->right);
	printf("delete tree data : %d \n", bt->data);
	free(bt);
}