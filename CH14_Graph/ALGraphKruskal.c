#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphKruskal.h"
#include "my_ArrStackDFS.h"

int WhoIsPrecede(int data1, int data2); //�񱳱���
int VisitVertex(ALGraph* pg, int visitV); //�湮�� ������ �ε����� 1�� �ٲ۴�.
//� ������ ���������� �����ϴ��� �Ǵ��Ѵ�. ������ ����Ǿ��ִٸ� 1 ��ȯ
int KRSKIsVertexIndependent(ALGraph* pg, int startV, int destiV);
int PQWeightComp(Edge d1, Edge d2); //������ ������������ ���� ������ ���� �Լ�
//���� ���� �Լ�
void RemoveEdge(ALGraph* pg, int v1, int v2);
//���� ���� �Լ�
void RecoverEdge(ALGraph* pg, int v1, int v2, int weight);
//�������� HelperFunc
void RemoveWayEdge(ALGraph* pg, int v1, int v2);

//�׷��� �ʱ�ȭ �Լ�
void GraphInit(ALGraph* pg, int nv)
{
	pg->numV = nv;
	pg->numE = 0;
	pg->adjList = (List*)malloc(sizeof(List) * nv); // nv * list��ŭ ���� �Ҵ�
	//���� �� ��ŭ int�� ���� ���� �迭 �Ҵ�(�ּҸ� ��� ������ int��������)
	for (int i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}

	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);
	//���� �Ҵ���� visitInfo �ʱ�ȭ ���� �߰�
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);

	PQueueInit(&(pg->pqueue), PQWeightComp);
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
void AddEdge(ALGraph* pg, int fromV, int toV, int weight)
{
	Edge nEdge = { fromV, toV, weight }; //���� ����ġ ���� ����

	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);

	pg->numE++;

	//���� ����ġ ���� �켱���� ť�� ����
	PEnqueue(&(pg->pqueue), nEdge);
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

//� ������ ���������� �����ϴ��� �Ǵ��Ѵ�. ������ ����Ǿ��ִٸ� 1 ��ȯ
int KRSKIsVertexIndependent(ALGraph* pg, int startV, int destiV)
{
	Stack stack;
	int visitV = startV;
	int nextV;
	int findVflag = FALSE; //���� ã�� �÷��� �⺻�� 0

	SInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;

		if (nextV == destiV)
		{
			memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
			return findVflag = TRUE; //��� ���� ã�Ҵٸ� �÷��� 1 ��ȯ
		}
			

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
				if (nextV == destiV)
				{
					memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
					return findVflag = TRUE; //��� ���� ã�Ҵٸ� �÷��� 1 ��ȯ
				}
					

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
	
	return findVflag; //��� ������ ���������� ��ã�Ҵٸ� 0 ��ȯ

}

// ũ�罺Į �˰��� ��� MST Ʈ���� ���� �Լ�
void ConKruskalMST(ALGraph* pg)
{
	Edge recvEdge[20]; //������ ���� ���� ���� ���� �迭
	Edge edge;
	int eidx = 0;
	int i;

	// MST�� ������ �� ���� while�� �ݺ�
	while (pg->numE + 1 > pg->numV) //������ ��+1�� ������ ���� ���������� �����.
	{
		edge = PDequeue(&(pg->pqueue)); //����ġ ������ ���� ���� ��ť
		RemoveEdge(pg, edge.v1, edge.v2); //��ť�� ���� ���� ����

		if(!KRSKIsVertexIndependent(pg, edge.v1, edge.v2))
		{
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);
			recvEdge[eidx++] = edge;
		}
	}
	for (i = 0; i < eidx; i++)
		PEnqueue(&(pg->pqueue), recvEdge[i]);
}

// ����ġ ���� ���
void ShowGraphEdgeWeightInfo(ALGraph* pg)
{
	for (int i = 1; i < pg->pqueue.numOfData+1; i++)
	{
		printf("from %c to %c, the weight is %d\n",
			pg->pqueue.heapArr[i].v1+65, pg->pqueue.heapArr[i].v2+65,
			pg->pqueue.heapArr[i].weight);
	}
}

int PQWeightComp(Edge d1, Edge d2) //for PQueue
{
	return d1.weight - d2.weight;
}

//���� ���� �Լ�
void RemoveEdge(ALGraph* pg, int v1, int v2)
{
	RemoveWayEdge(pg, v1, v2);
	RemoveWayEdge(pg, v2, v1);

	(pg->numE)--;
}


void RemoveWayEdge(ALGraph* pg, int v1, int v2)
{
	int nextV;

	if (LFirst(&(pg->adjList[v1]), &nextV) == TRUE)
	{
		if (nextV == v2)
		{
			LRemove(&(pg->adjList[v1]));
			return;
		}
		while (LNext(&(pg->adjList[v1]), &nextV) == TRUE)
		{
			if (nextV == v2)
			{
				LRemove(&(pg->adjList[v1]));
				return;
			}
		}
	}
}

//���� ���� �Լ�
void RecoverEdge(ALGraph* pg, int v1, int v2, int weight)
{
	LInsert(&(pg->adjList[v1]), v2);
	LInsert(&(pg->adjList[v2]), v1);
	(pg->numE)++;
}
