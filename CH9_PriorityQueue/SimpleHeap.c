#include "SimpleHeap.h"
#include <stdio.h>
#include <stdlib.h>

void HeapInit(Heap* ph) //힙 초기화
{
	ph->numOfData = 0;
}

int HIsEmpty(Heap* ph) // 힙 비었는지 numOfData로 판단
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) //부모 노드 인덱스 반환
{
	return idx / 2;
}

int GetLChildIDX(int idx)
{
	return idx * 2;
}

int GetRChildIDX(int idx)
{
	return (idx * 2) + 1;
}

int GetHiPriChildIDX(Heap* ph, int idx) //자식노드 우선순위 판별
{
	if (GetLChildIDX(idx) > ph->numOfData)
		return 0;
	else if (GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);
	else
	{
		if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}


HData HDelete(Heap* ph) // 힙 루트노드 삭제
{
	HData rdata = (ph->heapArr[1]).data;
	HeapElem LastElem = ph->heapArr[ph->numOfData];
	int parentIDX = 1;
	int childIDX;

	while (childIDX = GetHiPriChildIDX(ph, parentIDX))
	{
		if (LastElem.pr >= ph->heapArr[childIDX].pr)
		{
			ph->heapArr[parentIDX] = ph->heapArr[childIDX];
			parentIDX = childIDX;
		}
		else
			break;
	}

	ph->heapArr[parentIDX] = LastElem;
	ph->numOfData -= 1;
	return rdata;

}

void HInsert(Heap* ph, HData data, Priority pr)
{
	int newIDX = ph->numOfData + 1;
	HeapElem newlem = { pr, data }; //최종 저장할 노드 정보 임시저장

	while (newIDX != 1)
	{   // 부모보다 우선순위가 높다면
		if (ph->heapArr[GetParentIDX(newIDX)].pr >= pr)
		{   //메모리상 스왑
			ph->heapArr[newIDX] = ph->heapArr[GetParentIDX(newIDX)];
			newIDX = GetParentIDX(newIDX); //다음 비교위한 인덱스 갱신
		}
		else //우선순위 낮다면(제자리 찾은 것)
			break; //루프문 탈출
	}
	ph->heapArr[newIDX] = newlem;
	ph->numOfData += 1;
}