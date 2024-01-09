#include "BinaryTree.h"

void BSTInsert(BtreeNode** pRoot, BSTData data)
{
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

	//pNode의 자식 노드로 새 노드를 추가.
	if (pNode != Null)
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode); 
	}
}