#include <stdio.h>
#include <stdlib.h>

int Partition(int arr[], int left, int right);
void Swap(int arr[], int n1, int n2);
void QuickSort(int arr[], int left, int right);

void main()
{
	int myarr[] = { 4,2,6,7,9,0,5,7,2,8,1,2 };
	QuickSort(myarr, 0, (sizeof(myarr) / sizeof(int))-1); //배열 멤버 개수에서 -1 : 마지막 인덱스 수

	for (int i = 0; i < (sizeof(myarr) / sizeof(int)); i++)
	{
		printf("%d", myarr[i]);
	}
}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;
	while (low <= high)
	{
		// 피벗보다 큰 값을 찾는 과정
		while (pivot >= arr[low] && low <= right)
			low++;		// low 우측 이동
		// 피벗보다 작은 값을 찾는 과정
		while (pivot <= arr[high] && high >= (left+1))
			high--;		// high 좌측 이동
		//교차되지 않은 상태라면 Swap 실행
		if (low <= high)
			Swap(arr, low, high);
	}
	Swap(arr, left, high); //low와 high가 역전되면, swap실행
	return high;
}

void Swap(int arr[], int n1, int n2)
{
	int temp = arr[n1];
	arr[n1] = arr[n2];
	arr[n2] = temp;
}

void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}
