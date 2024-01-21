#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphDFS.h"
#include "my_ArrStackDFS.h"

int WhoIsPrecede(int data1, int data2); //�񱳱���
int VisitVertex(ALGraph* pg, int visitV); //�湮�� ������ �ε����� 1�� �ٲ۴�.

//�׷��� �ʱ�ȭ �Լ�
void GraphInit(ALGraph* pg, int nv)
{
	pg->numV = nv;
	pg->numE = 0;
	pg->adjList = (List*)malloc(sizeof(List) * nv); // nv * list��ŭ ���� �Ҵ�
	//���� �� ��ŭ int�� ���� ���� �迭 �Ҵ�(�ּҸ� ��� ������ int��������)
	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV); 
	//���� �Ҵ���� visitInfo �ʱ�ȭ ���� �߰�
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	
	for (int i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}
}

//�׷��� ���ҽ� ���� �Լ�
void GraphDestroy(ALGraph* pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}

//���� �߰� �Լ�
void AddEdge(ALGraph* pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);

	pg->numE++;
}

//���� ���� ��� �Լ�
void ShowGraphEdgeInfo(ALGraph* pg)
{
	int vx;

	for (int i = 0; i < pg->numV; i++)
	{
		printf("%c�� ����� ����: ", i + 65);

		if (LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65);
			while(LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}


int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}


//�׷����� ������ ���� ������ ������ ���ڷ� �޾� ��� ������ Ž���Ѵ�.(DFS)
void DFShowGraphVertex(ALGraph* pg, int startV)
{
	Stack stack;
	int visitV = startV;
	int nextV;

	SInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE) //�湮�� �����ߴٸ�
		{
			SPush(&stack, visitV); // ���� �ε����� stack�� push�Ѵ�.
			visitV = nextV; //���� �湮�� �ε����� �ֽ�ȭ �Ѵ�.
			visitFlag = TRUE; //���� ������ȸ���̶�°��� �˸���.
		}
		else //�湮�� �����ߴٸ�
		{	 //�������� �湮������ ���� ��带 ã�´�.
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if (VisitVertex(pg, nextV) == TRUE) //�湮�� �����ߴٸ�
				{
					SPush(&stack, visitV); // ���� �ε����� stack�� push�Ѵ�.
					visitV = nextV; //���� �湮�� �ε����� �ֽ�ȭ �Ѵ�.
					visitFlag = TRUE; //���� ������ȸ���̶�°��� �˸���.
					break; //�ٽ� ���� �ٱ� while ������ ���ư� �ݺ�
				}
				
			}
		}

		if (visitFlag == FALSE) //���� ���� if-else��𼭵� flag�� TRUE�� ���� �ʾҴٸ�
		{
			if (SIsEmpty(&stack) == TRUE)
				break; //�ű�� ���ñ��� ����ٸ�... Ž�� ����
			else
				visitV = SPop(&stack); //������ ���Ҵٸ� �ϳ� ������ �ٽ� �ݺ�
		}
	}
	//���� �Լ� ������ ���� visitInfo�ʱ�ȭ
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

//�湮�� ������ �ε����� 1�� �ٲ۴�.
int VisitVertex(ALGraph* pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0) //visitV�� ó�� �湮�ߴٸ�
	{
		pg->visitInfo[visitV] = 1; //���� 1�� �ٲٰ�
		printf("visited %c\n", visitV + 65); //�湮�� ������ �̸��� ����Ѵ�.
		return TRUE;
	}
	else
		return FALSE;

}