/* �Լ��� ���� ���� �з� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Storage Classes and Functions
	- Functions external (by default) or static
	- A function declaration is assumed to be extern
*/

int g_int = 123;// defining declaration
//TODO: try static

void fun(); // (extern) void fun(); �Լ��� ���ϱ� ������ �����Ǿ� �ִ�. main.c �ȿ� �ִ� �ٸ� �Լ��� ���漱�� ������ ��ü�� ����Ű�� �ִ�.
void fun_second(); // �ٸ� ���Ͽ� �ִ� �Լ��� ���� ���� ���� �굵 �ٸ� ���Ͽ� �Լ��� ����Ű�� �ִ�

int main()
{
	fun();
	fun_second();

	return 0;
}

void fun()
{
	extern int g_int;// optional

	g_int += 1;
	printf("g_int is fun() %d %p\n", g_int, &g_int);
}