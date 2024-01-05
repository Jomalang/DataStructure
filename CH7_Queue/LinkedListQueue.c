#include <stdio.h>
#include <stdlib.h>
#include "LinkedListQueue.h"

void QInit(LLQueue* pllq) //연결리스트 초기화
{
	pllq->front = NULL;
	pllq->rear = NULL;
	pllq->NumofData = 0;
}

void Enqueue(LLQueue* pllq, Data data) //연결리스트 데이터 넣기
{
	Node* tempnode = (Node*)malloc(sizeof(Node));
	tempnode->data = data;
	tempnode->next = NULL;

	if (pllq->rear == NULL)
	{
		pllq->rear = tempnode;
		pllq->front = tempnode;
	}
	else
	{
		pllq->rear->next = tempnode;
		pllq->rear = tempnode;
	}

		(pllq->NumofData)++;
}

Data Dequeue(LLQueue* pllq) //노드 연결 해제
{
	if (QIsEmpty(pllq))
	{
		printf("큐가 비었습니다.");
		exit(-1);
	}
		Node* tmpnode = pllq->front; //주소 백업
		Data rdata = pllq->front->data;//데이터 백업

		pllq->front = pllq->front->next;
		free(tmpnode);

		(pllq->NumofData)--;
		
		return rdata;
		
}

Data QPeek(LLQueue* pllq)
{
	Data rdata = pllq->front->data;
	return rdata;
}


int QIsEmpty(LLQueue* pllq)
{
	if (pllq->front == NULL)
		return 1;
	else
		return 0;
}
