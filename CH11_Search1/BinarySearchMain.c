#include <stdio.h>
#include "BinarySearchTree.h"


int main(void)
{
	BTreeNode* bstRoot; //bstRoot�� BST�� ��Ʈ ��带 ����Ŵ.
	BTreeNode* sNode;

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 3);

	sNode = BSTSearch(bstRoot, 1);

	if (sNode == NULL)
		printf("Search failed!\n");
	else
		printf("Ž���� ������ Ű�� �� : %d \n", BSTGetNodeData(sNode));
	return 0;
}