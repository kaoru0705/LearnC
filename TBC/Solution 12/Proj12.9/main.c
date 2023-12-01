/* Static Variables with Internal Linkage ���� ������ ���� ���� */
#define _CRT_SECURE_NO_WARNINGS
// main.c file
#include <stdio.h>

/*
    Static variable with internal linkage
    - file scope, external linkage, static storage duration
    - internal storage class
*/

/*
    Storage Classes and Functions
    - Functions external(by default) or static
    - A function declaration is assumed to be extern
    - �Լ��� ���α׷��� �Բ� �ε�Ǿ� �޸𸮿� ��� �����Ѵ�
*/

static int g_int = 123;  // ���� ���� ���ο����� ���� ����
// �⺻������ ���������� ����� �������� �ʴ´�. �ʹ� �����ϴϱ� ���� ���Ͽ��� ���� �ٲ�� ���߿� ������� �ϰų� �����ϰų� �߰��ϸ� �׷��� �ٸ� ���Ͽ��� ������� ���ϰ� ���ƹ����� �ʹٸ�?
//int g_int = 123;  // defining declaration �ʱ�ȭ�� �� ��������

void fun();  // �Լ��� ������Ÿ�� ���� �� extern�� �����Ǿ� �ִ� ������ �� �� �ִ�(��, ��������� �ٿ��� �翬�� �����Ѵ�)
void fun_second();
void fun_third();

int main()
{
    fun();
    fun_second();
    fun_third();

    return 0;
}

void fun()
{
    extern int g_int;  // Optional
    g_int += 1;
    printf("g_int in fun_second() %d %p\n", g_int, &g_int);
}