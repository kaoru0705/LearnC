/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* Logical Operators �� ������ */
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

	//bool test1 = 3 > 2 or 5 > 6;	// true	//iso646.h		�㳪  && || ! ���� �� �����̴�. 
	//bool test2 = 3 > 2 and 5 > 6;	// false
	//bool test3 = not(5 > 6);		// true, equivalent to 5 <= 6

	//printf("%d %d %d\n", test1, test2, test3);

	/* Character counting example */

	//char ch;
	//int count = 0;

	//while ((ch = getchar()) != STOP) // ������ '\n'�� buffer�� ����
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
	((a > b) && (b > c)) || (b > d);	// �����ϸ� ��ȣ�� �Ķ� 

	/*
		Short-circuit Evaluation	// ���ڰ��п��� ���� ����
		
		- Logical expressions are evalutated from left to right
		- && and || are sequence points
		https://docs.microsoft.com/en-us/cpp/c-language/c-sequence-points?view=msvc-170
	*/

	//int temp = (1 + 2) * (3 + 4);	// 1 + 2 3 + 4 �� ���� ���������� �� �� ����.
	//// �׷��� �� �ȿ� ���������� �� �� ����ϴ�. �㳪 �� �����ڴ� ���ʺ��ʹ�.

	//printf("Before : %d\n", temp);

	//if (temp == 0 && (++temp == 1024))
	//{
	//	// do something
	//};	// ��ȸ�� �� �ܶ� ������ false�� �׳� �������ȴ�. �߿��� ����
	//// ���� ������ true�� ��쿡�� �����ϴ� �Լ��� �����ʿ� ���� ���� �ִ�.
	//
	//printf("After : %d\n", temp);

	//int x = 1, y = 2;
	//if (x++ > 0 && x + y == 4)
	//	printf("%d %d\n", x, y);	// sequence points
	//// ���������� �������� �Ŀ� ���������ڸ� ���� ���� �ſ� �Ⱦ��Ѵ�. �򰥸��ϱ�


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
	//// ���������δ� ���� ���������� �ؿ��� ����ϴ�. �������� ���� ���� �� Ȱ���ؾ� �ȴ�.

	return 0;
}