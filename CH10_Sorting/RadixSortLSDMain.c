#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "LinkedListQueue.h"

#define MAX_BUKET_NUM 10


LSDRadixSort(int arr[], int n, int maxLen);

void main()
{
	int arr[] = { 3,2,55434,6,754,234,64534};
	LSDRadixSort(arr, (sizeof(arr) / sizeof(int)), 5);

	for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++)
	{
		printf("%d ", arr[i]);
	} 
}

LSDRadixSort(int arr[], int n, int maxLen) //maxLen은 주어진 데이터중 가장 긴 길이
{
	LLQueue bucket[MAX_BUKET_NUM]; // create llq
	int divfac =1;
	int radix;

	for (int bn = 0; bn < MAX_BUKET_NUM; bn++) // bn : max_buket_num(10)
		QInit(&bucket[bn]); // init llq

	for (int ml = 0; ml < maxLen; ml++) // ml : each maxlen
	{	
		for (int an = 0; an < n; an++) //an : extern array length
		{
			radix = (arr[an] / divfac) % 10;
			Enqueue(&bucket[radix], arr[an]);
		}
		
		for (int bn = 0, an = 0; bn < MAX_BUKET_NUM; bn++)
		{
			while (!QIsEmpty(&bucket[bn]))
				arr[an++] = Dequeue(&bucket[bn]);
		}
		divfac *= 10;
	}
}