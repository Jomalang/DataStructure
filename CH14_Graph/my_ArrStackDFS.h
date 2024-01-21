#ifndef __MY_ARR_STACK__
#define __MY_ARR_STACK__

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data;

typedef struct _arrStack
{
	Data arrstack[STACK_LEN];
	int TopPosition;

}Stack;

typedef struct _DarrStack
{
	Stack Darrstack[STACK_LEN];
	int TopPosition;

}DStack;

void SInit(Stack* pstack);
int SIsEmpty(Stack* pstack);
void SPush(Stack* pstack, Data data);

Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

void SNumofData(Stack* pstack);


void DSInit(DStack* pdstack);
int DSIsEmpty(DStack* pdstack);
void DSPush(DStack* pdstack, Stack stack);

Stack* DSPop(DStack* pdstack);
Stack* DSPeek(DStack* pstack);

void DSNumofData(DStack* pdstack);

#endif
