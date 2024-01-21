#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphDFS.h"
#include "my_ArrStackDFS.h"

int WhoIsPrecede(int data1, int data2); //비교기준
int VisitVertex(ALGraph* pg, int visitV); //방문한 정점의 인덱스를 1로 바꾼다.

//그래프 초기화 함수
void GraphInit(ALGraph* pg, int nv)
{
	pg->numV = nv;
	pg->numE = 0;
	pg->adjList = (List*)malloc(sizeof(List) * nv); // nv * list만큼 공간 할당
	//정점 수 만큼 int형 공간 갖는 배열 할당(주소를 담기 때문에 int사이즈임)
	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV); 
	//새로 할당받은 visitInfo 초기화 과정 추가
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	
	for (int i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}
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
void AddEdge(ALGraph* pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);

	pg->numE++;
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