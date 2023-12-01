/* �����˻�Ʈ�� ���α׷�(�ҽ�) */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "BinTree.h"

/*--- ��带 �������� �Ҵ� ---*/
static BinNode* AllocBinNode(void)
{
	return calloc(1, sizeof(BinNode));
}

/*--- ��� ��� �� ���� ----*/
static void SetBinNode(BinNode* n, const Member* x, const BinNode* left, const BinNode* right)
{
	n->data = *x;			/* ������ */
	n->left = left;			/* ���� ������ */
	n->right = right;		/* ������ ������ */
}

/*--- �˻� ---*/
BinNode* Search(BinNode* p, const Member* x)
{
	int cond;
	if (p == NULL)
		return NULL;										/* �˻� ���� */
	else if ((cond = MemberNoCmp(x, &p->data)) == 0)
		return p;                                           /* �˻� ���� */
	else if (cond < 0)
		Search(p->left, x);                                 /* ���� ���� Ʈ������ �˻� */
	else
		Search(p->right, x);                                /* ������ ���� Ʈ������ �˻� */
}

/*--- ��� ���� ---*/
BinNode* Add(BinNode* p, const Member* x)
{
	int cond;
	if (p == NULL) {
		p = AllocBinNode();
		SetBinNode(p, x, NULL, NULL);
	}
	else if ((cond = MemberNoCmp(x, &p->data)) == 0)
		printf("�������� %d�� �̹� ��ϵǾ� �ֽ��ϴ�.\n", x->no);
	else if (cond < 0)
		p->left = Add(p->left, x);
	else
		p->right = Add(p->right, x);
	return p;
}

/*--- ��� ���� ---*/
int Remove(BinNode** root, const Member* x)
{
	BinNode* next, * temp;
	BinNode** left;
	BinNode** p = root;

	while (1) {
		int cond;
		/* *p�� ã�� ���� ���� */
		if (*p == NULL) {
			printf("�������� %d�� ��ϵǾ� ���� �ʽ��ϴ�.\n", x->no);
			return -1;				/* �� Ű�� �����ϴ�. */
		}
		else if ((cond = MemberNoCmp(x, &(*p)->data)) == 0)
			break;					/* �˻� ���� */
		else if (cond < 0)
			p = &((*p)->left);		/* ���� ���� Ʈ������ �˻� */
		else
			p = &((*p)->right);		/* ������ ���� Ʈ������ �˻� */
	}

	if ((*p)->left == NULL)
		next = (*p)->right;
	else {
		left = &((*p)->left);
		while ((*left)->right != NULL) // ���� ���� Ʈ���� ��� ��� Ű ���� ���� ū ��� ���ϴ� �ݺ���
			left = &(*left)->right;
		next = *left;
		*left = (*left)->left;		
		next->left = (*p)->left;		// next�� �׳� ���������� ->left ->right�� �����͸� ���� �� ������ �׳� �̷��� �ص� �ȴ�. ���������Ͱ� �ƴϾ �������.  *p = next�� *p��ü�� �ּҸ� ���� �� �ִ� �����ʹ�.
		next->right = (*p)->right;
	}

	temp = *p;
	*p = next; // ���� �����͸� �� ���� BinNode* p = root; p = next; ���? ���� �� �ٲ� p���� next�� �־��� ���̴�. �ּҸ� �����ϴ� �����Ϳ��� �ּҷ� ������ ���̴�.

	free(temp);

	return 0;
}

/*--- ��� ����� �����͸� ��� ---*/
void PrintTree(const BinNode* p)
{
	if (p != NULL) {
		PrintTree(p->left);
		PrintLnMember(&p->data);
		PrintTree(p->right);
	}
}

/*--- ��� ������������ ��� ---*/
void PrintTreeReverse(const BinNode* p)
{
	if (p != NULL)
	{
		PrintTreeReverse(p->right);
		PrintLnMember(&p->data);
		PrintTreeReverse(p->left);
	}
}

/*--- ���� ���� Ű �� ���� ū �� ����� ������ ��ȯ */
BinNode* GetMinNode(const BinNode* p)
{
	while (p->left != NULL)
		p = p->left;
	
	return p;
}
BinNode* GetMaxNode(const BinNode* p)
{
	while (p->right != NULL)
		p = p->right;

	return p;
}

///* Q3 GetMinNode, GetMaxNode �Լ� �ۼ� */
//
///*--- �ּ� Ű ���� ������ ��带 �˻� ---*/
//BinNode *GetMinNode(const BinNode *p)
//{
//	if (p == NULL)
//		return NULL;
//	else {
//		while (p->left != NULL)
//			p = p->left;
//		return p;
//	}
//}
//
///*--- �ִ� Ű ���� ������ ��带 �˻� ---*/
//BinNode *GetMaxNode(const BinNode *p)
//{
//	if (p == NULL)
//		return NULL;
//	else {
//		while (p->right != NULL)
//			p = p->right;
//		return p;
//	}
//}

/*--- ��� ��� ���� ---*/
void FreeTree(BinNode* p)
{
	if (p != NULL) {
		FreeTree(p->left);
		FreeTree(p->right);
		free(p);
	}
}