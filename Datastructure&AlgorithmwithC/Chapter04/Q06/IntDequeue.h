// ����4-6 int�� ��ť IntDequeue(���) ����� ��⿭
#ifndef ___IntDequeue
#define ___IntDequeue

/*--- ��ť�� �����ϴ� ����ü ---*/
typedef struct {
    int max;        // ��ť�� �ִ� �뷮
    int num;        // ������ ������ ��
    int front;      // �� �� ��� Ŀ��
    int rear;       // �� �� ��� Ŀ��
    int* que;       // ��ť�� �� �� ��ҿ� ���� ������
} IntDequeue;

/*--- ��ť  �ʱ�ȭ ---*/
int Initialize(IntDequeue* q, int max);

/*--- ��ť�� �� �տ� �����͸� ��ť ---*/
int EnqueFront(IntDequeue* q, int x);

/*--- ��ť�� �� �ڿ� �����͸� ��ť ---*/
int EnqueRear(IntDequeue* q, int x);

/*--- ��ť�� �� �տ��� �����͸� ��ť ---*/
int DequeFront(IntDequeue* q, int* x);

/*--- ��ť�� �� �ڿ��� �����͸� ��ť ---*/
int DequeRear(IntDequeue* q, int* x);

/*--- ��ť�� �� �տ��� �����͸� ��ũ ---*/
int PeekFront(const IntDequeue* q, int* x);

/*--- ��ť�� �� �ڿ��� �����͸� ��ũ ---*/
int PeekRear(const IntDequeue* q, int* x);

/*--- ��� ������ ���� ---*/
void Clear(IntDequeue* q);

/*--- ��ť �� �ִ� �뷮 ---*/
int Capacity(const IntDequeue* q);

/*--- ��ť �� ����� ������ �� ---*/
int Size(const IntDequeue* q);

/*--- ��ť �� ��� �ִ°�? ---*/
int IsEmpty(const IntDequeue* q);

/*--- ��ť �� ���� á�°�? ---*/
int IsFull(const IntDequeue* q);

/*--- ��ť ���� �˻� ---*/
int Search(const IntDequeue* q, int x);

/*--- ��ť ���� �˻�(���� �ε����� ��ȯ) ---*/
int Search2(const IntDequeue* q, int x);

/*--- ��� ������ ��� ---*/
void Print(const IntDequeue* q);

/*--- ��ť  ���� ---*/
void Terminate(IntDequeue* q);

#endif
