#include <stdio.h>

extern int g_int;  // referencing declaration(���ʿ� g_int�� static���� ������ ��� ��ŷ ���� �߻�. ��, second.c ���� extern�� �ƴ� int g_int; ��� �����ϸ� �ش� ������ ����ȴ�)

void fun_third(void)
{
    g_int += 1;
    printf("g_int in fun_third() %d %p\n", g_int, &g_int);
}