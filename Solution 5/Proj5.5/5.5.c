/* ������ ������ */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	printf("Interger divisions\n");
	printf("%d\n", 14 / 7);
	printf("%d\n", 7 / 2); // 3.5 in floating divison ���������� �Ҽ��θ� ���ֹ���(Truncating)
	printf("%d\n", 7 / 3); // 2.333 in floating division
	printf("%d\n", 7 / 4); // 1.75 in floating division
	printf("%d\n", 8 / 4); // 2

	printf("Truncating toward zero (C99)\n"); // 0�� ����� ������ ¥����. ��ǻ� �Ҽ��� ���ֱ� �� ������ �����Ϸ��� ���� �޶���.
	printf("%d\n", -7 / 2); // -3.5 in floating division
	printf("%d\n", -7 / 3); // -2.33 in floating division
	printf("%d\n", -7 / 4); // -1.75 in floating division
	printf("%d\n", -8 / 4); // -2

	printf("\nFloating divisions\n");
	printf("%f\n", 9.0 / 4.0);
	printf("%f\n", 9.0 / 4); // Note: 4 is integer Compiler do from integer to double
	// CPU�� �ڷ����� �ٸ� ���ڳ��� ���ϱ� ������ �� �� ����. compiler���忡�� double�� �ٲ�

	return 0;
}