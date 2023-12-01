#include <stdio.h>

extern int g_int;  // referencing declaration(최초에 g_int를 static으로 선언한 경우 링킹 에러 발생. 단, second.c 에서 extern이 아닌 int g_int; 라고 선언하면 해당 변수와 연결된다)

void fun_third(void)
{
    g_int += 1;
    printf("g_int in fun_third() %d %p\n", g_int, &g_int);
}