// int�� ���� IntStack(���)
#ifndef ___IntStack2
#define ___IntStack2

/*--- ������ �����ϴ� ����ü ---*/
typedef struct {
    int max;    // ���� �뷮
    int ptrA;   // ���� ������
    int ptrB;   //
    int* stk;   // ������ ù ��ҿ� ���� ������
} IntStack;

/*--- ���� �ʱ�ȭ ---*/
int Initialize(IntStack* s, int max);

/*--- ���ÿ� �����͸� Ǫ�� ---*/
int Push(IntStack* s,int sw, int x);

/*--- ���ÿ��� �����͸� �� ---*/
int Pop(IntStack* s, int sw, int* x);

/*--- ���ÿ��� �����͸� ��ũ ---*/
int Peek(const IntStack* s, int sw, int* x);

/*--- ���� ���� ---*/
void Clear(IntStack* s, int sw);

/*--- ������ �ִ� �뷮 ---*/
int Capacity(const IntStack* s);

/*--- ������ ������ ���� ---*/
int Size(const IntStack* s, int sw);

/*--- ������ ��� �ֳ���? ---*/
int IsEmpty(const IntStack* s, int sw);

/*--- ������ ���� á����? ---*/
int IsFull(const IntStack* s);

/*--- ���ÿ��� �˻� ---*/
int Search(const IntStack* s, int sw, int x);

/*--- ��� ������ ��� ---*/
void Print(const IntStack* s, int sw);

/*--- ���� ���� ---*/
void Terminate(IntStack* s);
#endif
//// ����4-2 �迭 ���� int�� ���� IntStack2(���)
//#ifndef ___IntStack2
//#define ___IntStack2
//
//enum { StackA, StackB }; // ģȭ�� interface
//
///*--- �迭 ���� ������ �����ϴ� ����ü ---*/
//typedef struct {
//    int max;        // ���� �뷮
//    int ptrA;       // ���� ������ ��
//    int ptrB;       // ���� ������ ��
//    int* stk;       // ������ ù ��ҿ� ���� ������
//} IntStack;
//
///*--- ���� �ʱ�ȭ ---*/
//int Initialize(IntStack* s, int max);
//
///*--- ���ÿ� �����͸� Ǫ�� ---*/
//int Push(IntStack* s, int sw, int x);
//
///*--- ���ÿ��� �����͸� �� ---*/
//int Pop(IntStack* s, int sw, int* x);
//
///*--- ���ÿ��� �����͸� ��ũ ---*/
//int Peek(const IntStack* s, int sw, int* x);
//
///*--- ���� ���� ---*/
//void Clear(IntStack* s, int sw);
//
///*--- ���� �뷮 ---*/
//int Capacity(const IntStack* s);
//
///*--- ���ÿ� �׿� �ִ� ������ ����---*/
//int Size(const IntStack* s, int sw);
//
///*--- ������ ��� �ִ°�? ---*/
//int IsEmpty(const IntStack* s, int sw);
//
///*--- ������ ���� á�°�? ---*/
//int IsFull(const IntStack* s);
//
///*--- ���ÿ��� �˻� ---*/
//int Search(const IntStack* s, int sw, int x);
//
///*--- ��� ������ ��� ---*/
//void Print(const IntStack* s, int sw);
//
///*--- ���� ���� ---*/
//void Terminate(IntStack* s);
//
//#endif
