#include <stdio.h>

void BubbleSort(int arr[], int n);

int main()
{
	int arr[4] = {3,2,4,1};

	BubbleSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		printf("%d ", arr[i]);


	printf("\n");
	
	return 0;
}


void BubbleSort(int arr[], int n) //n => 배열의 크기
{
	int temp;

	for (int i = n - 1; i > 0; i--) //마지막 반복에서는 2개의 데이터만 서로 비교하면 된다.
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				//메모리상 데이터 교환
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}