/* Linked list로 구현한 Queue */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* prev;
    struct Node* next;
}Node;

Node* head;

void InitQueue()
{
    head = (Node*)malloc(sizeof(Node));
    head->prev = NULL;
    head->next = NULL;
}

void Insert(int data)
{

    Node* New;
    Node* tail;

    for (tail = head; tail->next; tail = tail->next) { ; }

    New = (Node*)malloc(sizeof(Node));
    New->value = data;
    New->next = NULL;
    New->prev = tail;
    tail->next = New;
}

int Delete()
{
    int data;
    Node* Target;
    Target = head->next;

    if (Target == NULL)
        return -1;

    data = Target->value;
    head->next = Target->next;

    if (head->next)
        head->next->prev = head;

    free(Target);

    return data;
}

void FreeQueue()
{
    while (Delete() != -1) { ; }

    free(head);

    head = NULL;
}

void main()
{
    int i;

    InitQueue();

    for (i = 0; i < 100; i++)
        Insert(i);

    for (i = 0; i < 100; i++)
        printf("%d  ", Delete());

    FreeQueue();
}