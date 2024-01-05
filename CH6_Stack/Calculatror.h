#ifndef __CAL_CUL_ATOR__
#define __CAL_CUL_ATOR__

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "my_ArrStack.h"

void ConvToRPNExp(char exp[]);
int GetOpPrec(char op);
int WhoPrecOp(char op1, char op2);
int AnsExpRPN(char exp[]);
int EvalInfixExp(char exp[]);
int InputExp();

















#endif
