/* 미리 정의된 매크로들, #line, #error */
#include <stdio.h>
#include "DifferentFile.h"

void different_function();

int main(void)
{
    printf("__FILE__ : %s\n", __FILE__);  // __FILE__ : 현재 매크로가 사용된 파일 이름을 문자열로 바꿈
    printf("__DATE__ %s\n", __DATE__);    // __DATE__ : 전처리가 실행된 날짜(실행 날짜가 아님)
    printf("__TIME__ %s\n", __TIME__);    // __TIME__ : 전처리가 실행된 시간(실행 날짜가 아님)
    printf("__LINE__ %d\n", __LINE__);    // __LINE__ : 이 매크로가 코드 몇 번째 줄에 위치해있는지 알려준다
    printf("__func__ %s\n", __func__);    // __func__ : 이 매크로가 포함된 함수 이름의 문자열

    different_function();

    different_function_in_different_file();

    /* Not defined in VS */

    //printf("__STDC__ %d\n", __STDC__);                // comforms to the C standard c언어 표준을 만족하는가? 만족하면 1
    //printf("__STDC_HOSTED__ %d\n", __STDC_HOSTED__);  // hosted vs freestanding implementation KNK p.330 표준을 엄격하게 따르느냐 아니냐 hosted면 1
    //printf("__STDC_VERSION__ %ld\n", __STDC_VERSION__); // 지금 c표준의 버전이 몇이냐

//#line 7         // 다음 줄의 라인을 7로 바꿔버림
//    printf("__LINE__ after #line %d\n", __LINE__);
//
//#line 1 "hello.txt"     // hello.txt의 경로로 강제로 바꿔버림
//    printf("__LINE__ after #line %d\n", __LINE__);
//    printf("__FILE__ : %s\n", __FILE__);

///*조건에 따라 컴파일을 못하도록 막는 방법*/
#if __LINE__ != 33  // 위 코드를 주석처리하고 하면 잘 실행 됨  1>hello.txt(6,1): fatal error C1189: #error:  Not line 33
#error Not line 33  // compile error가 나게 만듦 실무에선 많이 사용함
#endif

#if defined(_WIN64) != 1
#error Not WIN64 platform
#endif

//#if __STDC_VERSION__ != 201112L // L은 long type을 의미
//#error Not C11
//#endif

    return 0;
}

void different_function()
{
    printf("This function is %s\n", __func__);
    printf("This is line %d\n", __LINE__);
}
