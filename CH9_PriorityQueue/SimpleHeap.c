#include "SimpleHeap.h"
#include <stdio.h>
#include <stdlib.h>

void HeapInit(Heap* ph) //�� �ʱ�ȭ
{
	ph->numOfData = 0;
}

int HIsEmpty(Heap* ph) // �� ������� numOfData�� �Ǵ�
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) //�θ� ��� �ε��� ��ȯ
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

int GetHiPriChildIDX(Heap* ph, int idx) //�ڽĳ�� �켱���� �Ǻ�
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


HData HDelete(Heap* ph) // �� ��Ʈ��� ����
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
	HeapElem newlem = { pr, data }; //���� ������ ��� ���� �ӽ�����

	while (newIDX != 1)
	{   // �θ𺸴� �켱������ ���ٸ�
		if (ph->heapArr[GetParentIDX(newIDX)].pr >= pr)
		{   //�޸𸮻� ����
			ph->heapArr[newIDX] = ph->heapArr[GetParentIDX(newIDX)];
			newIDX = GetParentIDX(newIDX); //���� ������ �ε��� ����
		}
		else //�켱���� ���ٸ�(���ڸ� ã�� ��)
			break; //������ Ż��
	}
	ph->heapArr[newIDX] = newlem;
	ph->numOfData += 1;
}