#include <stdio.h>
#include "CircularQueue.h"

int main(void)
{
	// Queue의 생성 및 초기화 ///////
	Queue q;
	QueueInit(&q);

	// 데이터 넣기 ///////
	for (int i = 0; i < 5; i++)
	{
		(Enqueue(&q, i));
	}

	// 데이터 꺼내기 ///////
	while(!QIsEmpty(&q))
		printf("%d ", Dequeue(&q)); 

	return 0;
}