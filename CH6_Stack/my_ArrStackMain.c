#include <stdio.h>
#include <stdlib.h>
#include "my_ArrStack.h"

int main()
{
	DStack my_dstack;
	Stack my_stack;
	Stack my_stack2;
	Stack my_stack3;
	Data my_data;

	// 스택 초기화
	DSInit(&my_dstack);
	SInit(&my_stack);
	SInit(&my_stack2);
	SInit(&my_stack3);

	// 스택 값 할당
	for (int i = 0; i < 3; i++)
	{
		SPush(&my_stack, i);
	}
	for (int i = 3; i > 0; i--)
	{
		SPush(&my_stack2, i);
	}
	for (int i = 0; i < 5; i++)
	{
		SPush(&my_stack3, i);
	}

	DSPush(&my_dstack, my_stack);
	DSPush(&my_dstack, my_stack2);
	DSPush(&my_dstack, my_stack3);

	//스택 값 개수 출력
	DSNumofData(&my_dstack);
	SNumofData(&my_dstack.Darrstack[my_dstack.TopPosition]);
	SNumofData(&my_dstack.Darrstack[my_dstack.TopPosition-1]);
	SNumofData(&my_dstack.Darrstack[my_dstack.TopPosition-2]);

	// 스택 값 꺼내기
	while (!SIsEmpty(&my_dstack.Darrstack[my_dstack.TopPosition]))
	{
		printf("%d ", SPop(&my_dstack.Darrstack[my_dstack.TopPosition]));
	}
	printf("\n");

	while (!SIsEmpty(&my_dstack.Darrstack[my_dstack.TopPosition - 1]))
	{
		printf("%d ", SPop(&my_dstack.Darrstack[my_dstack.TopPosition-1]));
	}
	printf("\n");

	return 0;
}