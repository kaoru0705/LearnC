/* 이진검색트리 프로그램(소스) */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "BinTree.h"

/*--- 노드를 동적으로 할당 ---*/
static BinNode* AllocBinNode(void)
{
	return calloc(1, sizeof(BinNode));
}

/*--- 노드 멤버 값 설정 ----*/
static void SetBinNode(BinNode* n, const Member* x, const BinNode* left, const BinNode* right)
{
	n->data = *x;			/* 데이터 */
	n->left = left;			/* 왼쪽 포인터 */
	n->right = right;		/* 오른쪽 포인터 */
}

/*--- 검색 ---*/
BinNode* Search(BinNode* p, const Member* x)
{
	int cond;
	if (p == NULL)
		return NULL;										/* 검색 실패 */
	else if ((cond = MemberNoCmp(x, &p->data)) == 0)
		return p;                                           /* 검색 성공 */
	else if (cond < 0)
		Search(p->left, x);                                 /* 왼쪽 서브 트리에서 검색 */
	else
		Search(p->right, x);                                /* 오른쪽 서브 트리에서 검색 */
}

/*--- 노드 삽입 ---*/
BinNode* Add(BinNode* p, const Member* x)
{
	int cond;
	if (p == NULL) {
		p = AllocBinNode();
		SetBinNode(p, x, NULL, NULL);
	}
	else if ((cond = MemberNoCmp(x, &p->data)) == 0)
		printf("【오류】 %d는 이미 등록되어 있습니다.\n", x->no);
	else if (cond < 0)
		p->left = Add(p->left, x);
	else
		p->right = Add(p->right, x);
	return p;
}

/*--- 노드 삭제 ---*/
int Remove(BinNode** root, const Member* x)
{
	BinNode* next, * temp;
	BinNode** left;
	BinNode** p = root;

	while (1) {
		int cond;
		/* *p를 찾기 위한 여정 */
		if (*p == NULL) {
			printf("【오류】 %d는 등록되어 있지 않습니다.\n", x->no);
			return -1;				/* 이 키는 없습니다. */
		}
		else if ((cond = MemberNoCmp(x, &(*p)->data)) == 0)
			break;					/* 검색 성공 */
		else if (cond < 0)
			p = &((*p)->left);		/* 왼쪽 서브 트리에서 검색 */
		else
			p = &((*p)->right);		/* 오른쪽 서브 트리에서 검색 */
	}

	if ((*p)->left == NULL)
		next = (*p)->right;
	else {
		left = &((*p)->left);
		while ((*left)->right != NULL) // 왼족 서브 트리의 노드 가운데 키 값이 가장 큰 노드 구하는 반복문
			left = &(*left)->right;
		next = *left;
		*left = (*left)->left;		
		next->left = (*p)->left;		// next는 그냥 포인터지만 ->left ->right는 포인터를 담을 수 있으니 그냥 이렇게 해도 된다. 이중포인터가 아니어도 상관없다.  *p = next는 *p자체가 주소를 담을 수 있는 포인터다.
		next->right = (*p)->right;
	}

	temp = *p;
	*p = next; // 이중 포인터를 쓴 이유 BinNode* p = root; p = next; 라면? 전혀 안 바뀜 p에다 next를 넣었을 뿐이니. 주소를 저장하는 포인터에다 주소로 덮었을 뿐이다.

	free(temp);

	return 0;
}

/*--- 모든 노드의 데이터를 출력 ---*/
void PrintTree(const BinNode* p)
{
	if (p != NULL) {
		PrintTree(p->left);
		PrintLnMember(&p->data);
		PrintTree(p->right);
	}
}

/*--- 모든 내림차순으로 출력 ---*/
void PrintTreeReverse(const BinNode* p)
{
	if (p != NULL)
	{
		PrintTreeReverse(p->right);
		PrintLnMember(&p->data);
		PrintTreeReverse(p->left);
	}
}

/*--- 가장 작은 키 값 가장 큰 값 노드의 포인터 반환 */
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

///* Q3 GetMinNode, GetMaxNode 함수 작성 */
//
///*--- 최소 키 값을 가지는 노드를 검색 ---*/
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
///*--- 최대 키 값을 가지는 노드를 검색 ---*/
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

/*--- 모든 노드 삭제 ---*/
void FreeTree(BinNode* p)
{
	if (p != NULL) {
		FreeTree(p->left);
		FreeTree(p->right);
		free(p);
	}
}