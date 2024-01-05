#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int Descending(Point* nw, Point* cur); //�������� ����

int main(void)
{
	List list;
	Point compPos;
	Point * ppos;

	ListInit(&list);
	SetSortRule(&list, Descending);

	/*** 10���� ������ ���� ***/
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 1, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 5);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 4, 7);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 6, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 9);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 4, 7);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 1, 4);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 6, 9);
	LInsert(&list, ppos);

	/*** ����� �������� ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

	if(LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);
		
		while(LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	/*** xpos�� 2�� ��� ������ ���� ***/
	compPos.xpos=2;
	compPos.ypos=0;

	if(LFirst(&list, &ppos))
	{
		if(PointComp(ppos, &compPos)==1)
		{
			ppos=LRemove(&list);
			free(ppos);
		}
		
		while(LNext(&list, &ppos)) 
		{
			if(PointComp(ppos, &compPos)==1)
			{
				ppos=LRemove(&list);
				free(ppos);
			}
		}
	}

	/*** ���� �� ���� ������ ��ü ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

	if(LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);
		
		while(LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	return 0;
}

int Descending(Point* nw, Point* cur) //�������� ����
{
	if (nw->xpos < cur->xpos)
		return FALSE; //0
	else if(nw->xpos > cur->xpos)
		return TRUE; //1	
	else
	{
		if (nw->ypos < cur->ypos)
			return FALSE; //0
		else if (nw->ypos >= cur->ypos)
			return TRUE; //1	

	}
}