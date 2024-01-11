#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"


// BST�� ���� �� �ʱ�ȭ
void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}

// ��忡 ����� Ű ��ȯ
BTData BSTGetNodeKey(BTreeNode* bst)
{
	return GetKey(bst);
}

//��忡 ����� ������ ��ȯ
char* BSTGetNodeData(BTreeNode* bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode** pRoot, BSTData key, char* name)
{
	BTreeNode* pNode = NULL; // parent node
	BTreeNode* cNode = *pRoot; // current node start in Root
	BTreeNode* nNode = NULL; // new node

	//�� ��尡 �߰��� ��ġ Ž��
	while (cNode != NULL)
	{
		if (key == GetKey(cNode))
			return; // ������(Ű)�� �ߺ��� ������� �ʴ´�.

		pNode = cNode; //parent���, cNode�� �ڽĳ�� �ּҷ� �������� ���

		if (GetKey(cNode) > key)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	//pNode�� �ڽ� ���� �߰��� �� ����� ����
	nNode = MakeBTreeNode(); // �� ��� ����
	SetData(nNode, key, name); // �� ��忡 ������ ����
	

	//pNode�� �ڽ� ���� �� ��带 �߰�.
	if (pNode != NULL)
	{
		if (key < GetKey(pNode))
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

	if (cNode == NULL) //���� ��� �������� ���� ���
		return NULL;

	dNode = cNode; // ���� ��� dNode �Ҵ�

	//BTreeNode* pNode = *pRoot;
	//BTreeNode* dNode = NULL;
	// 
	////dNode�� pNode�� ���� ������ ���� ���� �θ��带 ����Ű�� �������̴�.
	//
	//// TODO : pNode �Ҵ� ����
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

	// CASE1 ������ ��尡 �ڽ��� ������
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode); //TODO : RemoveLeftSubTree() ����
		else
			RemoveRightSubTree(pNode); //TODO : RemoveRightSubTree() ����
	}
	// CASE2 ������ ��尡 �ϳ��� �ڽ� ������
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode* dcNode; // ���� ����� �ڽ� ��带 ����Ű�� ������ ����

		//���� ����� �ڽ� ��� Ž�� ����
		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		//���� ����� �θ� ���� �ڽ� ��� ����
		if (GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode); //TODO:ChangeLeftSubTree()����
		else
			ChangeRightSubTree(pNode, dcNode); //TODO:ChangeRightSubTree()����
	}
	//CASE 3 ������ ��尡 �ΰ��� �ڽ� ���� ��
	else if ((GetLeftSubTree(dNode) != NULL) && (GetRightSubTree(dNode) != NULL))
	{
		BTreeNode* mNode = GetRightSubTree(dNode); //mNode�� ���� ����� ��ü ��� ����ų ����(�׻� ������ �ڽ���)
		BTreeNode* mpNode = dNode; //mpNode�� ���� ��ü ����� �θ� ��� ����ų ����.

		// ���� ����� ��ü ��� Ž��
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}
		//while�� ������ mNode���� ���� ����� ��ü��尡 ����.(������ ���� Ʈ������ ���� ���� ��)
		// ������ ��忡 ��ü����� Ű�� ����
		SetData(dNode, GetKey(mNode), GetData(mNode)); 

		// ��ü�� ���� ���� ���ڸ� �޲ٱ� ���� ��ü�� ����� �ڽİ� ��ü�� ����� �θ� �����Ѵ�.
		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
	}

	//������ ��尡 ��Ʈ ����� ��쿡 ���� �߰� ó��(���� ��Ʈ��� ����)
	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);

	free(pVRoot);
	return dNode; //���� ��� �ּ� ��ȯ
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