#pragma once

#include "BinaryTree.h"
#include "my_LinkedlistStack.h"


BTreeNode* MakeExpTree(char exp[]); //수식 트리 구성
int EvaluateExpTree(BTreeNode* bt); //수식 트리 계산

void showPrefixTypeExp(BTreeNode* bt); //전위 표기법 기반 출력
void showPostfixTypeExp(BTreeNode* bt); //중위 표기법 기반 출력
void showInfixTypeExp(BTreeNode* bt); // 후위 표기법 기반 출력

