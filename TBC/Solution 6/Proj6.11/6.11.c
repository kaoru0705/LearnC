/* Comma operator */
/* https://en.cppreference.com/w/c/language/operator_precedence */
/* https://docs.microsoft.com/en-us/cpp/c-language/c-sequence-points?view=msvc-170 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	// int a, double b;
	// for (int n = 1, double nsqr = n * n; 이런 건 안 됨
	//comma도 연산자다. 
	
	//for (int n = 1, nsqr = n * n; n < 10; n++, nsqr = n * n) // comma operators
	//	printf("%d %d\n", n, nsqr);

	// Note that commas in printf() are not comma operators
	// but separators

	int i, j;
	i = 1;
	i++, j = i; // comma is a sequence point ;만 sequence point가 아니다. i++, 이 때 이미 i = 2
	printf("%d %d\n", i, j);

	int x, y, z;
	z = x = 1, y = 2;
	printf("x=%d, y=%d, z=%d \n", x, y, z);
	z = (x = 1), (y = 2);
	printf("x=%d, y=%d, z=%d \n", x, y, z);
	z = ((x = 1), (y = 2));	// comma 는 오른쪽의 값이 전체 expression의 값이 된다. 1이 아니고 2 
	printf("x=%d, y=%d, z=%d \n", x, y, z);

	//int my_money = 123,456; // error dollar표싴ㅋ
	int my_money = (123, 456); // 456 대입
	printf("%d\n", my_money);


	
	return 0;
}