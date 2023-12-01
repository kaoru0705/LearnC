/* int형 집합 IntSet(소스 부분) */
#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"

/*--- 집합 초기화 ---*/
int Initialize(IntSet* s, int max)
{
	s->num = 0;
	if ((s->set = calloc(max, sizeof(int))) == NULL) {
		s->max = 0;	/* 배열 생성에 실패 */
		return -1;
	}
	s->max = max;
	return 0;
}

/*--- 집합 s에 n이 들어있는지 확인 ---*/
int IsMember(const IntSet* s, int n)
{
	int i;
	for (i = 0; i < s->num; i++)
		if (s->set[i] == n)
			return i; 	/* 들어있음(인덱스를 반환) */
	return -1; 			/* 들어있지 않음 */
}

/*--- 집합 s에 n을 추가 ---*/
void Add(IntSet* s, int n)
{
	if (s->num < s->max && IsMember(s, n) == -1) 	/* 들어있지 않으면 */
		s->set[s->num++] = n; 						/* 배열 끝에 n을 추가 */
}

/*--- 집합 s에서 n을 삭제 ---*/
void Remove(IntSet* s, int n)
{
	int idx;
	if ((idx = IsMember(s, n)) != -1) {
		s->set[idx] = s->set[--s->num];				/* 마지막 요소를 삭제 위치로 옮김 */
	}
}

/*--- 집합 s에 넣을 수 있는 최대 원소 개수를 반환 ---*/
int Capacity(const IntSet* s)
{
	return s->max;
}

/*--- 집합 s의 원소 개수를 반환 ---*/
int Size(const IntSet* s)
{
	return s->num;
}

/*--- 집합 s2를 s1에 대입 ---*/
void Assign(IntSet* s1, const IntSet* s2)
{
	int i;
	int n = (s1->max < s2->num) ? s1->max : s2->num;	/* 복사하는 원소의 개수 */
	for (i = 0; i < n; i++)
		s1->set[i] = s2->set[i];
	s1->num = n;
}

/*--- 집합 s1과 s2가 같은지 확인 ---*/
int Equal(const IntSet* s1, const IntSet* s2)
{
	int i, j;
	if (Size(s1) != Size(s2))
		return 0;
	for (i = 0; i < s1->num; i++) {
		for (j = 0; j < s2->num; j++)
			if (s1->set[i] == s2->set[j])
				break;
		if (j == s2->num)
			return 0;
	}
	return 1;
}

/*--- 집합 s2와 s3의 합집합을 s1에 대입 ---*/
IntSet* Union(IntSet* s1, const IntSet* s2, const IntSet* s3)
{
	int i;
	Assign(s1, s2);
	for (i = 0; i < s3->num; i++)
		Add(s1, s3->set[i]);
	return s1;
}

/*--- 집합 s2와 s3의 교집합을 s1에 대입 ---*/
IntSet* Intersection(IntSet* s1, const IntSet* s2, const IntSet* s3)
{
	int i, j;
	s1->num = 0;		/* s1을 공집합으로 만듭니다. */
	for (i = 0; i < s2->num; i++)
		for (j = 0; j < s3->num; j++)
			if (s2->set[i] == s3->set[j])
				Add(s1, s2->set[i]);
	return s1;
}

/*--- 집합 s2에서 s3를 뺀 차집합을 s1에 대입 ---*/
IntSet* Difference(IntSet* s1, const IntSet* s2, const IntSet* s3)
{
	int i, j;
	s1->num = 0;		/* s1을 공집합으로 만듭니다. */
	for (i = 0; i < s2->num; i++) {
		for (j = 0; j < s3->num; j++)
			if (s2->set[i] == s3->set[j])
				break;
		if (j == s3->num)
			Add(s1, s2->set[i]);
	}
	return s1;
}

/*--- 집합 s의 모든 원소를 ​​출력 ---*/
void Print(const IntSet* s)
{
	int i;

	printf("{ ");
	for (i = 0; i < s->num; i++)
		printf("%d ", s->set[i]);
	printf("}");
}

/*--- 집합 s의 모든 원소를 출력(줄 바꿈 문자 포함) ---*/
void PrintLn(const IntSet* s)
{
	Print(s);
	putchar('\n');
}

