#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include"Person.h"

int GetSSN(Person* p)
{
	return p->ssn;
}
void ShowPerInfo(Person* p)
{
	printf("=======================\n");
	printf("ssn: %d \n", p->ssn);
	printf("name: %s \n", p->name);
	printf("addr: %s \n", p->addr);
	printf("=======================\n");
}
Person* MakePersonData(int ssn, const char* name, const char* addr)
{
	Person* newP = new Person;
	newP->ssn = ssn;
	strcpy(newP->name, name);
	strcpy(newP->addr, addr);
	return newP;
}