#ifndef __AL_GRAGH__
#define __AL_GRAGH__

#include "DLinkedListGraph.h" //use DmyLList 
#include "ALEdge.h" //������ ����ġ ���� ��� ����ü ���
#include "PriorityQueueKruskal.h" // ����ġ ����ü�� ���� �켱���� ť

// ���� �̸� ���ȭ (enum�̿�)
enum {A, B, C, D, E, F, G, H ,I, J, K, L ,N, M, O, P, Q};

typedef struct _ual
{
	int numV; //���� ��
	int numE; //���� ��
	List* adjList; //������ ����(����ġ ��...)
	int* visitInfo;
	PQueue pqueue; //������ ����ġ ���� ��� �켱���� ť(���� �ʿ��ϱ� ����)
	
} ALGraph;

//�׷��� �ʱ�ȭ �Լ�
void GraphInit(ALGraph* pg, int nv);

//�׷��� ���ҽ� ���� �Լ�
void GraphDestroy(ALGraph* pg);

//���� �߰� �Լ�
void AddEdge(ALGraph* pg, int fromV, int toV, int weight);

//���� ���� ��� �Լ�
void ShowGraphEdgeInfo(ALGraph* pg);

//�׷����� ������ ���� ������ ������ ���ڷ� �޾� ��� ������ Ž���Ѵ�.(DFS)
void DFShowGraphVertex(ALGraph* pg, int startV);

// MST Ʈ���� ����
void ConKruskalMST(ALGraph* pg);

// ����ġ ���� ���
void ShowGraphEdgeWeightInfo(ALGraph* pg);

#endif
