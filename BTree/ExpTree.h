#ifndef __EXP_TREE_H__
#define __EXP_TREE_H__

#include "BTree.h"
#include"LStack.h"

BTreeNode* MakeExpTree(const char exp[]);
int EvaluateTree(BTreeNode* bt);
void ShowPrefixTypeExp(BTreeNode* bt);
void ShowInfixTypeExp(BTreeNode* bt);
void ShowPostfixtypeExp(BTreeNode* bt);
#endif
