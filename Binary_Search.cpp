#include<stdio.h>

int BSearch(int arr[], int len, int target);

int main() {

	//test field
	int arr[] = {1,3,5,7,9};
	int idx;

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 2);
	if (idx == -1) printf("search failed\n");
	else
		printf("target index : %d\n", idx);

	return 0;
}

int BSearch(int arr[], int len, int target) {

	int first=0;
	int last=len-1;
	int mid;

	while (first <= last) {

		mid = (first + last) / 2;

		if (target == arr[mid]) return mid;
		
		else {
			if (target < arr[mid]) last = mid;
			else first = mid;
		}
	}
	return -1;
}