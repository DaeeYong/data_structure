#include <stdio.h>
#include "Alist.h"

void ListInit(AList* list) {

	list->curPosition = -1;
	list->numOfData = 0;

}
void LInsert(AList* list, LData data) {

	if (list->numOfData >= LIST_LEN) {
		puts("저장 불가능.");
		return;
	}
	list->arr[list->numOfData] = data;
	list->numOfData++;

}

int LFirst(AList* list, LData* data) {
	
	if (list->numOfData == 0) {
		puts("data 없음.");
			return -1;
	}
	list->curPosition = 0;
	*data = list->arr[0];
	return 1;
	}
int LNext(AList* list, LData* data) {

	if (list->curPosition >= list->numOfData)
		return -1;

	list->curPosition++;
	*data = list->arr[list->curPosition];
	

	return 1;
}

LData LRemove(AList* list) {
	LData data;
	int cur;
	int num;

	cur = list->curPosition;
	num = list->numOfData;
	data = list->arr[cur];

	for (int i = cur; i < num -1; i++) {
		list->arr[i] = list->arr[i + 1];
	}
	list->numOfData--;
	list->curPosition--;
	return data;

}
int count(AList* list) {

	return list->numOfData;
}