#include <stdio.h>

int main(void)
{
    int side, high;
    do
    {
        printf("����: ");
        scanf("%d", &high);
        printf("�ʺ�: ");
        scanf("%d", &side);
    } while (side <= 0 || high <= 0);

    for (int i = 1; i <= high; i++)
    {
        for (int j = 1; j <= side; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}
/*
// ����1-15 ���簢���� ���
#include <stdio.h>

int main(void)
{
    int height, width;          // ����, �ʺ�

    puts("���簢���� ����մϴ�.");

    do {
        printf("����: ");
        scanf("%d", &height);
    } while (height <= 0);

    do {
        printf("�ʺ�: ");
        scanf("%d", &width);
    } while (width <= 0);

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++)
            putchar('*');
        putchar('\n');
    }

    return 0;
}
*/