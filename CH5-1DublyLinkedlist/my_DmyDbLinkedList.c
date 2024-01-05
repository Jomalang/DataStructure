#include <stdio.h>
#include <stdlib.h>
#include "DmyDbLinkedList.h"

void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); //head point to DMY
	plist->tail = (Node*)malloc(sizeof(Node)); //tail point to DMY
	plist->head->next = plist->tail;
	plist->tail->prev = plist->head;
	plist->cur = NULL;
	plist->numOfData = 0;
}
void LInsert(List* plist, Data data) //add new node to TAIL.
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;

	plist->tail->prev->next = temp; //순서 중요.
	temp->prev = plist->tail->prev; // 순서 중요
	plist->tail->prev = temp;
	temp->next = plist->tail;
	

	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata)
{
	if (plist->head->next == plist->tail) // 우선 유효노드의 존재부터 확인한다.
		return FALSE;
	else
	{   // 유효노드가 있다면, 초기화를 진행한다.
		plist->cur = plist->head->next; // 첫 유효 노드

		*pdata = plist->cur->data;

		return TRUE;
	}
}

int LNext(List* plist, Data* pdata)
{
	if (plist->cur->next == plist->tail) // Lfirst실행되었는지 / cur가 리스트 끝에 왔는지 검사
		return FALSE;
	else
	{
		plist->cur = plist->cur->next;

		*pdata = plist->cur->data;

		return TRUE;
	}
}

Data LRemove(List* plist) //remove a Node cur pointed.
{
	if (plist->cur == NULL)
		return printf("삭제할 데이터가 없습니다.");

	Node* rNode;
	rNode = plist->cur; //주소 백업
	Data rdata = plist->cur->data; //데이터 백업

	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev; //리스트 구조 업데이트
	plist->cur = plist->cur->prev; //다음 탐색 위한 cur 위치 조정

	free(rNode); //메모리 할당 해제

	(plist->numOfData)--;

	return rdata;
}


