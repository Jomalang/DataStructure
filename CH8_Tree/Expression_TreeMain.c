#include<stdio.h>
#include "Expression_Tree.h"

int main()
{
	char exp[] = "12+7*";
	BTreeNode* eTree = MakeExpTree(exp);

	printf("����ǥ����� ����:");
	showInfixTypeExp(eTree);
	printf("\n");

	printf("����ǥ����� ����:");
	showPrefixTypeExp(eTree);
	printf("\n");

	printf("����ǥ����� ����:");
	showPostfixTypeExp(eTree);
	printf("\n");

	printf("%d", EvaluateExpTree(eTree));
}