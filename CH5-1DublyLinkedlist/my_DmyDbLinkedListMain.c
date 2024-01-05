#include <stdio.h>
#include "DmyDbLinkedList.h"

int main()
{
	// 양방향 연결 리스트의 생성 및 초기화  ///////
	List list;
	Data data;
	ListInit(&list);

	// 8개의 데이터 저장  ///////
	LInsert(&list, 1);  LInsert(&list, 2);
	LInsert(&list, 3);  LInsert(&list, 4);
	LInsert(&list, 5);  LInsert(&list, 6);
	LInsert(&list, 7);  LInsert(&list, 8);

	//데이터 출력
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}
	printf("\n\n");

	//2의 배수 데이터 삭제
	if (LFirst(&list, &data))
	{
		if (data % 2 == 0)
		{
			printf("데이터 %d 삭제 완료\n", LRemove(&list));
		}
		while (LNext(&list, &data))
		{
			if (data % 2 == 0)
			{
				printf("데이터 %d 삭제 완료\n", LRemove(&list));
			}
		}
		printf("\n");
	}
	
	//데이터 재 출력
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

