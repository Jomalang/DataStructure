#include <stdio.h>
#include <stdlib.h>
#include "my_CLinkedlistStack.h"

int main()
{
	Data data;
	CList my_llstack;

	// 스택 초기화
	LLSInit(&my_llstack);
	
	// 스택 값 할당
	for (int i = 0; i < 10; i++)
	{
		LLSPush(&my_llstack, i);
	}

	// 스택 값 조사
	if (!LLSIsEmpty(&my_llstack))
		printf("스택에 값이 없습니다.\n");
	else
		printf("스택에 값이 존재합니다.\n");

	//스택 값 해제
	printf("스택 값(%d) 해제.. \n", LLSPop(&my_llstack));
	printf("스택 값(%d) 해제.. \n", LLSPop(&my_llstack));
	printf("스택 값(%d) 해제.. \n", LLSPop(&my_llstack));

	//스택 값 확인
	printf("스택 값(%d) 확인.. \n", LLSPeek(&my_llstack));
	printf("스택에 %d개의 데이터가 있습니다.\n",LLSNumofData(&my_llstack));

	return 0;
}