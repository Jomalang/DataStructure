#ifndef __LINKED_LIST_QUEUE__
#define __LINKED_LIST_QUEUE__

#include <stdio.h>
#include <stdlib.h>

typedef int Data; //������

typedef struct _node //���Ḯ��Ʈ ���
{
	Data data;
	struct _node* next;

} Node;

typedef struct _linkedlist //���Ḯ��Ʈ ť
{
	Node* front;
	Node* rear;
	int NumofData;

} LLQueue;

void QInit(LLQueue* pllq); //���Ḯ��Ʈ �ʱ�ȭ
void Enqueue(LLQueue* pllq, Data data); //���Ḯ��Ʈ ������ �ֱ�
Data Dequeue(LLQueue* pllq); //��� ���� ����
Data QPeek(LLQueue* pllq); 

int QIsEmpty(LLQueue* pllq); // ��� 1��ȯ

















#endif