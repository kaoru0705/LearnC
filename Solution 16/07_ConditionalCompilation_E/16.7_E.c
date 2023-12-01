#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>

//#undef _WIN64

void say_hello()
{
#ifdef _WIN64                // 이 매크로는 x64일 때 컴파일러가 미리 정의를 해서 넣어놓고 전처리 작업을 시작한다.
//if defined (_WIN64)        // 윗줄과 동일한 의미
    printf("Hello, WIN64");
#elif _WIN32            
    printf("Hello, WIN32");
#elif __linux__
    printf("Hello, linux");
#endif
}

int main(void)
{
    say_hello();

    return 0;
}