#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__
#include "Slot_2.h"

#define TRUE	1
#define FALSE	0

typedef Slot LData;

typedef struct _node // 노드 구조체 정의
{
	LData data;
	struct _node * next;
} Node;

typedef struct _linkedList // 연결리스트 구조체
{
	Node * head;
	Node * cur;
	Node * before;
	int numOfData;
	int (*comp)(LData d1, LData d2);
} LinkedList;
typedef LinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2));
int Descending(LData* newdata, LData* curdata); //오름차순 정렬

#endif