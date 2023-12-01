// ����4-6 int�� ��ť IntDequeue(�ҽ�)
#include <stdio.h>
#include <stdlib.h>
#include "IntDequeue.h"

/*--- ��ť �ʱ�ȭ ---*/
int Initialize(IntDequeue* q, int max)
{
    q->num = q->front = q->rear = 0;
    if ((q->que = calloc(max, sizeof(int))) == NULL) {
        q->max = 0;                         // �迭 ������ ����
        return -1;
    }
    q->max = max;
    return 0;
}

/*--- ��ť�� �� �տ� �����͸� ��ť ---*/
int EnqueFront(IntDequeue* q, int x)
{
    if (q->num >= q->max)
        return -1;                          // ��ť�� ���� ��
    else {
        q->num++;
        if (--q->front < 0)
            q->front = q->max - 1;
        q->que[q->front] = x;
        return 0;
    }
}

/*--- ��ť�� �� �ڿ� �����͸� ��ť ---*/
int EnqueRear(IntDequeue* q, int x)
{
    if (q->num >= q->max)
        return -1;                          // ��ť�� ���� ��
    else {
        q->num++;
        q->que[q->rear++] = x;
        if (q->rear == q->max)
            q->rear = 0;
        return 0;
    }
}

/*--- ��ť�� �� �տ��� �����͸� ��ť ---*/
int DequeFront(IntDequeue* q, int* x)
{
    if (q->num <= 0)                        // ��ť�� ��� ����
        return -1;
    else {
        q->num--;
        *x = q->que[q->front++];
        if (q->front == q->max)
            q->front = 0;
        return 0;
    }
}

/*--- ��ť�� �� �ڿ��� �����͸� ��ť ---*/
int DequeRear(IntDequeue* q, int* x)
{
    if (q->num <= 0)                        // ��ť�� ��� ����
        return -1;
    else {
        q->num--;
        if (--q->rear < 0)
            q->rear = q->max - 1;
        *x = q->que[q->rear];
        return 0;
    }
}

/*--- ��ť�� �� �տ��� �����͸� ��ũ ---*/
int PeekFront(const IntDequeue* q, int* x)
{
    if (q->num <= 0)                        // ��ť�� ��� ����
        return -1;
    *x = q->que[q->front];
    return 0;
}

/*--- ��ť�� �� �ڿ��� �����͸� ��ũ ---*/
int PeekRear(const IntDequeue* q, int* x)
{
    if (q->num <= 0)                        // ��ť�� ��� ����
        return -1;
    if (q->rear -1 < 0)
        *x = q->que[q->max - 1];
    else
        *x = q->que[q->rear - 1];           // �ǹ� EnqueRear�� rear�� ���� ĭ�� ��Ÿ���� �ִµ� �̷����ϸ� ���� ���ñ�? ���� Ʋ�� �� �ƴϾ���.
    return 0;
}

/*--- ��� ������ ���� ---*/
void Clear(IntDequeue* q)
{
    q->num = q->front = q->rear = 0;
}

/*--- ��ť�� �ִ� �뷮 ---*/
int Capacity(const IntDequeue* q)
{
    return q->max;
}

/*--- ��ť�� �׿� �ִ� ������ �� ---*/
int Size(const IntDequeue* q)
{
    return q->num;
}

/*--- ��ť�� ��� �ִ°�? ---*/
int IsEmpty(const IntDequeue* q)
{
    return q->num <= 0;
}

/*--- ��ť�� ���� á�°�? ---*/
int IsFull(const IntDequeue* q)
{
    return q->num >= q->max;
}

/*--- ��ť���� �˻� ---*/
int Search(const IntDequeue* q, int x)
{
    int idx;

    for (int i = 0; i < q->num; i++) {
        if (q->que[idx = (i + q->front) % q->max] == x)
            return idx;     // �˻� ����
    }
    return -1;              // �˻� ����
}

/*--- ��ť���� �˻�(���� �ε����� ��ȯ) ---*/
int Search2(const IntDequeue* q, int x)
{
    for (int i = 0; i < q->num; i++) {
        if (q->que[(i + q->front) % q->max] == x)
            return i;       // �˻� ����
    }
    return -1;              // �˻� ����
}

/*--- ��� ������ ��� ---*/
void Print(const IntDequeue* q)
{
    for (int i = 0; i < q->num; i++)
        printf("%d ", q->que[(i + q->front) % q->max]);
    putchar('\n');
}

/*--- ��ť ���� ---*/
void Terminate(IntDequeue* q)
{
    if (q->que != NULL)
        free(q->que);                           // �迭�� ����
    q->max = q->num = q->front = q->rear = 0;
}
