// �� ������ �Է��ϰ� �ִ��� ���Ͽ� ���

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
// ����1-8��1, 2, ��, n�� ���� ���Ͽ� ���(���콺�� ����)
#include <stdio.h>

int main(void)
{
    int n;

    puts("1���� n������ ���� ���ϼ���.");

    printf("n��: ");
    scanf("%d", &n);

    int sum = (n + 1) * (n / 2) + (n % 2 == 1 ? (n + 1) / 2 : 0);

    printf("1���� %d������ ���� %d�Դϴ�.\n", n, sum);

    return 0;
}
*/
