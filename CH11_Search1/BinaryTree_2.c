#include<stdio.h>
#include<stdlib.h>
#include"BinaryTree_2.h"

BTreeNode* MakeBTreeNode(void) //��� ���� �� �ּ� ��ȯ
{
	BTreeNode* tmpN = (BTreeNode*)malloc(sizeof(BTreeNode));
	tmpN->left = NULL;
	tmpN->right = NULL;
	
	return tmpN;
}
BTData GetKey(BTreeNode* bt) //������ ��ȯ
{
	return bt->key;
}

char* GetData(BTreeNode* bt)
{
	return bt->name;
}

void SetData(BTreeNode* bt, BTData key, char* name) //������ ����
{
	bt->key = key;
	bt->name = name;
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
	action(bt->key); //��Ʈ ��� �湮
	InorderTraverse(bt->right, action);
}

void PreorderTraverse(BTreeNode* bt, VisitFunPtr action)// ������ȸ
{
	if (bt == NULL)
		return;

	action(bt->key); //��Ʈ ��� �湮
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}
void PostorderTraverse(BTreeNode* bt, VisitFunPtr action)// ������ȸ
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->key); //��Ʈ ��� �湮
}

//for BST
//���� �ڽ� ��带 Ʈ������ ����, ���ŵ� ����� �ּ� ��ȯ
BTreeNode* RemoveLeftSubTree(BTreeNode* bt)
{
	BTreeNode* delNode = NULL;
	if (bt != NULL)
	{
		delNode = GetLeftSubTree(bt);
		GetLeftSubTree(bt) == NULL;
	}
	return delNode;
}

//������ �ڽ� ��带 Ʈ������ ����, ���ŵ� ����� �ּ� ��ȯ
BTreeNode* RemoveRightSubTree(BTreeNode* bt)
{
	BTreeNode* delNode = NULL;
	if (bt != NULL)
	{
		delNode = GetRightSubTree(bt);
		GetRightSubTree(bt) == NULL;
	}
	return delNode;
}

//�޸� �Ҹ���� main�� ���� �ڽĳ�带 �ι�° �Ű����� ���� ����
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	main->left = sub;
}

//�޸� �Ҹ���� main�� ������ �ڽĳ�带 �ι�° �Ű����� ���� ����
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	main->right = sub;
}



void ShowIntData(int key)
{
	printf("%d\n", key);
}

void ShowNodeData(int key)
{
	if (0 <= key && key <= 9)
		printf("%d", key);
	else
		printf("%c", key);
}
