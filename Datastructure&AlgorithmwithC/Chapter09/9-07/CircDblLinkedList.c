/* ���� ���� ���� ����Ʈ(�ҽ�) */
#include <stdio.h>
#include <stdlib.h>
#include "CircDblLinkedList.h"

/*--- �ϳ��� ��带 �������� ���� ---*/
static Dnode* AllocDNode(void)
{
	return calloc(1, sizeof(Dnode));
}

/*--- ����� �� ����� ���� ���� ----*/
static void SetDNode(Dnode* n, const Member* x, const Dnode* prev,
	const Dnode* next)
{
	n->data = *x;                              /* ������ */
	n->prev = prev;                            /* ���ʳ�忡 ���� ������ */
	n->next = next;                            /* ���ʳ�忡 ���� ������ */
}

/*--- ����Ʈ�� ����ִ°�? ---*/
static int IsEmpty(const Dlist* list)
{
	return list->head->next == list->head;
}

/*--- ����Ʈ�� �ʱ�ȭ ---*/
void Initialize(Dlist* list)
{
	Dnode* dummyNode = AllocDNode();       /* ���� ��带 ���� */
	list->head = list->crnt = dummyNode;
	dummyNode->prev = dummyNode->next = dummyNode;
}

/*--- �ָ����� �����͸� ��� ---*/
void PrintCurrent(const Dlist* list)
{
	if (IsEmpty(list))
		printf("������ ��尡 �����ϴ�.");
	else
		PrintMember(&list->crnt->data);
}

/*--- �ָ����� �����͸� ���(�ٹٲ� ���� ����) ---*/
void PrintLnCurrent(const Dlist* list)
{
	PrintCurrent(list);
	putchar('\n');
}

/*--- �Լ� compare�� x�� ���� ��带 �˻� ---*/
Dnode* search(Dlist* list, const Member* x, int compare(const Member* x, const Member* y))
{
	Dnode* ptr = list->head->next;
	while (ptr != list->head) {
		if (compare(&ptr->data, x) == 0) {
			list->crnt = ptr;
			return ptr;                 /* �˻� ���� */
		}
		ptr = ptr->next;
	}
	return NULL;                        /* �˻� ���� */
}

/*--- ��� ����� �����͸� ����Ʈ ������ ��� ---*/
void Print(const Dlist* list)
{
	if (IsEmpty(list))
		puts("��尡 �����ϴ�.");
	else {
		Dnode* ptr = list->head->next;
		puts("�� ��� ���� ��");
		while (ptr != list->head) {
			PrintLnMember(&ptr->data);
			ptr = ptr->next;                /* ���ʳ�忡 �ָ� */
		}
	}
}

/*--- ��� ����� �����͸� ����Ʈ ���� �Ųٷ� ��� ---*/
void PrintReverse(const Dlist* list)
{
	if (IsEmpty(list))
		puts("��尡 �����ϴ�.");
	else {
		Dnode* ptr = list->head->prev;
		puts("�� ��� ���� ��");
		while (ptr != list->head) {
			PrintLnMember(&ptr->data);
			ptr = ptr->prev;                /* ���ʳ�忡 �ָ� */
		}
	}
}

/*--- �ָ��带 �ϳ� �������� ���ư����� ---*/
int Next(Dlist* list)
{
	if (IsEmpty(list) || list->crnt->next == list->head)
		return 0;                           /* ���ư� �� ���� */
	list->crnt = list->crnt->next;
	return 1;
}

/*--- �ָ��带 �ϳ� �������� �ǵ��ư����� ---*/
int Prev(Dlist* list)
{
	if (IsEmpty(list) || list->crnt->prev == list->head)
		return 0;                           /* �ǵ��ư� �� ���� */
	list->crnt = list->crnt->prev;
	return 1;
}

/*--- p�� ����Ű�� ��� �ٷ� �ڿ� ��带 ���� ---*/
void InsertAfter(Dlist* list, Dnode* p, const Member* x)
{
	Dnode* ptr = AllocDNode();
	Dnode* nxt = p->next;
	p->next = p->next->prev = ptr;
	SetDNode(ptr, x, p, nxt);
	list->crnt = ptr;                          /* ������ ��忡 �ָ� */
}

/*--- �Ӹ��� ��带 ���� ---*/
void InsertFront(Dlist* list, const Member* x)
{
	InsertAfter(list, list->head, x);
}
/*--- ������ ��带 ���� ---*/
void InsertRear(Dlist* list, const Member* x)
{
	InsertAfter(list, list->head->prev, x);
}

/*--- p�� ����Ű�� ��带 ���� ---*/
void Remove(Dlist* list, Dnode* p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
	list->crnt = p->prev;                   /* ������ ����� ���ʳ�忡 �ָ� */
	free(p);
	if (list->crnt == list->head)
		list->crnt = list->head->next;
}

/*--- �Ӹ���带 ���� ---*/
void RemoveFront(Dlist* list)
{
	if (!IsEmpty(list))
		Remove(list, list->head->next);
}

/*--- ������带 ���� ---*/
void RemoveRear(Dlist* list)
{
	if (!IsEmpty(list))
		Remove(list, list->head->prev);
}

/*--- �ָ��带 ���� ---*/
void RemoveCurrent(Dlist* list)
{
	if (list->crnt != list->head)
		Remove(list, list->crnt);
}

/*--- �� �Լ��� ����Ͽ� ���� ��带 ���� ---*/
void Purge(Dlist *list, int compare(const Member *x, const Member *y))
{
	Dnode *ptr = list->head->next;

	while (ptr->next != list->head)
	{
		Dnode *ptr2 = ptr;
		Dnode *pre = ptr;

		while (pre->next != list->head)
		{
			ptr2 = pre->next;
			if (!compare(&ptr->data, &ptr2->data))
			{
				/*pre->next = ptr2->next;
				ptr2->next->prev = pre;
				free(ptr2);*/
				list->crnt = ptr2;
				RemoveCurrent(list);
			}
			else
			{
				pre = ptr2;
			}
		}
		ptr = ptr->next;
	}
	list->crnt = list->head->next;
}

/*--- n�� ���� ��忡 ���� ������ ��ȯ n�� �����ų� ��尳������ ũ�� NULL */
Dnode* Retrieve(Dlist* list, int n)
{
	Dnode *ptr = list->head->next;

	while (n >= 0 && ptr != list->head)
	{
		if (n-- == 0)
		{
			list->crnt = ptr;
			return ptr;				/* �˻� ���� */
		}
		ptr = ptr->next;			/* ���� ��� ���� */
	}
	return NULL;					/* �˻� ���� */
}

///* Q4 Purge, Retrieve �Լ� �ۼ� */

/*--- ��� ��带 ���� ---*/
void Clear(Dlist* list)
{
	while (!IsEmpty(list))                    /* �� �� ������ */
		RemoveFront(list);                    /* �Ӹ���带 ���� */
}

/*--- ���� ���� ���� ����Ʈ�� ��ó�� ---*/
void Terminate(Dlist* list)
{
	Clear(list);                              /* ��� ��带 ���� */
	free(list->head);                         /* ���� ��带 ���� */
}
