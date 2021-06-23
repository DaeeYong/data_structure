#include<stdio.h>
#include"UHeap.h"

int DataPriorityComp(char ch1, char ch2)
{
	return ch2 - ch1;
	//return ch1 - ch2;
}
int main(void)
{
	Heap heap;
	HeapInit(&heap, DataPriorityComp);

	HInsert(&heap, 'E'); HInsert(&heap, 'A');
	HInsert(&heap, 'F'); HInsert(&heap, 'L');
	HInsert(&heap, 'D'); HInsert(&heap, 'H');
	while (!HIsEmpty(&heap))
	{
		printf("%c \n", HDelete(&heap));
	}
	return 0;
}