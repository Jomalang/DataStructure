#pragma once

#include "BinaryTree.h"
#include "my_LinkedlistStack.h"


BTreeNode* MakeExpTree(char exp[]); //���� Ʈ�� ����
int EvaluateExpTree(BTreeNode* bt); //���� Ʈ�� ���

void showPrefixTypeExp(BTreeNode* bt); //���� ǥ��� ��� ���
void showPostfixTypeExp(BTreeNode* bt); //���� ǥ��� ��� ���
void showInfixTypeExp(BTreeNode* bt); // ���� ǥ��� ��� ���

