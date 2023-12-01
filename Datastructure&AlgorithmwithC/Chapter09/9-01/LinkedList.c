/* 포인터를 사용한 선형 리스트(소스) */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "LinkedList.h"

/*
이 절의 마지막으로 연결 리스트라는 자료 구조의 실용성에 대해 고찰해 보자. 연결 리스트는 포인터를 사용하기는 하지만 그리 복잡하지는 않고 관리 함수들도 상식 수준에서 어렵지 않게 이해할 수 있다. 내부 구조가 직관적이며 링크를 조작하는 기법도 나름대로 재미 있어서 자료 구조를 처음 접하는 사람에게는 상당히 흥미로운 주제이다. 또한 자료 구조의 가장 기본적이고도 고전적인 주제로서 학술적인 가치도 높다.

연결 리스트를 처음 배운 사람들은 다음에 실무를 할 때 한 번씩 꼭 써보고 싶다는 생각이 들 정도로 매력적이기도 하다. 그러나 사실 현대의 컴퓨터 환경에서 연결 리스트의 실용성은 거의 빵점에 가까울 정도로 형편없다. 동적 배열과 비교되는 연결 리스트의 주요 단점들을 간략하게 정리해 보면 다음과 같다.



① 읽기 속도가 형편없이 느리다. 노드간의 관계가 링크로만 저장되기 때문에 중간의 한 노드를 찾으려면 순회하는 것만이 유일한 방법이다. 10만개의 노드 중 78000번째 노드를 읽어야 한다면 정말 끔찍할 것이다. 링크에 의해 삽입, 삭제는 빨라졌지만 대신 검색 속도가 느려진 것이다. 자료를 다루는 동작의 90%는 읽기이며 삽입, 삭제는 상대적으로 흔한 동작이 아니므로 읽는 동작이 느리다는 것은 치명적인 단점이다.

② 메모리 효율이 아주 좋지 못하다. 데이터 외에 링크를 별도로 가져야 하므로 링크분만큼의 메모리가 더 소모됨은 물론이고 개별 노드를 동적으로 할당해야 하므로 할당 헤더에 의한 메모리 소모도 만만치 않다. 게다가 삽입, 삭제를 빈번하게 할 경우 메모리 단편화가 심해져 시스템의 전체적인 성능도 떨어진다. 똑같은 양의 자료를 저장하는 배열과 비교한다면 최소한 2배, 많게는 6배 정도의 메모리가 더 필요하다.

③ 코드가 그리 어렵지는 않지만 배열과 비교했을 때 상대적으로 복잡하고 포인터 구문이 많아 개발자가 실수를 할 가능성이 많다. 링크 자체가 포인터인데다가 데이터에 포인터가 포함되어 있으면 a->next->b->data[3].c 따위의 복잡한 구문도 자주 사용된다. 이런 다단계 참조문을 다룰 때는 항상 주의해야 하며 직관적이지도 못해서 읽기 어렵고 유지, 보수 비용도 증가한다. 개발 시간이 더 오래 걸리며 개발 비용도 결국 비싸진다.

④ 자료 구조의 내부적인 모양이 선형(linear)이 아닌 입체적인 모양을 하고 있어 스트림 입출력이 번거롭다. 연결 리스트를 파일로 저장하려면 링크는 빼고 데이터만 저장해야 하며 다시 불러 올때는 일일이 링크를 복원해야 한다. 링크는 메모리상에서만 의미가 있는 값이므로 저장 대상이 아니다. 리스트 전체를 화면으로 출력하거나 네트워크로 전송할 때도 여러 모로 불편한 점이 많다.

⑤ qsort, bsearch 등의 알고리즘을 구현하는 표준 함수들은 기본적으로 배열에 대해 동작하도록 작성되어 있다. 정렬, 이분 검색은 둘 다 임의 접근을 요구하는데 연결 리스트는 임의 접근을 지원하지 않으므로 이런 표준 함수의 서비스를 받을 수 없다.



연결 리스트는 삽입과 삭제가 엄청나게 빠르다는 유일한 장점을 하나 가지고 있다. 그러나 이것조차도 항상 진실이라고 보기 어렵다. 동시에 다량의 데이터를 삽입할 때는 그야말로 내부에서 엄청난 포인터 조작을 해야 하는데 이에 비해 배열은 웬만한 대용량이라도 간단하고 빠르게 삽입된다. 동적 배열의 삽입 속도는 연결 리스트보다 확실히 느렸다. 그러나 이런 사정이 컴퓨터가 빨라지면서 달라져 현대의 컴퓨터 환경에서 수천~수만 건의 자료는 배열로 밀고 당겨도 속도 감소를 체감하지 못할 정도이며 수백건인 경우는 오히려 배열이 훨씬 더 빠르다.

연결 리스트의 빠른 삽입 속도가 배열을 압도할 정도가 되려면 자료가 수십만 건 정도 되어야 하며 백만건 정도 된다면 배열보다 연결 리스트가 확실히 나은 성능을 보일 것이다. 그러나 이 정도의 자료라면 당연히 트리 구조를 쓰는 것이 합리적이다. 결국 연결 리스트는 중소 규모에서는 배열에게 밀리고 대규모에서는 트리에게 밀려 지금은 설 자리가 마땅치 않은 단점 투성이의 자료 구조가 된 것이다. 연결 리스트가 월등히 우월한 경우라면 PDA나 핸드폰 등 느린 프로세서를 가진 기계에서 삽입, 삭제가 아주 빈번하고 자료의 양이 많을 때 정도에 국한된다.

그러나 연결 리스트에 대한 이론적 학습은 여전히 중요하다. 연결 리스트는 동적 메모리 할당과 포인터에 대한 생생한 실습 도구로서 학술적 가치가 높고 또한 노드를 관리하는 기법은 상위 자료 구조인 트리에서 그대로 적용되므로 자료 구조의 한 과목으로서 생략할 수 없는 주제이기도 하다. 분석해 볼만한 예제들 중에 연결 리스트로 작성되어 있는 것들도 많기 때문에 이런 좋은 예제들의 기법을 흡수하기 위해서라도 연결 리스트는 꼭 연구해야 봐야 한다.

실무에서 연결 리스트를 쓸 것인가 동적 배열을 쓸 것인가는 개인의 취향과 문제의 특수성에 따라 결정되어야 할 것이다. 사실 최근의 객체 지향 기법에서는 둘 다 객체로 포장해 버리면 외부에서 보기에는 차이점이 거의 없어 중소 용량인 경우 어떤 쪽을 선택하나 결과는 마찬가지라고 할 수 있다. 아뭏든 삽입과 삭제가 필요할 때 쓸 수 있는 자료 구조는 연결 리스트뿐이며 오로지 연결 리스트만이 최선의 해결책이라는 고정관념은 버려야겠다. 10여년전에는 사실이었지만 지금은 그렇지 않다.
*/

