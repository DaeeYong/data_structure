#include<cstdio>
#include<cstdlib>
#include"Table.h"
#include"DLinkedList.h"

void TBLInit(Table* pt, HashFunc f)
{
	for (int i = 0; i < MAX_TBL; i++)
	{
		ListInit(&(pt->tbl[i]));
	}
	pt->hf = f;
}
void TBLInsert(Table* pt, Key k, Value v)
{
	int hv = pt->hf(k);
	Slot newSlot = { k,v };

	if (TBLSearch(pt, k) != NULL)
	{
		printf("duplicated! error! \n");
		return;
	}
	else {
		FInsert(&(pt->tbl[hv]), newSlot);
	}
}
Value TBLDelete(Table* pt, Key k)
{
	int hv = pt->hf(k);
	Slot cSlot;

	if (LFirst(&(pt->tbl[hv]), &cSlot))
	{
		if (cSlot.key == k)
		{
			LRemove(&(pt->tbl[hv]));
			return cSlot.val;
		}
		else
		{
			while (LNext(&(pt->tbl[hv]), &cSlot))
			{
				if (cSlot.key == k)
				{
					LRemove(&(pt->tbl[hv]));
					return cSlot.val;
				}
			}
		}
	}
	return NULL;
}
Value TBLSearch(Table* pt, Key k)
{
	int hv = pt->hf(k);
	Slot cSlot;

	if (LFirst(&(pt->tbl[hv]), &cSlot)) {
		if (cSlot.key == k)
			return cSlot.val;
	}
	else {
		while (LNext(&(pt->tbl[hv]), &cSlot)) {
			if (cSlot.key == k)
				return cSlot.val;
		}
	}
	return NULL;
}
