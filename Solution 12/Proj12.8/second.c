#include <stdio.h>  // printf() in second.c

//extern int g_int;  //방법 1
//referencing declaration 다른 어딘가에 있는 변수를 이름을 가져다 쓰는 거다 일단 컴파일할 땐 어딘가에 있는 것처럼 컴파일 하고 링킹할 때 연결을 시켜라 그리고 실행할 때 링킹된 걸 따라서 실제로 메모리를 찾아가서 값을 가져오기도 하고 바꾸기도 하고 이렇게 작업을 해라.
//extern int g_int = 777;  // can initialize extern variables in file scope(linking error 단, main.c file에서 g_int가 초기화되어 있지 않은 경우에만 초기화 가능)
//file scope에서는 한 곳만 초기화 해야 된다. 개인적으로 extern이 붙은 곳엔 초기화를 안 하는 게 덜 헷갈린다.

void temp()
{
    extern int g_int;  // 방법 2
    //extern int g_int = 777;  // cannot initialize extern variables in block scope
    g_int += 1000;
}

void fun_sec()
{
    temp();

    extern int g_int;  // 방법 2
    //block scope에서는 초기화 절대 불가능 문법적으로 막아놈 함수 내부는 스택을 다루기 때문에 bss data segment는 안된다.
    g_int += 7;
    printf("g_int in fun_sec() %d %p\n", g_int, &g_int);
}