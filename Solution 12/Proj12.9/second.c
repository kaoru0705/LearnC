#include <stdio.h>

extern int g_int;  // referencing declaration(��Ŀ�� �ٸ� ���Ͽ��� �������ؼ� ������� obj������ ã�Ƽ� �������ش�. �׷��� �ٸ� ���Ͽ��� ������� �Լ��鿡�� ���� �޸𸮸� �����ϴ� ����, ���� ����, ���� ������Ʈ�� ����ϰ� �ȴ�
// (���ʿ� g_int�� static���� ������ ��� ��ŷ ���� �߻�) ���⼭ extern�� ����ٸ�?
/*
1>main.c
1>second.obj : error LNK2001: unresolved external symbol _g_int
1>third.obj : error LNK2001: unresolved external symbol _g_int
*/


static void tool(void)
{  // �Լ��� ���� ��� �������� ��밡���ϵ��� �����ϰ� ���� �� static Ű���尡 �����ϰ� ���δ�
    // do something
}

//static void fun_second(void);  // �Լ��� ������Ÿ�� �Ǵ� �ٵ� �߿� �ϳ��� static Ű���尡 �پ� �ִٸ� static �Լ��� �����ȴ�

void fun_second(void)
{  // �� �Լ��� static�� ���̸� �ٸ� ���Ͽ��� ã�� ���ϱ⿡ ��ŷ ���� �߻�
    tool();

    g_int += 1;
    printf("g_int in fun_second() %d %p\n", g_int, &g_int);
}