#include <stdio.h>  // printf() in second.c

//extern int g_int;  //��� 1
//referencing declaration �ٸ� ��򰡿� �ִ� ������ �̸��� ������ ���� �Ŵ� �ϴ� �������� �� ��򰡿� �ִ� ��ó�� ������ �ϰ� ��ŷ�� �� ������ ���Ѷ� �׸��� ������ �� ��ŷ�� �� ���� ������ �޸𸮸� ã�ư��� ���� �������⵵ �ϰ� �ٲٱ⵵ �ϰ� �̷��� �۾��� �ض�.
//extern int g_int = 777;  // can initialize extern variables in file scope(linking error ��, main.c file���� g_int�� �ʱ�ȭ�Ǿ� ���� ���� ��쿡�� �ʱ�ȭ ����)
//file scope������ �� ���� �ʱ�ȭ �ؾ� �ȴ�. ���������� extern�� ���� ���� �ʱ�ȭ�� �� �ϴ� �� �� �򰥸���.

void temp()
{
    extern int g_int;  // ��� 2
    //extern int g_int = 777;  // cannot initialize extern variables in block scope
    g_int += 1000;
}

void fun_sec()
{
    temp();

    extern int g_int;  // ��� 2
    //block scope������ �ʱ�ȭ ���� �Ұ��� ���������� ���Ƴ� �Լ� ���δ� ������ �ٷ�� ������ bss data segment�� �ȵȴ�.
    g_int += 7;
    printf("g_int in fun_sec() %d %p\n", g_int, &g_int);
}