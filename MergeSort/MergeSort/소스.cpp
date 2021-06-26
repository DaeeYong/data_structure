#include<stdio.h>
#include<stdlib.h>

void MergeSort(int arr[], int left, int right);
void MergeSortArea(int arr[], int left, int mid, int right);

int main(void)
{
	int arr[7] = { 3,2,4,1,7,6,5 };
	
	int arrIdxSize = sizeof(arr) / sizeof(int) - 1;
	MergeSort(arr, 0, arrIdxSize);

	for (int i = 0; i < arrIdxSize; i++)
	{
		printf("%d ", arr[i]);
	}
	fputc('\n',stdout);
	return 0;
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeSortArea(arr, left, mid, right);
	}
}

void MergeSortArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;
	int i;

	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));
	int sIdx = left;
	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx] <= arr[rIdx])
		{
			sortArr[sIdx] = arr[fIdx++];
		}
		else
		{
			sortArr[sIdx] = arr[rIdx++];
		}
		sIdx += 1;
	}
	if (fIdx > mid)
	{
		for (int i = rIdx; i <= right; i++,sIdx++)
		{
			sortArr[sIdx] = arr[i];

		}
	}
	else
	{
		for (int i = fIdx; i <= mid; i++,sIdx++)
		{
			sortArr[sIdx] = arr[i];
		}
	}

	for (int i = left; i != right+1; i++)
	{
		arr[i] = sortArr[i];
	}
	free(sortArr);
}