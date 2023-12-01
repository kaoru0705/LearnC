#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>

#define TYPE 1 // 2로 바꾸면 highlight되는 부분도 바뀐다.

#if TYPE == 1       // macro가 1이냐를 if문처럼 사용 가능 전처리기에서 처리
#include "my_function_1.h"
#elif TYPE == 2
#include "my_function_2.h"
#else
static void my_function()
{
    printf("Wrong compile option!");
}
#endif

int main(void)
{
    my_function();
    return 0;
}