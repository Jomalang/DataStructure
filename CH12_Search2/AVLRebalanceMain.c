#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree_2.h"
#include "BinaryTree_3.h"

int main(void)
{
	BTreeNode* avlRoot;
	BTreeNode* clNode; //current left node
	BTreeNode* crNode; //current right node
	BSTMakeAndInit(&avlRoot);

	BSTInsert(&avlRoot, 1, "조현진");
	BSTInsert(&avlRoot, 2, "김민준");
	BSTInsert(&avlRoot, 3, "최원우");
	BSTInsert(&avlRoot, 4, "화현준");
	BSTInsert(&avlRoot, 5, "윤성우");
	BSTInsert(&avlRoot, 6, "남궁성");
	BSTInsert(&avlRoot, 7, "홍정모");
	BSTInsert(&avlRoot, 8, "조현준");
	BSTInsert(&avlRoot, 9, "최현우");

	return 0;

}

