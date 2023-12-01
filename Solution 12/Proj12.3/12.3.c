/* 변수의 영역(Scope)과 연결 상태(Linkage), 객체의 지속 기간(Duration) */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
    variable scopes (visibility 변수의 가시성)
    - block, function, function prototype, file(모든 함수의 바깥 영역)
*/

// function scope
double func_block(double d) {
    double p = 0.0;

    int i;
    for (i = 0; i < 10; i++) {
        //for(int i = 0; i < 10; i++)  // C99
        double q = d * i;
        p *= q;

        if (i == 5)
            goto hello;  // goto문의 레이블은 예외적으로 함수 내 어디에서든 볼 수 있다
    }

hello:
    printf("Hello, world");

    return p;
}

// function prototype
void f1(int hello, double world);  // to the end of the prototype declaration(hello와 world의 수명은 프로토타입 끝부분까지다. 따라서 식별자가 굳이 필요하지 않다. 프로토타입에 식별자를 사용할 때는 함수 바디에 쓰인 식별자와 동일한 이름을 붙이는 게 유지보수에 용이하다. VLA의 경우 길이를 지정해줘야 하기 떄문에 프로토타입에서 식별자를 생략할 수 없다)
void via_param(int n, int m, double ar[n][m]);  // gcc only

// file scope
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
    printf("%d\n", g_j);  // Not initialized?(초기화 되지 않은 전역/정적 변수는 BSS 메모리 세그먼트에 위치하며 프로그램 시작 시 0으로 자동 초기화된다)
    printf("%d\n", local);

    return 0;
}