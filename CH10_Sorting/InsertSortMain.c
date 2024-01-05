#include <stdio.h>

void InsertSort(int arr[], int n);

int main()
{
	int arr[5] = { 4,3,5,2,1 };

	InsertSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 5; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");


	return 0;
}

void InsertSort(int arr[], int n)
{
	int i, j;
	int insData;
	
	for (i = 1; i < n; i++) // 인덱스 0은 이미 정렬 된 영역으로 고려함. 
	{						// 따라서 인덱스 1부터 시작
		insData = arr[i];	// 정렬 대상 저장

		for (j = i - 1; j >= 0; j--) // 정렬 완료된 영역 내 비교 반복문
		{
			if (arr[j] > insData)
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = insData;
	}
}