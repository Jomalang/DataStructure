#ifndef __DEQUEBASE_QUEUE__
#define __DEQUEBASE_QUEUE__

#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

typedef Deque Queue;

void QueueInit(Queue* pq); // 큐 초기화
int QIsEmpty(Queue* pq); // 큐가 비었는지 확인
void Enqueue(Queue* pq, Data data); //enque연산
Data Dequeue(Queue* pq); //deque 연산
Data QPeek(Queue* pq); // peek연산


#endif
