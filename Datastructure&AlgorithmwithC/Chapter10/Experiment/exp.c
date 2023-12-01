// 세 정수를 입력하고 최댓값을 구하여 출력

#include <stdio.h>

void swap(int* ptr)
{
    int b = 7;
    int* temp = ptr;
    ptr = &b;
}
int main(void)
{
    int a = 5;
    int* p = &a;

    swap(p);
    printf("%d", *p);

    return 0;
}
