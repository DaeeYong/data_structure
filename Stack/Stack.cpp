#include<stdlib.h>
#include<cstring>
#include<iostream>

using namespace std;

//연결리스트로 stack 구현

typedef struct _node
{
	int data;
	struct _node* next = NULL;
}Node;

typedef struct _stack
{
	Node* head = NULL;
	int numOfData = 0; //stack에 존재하는 data의 수 표시

}Stack;

//push 함수
void push(Stack* pstack, int data)
{
	if (pstack->head == NULL) //stack이 비어있는 경우
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->next = NULL;
		pstack->head = newNode;
		pstack->head->data = data;
		(pstack->numOfData)++;
	}
	else //stack이 비어있지 않는 경우에 head부분에 새로운 노드 추가
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->next = NULL;
		newNode->data = data;
		newNode->next = pstack->head;
		pstack->head = newNode;
		(pstack->numOfData)++;
	}
}

//pop연산
int pop(Stack* pstack)
{
	Node* removeNode;
	int removeData;

	//stack이  비어있는 경우 -1을 반환
	if (pstack->head == NULL) return -1;

	removeNode = pstack->head; //삭제할 노드 
	removeData = pstack->head->data; //삭제할 노드의 데이터
	pstack->head = pstack->head->next; //삭제할 노드의 그 다음 노드를 head가 가리킴.

	free(removeNode); //할당해제
	(pstack->numOfData)--; //data의 개수 하나 감소
	return removeData;
}

//stack의 size 반환
int size(Stack* pstack)
{
	return pstack->numOfData;
}


//stack이 비어있는지 유무 확인
int empty(Stack* pstack)
{
	if (pstack->head == NULL) return 1; //비어있다면 1 반환
	else return 0; //비어있지 않다면 0 반환
}

//stack의 제일 위에 있는 data 반환
int top(Stack* pstack)
{
	if (pstack->head == NULL) return -1; //반환할 data가 없다면 -1 리턴
	else return pstack->head->data;
}

int main()
{
	Stack stack;
	stack.head = NULL; //stack의 head를 NULL로 초기화
	
	push(&stack, 1); //1을 push
	push(&stack, 2); //2를 push
	push(&stack, 3); //3을 push

	
	printf("%d \n",pop(&stack));  //3이 나옴 
	printf("%d \n",pop(&stack));  //2가 나옴
	printf("%d \n",pop(&stack));  //1이 나옴


	//혹시나 모를 메모리 누수를 막기 위해서 확실하게 할당 해제
	while (!(stack.head == NULL))
	{
		Node* remove = NULL;
		remove = stack.head;
		stack.head = stack.head->next;
		free(remove);
	}
	return 0;
}
