#include <stdio.h>
#include <stdlib.h>
#include "Table.h"

void TBLInit(Table * pt, HashFunc * f)
{
	int i;

	for(i=0; i<MAX_TBL; i++)         //Table의 전체 slot형배열을 돌며 
		(pt->tbl[i]).status = EMPTY; //모든 인덱스의 status를 EMPTY로 바꾼다.

	pt->hf = f; //해시 함수를 등록한다.
}

void TBLInsert(Table * pt, Key k, Value v)
{
	int hv = pt->hf(k); //키를 해시함수에 입력해 인덱스를 얻는다.
	pt->tbl[hv].val = v; //인덱스(키)를 이용해 각각의 
	pt->tbl[hv].key = k; //슬롯(구조체)의 멤버에 접근한다.
	pt->tbl[hv].status = INUSE; //슬롯의 status를 INUSE로 바꾼다.
}

Value TBLDelete(Table * pt, Key k)
{
	int hv = pt->hf(k); //키를 해시함수에 입력해 인덱스를 얻는다.

	if((pt->tbl[hv]).status != INUSE) //이미 비어있다면 NULL반환
	{
		return NULL;
	}
	else
	{
		(pt->tbl[hv]).status = DELETED; //사용중이라면 DELETED전환
		return (pt->tbl[hv]).val;		//삭제되는 값(슬롯의 주소) 반환
	}
}

Value TBLSearch(Table * pt, Key k)
{
	int hv = pt->hf(k);

	if((pt->tbl[hv]).status != INUSE)
		return NULL;
	else
		return (pt->tbl[hv]).val; // 탐색 대상 값(슬롯 주소)반환
}