// 세 정수를 입력하고 최댓값을 구하여 출력

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sumof(int a, int b);
int main(void)
{
    int a, b, flag;
    flag = scanf("%d %d", &a, &b);
    if (flag != 2)
        exit(-1);
    printf("%d", sumof(a, b));

    return 0;
}

int sumof(int a, int b)
{
    /*int count = abs(b - a) + 1;

    int sum = (a + b) * (count / 2) + (count % 2 == 1 ? (a + b) / 2 : 0);*/

    int sum = 0;

    if (a >= b)
        for (a; a >= b; a--)
            sum += a;
    else
        for (a; a <= b; a++)
            sum += a;
   

    return sum;
}
/* answer */
/*
int sumof(int a, int b)
{
    int min, max;

    if (a < b) {
        min = a;  max = b;
    }
    else {
        min = b;  max = a;
    }

    int sum = 0;
    for (int i = min; i <= max; i++)
        sum += i;

    return sum;
}
*/