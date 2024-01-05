#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Bsearch(int* arr, int min, int max, int target);


int main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };

		int target = 0;
		scanf("%d", &target);
		Bsearch(arr, 0, 9, target);
	

	return 0;
	
}

int Bsearch(int* arr, int min, int max, int target)
{
	int mid = (min + max) / 2;
	if (min > max)
	{
		return printf("Bserach failed!");
	}
	else
	{
		if (arr[mid] == target)
		{
			return printf("the target index is %d\n", mid);
		}
		else
			if (arr[mid] < target)
			{
				Bsearch(arr, mid + 1, max, target);
			}
			else
				Bsearch(arr, min, mid -1, target);
	}
	
}