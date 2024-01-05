#include <stdio.h>
#include <stdlib.h>
#include "LinkedListQueue.h"

void QInit(LLQueue* pllq) //���Ḯ��Ʈ �ʱ�ȭ
{
	pllq->front = NULL;
	pllq->rear = NULL;
	pllq->NumofData = 0;
}

void Enqueue(LLQueue* pllq, Data data) //���Ḯ��Ʈ ������ �ֱ�
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

Data Dequeue(LLQueue* pllq) //��� ���� ����
{
	if (QIsEmpty(pllq))
	{
		printf("ť�� ������ϴ�.");
		exit(-1);
	}
		Node* tmpnode = pllq->front; //�ּ� ���
		Data rdata = pllq->front->data;//������ ���

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
