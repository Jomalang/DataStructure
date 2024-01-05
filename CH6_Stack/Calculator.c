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

	// ��ȯ�� ���� ���� ����
	char* convExp = (char*)malloc(expLen + 1); 

	int i, idx = 0; // idx => ��ȭ�� ������ �ε��� ����Ű�� ����
	char tok, popOp;

	// ��ȯ�� ���� ���� �迭 �ʱ�ȭ
	memset(convExp, 0, (expLen + 1*sizeof(char)));
	// ������ ���� ���� �ʱ�ȭ
	SInit(&stack); 

	
	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];
		if (isdigit(exp[i])) // �ǿ������� ��� 1 ��ȯ
		{
			convExp[idx++] = tok;
		}
		else // �������ϰ��
		{
			switch (tok)
			{
			case '(': //���ο� �ٴ� ����
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

				//if (SIsEmpty(&stack)) // ���� ��������� 1 ��ȯ
				//{
				//	SPush(&stack, tok); //������ ��� ������ ����.
				//	break;
				//}
				//else //���ÿ� �����ڰ� ������ �� ����.
				//{
				//	// WPO �Լ��� ��ȯ�� ���� �ӽ� ����
				//	int comp = WhoPrecOp(SPeek(&stack), tok);
				//	if (comp == 1 || comp == 0) //���ÿ� �ִ� �����ڰ� �켱���� ����
				//	{
				//		while (!SIsEmpty(&stack))
				//		{
				//			convExp[idx++] = SPop(&stack); //�ִ��� ����,
				//		}
				//		SPush(&stack, tok); //���� ����.
				//		break;
				//	}
				//	else if (comp == -1) //���ο� �����ڰ� �켱���� ����
				//	{
				//		SPush(&stack, tok); //���� ����.
				//		break;
				//	}
				//}
			}
			
			
		}
	}
	//���ÿ� ���� ������ �̵�
	while (!SIsEmpty(&stack))
		convExp[idx++] = SPop(&stack);

	strcpy(exp, convExp); //��ȯ�� ���� ��ȯ
	free(convExp); //��ȯ�� �迭 ���� ���� ����
}


int GetOpPrec(char op) //������ �켱���� ��ȯ
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
		return 1; //')'�� signal�� ���
	}

	return -1; // ��ϵ��� ���� �������� ��� -1 ��ȯ
}

int WhoPrecOp(char op1, char op2)
{
	int op1prec = GetOpPrec(op1);
	int op2prec = GetOpPrec(op2);

	if (op1prec > op2prec)
	{
		return 1; //op1�� op2���� �켱������ ����.
	}
	else if (op1prec < op2prec)
	{
		return -1; //op2�� op1���� �켱���� ����.
	}
	else
		return 0; // op1�� op2�� �켱���� ����.
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
		if (isdigit(tok)) // �ǿ������� ��� 1 ��ȯ
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

	ConvToRPNExp(expcpy); //���� ǥ��� ����ǥ������� ����
	ret = AnsExpRPN(expcpy); //����ǥ��� ���

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