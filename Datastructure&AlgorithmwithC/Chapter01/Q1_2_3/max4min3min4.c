// 세 정수를 입력하고 최댓값을 구하여 출력

#include <stdio.h>
int max4(int a, int b, int c, int d);
int min3(int a, int b, int c);
int min4(int a, int b, int c, int d);

int main(void)
{
    printf("최댓값은 %d입니다.\n", max4(1, 2, 3, 4));
    printf("최솟값은 %d입니다.\n", min3(1, 2, 3));
    printf("최솟값은 %d입니다.\n", min4(1, 2, 3, -5));

    return 0;
}

int max4(int a, int b, int c, int d)
{
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;

    return max;
}
int min3(int a, int b, int c)
{
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;

    return min;
}
int min4(int a, int b, int c, int d)
{
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;

    return min;
}