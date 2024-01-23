#include <stdio.h>
#include "ALGraphKruskal.h"

int main(void)
{
	ALGraph graph;
	GraphInit(&graph, 6);      // A, B, C, D, E, F의 정점 생성

	AddEdge(&graph, A, B, 9);
	AddEdge(&graph, B, C, 2);
	AddEdge(&graph, A, C, 12);
	AddEdge(&graph, A, D, 8);
	AddEdge(&graph, D, C, 6);
	AddEdge(&graph, A, F, 11);
	AddEdge(&graph, F, D, 4);
	AddEdge(&graph, D, E, 3);
	AddEdge(&graph, E, C, 7);
	AddEdge(&graph, F, E, 13);

	printf("==크루스칼 적용 이전 그래프 ==\n");
	ShowGraphEdgeInfo(&graph);
	printf("\n");
	printf("==크루스칼 적용 이전 가중치==\n");
	ShowGraphEdgeWeightInfo(&graph);
	printf("\n");

	printf("==크루스칼 적용중...==\n");
	ConKruskalMST(&graph);
	printf("\n");
	printf("==크루스칼 적용 이후 그래프 ==\n");
	ShowGraphEdgeInfo(&graph);
	printf("\n");
	printf("==크루스칼 적용 이후 가중치==\n");
	ShowGraphEdgeWeightInfo(&graph);
	printf("\n");
	GraphDestroy(&graph);
	return 0;
}