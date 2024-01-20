#ifndef __AL_GRAGH__
#define __AL_GRAGH__

#include "DLinkedListGraph.h" //use DmyLList 

// 정점 이름 상수화 (enum이용)
enum {A, B, C, D, E, F, G, H ,I, J};

typedef struct _ual
{
	int numV; //정점 수
	int numE; //간선 수
	List* adjList; //간선의 정보(가중치 등...)
} ALGraph;

//그래프 초기화 함수
void GraphInit(ALGraph* pg, int nv);

//그래프 리소스 해제 함수
void GraphDestory(ALGraph* pg);

//간선 추가 함수
void AddEdge(ALGraph* pg, int fromV, int toV);

//간선 정보 출력 함수
void ShowGraphEdgeInfo(ALGraph* pg);














#endif
