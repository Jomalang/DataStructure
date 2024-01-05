#include <stdio.h>
#include "LinkedListQueue.h"

int main()
{
	LLQueue my_llq;
	QInit(&my_llq); //큐 초기화

	for (int i = 0; i < 10; i++)
	{
		Enqueue(&my_llq, i);
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d is dequeued\n", Dequeue(&my_llq));
		
	}
	
	printf("%d is peeked\n", QPeek(&my_llq));

	for (int i = 0; i < 6; i++)
	{
		printf("%d is dequeued\n", Dequeue(&my_llq));

	}

	return 0;
}