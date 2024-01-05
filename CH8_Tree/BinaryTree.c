#include<stdio.h>
#include<stdlib.h>
#include"BinaryTree.h"

BTreeNode* MakeBTreeNode(void) //노드 생성 및 주소 반환
{
	BTreeNode* tmpN = (BTreeNode*)malloc(sizeof(BTreeNode));
	tmpN->left = NULL;
	tmpN->right = NULL;
	
	return tmpN;
}
BTData GetData(BTreeNode* bt) //데이터 반환
{
	return bt->data;
}

void SetData(BTreeNode* bt, BTData data) //데이터 저장
{
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt) //왼쪽 서브트리 주소 반환
{
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt) //오른쪽 서브트리 주소 반환
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

void InorderTraverse(BTreeNode* bt, VisitFunPtr action)  //중위순회
{
	if (bt == NULL)
		return;

	InorderTraverse(bt->left, action);
	action(bt->data); //루트 노드 방문
	InorderTraverse(bt->right, action);
}

void PreorderTraverse(BTreeNode* bt, VisitFunPtr action)// 전위순회
{
	if (bt == NULL)
		return;

	action(bt->data); //루트 노드 방문
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}
void PostorderTraverse(BTreeNode* bt, VisitFunPtr action)// 후위순회
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data); //루트 노드 방문
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
