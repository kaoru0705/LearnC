#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>

//#undef _WIN64

void say_hello()
{
#ifdef _WIN64                // �� ��ũ�δ� x64�� �� �����Ϸ��� �̸� ���Ǹ� �ؼ� �־���� ��ó�� �۾��� �����Ѵ�.
//if defined (_WIN64)        // ���ٰ� ������ �ǹ�
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