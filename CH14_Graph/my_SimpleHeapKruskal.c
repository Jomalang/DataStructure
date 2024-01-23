#include "my_SimpleHeapKruskal.h"
#include <stdio.h>
#include <stdlib.h>

void HeapInit(Heap* ph, PriorityComp pc) //�� �ʱ�ȭ
{
	ph->comp = pc;
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
		if (ph->comp(ph->heapArr[GetLChildIDX(idx)], //�Լ������� ��� 
			ph->heapArr[GetRChildIDX(idx)]) < 0)    
			return GetRChildIDX(idx); 
		else										
			return GetLChildIDX(idx); 
	}
}


HData HDelete(Heap* ph) // �� ��Ʈ��� ����
{
	HData rdata = ph->heapArr[1];
	HData lastdata = ph->heapArr[ph->numOfData];
	int parentIDX = 1;
	int childIDX;

	while (childIDX = GetHiPriChildIDX(ph, parentIDX))
	{
		if (ph->comp(lastdata, ph->heapArr[childIDX]) >= 0)
			break;
	
		ph->heapArr[parentIDX] = ph->heapArr[childIDX];
		parentIDX = childIDX;

	}

	ph->heapArr[parentIDX] = lastdata;
	ph->numOfData -= 1;
	return rdata;

}

void HInsert(Heap* ph, HData data)
{
	int newIDX = ph->numOfData + 1;

	while (newIDX != 1)
	{   // �θ𺸴� �켱������ ���ٸ�
		if (ph->comp(data, ph->heapArr[GetParentIDX(newIDX)]) > 0)
		{   //�޸𸮻� ����
			ph->heapArr[newIDX] = ph->heapArr[GetParentIDX(newIDX)];
			newIDX = GetParentIDX(newIDX); //���� ������ �ε��� ����
		}
		else //�켱���� ���ٸ�(���ڸ� ã�� ��)
			break; //������ Ż��
	}
	ph->heapArr[newIDX] = data;
	ph->numOfData += 1;
}