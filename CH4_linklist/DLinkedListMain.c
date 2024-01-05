#include <stdio.h>
#include "DLinkedList.h"

int main(void)
{
	// List�� ���� �� �ʱ�ȭ /////////////////////////////
	List list;
	int data;
	ListInit(&list);


	//���� ���� �Ҵ�
	int (*pf)(LData*, LData*) = Descending;
	SetSortRule(&list, *pf);

	// 5���� ������ ���� /////////////////////////////
	LInsert(&list, 1);  LInsert(&list, 2);
	LInsert(&list, 3);  LInsert(&list, 3);
	LInsert(&list, 4);

	// ����� �������� ��ü ��� /////////////////////////
	printf("���� �������� ��: %d \n", LCount(&list));

	if(LFirst(&list, &data))    // ù ��° ������ ��ȸ
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))    // �� ��° ������ ������ ��ȸ
			printf("%d ", data);
	}
	printf("\n\n");

	// ���� 22�� �˻��Ͽ� ��� ���� //////////////////////////
	if(LFirst(&list, &data))
	{
		if(data == 22)
			LRemove(&list);
		
		while(LNext(&list, &data))
		{
			if(data == 22)
				LRemove(&list);
		}
	}

	// ���� �� �����ִ� ������ ��ü ��� ////////////////////////
	printf("���� �������� ��: %d \n", LCount(&list));

	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}