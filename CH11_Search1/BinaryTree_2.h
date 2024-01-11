#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData key;
	char* name;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
} BTreeNode;

typedef void (*VisitFunPtr)(BTData key);

/*** BTreeNode 관련 연산들 ****/
BTreeNode * MakeBTreeNode(void);
BTData GetKey(BTreeNode * bt);
char* GetData(BTreeNode* bt);
void SetData(BTreeNode * bt, BTData key, char* name);

BTreeNode * GetLeftSubTree(BTreeNode * bt);
BTreeNode * GetRightSubTree(BTreeNode * bt);

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);
void DeleteTraverse(BTreeNode* main); //모든 노드 삭제
void InorderTraverse(BTreeNode* bt, VisitFunPtr action); //중위순회
void PreorderTraverse(BTreeNode* bt, VisitFunPtr action); // 전위순회
void PostorderTraverse(BTreeNode* bt, VisitFunPtr action); // 후위순회

//for BST
//왼쪽 자식 노드를 트리에서 제거, 제거된 노드의 주소 반환
BTreeNode* RemoveLeftSubTree(BTreeNode* bt);

//오른쪽 자식 노드를 트리에서 제거, 제거된 노드의 주소 반환
BTreeNode* RemoveRightSubTree(BTreeNode* bt);

//메모리 소멸없이 main의 왼쪽 자식노드를 두번째 매개변수 노드로 변경
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub);

//메모리 소멸없이 main의 오른쪽 자식노드를 두번째 매개변수 노드로 변경
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub);

void ShowIntData(int key);
void ShowNodeData(int key);

#endif