#include <stdio.h>
#include "my_ArrayList.h"

void ListInit(List* plist) //구조체 변수명이 하나 선언된걸 가정하고 초기화.
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List* plist, LData data) // numOfData가 인덱스 역할하며 데이터 저장.
{
	if (plist->numOfData > LIST_LEN)
	{
		printf("NO Room in list\n");
		return 0;
	}
	else
	{
		plist->arr[plist->numOfData] = data;
		(plist->numOfData)++;
	}
}

int LFirst(List* plist, LData* pdata)
{
	plist->curPosition = 0;
	if (*pdata = plist->arr[0])
		return 1;
	else
		return 0;
}

int LNext(List* plist, LData* pdata)
{
	plist->curPosition++;
	if (plist->curPosition < plist->numOfData)
	{
		*pdata = plist->arr[plist->curPosition];
		return 1;
	}
	return 0;
		
}

LData LRemove(List* plist)
{
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos]; // 삭제할 데이터 임시저장

	for (i = rpos; i <= num-1; i++)
	{
		plist->arr[i] = plist->arr[i + 1];

		(plist->numOfData)--;
		(plist->curPosition)--;
		return rdata; // 삭제된 데이터 반환
	}
}

int LCount(List* plist)
{
	return plist->numOfData;
}