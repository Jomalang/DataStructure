#include <stdio.h>
#include "my_SimpleHeap.h"

int PriComp(int n1, int n2)
{
	return n2 - n1; //오름차순
	//return n1 - n2; //내림차순
}

void HeapSort(int arr[], int n, PriorityComp pc)
{
	Heap heap;
	HeapInit(&heap, PriComp);

	for (int i = 0; i < n; i++) //데이터 힙 삽입
	{
		HInsert(&heap, arr[i]);
	}

	for (int i = 0; i < n; i++) //데이터 힙 추출
	{
		arr[i] = HDelete(&heap);
	}
}

int main()
{
	int arr[] = { 4,6,9,2,3,4,8,1,0,8 };

	HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d", arr[i]);
	}

	printf("\n");
}

