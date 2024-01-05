#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue* pq)
{
	pq->front = 0;
	pq->rear = 0;
}

int NextPosIdex(int pos)
{
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

int QIsEmpty(Queue* pq)
{
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* pq, Data data)
{
	if (NextPosIdex(pq->rear) == pq->front) // 큐가 가득찰 조건 설정
	{
		printf("the Queue is full\n");
	}
	else
	{
		pq->rear = NextPosIdex(pq->rear);
		pq->queArr[pq->rear] = data;
	}
}
Data Dequeue(Queue* pq)
{
	if (QIsEmpty(pq)) //큐가 비어있을 조건
	{
		printf("the Queue is empty\n");
	}
	else
	{
		
		pq->front = NextPosIdex(pq->front); // 한칸 이동 후
		return pq->queArr[pq->front]; //반환
	}
}

Data QPeek(Queue* pq)
{
	Data tmp;
	tmp = pq->queArr[pq->front];

	return tmp;
}