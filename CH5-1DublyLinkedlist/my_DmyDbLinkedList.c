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

	plist->tail->prev->next = temp; //���� �߿�.
	temp->prev = plist->tail->prev; // ���� �߿�
	plist->tail->prev = temp;
	temp->next = plist->tail;
	

	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata)
{
	if (plist->head->next == plist->tail) // �켱 ��ȿ����� ������� Ȯ���Ѵ�.
		return FALSE;
	else
	{   // ��ȿ��尡 �ִٸ�, �ʱ�ȭ�� �����Ѵ�.
		plist->cur = plist->head->next; // ù ��ȿ ���

		*pdata = plist->cur->data;

		return TRUE;
	}
}

int LNext(List* plist, Data* pdata)
{
	if (plist->cur->next == plist->tail) // Lfirst����Ǿ����� / cur�� ����Ʈ ���� �Դ��� �˻�
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
		return printf("������ �����Ͱ� �����ϴ�.");

	Node* rNode;
	rNode = plist->cur; //�ּ� ���
	Data rdata = plist->cur->data; //������ ���

	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev; //����Ʈ ���� ������Ʈ
	plist->cur = plist->cur->prev; //���� Ž�� ���� cur ��ġ ����

	free(rNode); //�޸� �Ҵ� ����

	(plist->numOfData)--;

	return rdata;
}


