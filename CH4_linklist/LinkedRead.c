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
	Node* tail = NULL;  // NULL ������ �ʱ�ȭ
	Node* cur = NULL;
	Node* newNode = NULL;

	Node DMY =
	{ -1,NULL };
	Node * head = &DMY;  // head ���̷� �ʱ�ȭ
	
	int readData;

	/**** �����͸� �Է� �޴� ���� ****/
	while(1)
	{
		printf("�ڿ��� �Է�: ");
		scanf("%d", &readData);
		if(readData < 1)
			break;

		/*** ����� �߰����� ***/
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head->next == NULL)
			head->next = newNode;
		else
		{
			tail->next = newNode; //�׸����� ȭ��ǥ�� ���� ����
		}
		tail = newNode; //��尡 �þ�� ���� ����
	}
	printf("\n");

	/**** �Է� ���� �������� ��°��� ****/
	printf("�Է� ���� �������� ��ü���! \n");
	if(tail == NULL) 
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	}
	else 
	{
		cur = head;

		while(cur->next != NULL)    // ���� ������ ������ ���
		{
			cur = cur->next;
			printf("%d  ", cur->data);
		}
	}
	printf("\n\n");

	/**** �޸��� �������� ****/
	if(tail == NULL) 
	{
		return 0;    // ������ ��尡 �������� �ʴ´�.
	}
	else 
	{
		Node * delNode = head;
		Node * delNextNode = head->next;
		
		while(delNextNode != NULL)    // ���� ������ ��� ���� ���� �ݺ���
		{
			
			delNode = delNextNode;
			delNextNode = delNextNode->next; 

			printf("%d��(��) �����մϴ�. \n", delNode->data);
			free(delNode);    // �� ��° ������ ��� ����
		}
	}

	return 0;
}