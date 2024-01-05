#include <stdio.h>
#include <stdlib.h>


void main()
{

}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;
	while (low <= high)
	{
		// �ǹ����� ū ���� ã�� ����
		while (pivot >= arr[low] && low <= right)
			low++;		// low ���� �̵�
		// �ǹ����� ���� ���� ã�� ����
		while (pivot <= arr[high] && high >= (left+1))
			high--;		// high ���� �̵�
		//�������� ���� ���¶�� Swap ����
		if (low <= high)
			Swap(arr, low, high);
	}
	Swap(arr, left, high); //low�� high�� �����Ǹ�, swap����
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
