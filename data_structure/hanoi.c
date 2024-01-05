#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NUM 6 // 하노이 원판의 수

int count = 0;
void hanoi(int num, char from, char by, char to)
{
	if(num == 1)
	{
		printf("%d is %c to %c\n", num, from, to);
		count++;
	}
	else
	{
		hanoi(num - 1, from, by, to);

		printf("%d is %c to %c\n", num, from, by);
		count++;
		hanoi(num - 1, to, from, by);
		
		return ;

	}	
}

int main()
{
	char A = 'A', B = 'B', C = 'C';
	hanoi(NUM, A, B, C);
	printf("the count is %d", count);
}