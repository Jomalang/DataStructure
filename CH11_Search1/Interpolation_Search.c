#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Bsearch(int* arr, int min, int max, int target);


int main()
{
	int arr[] = { 0,4,8,12,16,20 };

	int target = 0;
	scanf("%d", &target);
	Isearch(arr, 0, 4, target);


	return 0;

}

int Isearch(int* arr, int min, int max, int target)
{
	int mid = ((double)((target - arr[min]) / (arr[max] - arr[min])) * (max - min) + min);
	if (arr[min] > target || arr[max] < target)
	{
		return printf("Interpolation serach failed!");
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
				Isearch(arr, mid + 1, max, target);
			}
			else
				Isearch(arr, min, mid - 1, target);
	}

}