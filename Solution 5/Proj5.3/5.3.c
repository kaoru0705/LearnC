/* Addition, Subtraction, Sign, operators */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	printf("%d\n", 1 + 2);

	int income, salary, bonus;
	
	income = salary = (bonus = 100); // tripe assignment income = (salary = (bonus = 100))

	salary = 100;
	bonus = 30;

	income = salary + bonus; // l-value vs r-value 더한 값 자체는 l-value가 아니다.

	int takehome, tax;
	tax = 20;
	takehome = income - tax;

	int a, b;
	a = -7; // - sign operator -7이 literal이 아님
	b = -a;
	b = +a; // + does nothing

	1.0f + 2; // ? float에 저장됨 promotion승진
	
	// 항이 두 개라 이항 연산자 Binary operator 단항 연산자 Unary operator

	return 0;
}