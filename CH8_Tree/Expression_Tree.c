#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BinaryTree.h"
#include "my_LinkedlistStack.h"

BTreeNode* MakeExpTree(char exp[])
{
	LLStack stack;
	BTreeNode* pnode;
	int expLen = strlen(exp);

	LLSInit(&stack);

	for (int i = 0; i < expLen; i++) 
	{
		pnode = MakeBTreeNode(); //��� ���� �غ�
		if (isdigit(exp[i]))
		{
			SetData(pnode, exp[i] - '0');
		}
		else
		{
			MakeRightSubTree(pnode, LLSPop(&stack));
			MakeLeftSubTree(pnode, LLSPop(&stack));
			SetData(pnode, exp[i]);
		}
		LLSPush(&stack, pnode);
	}
	return LLSPop(&stack);
}

int EvaluateExpTree(BTreeNode* bt)
{
	int op1, op2;

	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt);

	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch (GetData(bt))
	{
	case'+':
		return op1 + op2;
	case'*':
		return op1 * op2;
	case'-':
		return op2 - op1;
	case'/':
		return op2 / op1;
	}
	
	return 0;
}


void showPrefixTypeExp(BTreeNode* bt) //���� ǥ��� ��� ���
{
	PreorderTraverse(bt, ShowNodeData);
}

void showPostfixTypeExp(BTreeNode* bt)//���� ǥ��� ��� ���
{
	PostorderTraverse(bt, ShowNodeData);
	
}

void showInfixTypeExp(BTreeNode* bt) // ���� ǥ��� ��� ���
{
	if (bt == NULL)
		return;

	if (bt->left != NULL || bt->right != NULL)
		printf("(");

	showInfixTypeExp(bt->left);
	ShowNodeData(bt->data);
	showInfixTypeExp(bt->right);

	if (bt->left != NULL || bt->right != NULL)
		printf(")");
}
