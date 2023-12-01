#pragma once

// 헤더가드가 표준이 되기 전에 쓰이던 방식: #ifndef, #define, #endif 조합
//#ifndef __MY_FUNCTIONS__ if not define 이런 게 선언이 안 되어 있다면? 그럴 때는 이걸 선언해라
//#define __MY_FUNCTIONS__

#include "my_functions.h" // pragma once가 없다면 ㅈ될 코드

extern int status;

static int si = 0;             // static 은 파일 스코프. 따라서 이 헤더파일을 include한 파일에 복사 붙여넣기가 된다(=include한 파일의 스코프를 갖게 된다)

extern int add(int a, int b);  // 함수는 기본적으로 extern 이므로 extern 키워드 생략 가능

static int multiply(int a, int b) // 함수를 static으로 둘 경우 body를 둘 수 있다.
{
    return a * b;
}

// int subtract(int a, int b)
inline int subtract(int a, int b)
{
    return a - b;
}

void print_status();
void print_address();

//endif 여기까지 딱 한 번만 선언된다.