#ifndef __MY_LINKED_LIST_STACK__
#define __MY_LINKED_LIST_STACK__

#include "BinaryTree.h"
#define TRUE 1
#define FALSE 0

typedef BTreeNode* Data;

typedef struct _node
{
	int data;
	struct _node* next;

}Node;

typedef struct _linkedlistStack
{
	Node* head;
	int StackPointer;

}LLStack;

void LLSInit(LLStack* pllstack);
int LLSIsEmpty(LLStack* pllstack);
void LLSPush(LLStack* pllstack, Data data);

Data LLSPop(LLStack* pllstack);
Data LLSPeek(LLStack* pllstack);

int LLSNumofData(LLStack* pllstack);



#endif
