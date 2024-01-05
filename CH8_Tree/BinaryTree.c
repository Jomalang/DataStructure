#include<stdio.h>
#include<stdlib.h>
#include"BinaryTree.h"

BTreeNode* MakeBTreeNode(void) //��� ���� �� �ּ� ��ȯ
{
	BTreeNode* tmpN = (BTreeNode*)malloc(sizeof(BTreeNode));
	tmpN->left = NULL;
	tmpN->right = NULL;
	
	return tmpN;
}
BTData GetData(BTreeNode* bt) //������ ��ȯ
{
	return bt->data;
}

void SetData(BTreeNode* bt, BTData data) //������ ����
{
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt) //���� ����Ʈ�� �ּ� ��ȯ
{
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt) //������ ����Ʈ�� �ּ� ��ȯ
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left == NULL)
	{
		main->left = sub;
		return;
	}
	else
	{
		DeleteTraverse(main->left);
		main->left = sub;
		return;
	}
}
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right == NULL)
	{
		main->right = sub;
		return;
	}
	else
	{
		DeleteTraverse(main->left);
		main->right = sub;
		return;
	}
}

void DeleteTraverse(BTreeNode* main)
{
	if (main->left != NULL)
	{
		DeleteTraverse(main->left);
	}
	if (main->right != NULL)
	{
		DeleteTraverse(main->right);
	}
	free(main);
	main = NULL;
}

void InorderTraverse(BTreeNode* bt, VisitFunPtr action)  //������ȸ
{
	if (bt == NULL)
		return;

	InorderTraverse(bt->left, action);
	action(bt->data); //��Ʈ ��� �湮
	InorderTraverse(bt->right, action);
}

void PreorderTraverse(BTreeNode* bt, VisitFunPtr action)// ������ȸ
{
	if (bt == NULL)
		return;

	action(bt->data); //��Ʈ ��� �湮
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}
void PostorderTraverse(BTreeNode* bt, VisitFunPtr action)// ������ȸ
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data); //��Ʈ ��� �湮
}

void ShowIntData(int data)
{
	printf("%d\n", data);
}

void ShowNodeData(int data)
{
	if (0 <= data && data <= 9)
		printf("%d", data);
	else
		printf("%c", data);
}
