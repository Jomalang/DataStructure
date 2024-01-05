#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque* pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int DQIsEmpty(Deque* pdeq)
{
	if (pdeq->head == NULL || pdeq->tail == NULL) // &&���� ����, ||���� ���� ���� ���� �ʿ�
		return 1;
	else
		return 0;
}

//void DQAddFirst(Deque* pdeq, Data data)
//{
//	Node* tmpN = (Node*)malloc(sizeof(Node)); //�ӽ� ��� ����
//	tmpN->data = data; //������ ����
//
//	if (pdeq->head == NULL)
//	{
//		pdeq->head = tmpN;//�Ӹ� �Ҵ�
//		pdeq->tail = tmpN;//���� �Ҵ�
//	}
//	else
//	{
//		tmpN->next = pdeq->head; //�� ��忡 �Ӹ� ����
//		pdeq->head->prev = tmpN; //�Ӹ��� �� ��� ����
//		pdeq->head = tmpN; //�Ӹ� �̵�
//	}
//	tmpN->prev = NULL;
//		
//}

void DQAddFirst(Deque* pdeq, Data data)
{
	Node* tmpN = (Node*)malloc(sizeof(Node));
	tmpN->data = data;

	tmpN->next = pdeq->head; //ù ����� ��쿡��, next�� NULL �Ҵ�/�ι�° ���ĺ��ʹ� �� ���� ��� ����
	if (pdeq->head == NULL) 
		pdeq->tail = tmpN; // �� ��尡 ù ����Ͻ� ������ �� ��忡 �Ҵ�.
	else
		pdeq->head->prev = tmpN; // �ƴҰ��, ���� �� ��� ����

	tmpN->prev = NULL; 
	pdeq->head = tmpN; //��� �̵�
}

void DQAddLast(Deque* pdeq, Data data)
{
	Node* tmpN = (Node*)malloc(sizeof(Node)); //�ӽ� ��� ����
	tmpN->data = data; //������ ����

	if (pdeq->tail == NULL)
	{
		pdeq->tail = tmpN;
		pdeq->head = tmpN;
	}
	else
	{
		tmpN->prev = pdeq->tail;
		pdeq->tail->next = tmpN;
		pdeq->tail = tmpN;
	}
}

Data DQRemoveFirst(Deque* pdeq)
{
	if (pdeq->head == NULL)
	{
		printf("Memorry error!");
		exit(-1);
	}
	Node* rNode = pdeq->head; //��� �ּ� ���
	Data rdata = pdeq->head->data; //��� ������ ���

	if (pdeq->head == pdeq->tail)
	{
		pdeq->head = NULL;
	}
	else
		pdeq->head = pdeq->head->next; //��� �̵�
	

	free(rNode); //��� �޸� �Ҵ� ����

	return rdata;
}

//Data DQRemoveFirst(Deque* pdeq)
//{
//	Node* rnode = pdeq->head;
//	Data rdata;
//	if (pdeq->head == NULL)
//	{
//		printf("Memorry error!");
//		exit(-1);
//	}
//	rdata = pdeq->head->data;
//
//	pdeq->head = pdeq->head->next;
//	free(rnode);
//
//	if (pdeq->head == NULL)
//		pdeq->tail = NULL;
//	else
//		pdeq->head->prev = NULL;
//
//	return rdata;
//}

Data DQRemoveLast(Deque* pdeq)
{
	if (pdeq->tail == NULL)
	{
		printf("Memorry error!");
		exit(-1);
	}
	Node* rNode = pdeq->tail; //���� �ּ� ���
	Data rdata = pdeq->tail->data; //���� ������ ���

	if (pdeq->head == pdeq->tail)
	{
		pdeq->tail = NULL;
	}
	else
		pdeq->tail = pdeq->tail->prev; //���� �̵�

	free(rNode); //��� �޸� �Ҵ� ����

	return rdata; //������ ��ȯ
}

Data DQGetFirst(Deque* pdeq)
{
	if (pdeq->head == NULL)
	{
		printf("Memorry error!");
		exit(-1);
	}
	Data rdata = pdeq->head->data; 

	return rdata;
}

Data DQGetLast(Deque* pdeq)
{
	if (pdeq->tail == NULL)
	{
		printf("Memorry error!");
		exit(-1);
	}
	Data rdata = pdeq->tail->data;

	return rdata;
}