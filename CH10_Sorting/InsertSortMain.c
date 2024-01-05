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
	
	for (i = 1; i < n; i++) // �ε��� 0�� �̹� ���� �� �������� �����. 
	{						// ���� �ε��� 1���� ����
		insData = arr[i];	// ���� ��� ����

		for (j = i - 1; j >= 0; j--) // ���� �Ϸ�� ���� �� �� �ݺ���
		{
			if (arr[j] > insData)
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = insData;
	}
}