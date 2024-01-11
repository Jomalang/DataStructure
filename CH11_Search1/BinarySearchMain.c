#include <stdio.h>
#include "BinarySearchTree.h"


int main(void)
{
	BTreeNode* bstRoot; //bstRoot는 BST의 루트 노드를 가리킴.
	BTreeNode* sNode;

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 1, "조현진");
	BSTInsert(&bstRoot, 2, "이길웅");
	BSTInsert(&bstRoot, 3, "문병국");
	BSTInsert(&bstRoot, 4, "이성연");

	sNode = BSTSearch(bstRoot, 2);

	if (sNode == NULL)
		printf("Search failed!\n");
	else
		printf("탐색에 성공한 이름의 값 : %s \n", BSTGetNodeData(sNode));

	BSTRemove(&bstRoot, 2);

	sNode = BSTSearch(bstRoot, 2);

	if (sNode == NULL)
		printf("Search failed!\n");
	else
		printf("탐색에 성공한 이름의 값 : %s \n", BSTGetNodeData(sNode));


	return 0;
}