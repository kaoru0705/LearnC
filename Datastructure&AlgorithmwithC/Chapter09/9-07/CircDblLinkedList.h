/* ���� ���߿��� ����Ʈ(�����) */
#ifndef ___CircDblLinkedList
#define ___CircDblLinkedList

#include "Member.h"

/*--- ��� ---*/
typedef struct __node {
	Member data;                   /* ������ */
	struct __node* prev;           /* ���ʳ�忡 ���� ������ */
	struct __node* next;           /* ���ʳ�忡 ���� ������ */
} Dnode;

/*--- ���� ���߿��� ����Ʈ ---*/
typedef struct {
	Dnode* head;                   /* �Ӹ� dummy ��忡 ���� ������ */
	Dnode* crnt;                   /* �ָ��忡 ���� ������ */
} Dlist;

/*--- ����Ʈ�� �ʱ�ȭ ---*/
void Initialize(Dlist* list);

/*--- �ָ����� �����͸� ��Ÿ�� ---*/
void PrintCurrent(const Dlist* list);

/*--- �ָ����� �����͸� ��Ÿ��(�ٹٲ� ���� ����) ---*/
void PrintLnCurrent(const Dlist* list);

/*--- �Լ� compare�� x�� ���� ��带 �˻� ---*/
Dnode* search(Dlist* list, const Member* x,
	int compare(const Member* x, const Member* y));

/*--- n�� ���� ��忡 ���� ������ ��ȯ n�� �����ų� ��尳������ ũ�� NULL */
Dnode* Retrieve(Dlist* list, int n);

/*--- ��� ����� �����͸� ����Ʈ ������ ��Ÿ�� ---*/
void Print(const Dlist* list);

/*--- ��� ����� �����͸� ����Ʈ ���� �Ųٷ� ��Ÿ�� ---*/
void PrintReverse(const Dlist* list);

/*--- �ָ��带 �ϳ� �������� ���ư����� ---*/
int Next(Dlist* list);

/*--- �ָ��带 �ϳ� �������� �ǵ��ư����� ---*/
int Prev(Dlist* list);

/*--- p�� ����Ű�� ��� �ٷ� �ڿ� ��带 ���� ---*/
void InsertAfter(Dlist* list, Dnode* p, const Member* x);

/*--- �Ӹ��� ��带 ���� ---*/
void InsertFront(Dlist* list, const Member* x);

/*--- ������ ��带 ���� ---*/
void InsertRear(Dlist* list, const Member* x);

/*--- p�� ����Ű�� ��带 ���� ---*/
void Remove(Dlist* list, Dnode* p);

/*--- �Ӹ���带 ���� ---*/
void RemoveFront(Dlist* list);

/*--- ������带 ���� ---*/
void RemoveRear(Dlist* list);

/*--- �ָ��带 ���� ---*/
void RemoveCurrent(Dlist* list);

/*--- ���� ���� ����� ���� ������ ��带 ����� ��� ���� ---*/
void Purge(Dlist* list, int compare(const Member* x, const Member* y));

/*--- ��� ��带 ���� ---*/
void Clear(Dlist* list);

/*--- ���� ���߿��� ����Ʈ�� ��ó�� ---*/
void Terminate(Dlist* list);
#endif