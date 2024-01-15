#include <stdlib.h>
#include "AVLReblance.h"
#include "BinarySearchTree_2.h"
#include "BinaryTree_3.h"

int GetHeight(BTreeNode* bst) //Get a height of node
{
	int rightH; //right height
	int leftH; // left height

	if (bst == NULL) // escape condition
		return 0; // return leaf node level

	leftH = GetHeight(GetLeftSubTree(bst));
	rightH = GetHeight(GetRightSubTree(bst));
	
	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

int GetHeightDiff(BTreeNode* bst) //Get a difference of each subtree
{
	int lsh; //left subtree height
	int rsh; //right subtree height

	if (bst == NULL) // entrance check
		return 0;

	lsh = GetHeight(GetLeftSubTree(bst));
	rsh = GetHeight(GetRightSubTree(bst));

	return lsh - rsh;
}

BTreeNode* RotateLL(BTreeNode* bst) //Rotate LL
{
	BTreeNode* pNode = bst;
	BTreeNode* cNode = GetLeftSubTree(bst);

	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
	ChangeRightSubTree(cNode, pNode);

	return cNode;
}

BTreeNode* RotateRR(BTreeNode* bst) //Rotate RR
{
	BTreeNode* pNode = bst;
	BTreeNode* cNode = GetRightSubTree(bst);

	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);

	return cNode;
}

BTreeNode* RotateLR(BTreeNode* bst) //Rotate LR
{
	BTreeNode* pNode = bst;
	BTreeNode* cNode = GetLeftSubTree(bst);

	ChangeLeftSubTree(pNode, RotateRR(cNode));
	return RotateLL(pNode);
}

BTreeNode* RotateRL(BTreeNode* bst) //Rotate RL
{
	BTreeNode* pNode = bst;
	BTreeNode* cNode = GetRightSubTree(bst);

	ChangeRightSubTree(pNode, RotateLL(cNode));
	return RotateRR(pNode);
}

BTreeNode* Rebalance(BTreeNode** pRoot)
{
	int hDiff = GetHeightDiff(*pRoot); // Get a Diff of *pRoot

	if (hDiff > 1) // it need to Rotate LL or LR
	{
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
			RotateLL(*pRoot);
		else
			RotateLR(*pRoot);
	}
	
	if (hDiff < -1) // it need to Rotate RR or RL
	{
		if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
			RotateRR(*pRoot);
		else
			RotateRL(*pRoot);
	}

	return *pRoot;
}