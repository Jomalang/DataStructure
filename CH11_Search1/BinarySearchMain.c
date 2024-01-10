#include <stdio.h>
#include "BinarySearchTree.h"


int main(void)
{
	BTreeNode* bstRoot; //bstRoot는 BST의 루트 노드를 가리킴.
	BTreeNode* sNode;

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 3);

	sNode = BSTSearch(bstRoot, 1);

	if (sNode == NULL)
		printf("Search failed!\n");
	else
		printf("탐색에 성공한 키의 값 : %d \n", BSTGetNodeData(sNode));
	return 0;
}