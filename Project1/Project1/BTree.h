#ifndef _B_TREE_H__
#define _B_TREE_H__

typedef int BTData;
typedef void(*VisitFuncPtr)(BTData data);
typedef struct _BTreeNode
{
	BTData data;
	struct _BTreeNode* left;
	struct _BTreeNode* right;
}BTreeNode;

BTreeNode* MakeBTreeNode(void);
BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data);
BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* root, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* root, BTreeNode* sub);

void InorderTraverse(BTreeNode* bt,VisitFuncPtr action);
void PreorderTraverse(BTreeNode* bt,VisitFuncPtr action);
void PostorderTraverse(BTreeNode* bt,VisitFuncPtr action);

void DeleteTree(BTreeNode* bt);

#endif
