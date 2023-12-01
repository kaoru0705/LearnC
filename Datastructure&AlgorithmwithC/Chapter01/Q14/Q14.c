#include <stdio.h>

int main(void)
{
    int side;
    scanf("%d", &side);

    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}

/*
// 연습1-14　정사각형을 출력
#include <stdio.h>

int main(void)
{
    int n;                  // 입력할 수(단 수)

    puts("정사각형을 출력합니다.");
    do {
        printf("단 수: ");
        scanf("%d", &n);
    } while (n <= 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            putchar('*');
        putchar('\n');
    }

    return 0;
}
*/
