#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->comp = NULL; //In SetSort
	plist->numOfData = 0;
}

void FInsert(List* plist, LData data)
{
	Node* tempNode = (Node*)malloc(sizeof(Node));
	tempNode->data = data;

	tempNode->next = plist->head->next;
	plist->head->next = tempNode; //head는 항상 고정되어있다.

	plist->numOfData++;
}

void SInsert(List* plist, LData data)
{
	Node* tempNode = (Node*)malloc(sizeof(Node));
	tempNode->data = data;
	Node* pred = plist->head;
	
	while (pred->next != NULL && plist->comp(tempNode->data, pred->data) != 0)
	{
		pred = pred->next;
	}
	tempNode->next = pred->next;
	pred->next = tempNode;
	(plist->numOfData)++;
}

void LInsert(List* plist, LData data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);

}

int LFirst(List* plist, LData* pdata)
{
	if (plist->head->next == NULL) // 우선 유효노드의 존재부터 확인한다.
		return FALSE;
	else
	{   // 유효노드가 있다면, 초기화를 진행한다.
		plist->before = plist->head; //더미 노드
		plist->cur = plist->head->next; // 첫 유효 노드

		*pdata = plist->cur->data;

		return TRUE;
	}
}

int LNext(List* plist, LData* pdata)
{
	if (plist->cur->next == NULL) // Lfirst실행되었는지 / cur가 리스트 끝에 왔는지 검사
		return FALSE;
	else
	{
		plist->before = plist->cur;
		plist->cur = plist->cur->next;

		*pdata = plist->cur->data;

		return TRUE;
	}
}

LData LRemove(List* plist)
{
	if (plist->cur->next == NULL)
		printf("삭제할 데이터가 없습니다."); //유효데이터 존재 여부 확인
	else
	{
		Node* GbgCn = plist->cur; //삭제할 노드 주소 백업
		LData rdata = plist->cur->data; // 삭제할 데이터 백업

		plist->before->next = plist->cur->next; //전체 리스트 업데이트
		plist->cur = plist->before; // cur 업데이트

		free(GbgCn); // 메모리할당 해제
		(plist->numOfData)--;

		return rdata; // 삭제한 데이터 반환
	}	
}

int LCount(List* plist)
{
	return plist->numOfData;
}


void SetSortRule(List* plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = *comp;
}

int Descending(LData* newdata, LData* curdata) //내림차순 정렬
{
	if (newdata <= curdata)
		return FALSE; //0
	else
		return TRUE; //1		
}