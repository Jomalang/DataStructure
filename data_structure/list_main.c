#include <stdio.h>
#include "my_ArrayList.h"


int main()
{
	/*생성 및 초기화*/
	List list; //리스트 생성
	int data;
	int sum; //리스트 내 데이터 합

	ListInit(&list); //리스트 초기화

	for (int i = 1; i <= 100; i++)
	{
		LInsert(&list, i);
	}

	printf("현재 데이터 수 : %d \n", LCount(&list)); //데이터 수 출력

	if (LFirst(&list, &data)) //첫 데이터 참조
	{
		sum = data;

		while (LNext(&list, &data)) //두 번째 데이터 이후의 참조
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