#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphKruskal.h"
#include "my_ArrStackDFS.h"

int WhoIsPrecede(int data1, int data2); //비교기준
int VisitVertex(ALGraph* pg, int visitV); //방문한 정점의 인덱스를 1로 바꾼다.
//어떤 정점이 독립적으로 존재하는지 판단한다. 정점이 연결되어있다면 1 반환
int KRSKIsVertexIndependent(ALGraph* pg, int startV, int destiV);
int PQWeightComp(Edge d1, Edge d2); //간선들 내림차순으로 정보 꺼내기 위한 함수
//간선 제거 함수
void RemoveEdge(ALGraph* pg, int v1, int v2);
//간선 복원 함수
void RecoverEdge(ALGraph* pg, int v1, int v2, int weight);
//간선복원 HelperFunc
void RemoveWayEdge(ALGraph* pg, int v1, int v2);

//그래프 초기화 함수
void GraphInit(ALGraph* pg, int nv)
{
	pg->numV = nv;
	pg->numE = 0;
	pg->adjList = (List*)malloc(sizeof(List) * nv); // nv * list만큼 공간 할당
	//정점 수 만큼 int형 공간 갖는 배열 할당(주소를 담기 때문에 int사이즈임)
	for (int i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}

	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);
	//새로 할당받은 visitInfo 초기화 과정 추가
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);

	PQueueInit(&(pg->pqueue), PQWeightComp);
}

//그래프 리소스 해제 함수
void GraphDestroy(ALGraph* pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}

//간선 추가 함수
void AddEdge(ALGraph* pg, int fromV, int toV, int weight)
{
	Edge nEdge = { fromV, toV, weight }; //간선 가중치 정보 저장

	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);

	pg->numE++;

	//간선 가중치 정보 우선순위 큐에 저장
	PEnqueue(&(pg->pqueue), nEdge);
}

//간선 정보 출력 함수
void ShowGraphEdgeInfo(ALGraph* pg)
{
	int vx;

	for (int i = 0; i < pg->numV; i++)
	{
		printf("%c와 연결된 정점: ", i + 65);

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


//그래프의 정보와 시작 정점의 정보를 인자로 받아 모든 정점을 탐색한다.(DFS)
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

		if (VisitVertex(pg, nextV) == TRUE) //방문에 성공했다면
		{
			SPush(&stack, visitV); // 기존 인덱스를 stack에 push한다.
			visitV = nextV; //다음 방문할 인덱스를 최신화 한다.
			visitFlag = TRUE; //아직 정점순회중이라는것을 알린다.
		}
		else //방문에 실패했다면
		{	 //다음으로 방문가능한 연결 노드를 찾는다.
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if (VisitVertex(pg, nextV) == TRUE) //방문에 성공했다면
				{
					SPush(&stack, visitV); // 기존 인덱스를 stack에 push한다.
					visitV = nextV; //다음 방문할 인덱스를 최신화 한다.
					visitFlag = TRUE; //아직 정점순회중이라는것을 알린다.
					break; //다시 가장 바깥 while 문으로 돌아가 반복
				}
				
			}
		}

		if (visitFlag == FALSE) //만약 위의 if-else어디서도 flag가 TRUE가 되지 않았다면
		{
			if (SIsEmpty(&stack) == TRUE)
				break; //거기다 스택까지 비었다면... 탐색 종료
			else
				visitV = SPop(&stack); //스택이 남았다면 하나 꺼내서 다시 반복
		}
	}
	//다음 함수 실행을 위한 visitInfo초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

//방문한 정점의 인덱스를 1로 바꾼다.
int VisitVertex(ALGraph* pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0) //visitV에 처음 방문했다면
	{
		pg->visitInfo[visitV] = 1; //값을 1로 바꾸고
		printf("visited %c\n", visitV + 65); //방문한 정점의 이름을 출력한다.
		return TRUE;
	}
	else
		return FALSE;
}

//어떤 정점이 독립적으로 존재하는지 판단한다. 정점이 연결되어있다면 1 반환
int KRSKIsVertexIndependent(ALGraph* pg, int startV, int destiV)
{
	Stack stack;
	int visitV = startV;
	int nextV;
	int findVflag = FALSE; //정점 찾음 플래그 기본값 0

	SInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;

		if (nextV == destiV)
		{
			memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
			return findVflag = TRUE; //대상 정점 찾았다면 플래그 1 반환
		}
			

		if (VisitVertex(pg, nextV) == TRUE) //방문에 성공했다면
		{
			
			SPush(&stack, visitV); // 기존 인덱스를 stack에 push한다.
			visitV = nextV; //다음 방문할 인덱스를 최신화 한다.
			visitFlag = TRUE; //아직 정점순회중이라는것을 알린다.
		}
		else //방문에 실패했다면
		{	 //다음으로 방문가능한 연결 노드를 찾는다.
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if (nextV == destiV)
				{
					memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
					return findVflag = TRUE; //대상 정점 찾았다면 플래그 1 반환
				}
					

				if (VisitVertex(pg, nextV) == TRUE) //방문에 성공했다면
				{
					SPush(&stack, visitV); // 기존 인덱스를 stack에 push한다.
					visitV = nextV; //다음 방문할 인덱스를 최신화 한다.
					visitFlag = TRUE; //아직 정점순회중이라는것을 알린다.
					break; //다시 가장 바깥 while 문으로 돌아가 반복
				}

			}
		}

		if (visitFlag == FALSE) //만약 위의 if-else어디서도 flag가 TRUE가 되지 않았다면
		{
			if (SIsEmpty(&stack) == TRUE)
				break; //거기다 스택까지 비었다면... 탐색 종료
			else
				visitV = SPop(&stack); //스택이 남았다면 하나 꺼내서 다시 반복
		}
	}
	//다음 함수 실행을 위한 visitInfo초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	
	return findVflag; //대상 정점을 마지막까지 못찾았다면 0 반환

}

// 크루스칼 알고리즘 기반 MST 트리의 구성 함수
void ConKruskalMST(ALGraph* pg)
{
	Edge recvEdge[20]; //복원할 간선 정보 저장 위한 배열
	Edge edge;
	int eidx = 0;
	int i;

	// MST를 형성할 때 까지 while문 반복
	while (pg->numE + 1 > pg->numV) //간선의 수+1이 정점의 수와 동일해지면 멈춘다.
	{
		edge = PDequeue(&(pg->pqueue)); //가중치 순으로 간선 정보 디큐
		RemoveEdge(pg, edge.v1, edge.v2); //디큐된 간선 실제 삭제

		if(!KRSKIsVertexIndependent(pg, edge.v1, edge.v2))
		{
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);
			recvEdge[eidx++] = edge;
		}
	}
	for (i = 0; i < eidx; i++)
		PEnqueue(&(pg->pqueue), recvEdge[i]);
}

// 가중치 정보 출력
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

//간선 제거 함수
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

//간선 복원 함수
void RecoverEdge(ALGraph* pg, int v1, int v2, int weight)
{
	LInsert(&(pg->adjList[v1]), v2);
	LInsert(&(pg->adjList[v2]), v1);
	(pg->numE)++;
}
