#ifndef __MY_SIMPLE_HEAP_H__
#define __MY_SIMPLE_HEAP_H__

#include "ALEdge.h"

#define TRUE	1
#define FALSE	0

#define HEAP_LEN	100

typedef Edge HData;
typedef int (*PriorityComp)(HData data1, HData data2);


typedef struct _heap
{
	PriorityComp comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

/*** Heap ���� ����� ****/
void HeapInit(Heap* ph, PriorityComp pc);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data);
HData HDelete(Heap* ph);

#endif