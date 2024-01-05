#include <stdio.h>
#include <stdlib.h>
#include "my_NameCard.h"

NameCard* MakeNameCard(char* name, char* phone) // NameCard ����ü ������ ���� �Ҵ� �� �ʱ�ȭ �� �ּ� �� ��ȯ
{
	NameCard* PtemName;

	(NameCard*)PtemName = (NameCard*)malloc((sizeof(char) * NAME_LEN) + (sizeof(char) * PHONE_LEN));
	if (PtemName == NULL)
	{
		printf("MemAollc Failed");
		exit(1);
	}
	
	for (int i = 0; i < NAME_LEN; i++)
	{
		PtemName->name[i] = name[i];
	}
	for (int i = 0; i < PHONE_LEN; i++)
	{
		PtemName->phone[i] = phone[i];
	}
	
	return PtemName;
}

void ShowNameCardInfo(NameCard* pcard) // NameCard ����ü ������ ���� ���
{
	fputs(pcard->name, stdout);
	printf("\n");
	fputs(pcard->phone, stdout);
	printf("\n\n");
}

int NameCompare(NameCard* pcard, char* name)// �̸��� ������ 0, �ٸ��� 0�� �ƴ� �� ��ȯ
{ 
	for(int i = 0; i < NAME_LEN; i++)
	{
		if (pcard->name[i] != name[i])
			return 1;
	}
	return 0;
}

void ChangePhoneNum(NameCard* pcard, char* phone)// ��ȭ��ȣ ������ ����
{
	for (int i = 0; i < PHONE_LEN; i++)
	{
		pcard->phone[i] = phone[i];
	}
	
}