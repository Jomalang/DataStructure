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
	plist->head->next = tempNode; //head�� �׻� �����Ǿ��ִ�.

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
	if (plist->head->next == NULL) // �켱 ��ȿ����� ������� Ȯ���Ѵ�.
		return FALSE;
	else
	{   // ��ȿ��尡 �ִٸ�, �ʱ�ȭ�� �����Ѵ�.
		plist->before = plist->head; //���� ���
		plist->cur = plist->head->next; // ù ��ȿ ���

		*pdata = plist->cur->data;

		return TRUE;
	}
}

int LNext(List* plist, LData* pdata)
{
	if (plist->cur->next == NULL) // Lfirst����Ǿ����� / cur�� ����Ʈ ���� �Դ��� �˻�
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
		printf("������ �����Ͱ� �����ϴ�."); //��ȿ������ ���� ���� Ȯ��
	else
	{
		Node* GbgCn = plist->cur; //������ ��� �ּ� ���
		LData rdata = plist->cur->data; // ������ ������ ���

		plist->before->next = plist->cur->next; //��ü ����Ʈ ������Ʈ
		plist->cur = plist->before; // cur ������Ʈ

		free(GbgCn); // �޸��Ҵ� ����
		(plist->numOfData)--;

		return rdata; // ������ ������ ��ȯ
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

int Descending(LData* newdata, LData* curdata) //�������� ����
{
	if (newdata <= curdata)
		return FALSE; //0
	else
		return TRUE; //1		
}