#include <stdio.h>
#include <stdlib.h>
#include "my_CLinkedlistStack.h"

int main()
{
	Data data;
	CList my_llstack;

	// ���� �ʱ�ȭ
	LLSInit(&my_llstack);
	
	// ���� �� �Ҵ�
	for (int i = 0; i < 10; i++)
	{
		LLSPush(&my_llstack, i);
	}

	// ���� �� ����
	if (!LLSIsEmpty(&my_llstack))
		printf("���ÿ� ���� �����ϴ�.\n");
	else
		printf("���ÿ� ���� �����մϴ�.\n");

	//���� �� ����
	printf("���� ��(%d) ����.. \n", LLSPop(&my_llstack));
	printf("���� ��(%d) ����.. \n", LLSPop(&my_llstack));
	printf("���� ��(%d) ����.. \n", LLSPop(&my_llstack));

	//���� �� Ȯ��
	printf("���� ��(%d) Ȯ��.. \n", LLSPeek(&my_llstack));
	printf("���ÿ� %d���� �����Ͱ� �ֽ��ϴ�.\n",LLSNumofData(&my_llstack));

	return 0;
}