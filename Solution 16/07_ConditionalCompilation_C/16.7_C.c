#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>

#define TYPE 1 // 2�� �ٲٸ� highlight�Ǵ� �κе� �ٲ��.

#if TYPE == 1       // macro�� 1�̳ĸ� if��ó�� ��� ���� ��ó���⿡�� ó��
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