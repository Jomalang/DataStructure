#ifndef __TABLE_H__
#define __TABLE_H__

#include "DLinkedList_2.h" 

#define MAX_TBL     100
#define True 1
#define FALSE 0

typedef int HashFunc(Key k);

typedef struct _table
{
	List tbl[MAX_TBL];
	HashFunc * hf;
}Table;


// ���̺��� �ʱ�ȭ 
void TBLInit(Table * pt, HashFunc * f);

// ���̺� Ű�� ���� ����
void TBLInsert(Table * pt, Key k, Value v);

// Ű�� �ٰŷ� ���̺��� ������ ����
int TBLDelete(Table * pt, Key k);

// Ű�� �ٰŷ� ���̺��� ������ Ž��
int TBLSearch(Table * pt, Key k);

#endif