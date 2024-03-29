#include<stdio.h>
#include<stdlib.h>
#include"BinaryTree_3.h"

BTreeNode* MakeBTreeNode(void) //노드 생성 및 주소 반환
{
	BTreeNode* tmpN = (BTreeNode*)malloc(sizeof(BTreeNode));
	tmpN->left = NULL;
	tmpN->right = NULL;
	
	return tmpN;
}
BTData GetKey(BTreeNode* bt) //데이터 반환
{
	return bt->key;
}

char* GetData(BTreeNode* bt)
{
	return bt->name;
}

void SetData(BTreeNode* bt, BTData key, char* name) //데이터 저장
{
	bt->key = key;
	bt->name = name;
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
	action(bt->key); //루트 노드 방문
	InorderTraverse(bt->right, action);
}

void BSTInorderTraverse(BTreeNode* bt, VisitFunPtr action)  //중위순회 for BSTShowAll
{
	if (bt == NULL)
		return;

	BSTInorderTraverse(bt->left, action);
	action(&bt, bt->key); //루트 노드 방문
	BSTInorderTraverse(bt->right, action);
}

void PreorderTraverse(BTreeNode* bt, VisitFunPtr action)// 전위순회
{
	if (bt == NULL)
		return;

	action(bt->key); //루트 노드 방문
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}
void PostorderTraverse(BTreeNode* bt, VisitFunPtr action)// 후위순회
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->key); //루트 노드 방문
}

//for BST
//왼쪽 자식 노드를 트리에서 제거, 제거된 노드의 주소 반환
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

//오른쪽 자식 노드를 트리에서 제거, 제거된 노드의 주소 반환
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

//메모리 소멸없이 main의 왼쪽 자식노드를 두번째 매개변수 노드로 변경
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	main->left = sub;
}

//메모리 소멸없이 main의 오른쪽 자식노드를 두번째 매개변수 노드로 변경
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	main->right = sub;
}



void ShowIntData(int key)
{
	printf("%s\n", key);
}

void ShowNodeData(int key)
{
	if (0 <= key && key <= 9)
		printf("%d", key);
	else
		printf("%c", key);
}
