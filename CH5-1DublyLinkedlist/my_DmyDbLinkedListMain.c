#include <stdio.h>
#include "DmyDbLinkedList.h"

int main()
{
	// ����� ���� ����Ʈ�� ���� �� �ʱ�ȭ  ///////
	List list;
	Data data;
	ListInit(&list);

	// 8���� ������ ����  ///////
	LInsert(&list, 1);  LInsert(&list, 2);
	LInsert(&list, 3);  LInsert(&list, 4);
	LInsert(&list, 5);  LInsert(&list, 6);
	LInsert(&list, 7);  LInsert(&list, 8);

	//������ ���
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}
	printf("\n\n");

	//2�� ��� ������ ����
	if (LFirst(&list, &data))
	{
		if (data % 2 == 0)
		{
			printf("������ %d ���� �Ϸ�\n", LRemove(&list));
		}
		while (LNext(&list, &data))
		{
			if (data % 2 == 0)
			{
				printf("������ %d ���� �Ϸ�\n", LRemove(&list));
			}
		}
		printf("\n");
	}
	
	//������ �� ���
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}
	printf("\n\n");
	

	return 0;
}

