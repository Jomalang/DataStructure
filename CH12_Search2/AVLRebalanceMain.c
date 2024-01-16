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

	BSTInsert(&avlRoot, 1, "������");
	BSTInsert(&avlRoot, 2, "�����");
	BSTInsert(&avlRoot, 3, "�ֿ���");
	BSTInsert(&avlRoot, 4, "ȭ����");
	BSTInsert(&avlRoot, 5, "������");
	BSTInsert(&avlRoot, 6, "���ü�");
	BSTInsert(&avlRoot, 7, "ȫ����");
	BSTInsert(&avlRoot, 8, "������");
	BSTInsert(&avlRoot, 9, "������");

	return 0;

}

