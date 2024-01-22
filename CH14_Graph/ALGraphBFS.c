#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ALGraphBFS.h"
#include "my_CircularQueueBFS.h"

int WhoIsPrecede(int data1, int data2); //비교기준
int VisitVertex(ALGraph* pg, int visitV); //방문한 정점 기록 함수

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

//너비우선 탐색 함수
void BFShowGraphVertex(ALGraph* pg, int stratV)
{
	CQueue queue;
	int visitV = stratV;
	int nextV; 

	QueueInit(&queue);
	VisitVertex(pg, visitV); //첫 노드 방문 
	
	while (1)
	{
		if (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
		{													
			if(VisitVertex(pg, nextV) == TRUE) // nextV방문 성공했다면
				Enqueue(&queue, nextV);//enqueue연산함

			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if (VisitVertex(pg, nextV) == TRUE) // nextV방문 성공했다면
					Enqueue(&queue, nextV);//enqueue연산함
			}
		}

		if (QIsEmpty(&queue))
			break;

		visitV = Dequeue(&queue); //visitV최신화 후 반복
	}
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