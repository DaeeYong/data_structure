#include<cstdio>
#include<stdlib.h>
#include"Person.h"
#include"Table.h"


int MyHashFunc(int k)
{
	return k % 100;
}

int main()
{
	Table mytbl;
	Person* np;
	Person* sp;
	Person* rp;	

	TBLInit(&mytbl, MyHashFunc);

	//Input Data
	np = MakePersonData(20120003, "lee", "seoul");
	TBLInsert(&mytbl, GetSSN(np), np);

	np = MakePersonData(20130012, "kim", "newyork");
	TBLInsert(&mytbl, GetSSN(np), np);

	np = MakePersonData(20170049, "han", "busan");
	TBLInsert(&mytbl, GetSSN(np), np);

	//Search Data section
	sp = TBLSearch(&mytbl, 20120003);
	if (sp != NULL) ShowPerInfo(sp);

	sp = TBLSearch(&mytbl, 20130012);
	if (sp != NULL) ShowPerInfo(sp);

	sp = TBLSearch(&mytbl, 20170049);
	if (sp != NULL) ShowPerInfo(sp);

	//Remove Data
	rp = TBLDelete(&mytbl, 20120003);
	if (rp != NULL) delete rp;

	rp = TBLDelete(&mytbl, 20120012);
	if (rp != NULL) delete rp;

	rp = TBLDelete(&mytbl, 20120049);
	if (rp != NULL) delete rp;

	return 0;
}

