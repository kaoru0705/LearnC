// �� ������ �Է��ϰ� �ִ��� ���Ͽ� ���

#include <stdio.h>

int main(void)
{
    int a, count=1;
    scanf("%d", &a);

    while (1)
    {
        if (a > 10)
        {
            a /= 10;
            count++;
        }
        else
            break;
    }

    printf("�� ���� %d�ڸ��Դϴ�.\n", count);
    return 0;
}
/*
// ����1-11������ ������ �ڸ����� ���Ͽ� ���
#include <stdio.h>

int main(void)
{
    int n;

    do {
        printf("���� ����: ");
        scanf("%d", &n);
    } while (n <= 0);

    int digits = 0;     // �ڸ���
    while (n > 0) {
        n /= 10;        // x�� 10���� ������
        digits++;
    }

    printf("�� ���� %d�ڸ��Դϴ�.\n", digits);

    return 0;
}
*/