// 세 정수를 입력하고 최댓값을 구하여 출력

#include <stdio.h>

int main(void)
{
    int n = 0, sum = 0;
    scanf("%d", &n);

    sum = (1 + n) * (n / 2);
    if (n % 2 == 1)
        sum += (n + 1) / 2;

    printf("%d", sum);
    return 0;
}

/* answer */
/*
// 연습1-8　1, 2, …, n의 합을 구하여 출력(가우스의 덧셈)
#include <stdio.h>

int main(void)
{
    int n;

    puts("1부터 n까지의 합을 구하세요.");

    printf("n값: ");
    scanf("%d", &n);

    int sum = (n + 1) * (n / 2) + (n % 2 == 1 ? (n + 1) / 2 : 0);

    printf("1부터 %d까지의 합은 %d입니다.\n", n, sum);

    return 0;
}
*/
