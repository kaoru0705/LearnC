// ����4-3 int�� ť ArrayIntQueue(�ҽ�)
#include <stdio.h>
#include <stdlib.h>
#include "ArrayIntQueue.h"

/*--- ť �ʱ�ȭ ---*/
int Initialize(ArrayIntQueue* q, int max)
{
    q->num = 0;
    if ((q->que = calloc(max, sizeof(int))) == NULL) {
        q->max = 0;                             // �迭 ������ ����
        return -1;
    }
    q->max = max;
    return 0;
}

/*--- ť�� �����͸� ��ť ---*/
int Enque(ArrayIntQueue* q, int x)
{
    if (q->num >= q->max)
        return -1;                              // ť�� ���� ��
    else {
        q->que[q->num++] = x;
        return 0;
    }
}

/*--- ť���� �����͸� ��ť ---*/
int Deque(ArrayIntQueue* q, int* x)
{
    if (q->num <= 0)                            // ť�� ��� ����
        return -1;
    else {
        *x = q->que[0];
        for (int i = 0; i < q->num - 1; i++)
            q->que[i] = q->que[i + 1];
        q->num--;
        return 0;
    }
}

/*--- ť���� �����͸� ��ũ ---*/
int Peek(const ArrayIntQueue* q, int* x)
{
    if (q->num <= 0)                            // ť�� ��� ����
        return -1;
    *x = q->que[0];
    return 0;
}

/*--- ��� ������ ���� ---*/
void Clear(ArrayIntQueue* q)
{
    q->num = 0;
}

/*--- ť�� �ִ� �뷮 ---*/
int Capacity(const ArrayIntQueue* q)
{
    return q->max;
}

/*--- ť�� �׿� �ִ� ������ �� ---*/
int Size(const ArrayIntQueue* q)
{
    return q->num;
}

/*--- ť�� ��� �ִ°�? ---*/
int IsEmpty(const ArrayIntQueue* q)
{
    return q->num <= 0;
}

/*--- ť�� ���� á�°�? ---*/
int IsFull(const ArrayIntQueue* q)
{
    return q->num >= q->max;
}

/*--- ť���� �˻� ---*/
int Search(const ArrayIntQueue* q, int x)
{
    for (int i = 0; i < q->num; i++) {
        if (q->que[i] == x)
            return i;       // �˻� ����
    }
    return -1;              // �˻� ����
}

/*--- ��� ������ ��� ---*/
void Print(const ArrayIntQueue* q)
{
    for (int i = 0; i < q->num; i++)
        printf("%d ", q->que[i]);
    putchar('\n');
}

/*--- ť ���� ---*/
void Terminate(ArrayIntQueue* q)
{
    if (q->que != NULL)
        free(q->que);                           // �迭�� ����
    q->max = q->num = 0;
}
