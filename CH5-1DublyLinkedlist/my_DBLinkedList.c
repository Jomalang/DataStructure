#include <stdio.h>
#include "DBLinkedList.h"

void ListInit(List* plist)
{
	plist->head = NULL;
	plist->cur = NULL;
	plist->numOfData = 0;
}

//void LInsert(List* plist, Data data)
//{
//	Node* temp = (Node*)malloc(sizeof(Node));
//	temp->data = data;
//
//	if (plist->head == NULL)
//	{
//		plist->head = temp;
//		plist->head->next = NULL;
//		plist->head->prev = NULL;
//	}
//	else
//	{
//		temp->next = plist->head->next;
//		plist->head->next = temp;
//		temp->prev = plist->head;
//	}
//
//	(plist->numOfData)++;
//}

void LInsert(List* plist, Data data)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;

	temp->next = plist->head; //첫 노드에는 NULL 할당
	if (plist->head != NULL)
		plist->head->prev = temp;

	temp->prev = NULL;
	plist->head = temp;

	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata)
{
	if (plist->head == NULL)
		return FALSE;
	plist->cur = plist->head;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, Data* pdata)
{
	if (plist->cur->next == NULL)
	return FALSE;

	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LPrevious(List* plist, Data* pdata)
{
	if (plist->cur->prev == NULL)
	return FALSE;

	plist->cur = plist->cur->prev;

	*pdata = plist->cur->data;
	return TRUE;
}