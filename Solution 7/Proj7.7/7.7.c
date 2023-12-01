/* 중요한 프로젝트는 책꽂이를 해라*/
/* Logical Operators 논리 연산자 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <ctype.h>		// islower()
#include <stdbool.h>
#include <iso646.h>		// and, or, not

#define STOP '.'
int main()
{
	/*
		Logical operators

		&&	: and
		||	: or
		!	: not
	*/

	//bool test1 = 3 > 2 or 5 > 6;	// true	//iso646.h		허나  && || ! 쓰는 게 정석이다. 
	//bool test2 = 3 > 2 and 5 > 6;	// false
	//bool test3 = not(5 > 6);		// true, equivalent to 5 <= 6

	//printf("%d %d %d\n", test1, test2, test3);

	/* Character counting example */

	//char ch;
	//int count = 0;

	//while ((ch = getchar()) != STOP) // 마지막 '\n'는 buffer에 쌓임
	//{
	//	//TODO: make exceptions
	//	if (ch != '\n' && ch != ' ')
	//		count++;
	//}

	//printf("%d", count);

	/*
		Alternatives in iso646.h
		
		&&	: and
		||	: or
		!	: not
	*/

	/*
		Precedence
		
		Check !, &&, !! in the operator precednece table
		https://en.cppreference.com/w/c/language/operator_precedence
	*/

	int a = 1, b = 2, c = 3, d = 4;

	// a > b && b > c || b > d;
	((a > b) && (b > c)) || (b > d);	// 복잡하면 괄호를 쳐라 

	/*
		Short-circuit Evaluation	// 전자공학에서 나온 개념
		
		- Logical expressions are evalutated from left to right
		- && and || are sequence points
		https://docs.microsoft.com/en-us/cpp/c-language/c-sequence-points?view=msvc-170
	*/

	//int temp = (1 + 2) * (3 + 4);	// 1 + 2 3 + 4 중 뭐가 먼저인지는 알 수 없다.
	//// 그래서 이 안에 증감연산자 할 때 곤란하다. 허나 논리 연산자는 왼쪽부터다.

	//printf("Before : %d\n", temp);

	//if (temp == 0 && (++temp == 1024))
	//{
	//	// do something
	//};	// 단회로 평가 단락 왼쪽이 false라 그냥 끝나버렸다. 중요한 성질
	//// 응용 왼쪽이 true일 경우에만 실행하는 함수를 오른쪽에 넣을 수도 있다.
	//
	//printf("After : %d\n", temp);

	//int x = 1, y = 2;
	//if (x++ > 0 && x + y == 4)
	//	printf("%d %d\n", x, y);	// sequence points
	//// 개인적으로 논리연산자 식에 증감연산자를 쓰는 것을 매우 싫어한다. 헷갈리니까


	/* Ranges */
	
	//for (int i = 0; i < 100; ++i)
	//	if (i >= 10 && i <= 20)
	//		printf("%d ", i);

	//printf("\n");
	//
	//for (int i = 0; i < 100; ++i) // amateur
	//	if (10 <= i <= 20)		// Note: if((10 <= i) <= 20) -> ((0 || 1) <= 20)
	//		printf("%d ", i);

	//printf("\n");

	//for (char c = -128; c < 127; ++c)
	//	if (c >= 'a' && c <= 'z')
	//		printf("%c ", c);

	//printf("\n");

	//for (char c = 0; c < 127; ++c)
	//	if (islower(c))
	//		printf("%c ", c);
	//// 개인적으로는 위를 좋아하지만 밑에가 깔끔하다. 실전에선 여러 가지 잘 활용해야 된다.

	return 0;
}