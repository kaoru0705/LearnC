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
// ����1-14�����簢���� ���
#include <stdio.h>

int main(void)
{
    int n;                  // �Է��� ��(�� ��)

    puts("���簢���� ����մϴ�.");
    do {
        printf("�� ��: ");
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
