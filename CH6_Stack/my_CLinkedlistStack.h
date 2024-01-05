#ifndef __MY_LINKED_LIST_STACK__
#define __MY_LINKED_LIST_STACK__

#include "CLinkedList.h"

#define TRUE 1
#define FALSE 0

typedef int Data;
typedef CList LLStack;

void LLSInit(LLStack* pllstack);
int LLSIsEmpty(LLStack* pllstack);
void LLSPush(LLStack* pllstack, Data data);

Data LLSPop(LLStack* pllstack);
Data LLSPeek(LLStack* pllstack);

int LLSNumofData(LLStack* pllstack);



#endif
