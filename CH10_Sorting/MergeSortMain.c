#include <stdio.h>
#include <stdlib.h>

void MergeSort(int arr[], int left, int right);
void MergeTwoArea(int arr[], int left, int mid, int right);

void main() {
	
	int arr[] = { 4,2,6,4,8,2,0,9,1,6 };
	MergeSort(arr, 0, (sizeof(arr) / sizeof(int) - 1));

	for (int i = 0; i < (sizeof(arr) / sizeof(int) - 1); i++)
		printf("%d", arr[i]);

}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right)
	{
		//�߰����� ���
		mid = (left + right) / 2;

		//�ѷ� ������ ���� �����Ѵ�.
		MergeSort(arr, left, mid);
		MergeSort(arr, mid+1, right);

		MergeTwoArea(arr, left, mid, right);
	}
}

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fldx = left; // �� ���ȣ��ܰ��� left
	int rldx = mid + 1; // �� ���ȣ�� �ܰ��� mid+1
	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));
	int mldx = left;
	while (fldx <= mid && rldx <= right)
	{
		if (arr[fldx] <= arr[rldx])
			sortArr[mldx] = arr[fldx++];
		else
			sortArr[mldx] = arr[rldx++];
		mldx++;
	}

	if (fldx > mid)
	{
		while (rldx <= right)
		{
			sortArr[mldx] = arr[rldx];
			rldx++; mldx++;
		}
	}
	else if(rldx > right)
	{
		while (fldx <= mid)
		{
			sortArr[mldx] = arr[fldx];
			fldx++; mldx++;
		}
	}

	for (int i = left; i <= right; i++)
	{
		arr[i] = sortArr[i];
	}
	free(sortArr);
}