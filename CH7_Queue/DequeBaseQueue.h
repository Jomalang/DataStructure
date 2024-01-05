#ifndef __DEQUEBASE_QUEUE__
#define __DEQUEBASE_QUEUE__

#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

typedef Deque Queue;

void QueueInit(Queue* pq); // ť �ʱ�ȭ
int QIsEmpty(Queue* pq); // ť�� ������� Ȯ��
void Enqueue(Queue* pq, Data data); //enque����
Data Dequeue(Queue* pq); //deque ����
Data QPeek(Queue* pq); // peek����


#endif
