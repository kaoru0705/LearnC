/* 나누기 연산자 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	printf("Interger divisions\n");
	printf("%d\n", 14 / 7);
	printf("%d\n", 7 / 2); // 3.5 in floating divison 정수연산은 소수부를 없애버림(Truncating)
	printf("%d\n", 7 / 3); // 2.333 in floating division
	printf("%d\n", 7 / 4); // 1.75 in floating division
	printf("%d\n", 8 / 4); // 2

	printf("Truncating toward zero (C99)\n"); // 0에 가까운 식으로 짜른다. 사실상 소수부 없애기 그 전에는 컴파일러에 따라 달랐다.
	printf("%d\n", -7 / 2); // -3.5 in floating division
	printf("%d\n", -7 / 3); // -2.33 in floating division
	printf("%d\n", -7 / 4); // -1.75 in floating division
	printf("%d\n", -8 / 4); // -2

	printf("\nFloating divisions\n");
	printf("%f\n", 9.0 / 4.0);
	printf("%f\n", 9.0 / 4); // Note: 4 is integer Compiler do from integer to double
	// CPU는 자료형이 다른 숫자끼리 곱하기 나누기 할 수 없다. compiler입장에서 double로 바꿈

	return 0;
}