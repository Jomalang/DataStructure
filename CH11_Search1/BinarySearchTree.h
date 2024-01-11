#pragma once
#include "BinaryTree_2.h"

typedef BTData BSTData;

// BST의 생성 및 초기화
void BSTMakeAndInit(BTreeNode** pRoot);

// 노드에 저장된 키 반환
BTData BSTGetNodeKey(BTreeNode* bst);

//노드에 저장된 데이터 반환
char* BSTGetNodeData(BTreeNode* bst);

// BST를 대상으로 데이터 저장(노드 생성과정 포함)
void BSTInsert(BTreeNode** pRoot, BSTData key, char* name);

// BST를 대상으로 데이터 탐색
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);

// BST를 대상으로 데이터 삭제
BSTData* BSTRemove(BTreeNode** pRoot, BSTData target);
