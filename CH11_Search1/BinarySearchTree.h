#pragma once
#include "BinaryTree_2.h"

typedef BTData BSTData;

// BST�� ���� �� �ʱ�ȭ
void BSTMakeAndInit(BTreeNode** pRoot);

// ��忡 ����� Ű ��ȯ
BTData BSTGetNodeKey(BTreeNode* bst);

//��忡 ����� ������ ��ȯ
char* BSTGetNodeData(BTreeNode* bst);

// BST�� ������� ������ ����(��� �������� ����)
void BSTInsert(BTreeNode** pRoot, BSTData key, char* name);

// BST�� ������� ������ Ž��
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);

// BST�� ������� ������ ����
BSTData* BSTRemove(BTreeNode** pRoot, BSTData target);
