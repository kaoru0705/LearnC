/* 중요한 프로젝트는 책꽂이를 해라*/
/* 포인터형 매개변수 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// pointer가 번거롭지만 자료구조 배울 때도 쓰는 게 연습하는 데 도움이 된다. 
// 사실 포인터 매개변수 방식은 최근엔 c++ java python 이런 언어들에서는 많이 사용하지 않는다. 더 쉬운 방법으로 코딩한다.
// 그대신 더 느려짐
// 효율이 높은 프로그램을 작성하려면 내부적으로 포인터, 포인터에 상응하는 뭔가를 사용해야 된다. 초보일 때일수록 많이 써라

/* try 1*/
//void swap(int u, int v)
//{
//	printf("%p %p\n", &u, &v); // 다른 존재, 다른 오브젝트이므로 스왑이 이루어지지 않는다.
//	// 값에 의한 호출 call by value
//
//	// swap
//	int temp = u;
//	u = v;
//	v = temp;
//}

/*try 2*/
void swap(int* u, int* v) // call by pointer 
{
	printf("%p %p\n", u, v); // &u &v = pointer자체의 주소 이중포인터 배울 때 배움
	// swap
	int temp = *u;
	*u = *v;
	*v = temp;
}

int main()
{
	int a = 123;
	int b = 456;

	printf("%p %p\n", &a, &b);

	swap(&a, &b); //swap(a, b) = 문맥오류

	//swap(a, b); // 값이 들어가고 복사만 됐다. 우연히 이름만 같음 덜 헷갈리게 u, v로 바꿈

	printf("%d %d\n", a, b);

	
	return 0;
}