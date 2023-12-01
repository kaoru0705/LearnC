/* 중요한 프로젝트는 책꽂이를 해라*/
/* Factorial */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	loop vs recursion 모든 재귀함수는 반복문으로 구현할 수 있다.
	0! = 1
	5! = 5 * 4 ! = 5 * 4 * 3! = 5 * 4 * 3 * 2! = 5 * 4 * 3 * 2 * 1! = 5 * 4 * 3 * 2 * 1 * 0!
*/
long loop_factorial(int n);
long recursive_factorial(int n);

int main()
{
	int num = 5;
	
	printf("%d\n", loop_factorial(num));
	printf("%d\n", recursive_factorial(num));


	return 0;
}
/* My answer */
long loop_factorial(int n)
{
	return (n > 1) ? n * loop_factorial(n - 1) : 1; // return 앞에서 recursion하는 것을 tail (end) recursion 재귀함수는 tail recursion을 많이 쓴다. 수학적정의를 깔끔하게 구현가능
}

//long recursive_factorial(int n)
//{
//	int result = 1;
//	for (int i = n; i > 1; --i)
//		result *= i;
//
//	return result;
//}

long recursive_factorial(int n)
{
	long ans;

	for (ans = 1; n >= 1; n--) // 지금은 최적화고 나발이고 구현부터하고 실행 잘 되면 그때부터 최적화가 트렌드 정의상 1을 포함했지만 빼도 되잖아? 하면서 나중에 최적화하는 거임
		ans *= n;

	return ans;
}