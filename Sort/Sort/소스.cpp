#include<stdio.h>
#include"SimpleSort.h"
#include"UHeap.h"

int Pricomp(int n1, int n2)
{
	return n2 - n1;
//	return n1 - n2;
}

int main()
{
	int arr[6] = { 4,5,6,2,1,8 };
	int i;
	
	HeapSort(arr, sizeof(arr) / sizeof(int), Pricomp);

	for (i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
