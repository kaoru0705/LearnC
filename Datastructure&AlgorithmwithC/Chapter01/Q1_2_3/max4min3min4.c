// �� ������ �Է��ϰ� �ִ��� ���Ͽ� ���

#include <stdio.h>
int max4(int a, int b, int c, int d);
int min3(int a, int b, int c);
int min4(int a, int b, int c, int d);

int main(void)
{
    printf("�ִ��� %d�Դϴ�.\n", max4(1, 2, 3, 4));
    printf("�ּڰ��� %d�Դϴ�.\n", min3(1, 2, 3));
    printf("�ּڰ��� %d�Դϴ�.\n", min4(1, 2, 3, -5));

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