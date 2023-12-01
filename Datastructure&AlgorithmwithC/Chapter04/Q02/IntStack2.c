// int�� ���� IntStack(�ҽ�)
#include <stdio.h>
#include <stdlib.h>
#include "IntStack2.h"

/*--- ���� �ʱ�ȭ ---*/
int Initialize(IntStack* s, int max)
{
    s->ptrA = 0;
    s->ptrB = max - 1;
    if ((s->stk = calloc(max, sizeof(int))) == NULL) {
        s->max = 0;                     // �迭�� ������ ����
        s->ptrB = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

/*--- ���ÿ� ������ Ǫ�� ---*/
int Push(IntStack* s, int sw, int x)
{
    if (s->ptrA > s->ptrB)               // ������ ���� ��
        return -1;
    if (sw == 1)
    s->stk[s->ptrA++] = x;
    else
        s->stk[s->ptrB--] = x;

    return 0;
}

/*--- ���ÿ��� �����͸� ���� ---*/
int Pop(IntStack* s, int sw, int* x)
{
    if (sw == 1)
    {
        if (s->ptrA <= 0)                    // ������ ��� ����
            return -1;
        *x = s->stk[--s->ptrA];
    }
    else
    {
        if (s->ptrB >= s->max - 1)                    // ������ ��� ����
            return -1;
        *x = s->stk[++s->ptrB];
    }
    return 0;
}

/*--- ���ÿ��� ������ ������ ---*/
int Peek(const IntStack* s, int sw, int* x)
{
    if (sw == 1)
    {
        if (s->ptrA <= 0)                    // ������ ��� ����
            return -1;
        *x = s->stk[s->ptrA - 1];
    }
    else
    {
        if (s->ptrB >= s->max - 1)                    // ������ ��� ����
            return -1;
        *x = s->stk[s->ptrB + 1];
    }
    return 0;
}

/*--- ������ ��� ��� ���� ---*/
void Clear(IntStack* s, int sw)
{
    if (sw == 1)
        s->ptrA = 0;
    else
        s->ptrB = s->max - 1;
}

/*--- ���� �뷮 ---*/
int Capacity(const IntStack* s)
{
    return s->max;
}

/*--- ���ÿ� �׿� �ִ� ������ �� ---*/
int Size(const IntStack* s, int sw)
{
    if (sw == 1)
        return s->ptrA;
    else
        return s->max - s->ptrB - 1;
}

/*--- ������ ��� �ִ°�? ---*/
int IsEmpty(const IntStack* s, int sw)
{
    return (sw == 1) ? s->ptrA <= 0 : s->ptrB >= s->max - 1;
}

/*--- ������ ���� á�°�? ---*/
int IsFull(const IntStack* s)
{
    return s->ptrA > s->ptrB;
}

/*--- ���ÿ��� �˻� ---*/
int Search(const IntStack* s, int sw, int x)
{
    if (sw == 1)
    {
        for (int i = s->ptrA - 1; i >= 0; i--)   // �����(top) �� �ٴ�(bottom)���� ���� �˻�
            if (s->stk[i] == x)
                return i;       // �˻� ����
    }
    else
    {
        for (int i = s->ptrB + 1; i < s->max; i++)
            if (s->stk[i] == x)
                return i;
    }
      
    return -1;              // �˻� ����
}

/*--- ��� ������ ��� ---*/
void Print(const IntStack* s, int sw)
{
    if(sw == 1)
        for (int i = 0; i < s->ptrA; i++)        // �ٴ�(bottom) �� �����(top)�� ��ĵ
            printf("%d ", s->stk[i]);
    else
        for (int i = s->max-1; i > s->ptrB; i--)
            printf("%d ", s->stk[i]);
    putchar('\n');
}

/*--- ���� ���� ---*/
void Terminate(IntStack* s)
{
    if (s->stk != NULL)
        free(s->stk);       // �迭�� ����
    s->max = s->ptrA = s->ptrB = 0;
}

//// ����4-2 �迭 ���� int�� ���� IntStack2(�ҽ�)
//#include <stdio.h>
//#include <stdlib.h>
//#include "IntStack2.h"
//
///*--- ���� �ʱ�ȭ ---*/
//int Initialize(IntStack* s, int max)
//{
//    s->ptrA = 0;
//    if ((s->stk = calloc(max, sizeof(int))) == NULL) {
//        s->max = 0;                             // �迭 ������ ����
//        s->ptrB = 0;
//        return -1;
//    }
//    s->ptrB = max - 1;
//    s->max = max;
//    return 0;
//}
//
///*--- ���ÿ� �����͸� Ǫ�� ---*/
//int Push(IntStack* s, int sw, int x)
//{
//    if (s->ptrA >= s->ptrB + 1)                 // ������ ���� ��
//        return -1;
//
//    switch (sw) {
//    case StackA: s->stk[s->ptrA++] = x;  break;
//    case StackB: s->stk[s->ptrB--] = x;  break;
//    }
//    return 0;
//}
//
///*--- ���ÿ��� �����͸� �� ---*/
//int Pop(IntStack* s, int sw, int* x)
//{
//    switch (sw) {
//    case StackA:
//        if (s->ptrA <= 0)                       // ������ �����
//            return -1;
//        *x = s->stk[--s->ptrA];
//        break;
//
//    case StackB:
//        if (s->ptrB >= s->max - 1)              // ������ �����
//            return -1;
//        *x = s->stk[++s->ptrB];
//        break;
//    }
//    return 0;
//}
//
///*--- ���ÿ��� �����͸� ��ũ ---*/
//int Peek(const IntStack* s, int sw, int* x)
//{
//    switch (sw) {
//    case StackA:
//        if (s->ptrA <= 0)                       // ������ �����
//            return -1;
//        *x = s->stk[s->ptrA - 1];
//        break;
//
//    case StackB:
//        if (s->ptrB >= s->max - 1)              // ������ �����
//            return -1;
//        *x = s->stk[s->ptrB + 1];
//        break;
//    }
//    return 0;
//}
//
///*--- ���� ���� ---*/
//void Clear(IntStack* s, int sw)
//{
//    switch (sw) {
//    case StackA: s->ptrA = 0;          break;
//    case StackB: s->ptrB = s->max - 1; break;
//    }
//}
//
///*--- ���� �뷮 ---*/
//int Capacity(const IntStack* s)
//{
//    return s->max;
//}
//
///*--- ���ÿ� �׿� �ִ� ������ ����---*/
//int Size(const IntStack* s, int sw)
//{
//    return (sw == StackA) ? s->ptrA : s->max - s->ptrB - 1;
//}
//
///*--- ������ ��� �ִ°�? ---*/
//int IsEmpty(const IntStack* s, int sw)
//{
//    return (sw == StackA) ? (s->ptrA <= 0) : (s->ptrB >= s->max - 1);
//}
//
///*--- ������ ���� á�°�? ---*/
//int IsFull(const IntStack* s)
//{
//    return s->ptrA >= s->ptrB + 1;
//}
//
///*--- ���ÿ��� �˻� ---*/
//int Search(const IntStack* s, int sw, int x)
//{
//    switch (sw) {
//    case StackA:
//        for (int i = s->ptrA - 1; i >= 0; i--)      // �����(top) �� �ٴ�(bottom)���� ���� �˻�
//            if (s->stk[i] == x)
//                return i;       // �˻� ����
//        return -1;              // �˻� ����
//
//    case StackB:
//        for (int i = s->ptrB + 1; i < s->max; i++)  // �����(top) �� �ٴ�(bottom)���� ���� �˻�
//            if (s->stk[i] == x)
//                return i;       // �˻� ����
//        return -1;              // �˻� ����
//    }
//}
//
///*--- ��� ������ ��� ---*/
//void Print(const IntStack* s, int sw)
//{
//    switch (sw) {
//    case StackA:
//        for (int i = 0; i < s->ptrA; i++)           // �ٴ�(bottom) �� �����(top)�� ��ĵ
//            printf("%d ", s->stk[i]);
//        break;
//
//    case StackB:
//        for (int i = s->max - 1; i > s->ptrB; i--)  // �ٴ�(bottom) �� �����(top)�� ��ĵ
//            printf("%d ", s->stk[i]);
//        break;
//    }
//    putchar('\n');
//}
//
///*--- ���� ���� ---*/
//void Terminate(IntStack* s)
//{
//    if (s->stk != NULL)
//        free(s->stk);               // �迭�� ����
//    s->max = s->ptrA = s->ptrB = 0;
//}
