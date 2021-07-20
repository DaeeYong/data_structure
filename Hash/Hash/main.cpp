#include<stdio.h>
#include<stdlib.h>
#include "Person.h"
#include"Table.h"

int HashFunc(int k)
{
	return k % 100;
}

int main(void)
{
	Table myTbl;
	Person* np;
	Person* sp;
	Person* rp;

	TBLInit(&myTbl, HashFunc);

	np = MakePersonData(900254, "Lee", "seoul");
	TBLInsert(&myTbl, GetSSN(np), np);
	np = MakePersonData(900139, "kim", "NY");
	TBLInsert(&myTbl, GetSSN(np), np);
	np = MakePersonData(900827, "Han", "None");
	TBLInsert(&myTbl, GetSSN(np), np);


	sp = TBLSearch(&myTbl, 900139);
	if (sp != NULL)
		ShowPerInfo(sp);
	sp = TBLSearch(&myTbl, 900254);
	if (sp != NULL)
		ShowPerInfo(sp);
	sp = TBLSearch(&myTbl, 900827);
	if (sp != NULL)
		ShowPerInfo(sp);

	rp = TBLDelete(&myTbl, 900254);
	if (rp != NULL)
		free(rp);
	rp = TBLDelete(&myTbl, 900139);
	if (rp != NULL)
		free(rp);
	rp = TBLDelete(&myTbl, 900827);
	if (rp != NULL)
		free(rp);

	return 0;
}