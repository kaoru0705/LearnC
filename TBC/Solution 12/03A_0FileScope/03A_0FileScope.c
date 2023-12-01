/* 변수의 영역(Scope)과 연결 상태(Linkage), 객체의 지속 기간(Duration) */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
    variable scopes (visibility 변수의 가시성)
    - block, function, function prototype, file(모든 함수의 바깥 영역)
*/

// file scope 03A_0FileScope.c라는 파일에서 코딩하고 있으니
int g_i = 123;  // global variable(file scope)
int g_j;        // global variable(file scope)

void func1()
{
    g_i++;

    {
        g_i = 123;
    }
}

void func2()
{
    g_i += 2;  // uses g_i

    //local = 456;  //  local scope는 func2에서는 보이지 않는다. visibility Error
}

int main()
{
    int local = 1234;

    func1();
    func2();

    printf("%d\n", g_i);  // uses g_i
    printf("%d\n", g_j);  // warning도 안 뜸 Not initialized?(초기화 되지 않은 전역/정적 변수는 BSS 메모리 세그먼트에 위치하며 프로그램 시작 시 0으로 자동 초기화된다)
    printf("%d\n", local);

    return 0;
}