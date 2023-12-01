/* 중요한 프로젝트는 책꽂이를 해라*/
/* 피보나치(Fibonaccci) 예제와 재귀 호출의 장단점 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
	Fibonacci sequence
	1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89. 144

	ex ) fibonacci(5) = 3 + 2 = fibonacci(4) + fibonacci(3)
*/

int fibonacci(int number);

int main()
{
	for (int count = 1; count < 13; ++count)
		printf("%d ", fibonacci(count));

	return 0;
}

int fibonacci(int number)
{

	return (number < 3) ? 1 : fibonacci(number - 1) + fibonacci(number - 2);
	// double recursion 컴퓨터가 실행시킬 때는 동시에 시키지는 않는다. debuger를 찍어봐라
	// 장점 수학적으로 정의된 경우에는 구현이 간결해진다.
	// 단점:	1. 메모리를 많이 쓴다. 재귀호출이 될 때마다 파라미터가 스택에 쌓인다. 당연히 많이 쌓일수록 메모리를 많이 사용
	//			stack frame에는 변수만 쌓이는 것이 아니고 변수를 사용하기 위한 프로그램 함수도 같이 쌓인다.
	//			overhead : 실제로 사용하는 것보다 더 추가돼서 사용하는 것을 일컬음
	//		2. 계산에 중복이 생긴다. redundant computation printf("fibonacci with %d\n", number);
}	//			구현이 간결해지면 간결해진 대가로써 메모리도 많이 쓴다.

//Note: memory (in)efficiency, redundant computation