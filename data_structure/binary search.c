#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void BSearch(int ar[], int len, int target)
{
	int first = 0;
	int last = len - 1;
	int mid;
	int count = 1;

	while (first <= last)
	{
		mid = (first + last) / 2;
		if (target == ar[mid])
		{
			return printf("count is %d", count); //Å½»ö ¿Ï·á
		}
		else
		{
			if (target < ar[mid])
				last = mid - 1;
			else
				first = mid + 1;
		}
		count++;
	}
	return printf("%d",count); //Å½»ö ½ÇÆÐ½Ã
}

main()
{

	
	int target;
	int ans = -1;
	int count = 1;
	int arr[15] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	int arr2[5000] = { 0, };
	scanf("%d", &target);
	BSearch(arr2, 5000, target);


	//int min = 0, max = sizeof(arr) / sizeof(int) -1; //index in binary search 

	//if (scanf("%d", &target) == 1)
	//{
	//	while (min <= max)
	//	{
	//		if (arr[(int)((min + max) / 2)] == target)
	//		{
	//			ans = (min + max) / 2;
	//			return printf("We finded %d in index %d\ncount is a %d", target, ans, count);
	//		}
	//		else if (arr[(int)((min + max) / 2)] > target)
	//		{
	//			max = (int)((min + max) / 2)-1;
	//		}
	//		else
	//			min = (int)((min + max) / 2)+1;
	//		count++;
	//	}
	//	printf("Serach failed!");
	//}
	//else
	//	printf("Plz input a one number");
}