#include <stdio.h>
#include <stdlib.h>
#include "my_LinkedlistStack.h"

void LLSInit(LLStack* pllstack)
{
	pllstack->head = NULL;
	pllstack->StackPointer = -1;
}

int LLSIsEmpty(LLStack* pllstack)
{
	if (pllstack->head == NULL)
		return 1;
	else
		return 0;
}

void LLSPush(LLStack* pllstack, Data data)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;

	if (pllstack->head == NULL)
	{
		pllstack->head = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = pllstack->head;
		pllstack->head = temp;
	}

	pllstack->StackPointer += 1;
}

Data LLSPop(LLStack* pllstack)
{
	if (pllstack->head == NULL)
	{
		printf("스택에 데이터가 없습니다.");
		exit(-1);
	}
	Node* rNode;
	Data rdata;
	
	rNode = pllstack->head; //주소 백업
	rdata = pllstack->head->data; // 데이터 백업

	pllstack->head = pllstack->head->next; //전체 리스트 업데이트
	pllstack->StackPointer -= 1;

	free(rNode);
	return rdata;
}

Data LLSPeek(LLStack* pllstack)
{
	Data pdata;

	pdata = pllstack->head->data;

	return pdata;
}

int LLSNumofData(LLStack* pllstack)
{
	return (pllstack->StackPointer)+1;
}