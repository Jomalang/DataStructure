#include <stdio.h>
#include <stdlib.h>
#include "my_ArrStackDFS.h"

void SInit(Stack* pstack)
{
	pstack->TopPosition = -1;

}

int SIsEmpty(Stack* pstack)
{
	if (pstack->TopPosition == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
		
}
void SPush(Stack* pstack, Data data)
{
	pstack->TopPosition++;
	pstack->arrstack[pstack->TopPosition] = data;
	
}

Data SPop(Stack* pstack)
{
	if (SIsEmpty(pstack) == 1)
	{
		printf("���ÿ� ���� �����ϴ�.");
		exit(-1);
	}
	Data temp;
	temp = pstack->arrstack[pstack->TopPosition];
	pstack->TopPosition--;

	return temp;
}
Data SPeek(Stack* pstack)
{	
	if (SIsEmpty(pstack) == 1)
	{
		printf("���ÿ� ���� �����ϴ�.");
		exit(-1);
	}
	Data temp;
	temp = pstack->arrstack[pstack->TopPosition];

	return temp;
}

void SNumofData(Stack* pstack)
{
	printf("���ÿ� %d���� �����Ͱ� �ֽ��ϴ�.\n", (pstack->TopPosition + 1));
}

void DSInit(DStack* pdstack)
{
	pdstack->TopPosition = -1;

}

int DSIsEmpty(DStack* pdstack)
{
	if (pdstack->TopPosition == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
void DSPush(DStack* pdstack, Stack stack)
{
	pdstack->TopPosition++;
	pdstack->Darrstack[pdstack->TopPosition] = stack;

}

Stack* DSPop(DStack* pdstack)
{
	if (DSIsEmpty(pdstack) == 1)
	{
		printf("���ÿ� ���� �����ϴ�.");
		exit(-1);
	}
	Stack* temp;
	temp = &pdstack->Darrstack[pdstack->TopPosition];
	pdstack->TopPosition--;

	return temp;
}
Stack* DSPeek(DStack* pdstack)
{
	if (DSIsEmpty(pdstack) == 1)
	{
		printf("���ÿ� ���� �����ϴ�.");
		exit(-1);
	}
	Stack* temp;
	temp = &pdstack->Darrstack[pdstack->TopPosition];

	return temp;
}

void DSNumofData(DStack* pdstack)
{
	printf("���ÿ� %d���� �����Ͱ� �ֽ��ϴ�.\n", (pdstack->TopPosition + 1));
}