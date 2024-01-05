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


void BubbleSort(int arr[], int n) //n => �迭�� ũ��
{
	int temp;

	for (int i = n - 1; i > 0; i--) //������ �ݺ������� 2���� �����͸� ���� ���ϸ� �ȴ�.
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				//�޸𸮻� ������ ��ȯ
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}