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


// 테이블의 초기화 
void TBLInit(Table * pt, HashFunc * f);

// 테이블에 키와 값을 저장
void TBLInsert(Table * pt, Key k, Value v);

// 키를 근거로 테이블에서 데이터 삭제
int TBLDelete(Table * pt, Key k);

// 키를 근거로 테이블에서 데이터 탐색
int TBLSearch(Table * pt, Key k);

#endif