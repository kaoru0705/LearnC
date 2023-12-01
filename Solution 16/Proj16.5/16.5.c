/*  Variadic Macros ���� �μ� ��ũ�� */
#include <stdio.h>
#include <math.h>

/*
    Variadic Macros accept a variable number of arguments
*/

#define PRINT(X, ...) printf("Message " #X ": " __VA_ARGS__)
// ... : ellipses(������ǥ) ...�� ���� �μ��� �� �� �ִٴ� ��
// __VA_ARGS : one of the predefined macros. variadic argument ����
// ...�κ��� ��°�� __VA_ARGS__�� ���� ������

/*
printf(...) printf f12�� �� ���� ...�� ���� �μ��� �� �� �ִٴ� ��
strvar.h Variadic arguments printf���� �����μ��� ����ϴ� ���� ���߿�
*/

int main(void)
{
    double x = 48;
    double y;

    y = sqrt(x);
    PRINT(1, "x = %g\n", x);
    printf("Message " "1" ": " "x = %g\n", x); // printf("Message " "1" ": " __VA_ARGS__) -> printf("Message " "1" ": " "x = %g\n", x)

    PRINT(2, "x = %.2F, y = %.4F\n", x, y);
    printf("Message " "2" ": " "x = %.2F, y = %.4F\n", x, y);
}