// 1, 2, ��, n�� ���� ���Ͽ� ���(do ������ ����� n������ �Է�)
#include <stdio.h>

int main(void)
{
    int n;

    puts("1���� n������ ������ ���մϴ�.");

    do {
        printf("n��: ");
        scanf("%d", &n);
    } while (n <= 0);

    int sum = 0;        // ����

    for (int i = 1; i <= n; i++)    // i = 1, 2, ��, n
        sum += i;                   // sum�� i�� �߰�

    printf("1���� %d������ ������ %d�Դϴ�.\n", n, sum);

    return 0;
}
