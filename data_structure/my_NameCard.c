#include <stdio.h>
#include <stdlib.h>
#include "my_NameCard.h"

NameCard* MakeNameCard(char* name, char* phone) // NameCard 구조체 변수의 동적 할당 및 초기화 후 주소 값 반환
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

void ShowNameCardInfo(NameCard* pcard) // NameCard 구조체 변수의 정보 출력
{
	fputs(pcard->name, stdout);
	printf("\n");
	fputs(pcard->phone, stdout);
	printf("\n\n");
}

int NameCompare(NameCard* pcard, char* name)// 이름이 같으면 0, 다르면 0이 아닌 값 반환
{ 
	for(int i = 0; i < NAME_LEN; i++)
	{
		if (pcard->name[i] != name[i])
			return 1;
	}
	return 0;
}

void ChangePhoneNum(NameCard* pcard, char* phone)// 전화번호 정보를 변경
{
	for (int i = 0; i < PHONE_LEN; i++)
	{
		pcard->phone[i] = phone[i];
	}
	
}