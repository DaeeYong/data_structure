#ifndef __A_LIST_H_
#define __A_LIST_H_

#define LIST_LEN 100
typedef int LData;

typedef struct __ArrayList {

	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;

}ArrayList;

/*** 관련 연산들 ***/
typedef ArrayList AList;

//initialize array list
void ListInit(AList* list);

//insert data
void LInsert(AList* list, LData data);

//have to use this fuction at first before use LNext function.
// ex) LFirst->LNext->LNext
int LFirst(AList* list, LData* data);

int LNext(AList* list,LData* data);

//this function is eliminate data and return removed data
LData LRemove(AList* list);

//this function prints the element number. 
int count(AList* list);

#endif
