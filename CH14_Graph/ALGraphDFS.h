#ifndef __AL_GRAGH__
#define __AL_GRAGH__

#include "DLinkedListGraph.h" //use DmyLList 

// ���� �̸� ���ȭ (enum�̿�)
enum {A, B, C, D, E, F, G, H ,I, J};

typedef struct _ual
{
	int numV; //���� ��
	int numE; //���� ��
	List* adjList; //������ ����(����ġ ��...)
	int* visitInfo;
} ALGraph;

//�׷��� �ʱ�ȭ �Լ�
void GraphInit(ALGraph* pg, int nv);

//�׷��� ���ҽ� ���� �Լ�
void GraphDestroy(ALGraph* pg);

//���� �߰� �Լ�
void AddEdge(ALGraph* pg, int fromV, int toV);

//���� ���� ��� �Լ�
void ShowGraphEdgeInfo(ALGraph* pg);

//�׷����� ������ ���� ������ ������ ���ڷ� �޾� ��� ������ Ž���Ѵ�.(DFS)
void DFShowGraphVertex(ALGraph* pg, int startV);

#endif
