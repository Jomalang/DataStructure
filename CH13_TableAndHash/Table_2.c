#include <stdio.h>
#include <stdlib.h>
#include "Slot_2.h"
#include "DLinkedList_2.h"
#include "Table_2.h"

void TBLInit(Table * pt, HashFunc * f)
{
	int i;

	for (i = 0; i < MAX_TBL; i++) //Table의 전체 slot형배열을 돌며 
		ListInit(&(pt->tbl[i])); // 모든 index의 list를 초기화한다.

	pt->hf = f; //해시 함수를 등록한다.
}

void TBLInsert(Table * pt, Key k, Value v)
{
	int hv = pt->hf(k); //키를 해시함수에 입력해 인덱스를 얻는다.
	Slot nSlot = { .key = k, .val = v };

	if (TBLSearch(pt, k) != NULL)
	{
		printf("키 중복 오류 \n");
		return;
	}
	else
	{
		LInsert(&(pt->tbl[hv]), nSlot);
	}
}

int TBLDelete(Table * pt, Key k)
{
	int hv = pt->hf(k); //키를 해시함수에 입력해 인덱스를 얻는다.
	Slot rSlot;

	if (LFirst(&(pt->tbl[hv]), &rSlot))
	{
		if (rSlot.key == k)
		{
			LRemove(&(pt->tbl[hv]));
			return rSlot.val;
		}
		else
		{
			while (LNext(&(pt->tbl[hv]), &rSlot))
			{
				if (rSlot.key == k)
				{
					LRemove(&(pt->tbl[hv]));
					return rSlot.val;
				}
			}
		}	
	}
	return FALSE;
}

int TBLSearch(Table * pt, Key k)
{
	int hv = pt->hf(k);

	Slot rSlot;

	if (LFirst(&(pt->tbl[hv]), &rSlot))
	{
		if (rSlot.key == k)
			return rSlot.val;
		else
		{
			while (LNext(&(pt->tbl[hv]), &rSlot))
			{
				if (rSlot.key == k)
					return rSlot.val;
			}
		}
	}
	return FALSE;
}