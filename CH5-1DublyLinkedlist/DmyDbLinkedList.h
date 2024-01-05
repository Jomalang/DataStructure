#ifndef DMY_DB_LINKED_LIST
#define DMY_DB_LINKED_LIST

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
	struct _node* prev;
} Node;

typedef struct _dbDLinkedList
{
	Node* head;
	Node* tail;
	Node* cur;
	int numOfData;
} DBDLinkedList;

typedef DBDLinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, Data data); //add new node to tail.

int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* padata);

Data LRemove(List* plist); //remove the node cur pointed.
int Lcount(List* plist);

#endif
