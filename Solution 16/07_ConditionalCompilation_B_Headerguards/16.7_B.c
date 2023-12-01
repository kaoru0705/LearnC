#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>

#include "Header_B.h"  // Header_B.h 가 Header_A.h 를 include하고 있으므로 Header_B.h 만 include하면 Header_A.h 도 함께 include된다
                        //  대부분의 경우 프로그래머가 모든 헤더가 어디 있는지 모르기 때문에 중복되는 경우가 많이 발생 현실적으로 코드양이 많아지면 어쩔 수 없음
//#include "Header_A.h"  // (헤더가드가 없을 경우)Header_A.h 가 main.c 에 중복해서 두 번 include 된다

int main(void)
{
    test_function_A();
    test_function_B();

    return 0;
}