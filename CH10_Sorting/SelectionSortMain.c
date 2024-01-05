#include <stdio.h>

void SelSort(int arr[], int n);

void main()
{
	int arr[5] = { 4,3,5,2,1 };

	SelSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 5; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
}


void SelSort(int arr[], int n)
{
	int i, j, maxIDX;
	int temp;

	for (i = 0; i < n-1; i++)
	{
		for (j = i; j < n - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				maxIDX = j + 1;
			}
				
		}
		temp = arr[i];
		arr[i] = arr[maxIDX];
		arr[maxIDX] = temp;

	}
}

