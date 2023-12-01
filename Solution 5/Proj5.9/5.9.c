/* ǥ���İ� ���� Expressions Statements */
// expression = �����ڿ� �ǿ����ڰ� ���յǾ� �ִ� ��, ���� ���� �ִ�.
// q = 5 * 2 �� ǥ������ ����� ������ ���� ����ϴ� �� �����Ϸ� ���ο����� �׷���.
// ������ side effect �� ���ۿ��̶� ���� �ƴϴ�. ���� �浵 ����
// x = 4; 4��� expression(���� ��ü�� ���� ������ �����Ƿ�)�� 4�� �����ϴ� sideeffect�� �ִ�. assignment statement��. 
// statements, expression���� ��������� ���� semicolon�� �پ� �ִ� ����
/* https://docs.microsoft.com/en-us/cpp/c-language/c-sequence-points?view=msvc-170 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	/* Statements */
	/*
	int x, y, apples;	// declaration statement
	apples = 3;			// assignment statement
	;					// null statement
	7;
	1 + 2;
	x = 4;
	x = 1 + (y = 5);	// y = 5 is subexpression �κн�
	while (x++ < 10);	// while statement (structed statements)
	printf("%d\n", y)	// function statement
	
	return 0; // return statement
	*/

	/* Side Effects and Sequence Points(���� ���� ����ϴ� ��? ��ħǥ. �� expression�� ���� ����ص� �Ǵ±���) */
	int x = 4;					// main intent is evaluating expressions �㳪 ���������δ� x�� 4�� �����ϴ� ��
	int y = 1 + x++;

	while (x++ < 10)			// (x++ < 10) is a full expression. ������ compiler�� �����ݷ�(sequence points)�� ������ expression�� ����ϴ� �ǵ�
		printf("%d\n", x);		// while �� ���� ���� ���ǹ� ��ü�� full expression�̶� �� ����� ��ģ��.

	printf("%d\n", x); // x = 11

	y = (4 + x++) + (6 + x++);	// Not (4 + x++) nor (6 + x++) is a full expression.
								// compiler�� ��ȣ ������ ������� �����ݷг����� ��������� ��ȣ�ϴ�.
								// Ư�� �����Ϸ��� ����� ������ �����Ϸ��� ���� �ٸ� �� �ִ�.
								// �� ���� �ȿ� ���� ������ ���� �����ڸ� �� �� ���� ���� ����. Ư�� �Լ��� �Ķ���Ϳ��� �׷��� ����.
	printf("%d\n", y);
	return 0;
}