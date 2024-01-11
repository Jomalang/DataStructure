#include <stdio.h>
#include "BinarySearchTree.h"


int main(void)
{
	BTreeNode* bstRoot; //bstRoot�� BST�� ��Ʈ ��带 ����Ŵ.
	BTreeNode* sNode;

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 1, "������");
	BSTInsert(&bstRoot, 2, "�̱��");
	BSTInsert(&bstRoot, 3, "������");
	BSTInsert(&bstRoot, 4, "�̼���");

	sNode = BSTSearch(bstRoot, 2);

	if (sNode == NULL)
		printf("Search failed!\n");
	else
		printf("Ž���� ������ �̸��� �� : %s \n", BSTGetNodeData(sNode));

	BSTShowData(&bstRoot, 1);

	BSTRemove(&bstRoot, 2);

	sNode = BSTSearch(bstRoot, 2);

	if (sNode == NULL)
		printf("Search failed!\n");
	else
		printf("Ž���� ������ �̸��� �� : %s \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 1);

	if (sNode == NULL)
		printf("Search failed!\n");
	else
		printf("Ž���� ������ �̸��� �� : %s \n", BSTGetNodeData(sNode));

	BSTShowAll(bstRoot);

	return 0;
}