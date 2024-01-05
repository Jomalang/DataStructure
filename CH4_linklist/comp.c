#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

int Ascending(LData* newdata, LData* curdata) //오름차순 정렬
{
	if (newdata <= curdata)
		return FALSE; //0
	else
		return TRUE; //1		
}