/* 자료형에게 별명을 붙여주는 typedef */
#define _CRT_SECURE_NO_WANRINGS

#include <stdio.h>
#include <time.h>  // time()
#define yoyo char *
int main(void)
{
    /*
        typedef specifier type definition
        - Give symbolic names(or aliases) to types
        - Does not create new types 이름을 바꿔주는 것 뿐
    */

    typedef unsigned char BYTE;       // Note the scope of BYTE
    // 1. 굉장히 긴 자료형을 반복해서 사용할 경우 줄이기 위해
    // 2. 어떤 분야에서는 unsigned char를 문자로 사용하기보다는 바이트라는 정보의 양을 측정하는 단위로써 1바이트짜리 자료를 저장하는 기본 자료형으로만 생각하고 싶어서

    BYTE x, y[10] = { 0, }, * z = &x;

    {
        typedef unsigned char byte;   // You can use lowercases as well

        /* Portable data types */

        size_t s = sizeof(byte);  // sizeof연산자의 반환형: unsigned int (x86), unsigned long long (x64) 
        // x64로 바꾸면 size_t가 알아서 unsigned long long으로 바뀜 f12 #ifdef 전처리기 바꿀 때마다 흐려지는 것을 알 수 있다.
        // unsigned int s = sizeof(byte);        // x86
        // unsigned long long s = sizeof(byte);  // x64
    }

    //byte b;  // error. typedef definition has a scope

    /*
        This function returns the time since 00:00:00 UTC, January 1, 1970 (Unix timestamp) in seconds.
    */

    time_t t = time(NULL); // 이것도 f12를 해보면 x64 x86에 따라 바뀐다.

    printf("%lld\n", t);

    /*
        typedef vs #define 기본적으로는 typdef를 권장한다.
    */

    typedef char* STRING;

    STRING name = "John Wick", sign = "World";

    /*
        - typedef interpretation is performed by the compiler, not the preprocessor
        - More flexible than #define

     #define STRING char *

     STRING name, sign; sign도 문자형 포인터 STRING으로 묶었으니
     char* name, sign;  // Note the type of sign 문법상 sign은 *이 없으므로 문자형이지 문자형 포인터가 아니다. 큰 문제가 생길 수 있는 실수
    */

    typedef struct complex {
        float real;
        float imag;
    } COMPLEX;  // typedef struct complex COMPLEX

    typedef struct { double width; double height; } rect;  // No tag
    rect r1 = { 1.1, 2.2 };
    rect r2 = r1;
    printf("%f %f\n", r2.width, r2.height);

    return 0;
}