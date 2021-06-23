#include<stdio.h>
#include "SimpleSort.h"

void BubbleSort(int arr[], int n)
{
	int temp;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (n - i) - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void SelectSort(int arr[], int n)
{
	int minIdx;
	int temp;
	for (int i = 0; i < n - 1; i++) {
		minIdx = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIdx])
				minIdx = j;
		}
		temp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = temp;
	}
}
void InsertSort(int arr[], int n)
{
	int j;
	int insData;

	for (int i = 1; i < n; i++)
	{
		insData = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > insData)
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = insData;
	}
}

void HeapSort(int arr[], int n, PriorityComp pc)
{
	Heap heap;
	HeapInit(&heap, pc);

	for (int i = 0; i < n; i++)
		HInsert(&heap, arr[i]);

	for (int i = 0; i < n; i++)
		arr[i] = HDelete(&heap);

}