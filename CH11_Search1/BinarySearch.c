#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"


// BST의 생성 및 초기화
void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}

// 노드에 저장된 키 반환
BTData BSTGetNodeKey(BTreeNode* bst)
{
	return GetKey(bst);
}

//노드에 저장된 데이터 반환
char* BSTGetNodeData(BTreeNode* bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode** pRoot, BSTData key, char* name)
{
	BTreeNode* pNode = NULL; // parent node
	BTreeNode* cNode = *pRoot; // current node start in Root
	BTreeNode* nNode = NULL; // new node

	//새 노드가 추가될 위치 탐색
	while (cNode != NULL)
	{
		if (key == GetKey(cNode))
			return; // 데이터(키)의 중복을 허용하지 않는다.

		pNode = cNode; //parent노드, cNode가 자식노드 주소로 가기전에 백업

		if (GetKey(cNode) > key)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	//pNode의 자식 노드로 추가할 새 노드의 생성
	nNode = MakeBTreeNode(); // 새 노드 생성
	SetData(nNode, key, name); // 새 노드에 데이터 저장
	

	//pNode의 자식 노드로 새 노드를 추가.
	if (pNode != NULL)
	{
		if (key < GetKey(pNode))
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
			if (GetKey(cNode) > target)
				cNode = GetLeftSubTree(cNode);
			else if (GetKey(cNode) < target)
				cNode = GetRightSubTree(cNode);
			else
				return cNode;
		}
		return NULL;
}

BSTData* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	//for remove Root
	BTreeNode* pVRoot = MakeBTreeNode();
	BTreeNode* pNode = pVRoot; //Parent Node
	BTreeNode* cNode = *pRoot; //Current Node
	BTreeNode* dNode;

	ChangeRightSubTree(pVRoot, *pRoot);

	while (cNode != NULL && GetKey(cNode) != target)
	{
		pNode = cNode;

		if (target < GetKey(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL) //삭제 대상 존재하지 않을 경우
		return NULL;

	dNode = cNode; // 삭제 대상 dNode 할당

	//BTreeNode* pNode = *pRoot;
	//BTreeNode* dNode = NULL;
	// 
	////dNode와 pNode는 각각 삭제할 노드와 이의 부모노드를 가리키는 포인터이다.
	//
	//// TODO : pNode 할당 구현
	/*while (GetData(GetRightSubTree(pNode)) == target || GetData(GetLeftSubTree(pNode)) == target)
	{
		if (GetData(GetLeftSubTree(pNode)) > target)
			pNode = GetLeftSubTree(pNode);
		else if (GetData(GetRightSubTree(pNode)) < target)
			pNode = GetRightSubTree(pNode);
	}
	if(GetData(GetLeftSubTree(pNode)) == target)
		dNode = GetLeftSubTree(pNode);
	else if(GetData(GetRightSubTree(pNode)) == target)
		dNode = GetRightSubTree(pNode);*/

	// CASE1 삭제할 노드가 자식이 없을때
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode); //TODO : RemoveLeftSubTree() 구현
		else
			RemoveRightSubTree(pNode); //TODO : RemoveRightSubTree() 구현
	}
	// CASE2 삭제할 노드가 하나의 자식 가질때
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode* dcNode; // 삭제 대상의 자식 노드를 가리키는 포인터 변수

		//삭제 대상의 자식 노드 탐색 과정
		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		//삭제 대상의 부모 노드와 자식 노드 연결
		if (GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode); //TODO:ChangeLeftSubTree()구현
		else
			ChangeRightSubTree(pNode, dcNode); //TODO:ChangeRightSubTree()구현
	}
	//CASE 3 삭제할 노드가 두개의 자식 가질 때
	else if ((GetLeftSubTree(dNode) != NULL) && (GetRightSubTree(dNode) != NULL))
	{
		BTreeNode* mNode = GetRightSubTree(dNode); //mNode는 삭제 노드의 대체 노드 가리킬 예정(항상 오른쪽 자식임)
		BTreeNode* mpNode = dNode; //mpNode는 위의 대체 노드의 부모 노드 가리킬 예정.

		// 삭제 대상의 대체 노드 탐색
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}
		//while문 종료후 mNode에는 삭제 대상의 대체노드가 들어간다.(오른쪽 서브 트리에서 가장 작은 값)
		// 삭제할 노드에 대체노드의 키값 대입
		SetData(dNode, GetKey(mNode), GetData(mNode)); 

		// 대체로 인해 생긴 빈자리 메꾸기 위해 대체된 노드의 자식과 대체한 노드의 부모 연결한다.
		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
	}

	//삭제된 노드가 루트 노드인 경우에 대한 추가 처리(가상 루트노드 제거)
	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);

	free(pVRoot);
	return dNode; //삭제 대상 주소 반환
}

void BSTShowData(BTreeNode** pRoot, int key)
{
	BTreeNode* temp = BSTSearch(*pRoot, key);
	printf("%s\n", GetData(temp));
}

void BSTShowAll(BTreeNode* bst)
{
	BSTInorderTraverse(bst, BSTShowData);
}