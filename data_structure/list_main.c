#include <stdio.h>
#include "my_ArrayList.h"


int main()
{
	/*���� �� �ʱ�ȭ*/
	List list; //����Ʈ ����
	int data;
	int sum; //����Ʈ �� ������ ��

	ListInit(&list); //����Ʈ �ʱ�ȭ

	for (int i = 1; i <= 100; i++)
	{
		LInsert(&list, i);
	}

	printf("���� ������ �� : %d \n", LCount(&list)); //������ �� ���

	if (LFirst(&list, &data)) //ù ������ ����
	{
		sum = data;

		while (LNext(&list, &data)) //�� ��° ������ ������ ����
			sum += data;
	}
	printf("the sum is %d", sum);

	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}
}