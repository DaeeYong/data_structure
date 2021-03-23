#include<stdlib.h>
#include<cstring>
#include<iostream>

using namespace std;

//���Ḯ��Ʈ�� stack ����

typedef struct _node
{
	int data;
	struct _node* next = NULL;
}Node;

typedef struct _stack
{
	Node* head = NULL;
	int numOfData = 0; //stack�� �����ϴ� data�� �� ǥ��

}Stack;

//push �Լ�
void push(Stack* pstack, int data)
{
	if (pstack->head == NULL) //stack�� ����ִ� ���
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->next = NULL;
		pstack->head = newNode;
		pstack->head->data = data;
		(pstack->numOfData)++;
	}
	else //stack�� ������� �ʴ� ��쿡 head�κп� ���ο� ��� �߰�
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->next = NULL;
		newNode->data = data;
		newNode->next = pstack->head;
		pstack->head = newNode;
		(pstack->numOfData)++;
	}
}

//pop����
int pop(Stack* pstack)
{
	Node* removeNode;
	int removeData;

	//stack��  ����ִ� ��� -1�� ��ȯ
	if (pstack->head == NULL) return -1;

	removeNode = pstack->head; //������ ��� 
	removeData = pstack->head->data; //������ ����� ������
	pstack->head = pstack->head->next; //������ ����� �� ���� ��带 head�� ����Ŵ.

	free(removeNode); //�Ҵ�����
	(pstack->numOfData)--; //data�� ���� �ϳ� ����
	return removeData;
}

//stack�� size ��ȯ
int size(Stack* pstack)
{
	return pstack->numOfData;
}


//stack�� ����ִ��� ���� Ȯ��
int empty(Stack* pstack)
{
	if (pstack->head == NULL) return 1; //����ִٸ� 1 ��ȯ
	else return 0; //������� �ʴٸ� 0 ��ȯ
}

//stack�� ���� ���� �ִ� data ��ȯ
int top(Stack* pstack)
{
	if (pstack->head == NULL) return -1; //��ȯ�� data�� ���ٸ� -1 ����
	else return pstack->head->data;
}

int main()
{
	Stack stack;
	stack.head = NULL; //stack�� head�� NULL�� �ʱ�ȭ
	
	push(&stack, 1); //1�� push
	push(&stack, 2); //2�� push
	push(&stack, 3); //3�� push

	
	printf("%d \n",pop(&stack));  //3�� ���� 
	printf("%d \n",pop(&stack));  //2�� ����
	printf("%d \n",pop(&stack));  //1�� ����


	//Ȥ�ó� �� �޸� ������ ���� ���ؼ� Ȯ���ϰ� �Ҵ� ����
	while (!(stack.head == NULL))
	{
		Node* remove = NULL;
		remove = stack.head;
		stack.head = stack.head->next;
		free(remove);
	}
	return 0;
}
