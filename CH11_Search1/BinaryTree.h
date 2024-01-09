#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
} BTreeNode;

typedef void (*VisitFunPtr)(BTData data);

/*** BTreeNode 관련 연산들 ****/
BTreeNode * MakeBTreeNode(void);
BTData GetData(BTreeNode * bt);
void SetData(BTreeNode * bt, BTData data);

BTreeNode * GetLeftSubTree(BTreeNode * bt);
BTreeNode * GetRightSubTree(BTreeNode * bt);

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);
void DeleteTraverse(BTreeNode* main); //모든 노드 삭제
void InorderTraverse(BTreeNode* bt, VisitFunPtr action); //중위순회
void PreorderTraverse(BTreeNode* bt, VisitFunPtr action); // 전위순회
void PostorderTraverse(BTreeNode* bt, VisitFunPtr action); // 후위순회

void ShowIntData(int data);
void ShowNodeData(int data);
#endif