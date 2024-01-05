#include <stdio.h>
#include "my_ArrayList.h"

void ListInit(List* plist) //����ü �������� �ϳ� ����Ȱ� �����ϰ� �ʱ�ȭ.
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List* plist, LData data) // numOfData�� �ε��� �����ϸ� ������ ����.
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
	LData rdata = plist->arr[rpos]; // ������ ������ �ӽ�����

	for (i = rpos; i <= num-1; i++)
	{
		plist->arr[i] = plist->arr[i + 1];

		(plist->numOfData)--;
		(plist->curPosition)--;
		return rdata; // ������ ������ ��ȯ
	}
}

int LCount(List* plist)
{
	return plist->numOfData;
}