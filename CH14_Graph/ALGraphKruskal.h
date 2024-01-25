#ifndef __AL_GRAGH__
#define __AL_GRAGH__

#include "DLinkedListGraph.h" //use DmyLList 
#include "ALEdge.h" //간선의 가중치 정보 담는 구조체 헤더
#include "PriorityQueueKruskal.h" // 가중치 구조체를 담을 우선순위 큐

// 정점 이름 상수화 (enum이용)
enum {A, B, C, D, E, F, G, H ,I, J, K, L ,N, M, O, P, Q};

typedef struct _ual
{
	int numV; //정점 수
	int numE; //간선 수
	List* adjList; //간선의 정보(가중치 등...)
	int* visitInfo;
	PQueue pqueue; //간선의 가중치 정보 담는 우선순위 큐(정렬 필요하기 때문)
	
} ALGraph;

//그래프 초기화 함수
void GraphInit(ALGraph* pg, int nv);

//그래프 리소스 해제 함수
void GraphDestroy(ALGraph* pg);

//간선 추가 함수
void AddEdge(ALGraph* pg, int fromV, int toV, int weight);

//간선 정보 출력 함수
void ShowGraphEdgeInfo(ALGraph* pg);

//그래프의 정보와 시작 정점의 정보를 인자로 받아 모든 정점을 탐색한다.(DFS)
void DFShowGraphVertex(ALGraph* pg, int startV);

// MST 트리의 구성
void ConKruskalMST(ALGraph* pg);

// 가중치 정보 출력
void ShowGraphEdgeWeightInfo(ALGraph* pg);

#endif