/*--- 노드를 동적으로 생성 ---*/
static Node* AllocNode(void)
{
	return calloc(1, sizeof(Node));
}

/*--- n이 가리키는 노드의 각 멤버에 값을 설정 ----*/
static void SetNode(Node* n, const Member* x, const Node* next)
{
	n->data = *x;		/* 데이터 */
	n->next = next;		/* 뒤쪽 포인터 */
}
/*--- 선형 리스트를 초기화 ---*/
void Initialize(List* list)
{
	list->head = NULL;	/* 머리 노드 */
	list->crnt = NULL;	/* 선택한 노드 */
}

/*--- 함수 compare를 사용해 x를 검색합니다. ---*/
Node* search(List* list, const Member* x, int compare(const Member* x, const Member* y))
{
	Node* ptr = list->head;
	while (ptr != NULL) {
		if (compare(&ptr->data, x) == 0) {	/* 키값이 같은 경우 */
			list->crnt = ptr;
			return ptr;			/* 검색 성공 */
		}
		ptr = ptr->next;			/* 다음 노드를 선택 */
	}
	return NULL;					/* 검색 실패 */
}

/*--- n개 뒤의 노드에 대한 포인터 반환 n이 음수거나 노드개수보다 크면 NULL */
Node* Retrieve(List* list, int n)
{
	Node *ptr = list->head;
	int i;
	for (i = 0; i < n; i++)
	{
		if (ptr->next == NULL && i < n - 1) // 조건 이렇게 할 거면 while을 해라.
			return NULL;
		ptr = ptr->next;
	}

	return ptr;
}

///* Q2 Retrieve 함수 작성 */
//
///*--- n번째 노드의 커서(포인터)를 반환 ---*/
//Node *Retrieve(List *list, int n)
//{
//	Node *ptr = list->head;
//
//	while (n >= 0 && ptr != NULL) {
//		if (n-- == 0) {
//			list->crnt = ptr;
//			return ptr;				/* 검색 성공 */
//		}
//		ptr = ptr->next;			/* 다음 노드 선택 */
//	}
//	return NULL;					/* 검색 실패 */
//}

/*--- 머리에 노드를 삽입하는 함수 ---*/
void InsertFront(List* list, const Member* x)
{
	Node* ptr = list->head;
	list->head = list->crnt = AllocNode();
	SetNode(list->head, x, ptr);
}

