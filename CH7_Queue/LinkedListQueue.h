#ifndef __LINKED_LIST_QUEUE__
#define __LINKED_LIST_QUEUE__

#include <stdio.h>
#include <stdlib.h>

typedef int Data; //데이터

typedef struct _node //연결리스트 노드
{
	Data data;
	struct _node* next;

} Node;

typedef struct _linkedlist //연결리스트 큐
{
	Node* front;
	Node* rear;
	int NumofData;

} LLQueue;

void QInit(LLQueue* pllq); //연결리스트 초기화
void Enqueue(LLQueue* pllq, Data data); //연결리스트 데이터 넣기
Data Dequeue(LLQueue* pllq); //노드 연결 해제
Data QPeek(LLQueue* pllq); 

int QIsEmpty(LLQueue* pllq); // 비면 1반환

















#endif