#include<stdio.h>
#include "Expression_Tree.h"

int main()
{
	char exp[] = "12+7*";
	BTreeNode* eTree = MakeExpTree(exp);

	printf("중위표기법의 수식:");
	showInfixTypeExp(eTree);
	printf("\n");

	printf("전위표기법의 수식:");
	showPrefixTypeExp(eTree);
	printf("\n");

	printf("후위표기법의 수식:");
	showPostfixTypeExp(eTree);
	printf("\n");

	printf("%d", EvaluateExpTree(eTree));
}