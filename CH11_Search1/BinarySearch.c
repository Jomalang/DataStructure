#include <stdlib.h>
#include "BinarySearchTree.h"


// BST�� ���� �� �ʱ�ȭ
void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}

// ��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode* bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode** pRoot, BSTData data)
{
	BTreeNode* pNode = NULL; // parent node
	BTreeNode* cNode = *pRoot; // current node start in Root
	BTreeNode* nNode = NULL; // new node

	//�� ��尡 �߰��� ��ġ Ž��
	while (cNode != NULL)
	{
		if (data == GetData(cNode))
			return; // ������(Ű)�� �ߺ��� ������� �ʴ´�.

		pNode = cNode; //parent���, cNode�� �ڽĳ�� �ּҷ� �������� ���

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	//pNode�� �ڽ� ���� �߰��� �� ����� ����
	nNode = MakeBTreeNode(); // �� ��� ����
	SetData(nNode, data); // �� ��忡 ������ ����
	

	//pNode�� �ڽ� ���� �� ��带 �߰�.
	if (pNode != NULL)
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode); 
	}
	else //pNode�� NULL�̶�� ��Ʈ�� ���� ��Ȳ��.
	{
		*pRoot = nNode;
	}
}


// BST�� ������� ������ Ž��
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
	return printf("����ִ� ����Ž��Ʈ���Դϴ�.");
}

