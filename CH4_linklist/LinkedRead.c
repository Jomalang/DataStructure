#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node * next;
} Node;

int main(void)
{
	Node* tail = NULL;  // NULL 포인터 초기화
	Node* cur = NULL;
	Node* newNode = NULL;

	Node DMY =
	{ -1,NULL };
	Node * head = &DMY;  // head 더미로 초기화
	
	int readData;

	/**** 데이터를 입력 받는 과정 ****/
	while(1)
	{
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if(readData < 1)
			break;

		/*** 노드의 추가과정 ***/
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head->next == NULL)
			head->next = newNode;
		else
		{
			tail->next = newNode; //그림에서 화살표의 방향 설정
		}
		tail = newNode; //노드가 늘어나는 방향 설정
	}
	printf("\n");

	/**** 입력 받은 데이터의 출력과정 ****/
	printf("입력 받은 데이터의 전체출력! \n");
	if(tail == NULL) 
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else 
	{
		cur = head;

		while(cur->next != NULL)    // 더미 이후의 데이터 출력
		{
			cur = cur->next;
			printf("%d  ", cur->data);
		}
	}
	printf("\n\n");

	/**** 메모리의 해제과정 ****/
	if(tail == NULL) 
	{
		return 0;    // 해제할 노드가 존재하지 않는다.
	}
	else 
	{
		Node * delNode = head;
		Node * delNextNode = head->next;
		
		while(delNextNode != NULL)    // 더미 이후의 노드 삭제 위한 반복문
		{
			
			delNode = delNextNode;
			delNextNode = delNextNode->next; 

			printf("%d을(를) 삭제합니다. \n", delNode->data);
			free(delNode);    // 두 번째 이후의 노드 삭제
		}
	}

	return 0;
}