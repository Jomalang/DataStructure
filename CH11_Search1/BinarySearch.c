#include <stdlib.h>
#include "BinarySearchTree.h"


// BST의 생성 및 초기화
void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode* bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode** pRoot, BSTData data)
{
	BTreeNode* pNode = NULL; // parent node
	BTreeNode* cNode = *pRoot; // current node start in Root
	BTreeNode* nNode = NULL; // new node

	//새 노드가 추가될 위치 탐색
	while (cNode != NULL)
	{
		if (data == GetData(cNode))
			return; // 데이터(키)의 중복을 허용하지 않는다.

		pNode = cNode; //parent노드, cNode가 자식노드 주소로 가기전에 백업

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	//pNode의 자식 노드로 추가할 새 노드의 생성
	nNode = MakeBTreeNode(); // 새 노드 생성
	SetData(nNode, data); // 새 노드에 데이터 저장
	

	//pNode의 자식 노드로 새 노드를 추가.
	if (pNode != NULL)
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode); 
	}
	else //pNode가 NULL이라면 루트가 없는 상황임.
	{
		*pRoot = nNode;
	}
}


// BST를 대상으로 데이터 탐색
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
	BTreeNode* cNode = bst;

		while (cNode != NULL)
		{
			if (GetData(cNode) > target)
				cNode = GetLeftSubTree(cNode);
			else if (GetData(cNode) < target)
				cNode = GetRightSubTree(cNode);
			else
				return cNode;
		}
	return printf("비어있는 이진탐색트리입니다.");
}

