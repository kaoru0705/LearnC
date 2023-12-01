/* 중요한 프로젝트는 책꽂이를 해라*/
/* Conditional Operator 조건 연산자 ? : */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdbool.h>

int main()
{
	//int temp;
	//temp = true ? 1024 : 7; // 항이 세 개라 ternary operator (unary, binary, ternary) 삼항 연산자보다는 조건연산자 right to left
	//printf("%d\n", temp);

	//temp = false ? 1024 : 7; // temp = 0 ? 1024 : 7;
	//printf("%d\n", temp);
	
	//int a = 1, b = 2;
	//int max = (a > b) ? a : b;	// 값 비교할 때도 많이 씀

	int number;
	scanf("%d", &number);

	const bool is_even = (number % 2 == 0) ? true : false; // 더 줄여서 이렇게
	// 선언과 동시에 값을 조건에 따라 고정 시키고 싶다면 이 때 조건연산자를 많이 씀
	
	/*is_even = (number % 2 == 0) ? true : false;*/	// 조건연산자 ?는 연산순위가 매우 낮다.
												// 그래도 보기 편하니까 소괄호 넣어라
	/*if (number % 2 == 0)
		is_even = true;
	else
		is_even = false;*/

	if (is_even)
		printf("Even");
	else
		printf("Odd");
	int a = 3;

	//(number % 2 == 0) ? printf("Even") : printf("Odd"); 더욱 더 줄여서 이렇게
	// 허나 이렇게까진 사용하지 않는다. 대부분은 플래그를 선언하고 거기에 따라 기능을 수행

	return 0;
}