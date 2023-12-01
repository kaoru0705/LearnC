/* 중요한 프로젝트는 책꽂이를 해라*/
/* Recursion & Stack */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// 무한루프를 사용할 때 재귀호출을 사용하면 안 된다.
void my_func(int);
// stack overflow 무한한 메모리가 아니라 출력하다가 비정상적으로 종료된다. 주소는 다 다르다. 변수이름이 아니라 주소가 중요함
//Level 1, address of variable n = 00EFF948 32bit 이상 차이남 스택에 쌓이는 건 프로그램도 같이 쌓인다. my_func자체도
//Level 2, address of variable n = 00EFF870 그림으로 표현할려고 변수만 쌓이는 것처럼 표현한 것 뿐
// 프로그램이 실행되면 기본적으로 모든 것이 메모리에 저장된다. 함수를 실행하기 위해 필요한 데이터 함수도 메모리에 저장된다.
// 허나 정확하진 않다. 컴파일러가 요즘엔 최적화를 잘해주기 때문
// 자세히는 os compiler 전산학을 배우면 알 수 있다. stack에 변수와 함께 사용하는 코드도 함수도 같이 쌓인다. 통틀어 stack frame

int main()
{
	my_func(1);

	return 0;
}

void my_func(int n)
{
	printf("Level %d, address of variable n = %d\n", n, (int)& n); // 10진수로 바꾸기 위해서 ptr -> int casting
	// == printf("Level %d, address of variable n = %d\n", n, &n); (int) cast operator int는 기본이 decimal


	if (n < 4) //TODO: stop condition 
		my_func(n + 1); // 더해진 상태로 호출하고 다시 돌아옴
	// 재귀호출이 어렵게 느껴지겠지만 수학 알고리즘에서는 편한 경우가 있다.
	// 아주 반복되는 상황이 많거나 컴퓨터가 작동되는 효율을 높이고 싶은 경우에는 일반적인 for문으로 바꿀 수 있다.
	// 동명이인이라고 같은 사람이냐?
	printf("Level %d, address of variable n = %d\n", n, (int)&n);

	// ... = compiler나 OS는 알지만 우린 알 필요 없는 메모리 공간
	//TODO: tail recursion
}