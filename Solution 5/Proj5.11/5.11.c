/* Type Conversions(�ڷ��� ��ȯ) */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	/* promotions in assignments */ // ���� ���� ū �ſ� ���� �� promotions
	short s = 64;
	int i = s;

	float f = 3.14f;
	double d = f;

	/* demotion in assignments */
	d = 1.25;
	f = 1.25;	// �ƴ� 16������ �� ������ �� ��? 0.25�� double�̵� float�� �Ϻ��ϴϱ�
	f = 1.123;	//warning truncation from 'double' to 'float'

	/* ranking of types in operations */
	// long double > double > float ���� ���� ��ŷ�� ����.
	// unsigned long long, long long // ���� ���� ��ŷ�� ����
	// unsigned long, long
	// unsigned, int
	// short int, unsigned short int
	// signed char, char, unsigned char
	// _Bool
	//Ref: Google 'Integer conversion rank'
	d = f + 1.234;
	f = f + 1.234;	// '=': conversion from 'double' to 'float', possible loss of data
	// ��ġ������ ������ ���α׷��� ��� �ǹ̰� �ִ�.

	/* automatic promotion of function arguments */ // ���Ŀ� ���� ��κ��� ���� ����� ��ó�� �Ǵµ� �׷��� ���� �� ���� ���
	// 1. Functions without prototypes ������Ÿ���� ���� �Լ��� �� ��� C99 �� �� ����
	// 2. Variadic functions (ex) ellipsis) ���� �μ��� ���� �� �ִ� ��� ������α׷��� �� �� �˾Ƹ� ����. c++������ ����

	/* casting operators */ // ���� �ٶ����ϴ�. �����Ϸ����� �ǵ��� �����ֱ� ����
	d = (double)3.14f;
	i = 1.6 + 1.7;	// 3
	i = (int) 1.6 + (int)1.7;	// ���� result 2
	
	/* more examples */
	char c;
	//int i;
	//float f;
	f = i = c = 'A'; // 65 char�� ���������δ� ���� ���
	printf("%c %d %f\n", c, i, f);
	c = c + 2; // 'C', 67
	i = f + 2 * c; // 65.0f + 2 * 67
	printf("%c %d %f\n", c, i, f); // 199
	c = 1106; // demolition, 1106 = 0b10001010010, 0b01010010 �պκ��� ©�� = 1106 % 256 = 82 = 'R'
	printf("%c\n", c);
	c = 83.99;
	printf("%c\n", c);

	i = 300;
	f = 21.75324f;
	printf("%hhd %f", i, f); // demolition �����ε�? ���� �и��� �� ���� overflow? // ��Ȯ���� ����

	return 0;
}