#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

int Ascending(LData* newdata, LData* curdata) //�������� ����
{
	if (newdata <= curdata)
		return FALSE; //0
	else
		return TRUE; //1		
}