/*--- 꼬리에 노드를 삽입하는 함수 ---*/
void InsertRear(List* list, const Member* x)
{
	if (list->head == NULL)		/* 비어있는 경우 */
		InsertFront(list, x);	/* 머리에 삽입 */
	else {
		Node* ptr = list->head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = list->crnt = AllocNode();
		SetNode(ptr->next, x, NULL);
	}
}

/*--- 머리노드를 삭제하는 함수 ---*/
void RemoveFront(List* list)
{
	if (list->head != NULL) {
		Node* ptr = list->head->next;		/* 두 번째 노드에 대한 포인터 */
		free(list->head);					/* 머리 노드를 해제 */
		list->head = list->crnt = ptr;		/* 새로운 머리 노드 */
	}
}

/*--- 꼬리 노드를 삭제하는 함수 ---*/
void RemoveRear(List* list)
{
	if (list->head != NULL) {
		if ((list->head)->next == NULL)	/* 노드가 하나만 있는 경우 */
			RemoveFront(list);			/* 머리 노드를 삭제 */
		else {
			Node* ptr = list->head;
			Node* pre = NULL;
			while (ptr->next != NULL) {
				pre = ptr;
				ptr = ptr->next;
			}

			pre->next = NULL;	/* pre는 꼬리 노드부터 두 번째 노드 */ // predecessor 전 노드
			free(ptr);			/* ptr은 꼬리 노드 */
			list->crnt = pre;
		}
	}
}

/*--- 선택한 노드를 삭제하는 함수 ---*/
void RemoveCurrent(List* list)
{
	if (list->head != NULL) {
		if (list->crnt == list->head)	/* 머리 노드를 선택한 상태라면 */
			RemoveFront(list);			/* 머리 노드를 삭제 */
		else {
			Node* ptr = list->head;
			while (ptr->next != list->crnt)
				ptr = ptr->next;
			ptr->next = list->crnt->next;
			free(list->crnt);
			list->crnt = ptr;
		}
	}
}

/*--- 서로 같은 노드를, 가장 앞쪽의 노드를 남기고 모두 삭제 ---*/
void Purge(List* list, int compare(const Member* x, const Member* y))
{
	if (list->head != NULL)
	{
		Node* ptr = list->head;
		Node* j;
		while (ptr->next != NULL)
		{
			for (j = ptr->next; j->next != NULL; j = j->next)
			{
				if (compare(&ptr->data, &j->data) == 0)
				{
					list->crnt = j;
					RemoveCurrent(list);
					j = list->crnt;
				}
			}

			if (compare(&ptr->data, &j->data) == 0) // compare 마지막 좆중복
			{
				list->crnt = j;
				RemoveCurrent(list);
			}

			ptr = ptr->next;
		}
	}
}

///* Q1 Purge 함수 작성 */

///*--- 비교 함수를 사용하여 같은 노드를 삭제 ---*/
//void Purge(List *list, int compare(const Member *x, const Member *y))
//{
//	Node *ptr = list->head;
//
//	while (ptr != NULL) {
//		Node *ptr2 = ptr;
//		Node *pre = ptr;
//
//		while (pre->next != NULL) {
//			ptr2 = pre->next;
//			if (!compare(&ptr->data, &ptr2->data)) {
//				pre->next = ptr2->next;
//				free(ptr2);
//			}
//			else {
//				pre = ptr2;
//			}
//		}
//		ptr = ptr->next;
//	}
//	list->crnt = list->head;
//}

/*--- 모든 노드를 삭제 ---*/
void Clear(List* list)
{
	while (list->head != NULL)		/* 텅 빌 때까지 */
		RemoveFront(list);			/* 머리 노드를 삭제 */
	list->crnt = NULL;				// 노드가 하니 분인 list면 RemoveFront에서 list-crnt = NULL해주므로 이건 사실 필요 없다.
}

/*--- 선택한 노드의 데이터를 출력 ---*/
void PrintCurrent(const List* list)
{
	if (list->crnt == NULL)
		printf("선택한 노드가 없습니다.");
	else
		PrintMember(&list->crnt->data);
}
/*--- 선택한 노드의 데이터를 출력(줄바꿈 문자 포함) ---*/
void PrintLnCurrent(const List* list)
{
	PrintCurrent(list);
	putchar('\n');
}

/*--- 모든 노드의 데이터를 순서대로 출력하는 함수 ---*/
void Print(const List* list)
{
	if (list->head == NULL)
		puts("노드가 없습니다.");
	else {
		Node* ptr = list->head;
		puts("【 모두 보기 】");
		while (ptr != NULL) {
			PrintLnMember(&ptr->data);
			ptr = ptr->next;		/* 뒤쪽 노드 선택 */
		}
	}
}
/*--- 선형 리스트를 종료하는 함수 ---*/
void Terminate(List* list)
{
	Clear(list);		/* 모든 노드를 삭제 */
}