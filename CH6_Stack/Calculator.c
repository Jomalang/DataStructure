#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Calculatror.h"
#include "my_ArrStack.h"

void ConvToRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);

	// 변환된 수식 담을 공간
	char* convExp = (char*)malloc(expLen + 1); 

	int i, idx = 0; // idx => 변화된 스택의 인덱스 가리키는 변수
	char tok, popOp;

	// 변환된 수식 담을 배열 초기화
	memset(convExp, 0, (expLen + 1*sizeof(char)));
	// 연산자 담을 스택 초기화
	SInit(&stack); 

	
	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];
		if (isdigit(exp[i])) // 피연산자일 경우 1 반환
		{
			convExp[idx++] = tok;
		}
		else // 연산자일경우
		{
			switch (tok)
			{
			case '(': //새로운 바닥 생성
				SPush(&stack, tok);
				break;
			case ')':
				while (1)
				{
					popOp = SPop(&stack);
					if (popOp == '(')
						break;
					convExp[idx++] = popOp;
				}
				break;
			case '+':case '-':
			case '*':case '/':
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
				{
					convExp[idx++] = SPop(&stack);
				}
				SPush(&stack, tok);
				break;

				//if (SIsEmpty(&stack)) // 스택 비어있으면 1 반환
				//{
				//	SPush(&stack, tok); //스택이 비면 연산자 쌓음.
				//	break;
				//}
				//else //스택에 연산자가 있으면 비교 시작.
				//{
				//	// WPO 함수의 반환값 담을 임시 변수
				//	int comp = WhoPrecOp(SPeek(&stack), tok);
				//	if (comp == 1 || comp == 0) //스택에 있던 연산자가 우선순위 높음
				//	{
				//		while (!SIsEmpty(&stack))
				//		{
				//			convExp[idx++] = SPop(&stack); //있던거 빼고,
				//		}
				//		SPush(&stack, tok); //새로 쌓음.
				//		break;
				//	}
				//	else if (comp == -1) //새로운 연산자가 우선순위 높음
				//	{
				//		SPush(&stack, tok); //위에 쌓음.
				//		break;
				//	}
				//}
			}
			
			
		}
	}
	//스택에 남은 연산자 이동
	while (!SIsEmpty(&stack))
		convExp[idx++] = SPop(&stack);

	strcpy(exp, convExp); //변환된 수식 반환
	free(convExp); //변환된 배열 담은 공간 해제
}


int GetOpPrec(char op) //연산자 우선순위 반환
{
	switch(op)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1; //')'는 signal로 취급
	}

	return -1; // 등록되지 않은 연산자일 경우 -1 반환
}

int WhoPrecOp(char op1, char op2)
{
	int op1prec = GetOpPrec(op1);
	int op2prec = GetOpPrec(op2);

	if (op1prec > op2prec)
	{
		return 1; //op1이 op2보다 우선순위가 높음.
	}
	else if (op1prec < op2prec)
	{
		return -1; //op2이 op1보다 우선순위 높음.
	}
	else
		return 0; // op1과 op2의 우선순위 같음.
}

int AnsExpRPN(char exp[])
{
	Stack stack;
	SInit(&stack);

	int i, idx = 0;
	int ExpLen = strlen(exp);
	int tok, ans;
	for (i = 0; i < ExpLen; i++)
	{
		tok = exp[i];
		if (isdigit(tok)) // 피연산자일 경우 1 반환
		{
			tok = tok - '0'; //ASCIId To Int
			SPush(&stack, tok);
		}
		else
		{
			ans = SPop(&stack);
			switch(tok)
			{
			case'+':
				ans += SPop(&stack);
				SPush(&stack, ans);
				break;
			case'-':
				ans = (SPop(&stack) -ans);
				SPush(&stack, ans);
				break;
			case'*':
				ans *= SPop(&stack);
				SPush(&stack, ans);
				break;
			case'/':
				ans = (SPop(&stack)/ans);
				SPush(&stack, ans);
				break;
			}
		}
	}
	return ans;
	
}

int EvalInfixExp(char exp[]) 
{
	int len = strlen(exp);
	int ret;
	char* expcpy = (char*)malloc(len + 1);
	strcpy(expcpy, exp);

	ConvToRPNExp(expcpy); //중위 표기법 후위표기법으로 변경
	ret = AnsExpRPN(expcpy); //후위표기법 계산

	free(expcpy);
	return ret;
}

int InputExp()
{
	int len = 100;
	printf("int put the exp : \n");
	char* arr = (char*)malloc(len + 1);
	int ret;
	scanf("%s", arr);
	ret = EvalInfixExp(arr);

	printf("%s = %d\n", arr, ret);
	free(arr);
	return ret;
}