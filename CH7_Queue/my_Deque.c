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
	if (pdeq->head == NULL || pdeq->tail == NULL) // &&으로 할지, ||으로 할지 추후 결정 필요
		return 1;
	else
		return 0;
}

//void DQAddFirst(Deque* pdeq, Data data)
//{
//	Node* tmpN = (Node*)malloc(sizeof(Node)); //임시 노드 생성
//	tmpN->data = data; //데이터 저장
//
//	if (pdeq->head == NULL)
//	{
//		pdeq->head = tmpN;//머리 할당
//		pdeq->tail = tmpN;//꼬리 할당
//	}
//	else
//	{
//		tmpN->next = pdeq->head; //새 노드에 머리 연결
//		pdeq->head->prev = tmpN; //머리에 새 노드 연결
//		pdeq->head = tmpN; //머리 이동
//	}
//	tmpN->prev = NULL;
//		
//}

void DQAddFirst(Deque* pdeq, Data data)
{
	Node* tmpN = (Node*)malloc(sizeof(Node));
	tmpN->data = data;

	tmpN->next = pdeq->head; //첫 노드일 경우에는, next에 NULL 할당/두번째 이후부터는 새 노드와 헤드 연결
	if (pdeq->head == NULL) 
		pdeq->tail = tmpN; // 새 노드가 첫 노드일시 꼬리도 새 노드에 할당.
	else
		pdeq->head->prev = tmpN; // 아닐경우, 헤드와 새 노드 연결

	tmpN->prev = NULL; 
	pdeq->head = tmpN; //헤드 이동
}

void DQAddLast(Deque* pdeq, Data data)
{
	Node* tmpN = (Node*)malloc(sizeof(Node)); //임시 노드 생성
	tmpN->data = data; //데이터 저장

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
	Node* rNode = pdeq->head; //헤드 주소 백업
	Data rdata = pdeq->head->data; //헤드 데이터 백업

	if (pdeq->head == pdeq->tail)
	{
		pdeq->head = NULL;
	}
	else
		pdeq->head = pdeq->head->next; //헤드 이동
	

	free(rNode); //노드 메모리 할당 해제

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
	Node* rNode = pdeq->tail; //꼬리 주소 백업
	Data rdata = pdeq->tail->data; //꼬리 데이터 백업

	if (pdeq->head == pdeq->tail)
	{
		pdeq->tail = NULL;
	}
	else
		pdeq->tail = pdeq->tail->prev; //꼬리 이동

	free(rNode); //노드 메모리 할당 해제

	return rdata; //데이터 반환
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