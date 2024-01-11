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

/*** BTreeNode ���� ����� ****/
BTreeNode * MakeBTreeNode(void);
BTData GetKey(BTreeNode * bt);
char* GetData(BTreeNode* bt);
void SetData(BTreeNode * bt, BTData key, char* name);

BTreeNode * GetLeftSubTree(BTreeNode * bt);
BTreeNode * GetRightSubTree(BTreeNode * bt);

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);
void DeleteTraverse(BTreeNode* main); //��� ��� ����
void InorderTraverse(BTreeNode* bt, VisitFunPtr action); //������ȸ
void PreorderTraverse(BTreeNode* bt, VisitFunPtr action); // ������ȸ
void PostorderTraverse(BTreeNode* bt, VisitFunPtr action); // ������ȸ

//for BST
//���� �ڽ� ��带 Ʈ������ ����, ���ŵ� ����� �ּ� ��ȯ
BTreeNode* RemoveLeftSubTree(BTreeNode* bt);

//������ �ڽ� ��带 Ʈ������ ����, ���ŵ� ����� �ּ� ��ȯ
BTreeNode* RemoveRightSubTree(BTreeNode* bt);

//�޸� �Ҹ���� main�� ���� �ڽĳ�带 �ι�° �Ű����� ���� ����
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub);

//�޸� �Ҹ���� main�� ������ �ڽĳ�带 �ι�° �Ű����� ���� ����
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub);

void ShowIntData(int key);
void ShowNodeData(int key);

#endif