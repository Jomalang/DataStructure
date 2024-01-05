#include <stdio.h>
#include "BinaryTree.h"

int main(void)
{
	BTreeNode * bt1 = MakeBTreeNode();
	BTreeNode * bt2 = MakeBTreeNode();
	BTreeNode * bt3 = MakeBTreeNode();
	BTreeNode * bt4 = MakeBTreeNode();
	BTreeNode* bt5 = MakeBTreeNode();
	BTreeNode* bt6 = MakeBTreeNode();
	BTreeNode* bt7 = MakeBTreeNode();
	BTreeNode* bt8 = MakeBTreeNode();
	BTreeNode* bt9 = MakeBTreeNode();
	BTreeNode* bt10 = MakeBTreeNode();
	BTreeNode* bt11 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);
	SetData(bt7, 7);
	SetData(bt8, 8);
	SetData(bt9, 9);
	SetData(bt10, 10);
	SetData(bt11, 11);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	MakeLeftSubTree(bt3, bt6);
	MakeRightSubTree(bt3, bt7);
	MakeLeftSubTree(bt4, bt8);
	MakeRightSubTree(bt4, bt9);
	MakeLeftSubTree(bt5, bt10);

	printf("���� ��ȸ ����\n");
	InorderTraverse(bt1, ShowIntData);
	printf("���� ��ȸ ��\n");

	printf("���� ��ȸ ����\n");
	PreorderTraverse(bt1, ShowIntData);
	printf("���� ��ȸ ��\n");

	printf("���� ��ȸ ����\n");
	PostorderTraverse(bt1, ShowIntData);
	printf("���� ��ȸ ��\n");

	DeleteTraverse(bt1);

	return 0;
}