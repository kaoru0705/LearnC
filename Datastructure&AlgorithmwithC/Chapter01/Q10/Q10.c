#include <stdio.h>

int main(void)
{
    int a, b;

    printf("a의 값 : ");
    scanf("%d", &a);
    printf("b의 값 : ");
    scanf("%d", &b);
    while (b <= a)
    {
        printf("a보다 큰 값을 입력하세요!\n");
        printf("b의 값 : ");
        scanf("%d", &b);
    }
    printf("b - a는 %d입니다.\n", b - a);

    return 0;
}
/*
// 연습1-10　b - a의 값을 구하여 출력(b > a가 되도록 읽기)
#include <stdio.h>

int main(void)
{
    int a, b;

    printf("a값: ");
    scanf("%d", &a);

    while (1) {
        printf("b값: ");
        scanf("%d", &b);
        if (b > a) break;
        printf("a보다 큰 값을 입력하세요!\n");
    }

    printf("b - a는 %d입니다.\n", b - a);

    return 0;
}
*/