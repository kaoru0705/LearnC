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

	income = salary + bonus; // l-value vs r-value ���� �� ��ü�� l-value�� �ƴϴ�.

	int takehome, tax;
	tax = 20;
	takehome = income - tax;

	int a, b;
	a = -7; // - sign operator -7�� literal�� �ƴ�
	b = -a;
	b = +a; // + does nothing

	1.0f + 2; // ? float�� ����� promotion����
	
	// ���� �� ���� ���� ������ Binary operator ���� ������ Unary operator

	return 0;
}