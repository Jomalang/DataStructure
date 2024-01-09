#include "BinaryTree.h"

void BSTInsert(BtreeNode** pRoot, BSTData data)
{
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

	//pNode�� �ڽ� ���� �� ��带 �߰�.
	if (pNode != Null)
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode); 
	}
}