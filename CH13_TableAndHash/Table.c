#include <stdio.h>
#include <stdlib.h>
#include "Table.h"

void TBLInit(Table * pt, HashFunc * f)
{
	int i;

	for(i=0; i<MAX_TBL; i++)         //Table�� ��ü slot���迭�� ���� 
		(pt->tbl[i]).status = EMPTY; //��� �ε����� status�� EMPTY�� �ٲ۴�.

	pt->hf = f; //�ؽ� �Լ��� ����Ѵ�.
}

void TBLInsert(Table * pt, Key k, Value v)
{
	int hv = pt->hf(k); //Ű�� �ؽ��Լ��� �Է��� �ε����� ��´�.
	pt->tbl[hv].val = v; //�ε���(Ű)�� �̿��� ������ 
	pt->tbl[hv].key = k; //����(����ü)�� ����� �����Ѵ�.
	pt->tbl[hv].status = INUSE; //������ status�� INUSE�� �ٲ۴�.
}

Value TBLDelete(Table * pt, Key k)
{
	int hv = pt->hf(k); //Ű�� �ؽ��Լ��� �Է��� �ε����� ��´�.

	if((pt->tbl[hv]).status != INUSE) //�̹� ����ִٸ� NULL��ȯ
	{
		return NULL;
	}
	else
	{
		(pt->tbl[hv]).status = DELETED; //������̶�� DELETED��ȯ
		return (pt->tbl[hv]).val;		//�����Ǵ� ��(������ �ּ�) ��ȯ
	}
}

Value TBLSearch(Table * pt, Key k)
{
	int hv = pt->hf(k);

	if((pt->tbl[hv]).status != INUSE)
		return NULL;
	else
		return (pt->tbl[hv]).val; // Ž�� ��� ��(���� �ּ�)��ȯ
}