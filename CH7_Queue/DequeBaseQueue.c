#include <stdio.h>
#include <stdlib.h>
#include "DequeBaseQueue.h"
#include "Deque.h"

void QueueInit(Queue* pq) // ť �ʱ�ȭ
{
	pq->head = NULL; //front
	pq->tail = NULL; //rear
}


int QIsEmpty(Queue* pq) // ť�� ������� Ȯ��
{
	if (pq->head == NULL)
		return 1;
	else
		return 0;
}

void Enqueue(Queue* pq, Data data) //enque����
{

	DQAddLast(pq, data);
}

Data Dequeue(Queue* pq) //deque ����
{
	return DQRemoveFirst(pq);
}
Data QPeek(Queue* pq) //peek ����
{
	return DQGetFirst(pq);
}