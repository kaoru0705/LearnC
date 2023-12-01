/* _Generic 표현식 */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>
// VS에서 제공이 안되는 문법
/* https://www.onlinegdb.com/online_c_compiler */
/*
    Generic selection expression
    - Generic programming : code is not specific to a particular type    여러가지 자료형에 대해서 다 돌아갈 수 있는 코드를 만들기 위해 사용 c++ template

    _Generic : C11 keyword
*/
// function-like macro
#define MYTYPE(X) _Generic((X), \ // x의 expression이 자료형이 무엇인지에 매크로가 반환하는 값이 달라진다.
    int : (X + 123), \
    float : "float", \
    double : "double", \
    long : "long", \
    int* : "int*", \
     default : "other"\
)

int main(void)
{
    int d = 5;

    printf("%d\n", MYTYPE(d));
    printf("%s\n", MYTYPE(2.0 * d));
    printf("%s\n", MYTYPE(3L));
    printf("%s\n", MYTYPE(&d));

    return 0;
}