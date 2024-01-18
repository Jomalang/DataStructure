#include <stdio.h>
#include <stdlib.h>
#include "Slot_2.h"
#include "DLinkedList_2.h"
#include "Table_2.h"

void TBLInit(Table * pt, HashFunc * f)
{
	int i;

	for (i = 0; i < MAX_TBL; i++) //Table�� ��ü slot���迭�� ���� 
		ListInit(&(pt->tbl[i])); // ��� index�� list�� �ʱ�ȭ�Ѵ�.

	pt->hf = f; //�ؽ� �Լ��� ����Ѵ�.
}

void TBLInsert(Table * pt, Key k, Value v)
{
	int hv = pt->hf(k); //Ű�� �ؽ��Լ��� �Է��� �ε����� ��´�.
	Slot nSlot = { .key = k, .val = v };

	if (TBLSearch(pt, k) != NULL)
	{
		printf("Ű �ߺ� ���� \n");
		return;
	}
	else
	{
		LInsert(&(pt->tbl[hv]), nSlot);
	}
}

int TBLDelete(Table * pt, Key k)
{
	int hv = pt->hf(k); //Ű�� �ؽ��Լ��� �Է��� �ε����� ��´�.
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