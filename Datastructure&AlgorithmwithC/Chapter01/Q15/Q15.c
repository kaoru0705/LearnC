#include <stdio.h>

int main(void)
{
    int side, high;
    do
    {
        printf("높이: ");
        scanf("%d", &high);
        printf("너비: ");
        scanf("%d", &side);
    } while (side <= 0 || high <= 0);

    for (int i = 1; i <= high; i++)
    {
        for (int j = 1; j <= side; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}
/*
// 연습1-15 직사각형을 출력
#include <stdio.h>

int main(void)
{
    int height, width;          // 높이, 너비

    puts("직사각형을 출력합니다.");

    do {
        printf("높이: ");
        scanf("%d", &height);
    } while (height <= 0);

    do {
        printf("너비: ");
        scanf("%d", &width);
    } while (width <= 0);

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++)
            putchar('*');
        putchar('\n');
    }

    return 0;
}
*/