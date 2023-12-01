/* Static Variables with Internal Linkage 정적 변수의 내부 연결 */
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
    - 함수는 프로그램과 함께 로드되어 메모리에 계속 존재한다
*/

static int g_int = 123;  // 현재 파일 내부에서만 접근 가능
// 기본적으로 전역변수는 사용을 권장하지 않는다. 너무 복잡하니까 여러 파일에서 값이 바뀐다 나중에 디버깅을 하거나 수정하거나 추가하면 그래서 다른 파일에서 사용하지 못하게 막아버리고 싶다면?
//int g_int = 123;  // defining declaration 초기화는 한 곳에서만

void fun();  // 함수의 프로토타입 선언 시 extern이 생략되어 있는 것으로 볼 수 있다(즉, 명시적으로 붙여도 당연히 동작한다)
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