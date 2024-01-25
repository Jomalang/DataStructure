#include <stdio.h>
#include "ALGraphKruskal.h"

int main(void)
{
	ALGraph graph;
	GraphInit(&graph, 14);      // A, B, C, D, E, F�� ���� ����

	AddEdge(&graph, A, D, 9);
	AddEdge(&graph, B, D, 2);
	AddEdge(&graph, C, D, 12);
	AddEdge(&graph, D, D, 6);
	AddEdge(&graph, F, D, 4);
	AddEdge(&graph, D, D, 3);
	AddEdge(&graph, E, D, 7);
	AddEdge(&graph, J, D, 15);
	AddEdge(&graph, N, D, 20);
	AddEdge(&graph, M, D, 17);
	AddEdge(&graph, G, D, 19);
	AddEdge(&graph, H, D, 17);
	AddEdge(&graph, I, D, 13);
	AddEdge(&graph, K, D, 13);
	AddEdge(&graph, L, D, 13);

	printf("==ũ�罺Į ���� ���� �׷��� ==\n");
	ShowGraphEdgeInfo(&graph);
	printf("\n");
	printf("==ũ�罺Į ���� ���� ����ġ==\n");
	ShowGraphEdgeWeightInfo(&graph);
	printf("\n");

	printf("==ũ�罺Į ������...==\n");
	ConKruskalMST(&graph);
	printf("\n");
	printf("==ũ�罺Į ���� ���� �׷��� ==\n");
	ShowGraphEdgeInfo(&graph);
	printf("\n");
	printf("==ũ�罺Į ���� ���� ����ġ==\n");
	ShowGraphEdgeWeightInfo(&graph);
	printf("\n");
	GraphDestroy(&graph);
	return 0;
}