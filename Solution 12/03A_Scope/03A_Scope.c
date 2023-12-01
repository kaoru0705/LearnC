/* */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdio.h>

/*
    variable scopes (visibility 변수의 가시성)
    - block, function, function prototype, file(모든 함수의 바깥 영역)
*/

void f1(int hello, double world);    // to the end of the prototype declaration
                                    // (프로토타입 끝날때까지가 수명이 끝, 생략가능(그래서 자료형만 중요))
//void vla_param(int n, int m, double ar[n][m]); // gcc only
// [예외] VLA는 길이를 지정해줘야 하기때문에 프로토타입에서 식별자 생략 불가

// function, block scope는 비슷
double func_block(double d)
{

    double p = 0.0;
    int i;

    for (i = 0; i < 10; i++)
    //for (int i = 0; i < 10; i++) // C99
    {
        double q = d * i;
        p *= q;
        if (i == 5)
            goto hello; //hello 선언보다 앞에있음 (모든 식별자는 선언이 된 뒤에 사용가능한데 goto문은 예외)
    }
hello:
    printf("Hello, World");

    return p;
}
int main(void)
{



    func_block(1.0);
}
void f1(int hello, double world)
{

}
//void vla_param(int n, int m, double ar[n][m])
//{
//
//}