/*--- 집합 종료 ---*/
void Terminate(IntSet* s)
{
	if (s->set != NULL) {
		free(s->set);	/* 배열 해제 */
		s->max = s->num = 0;
	}
}
int IsFull(const IntSet* s)
{
	if (s->max == s->num)
		return 1;
	else
		return 0;
}
void Clear(IntSet* s)
{
	s->num = 0;
}
IntSet* symmetricDifference(IntSet* s1, const IntSet* s2, const IntSet* s3)
{
	Difference(s1, s2, s3);
	int i, j;
	for (i = 0; i < s3->num; i++)
	{
		for (j = 0; j < s1->num; j++)
			if (s3->set[i] == s1->set[j])
				break;
		if (j == s1->num)
		Add(s1, s3->set[i]);
	}
}
IntSet* ToUnion(IntSet* s1, const IntSet* s2)
{
	int i;
	for (i = 0; i < s2->num; i++)
		Add(s1, s2->set[i]);
	return s1;
}
IntSet* ToIntersection(IntSet* s1, const IntSet* s2)
{
	int i, j;
	for (i = 0; i < s1->num; i++)
	{
		for (j = 0; j < s2->num; j++)
		{
			if (s1->set[i] == s2->set[j])
				break;
		}
		if (j == s2->num)
		{
			Remove(s1, s1->set[i]);
			i--;
		}
	}
	return s1;
}
IntSet* ToDifference(IntSet* s1, const IntSet* s2)
{
	int i, j;
	for (i = 0; i < s1->num; i++)
	{
		for (j = 0; j < s2->num; j++)
		{
			if (s1->set[i] == s2->set[j])
			{
				Remove(s1, s2->set[j]);
				i--;
				break;
			}
		}
	}
	return s1;
}
int IsSubset(const IntSet* s1, const IntSet* s2)
{
	if (s1->num > s2->num)
		return 0;
	else if (Equal(s1, s2))
		return 1;
	else
		for (int i = 0; i < s1->num; i++)
			if (!IsMember(s2, s1->set[i]))
				return 0;
	return 1;
}
int IsProperSubset(const IntSet* s1, const IntSet* s2)
{
	if (s1->num >= s2->num)
		return 0;
	else
		for (int i = 0; i < s1->num; i++)
			if (!IsMember(s2, s1->set[i]))
				return 0;
		return 1;
}
///* Q1 실습 7-2 프로그램(IntSet.c)에 8개 함수 추가 */
//#include <stdio.h>
//#include <stdlib.h>
//#include "IntSet.h"
//
///*--- ■ 표시가 있는 함수가 새로 추가된 8개의 함수 입니다. ---*/
//
//int Initialize(IntSet *s, int max)
//{
//	s->num = 0;
//	if ((s->set = calloc(max, sizeof(int))) == NULL) {
//		s->max = 0;								
//		return -1;
//	}
//	s->max = max;
//	return 0;
//}
//
//int IsMember(const IntSet *s, int n)
//{
//	int i;
//
//	for (i = 0; i < s->num; i++)
//		if (s->set[i] == n)
//			return i;			
//	return -1;					
//}
//
///*--- ■ 집합이 가득 찼다면 1, 아니면 0을 반환 ---*/
//int IsFull(const IntSet *s)
//{
//	return s->num >= s->max;	// 왜 같은 게 아니라 이상인가? 예전에 나왔다. num이 더 커지는 상황을 대비
//}
//
//void Add(IntSet *s, int n)
//{
//	if (s->num < s->max && IsMember(s, n) == -1)	
//		s->set[s->num++] = n;						
//}
//
//void Remove(IntSet *s, int n)
//{
//	int idx;
//
//	if ((idx = IsMember(s, n)) != -1) {
//		s->set[idx] = s->set[--s->num];	
//	}
//}
//
//int Capacity(const IntSet *s)
//{
//	return s->max;
//}
//
//int Size(const IntSet *s)
//{
//	return s->num;
//}
//
//void Assign(IntSet *s1, const IntSet *s2)
//{
//	int i;
//	int n = (s1->max < s2->num) ? s1->max : s2->num;	
//
//	for (i = 0; i < n; i++)
//		s1->set[i] = s2->set[i];
//	s1->num = n;
//}
//
//int Equal(const IntSet *s1, const IntSet *s2)
//{
//	int i, j;
//
//	if (Size(s1) != Size(s2))
//		return 0;
//
//	for (i = 0; i < s1->num; i++) {
//		for (j = 0; j < s2->num; j++)
//			if (s1->set[i] == s2->set[j])
//				break;
//		if (j == s2->num)
//			return 0;
//	}
//	return 1;
//}
//
//IntSet *Union(IntSet *s1, const IntSet *s2, const IntSet *s3)
//{
//	int i;
//
//	Assign(s1, s2);
//	for (i = 0; i < s3->num; i++)
//		Add(s1, s3->set[i]);
//
//	return s1;
//}
//
//IntSet *Intersection(IntSet *s1, const IntSet *s2, const IntSet *s3)
//{
//	int i, j;
//
//	s1->num = 0;			/* s1を空集合にする */
//	for (i = 0; i < s2->num; i++)
//		for (j = 0; j < s3->num; j++)
//			if (s2->set[i] == s3->set[j])
//				Add(s1, s2->set[i]);
//	return s1;
//}
//
//IntSet *Difference(IntSet *s1, const IntSet *s2, const IntSet *s3)
//{
//	int i, j;
//
//	s1->num = 0;			/* s1を空集合にする */
//	for (i = 0; i < s2->num; i++) {
//		for (j = 0; j < s3->num; j++)
//			if (s2->set[i] == s3->set[j])
//				break;
//		if (j == s3->num)
//			Add(s1, s2->set[i]);
//	}
//	return s1;
//}
//
///*--- ■ 집합 s2, s3의 대칭 차를 s1에 대입하는 함수 ---*/
//IntSet *SymmetricDifference(IntSet *s1, const IntSet *s2, const IntSet *s3)
//{
//	int i;
//
//	s1->num = 0;			/* s1을 공집합으로 */
//
//	for (i = 0; i < s2->num; i++)
//		if (IsMember(s3, s2->set[i]) == -1)
//			Add(s1, s2->set[i]);
//
//	for (i = 0; i < s3->num; i++)
//		if (IsMember(s2, s3->set[i]) == -1)
//			Add(s1, s3->set[i]);
//
//	return s1;
//}
//
///*--- ■ 집합 s1에 s2의 모든 원소를 추가하는 함수(s1 포인터 반환) ---*/
//IntSet *ToUnion(IntSet *s1, const IntSet *s2)
//{
//	int i;
//
//	for (i = 0; i < s2->num; i++)
//		Add(s1, s2->set[i]);
//
//	return s1;
//}
//
///*--- ■ 집합 s1에서 s2에 들어 있지 않은 모든 원소를 삭제하는 함수(s1 포인터 반환) ---*/
//IntSet *ToIntersection(IntSet *s1, const IntSet *s2)
//{
//	int i = 0;
//
//	while (i < s1->num) {
//		if (IsMember(s2, s1->set[i]) == -1)
//			Remove(s1, s1->set[i]);
//		else
//			i++;		// for 문이 아니라 while로 함으로써 remove 하고 i--하는 짓거리를 안 했다.
//	}
//	return s1;
//}
//
///*--- ■ 집합 s1에서 s2에 들어 있는 모든 원소를 삭제하는 함수(s1 포인터 반환) ---*/
//IntSet *ToDifference(IntSet *s1, const IntSet *s2)
//{
//	int i;
//
//	for (i = 0; i < s2->num; i++)
//		Remove(s1, s2->set[i]); // 와 시발 
//
//	return s1;
//}
//
///*--- ■ 집합 s1이 s2의 부분집합이면 1, 아니면 0을 반환 ---*/
//int IsSubset(const IntSet *s1, const IntSet *s2)
//{
//	int i, j;
//
//	for (i = 0; i < s1->num; i++) {	// 이렇게하면 크거나 같을 때가 필요 없다.
//		for (j = 0; j < s2->num; j++)
//			if (s1->set[i] == s2->set[j])
//				break;
//		if (j == s2->num)					
//			return 0;
//	}
//	return 1;
//}
//
///*--- ■ 집합 s1이 s2의 진부분집합이면 1, 아니면 0을 반환 ---*/
//int IsProperSubset(const IntSet *s1, const IntSet *s2)
//{
//	int i;
//
//	if (s1->num >= s2->num)					
//		return 0;							
//
//	return IsSubset(s1, s2);		// 아니 시발 아 맞다.
//}
//
//void Print(const IntSet *s)
//{
//	int i;
//
//	printf("{ ");
//	for (i = 0; i < s->num; i++)
//		printf("%d ", s->set[i]);
//	printf("}");
//}
//
//void PrintLn(const IntSet *s)
//{
//	Print(s);
//	putchar('\n');
//}
//
///*--- ■ 집합의 모든 원소를 삭제하는 함수 ---*/
//void Clear(IntSet *s)
//{
//	s->num = 0;
//}
//
//void Terminate(IntSet *s)
//{
//	if (s->set != NULL) {
//		free(s->set);							
//		s->max = s->num = 0;
//	}
//}
