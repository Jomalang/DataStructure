#include <stdio.h>
#include <stdlib.h>
#include "DequeBaseQueue.h"
#include "Deque.h"

void QueueInit(Queue* pq) // 큐 초기화
{
	pq->head = NULL; //front
	pq->tail = NULL; //rear
}


int QIsEmpty(Queue* pq) // 큐가 비었는지 확인
{
	if (pq->head == NULL)
		return 1;
	else
		return 0;
}

void Enqueue(Queue* pq, Data data) //enque연산
{

	DQAddLast(pq, data);
}

Data Dequeue(Queue* pq) //deque 연산
{
	return DQRemoveFirst(pq);
}
Data QPeek(Queue* pq) //peek 연산
{
	return DQGetFirst(pq);
}