#include <stdio.h>
#include <stdlib.h>
#include "my_CLinkedlistStack.h"

void LLSInit(LLStack* pllstack)
{
	pllstack->tail = NULL;
	pllstack->cur = NULL; //not nessecery
	pllstack->before = NULL; // not nessecery
	pllstack->numOfData = 0;
}

int LLSIsEmpty(LLStack* pllstack)
{
	if (pllstack->tail == NULL)
		return 1;
	else
		return 0;
}

void LLSPush(LLStack* pllstack, Data data)
{
	LInsertFront(pllstack, data);
}

Data LLSPop(LLStack* pllstack)
{
	Data pdata;
	LFirst(pllstack, &pdata);
	return LRemove(pllstack);
}

Data LLSPeek(LLStack* pllstack)
{
	Data pdata;
	LFirst(pllstack, &pdata);
	
	return pdata;
}

int LLSNumofData(LLStack* pllstack)
{
	return pllstack->numOfData;
}