#include <stdio.h>
#include "my_SimpleHeap.h"


int HCompPriINT(HData data1, HData data2);


int main(void)
{
	Heap heap;
	HeapInit(&heap, HCompPriINT);

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c \n", HDelete(&heap));

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c \n", HDelete(&heap));

	while (!HIsEmpty(&heap))
		printf("%c \n", HDelete(&heap));

	return 0;
}


int HCompPriINT(char data1, char data2)
{
	return data2 - data1;
}
