// �� ������ �Է��ϰ� �߾Ӱ��� ���Ͽ� ���

#include <stdio.h>

/*--- a, b, c�� �߾Ӱ� ---*/
int med3(int a, int b, int c)
{
    if (a >= b)
        if (b >= c)
            return b;
        else if (a <= c)
            return a;
        else
            return c;
    else if (a > c)
        return a;
    else if (b > c)
        return c;
    else
        return b;
}

int main(void)
{
    int a, b, c, flag = 1;

    while (1)
    {
        printf("�� ������ �߾Ӱ��� ���մϴ�.\n");
        printf("a��: ");   flag = scanf("%d", &a);
        if (flag == 0) break;
        printf("b��: ");   scanf("%d", &b);
        printf("c��: ");   scanf("%d", &c);

        printf("�߾Ӱ���%d�Դϴ�.\n", med3(a, b, c));

    }
    return 0;
}
