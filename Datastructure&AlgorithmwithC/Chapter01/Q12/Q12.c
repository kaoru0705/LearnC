// ����ǥ�� ���

#include <stdio.h>

int main(void)
{
    printf("----- ����ǥ -----\n");

    for (int j = 1; j <= 9; j++)
    {
        if (j == 1)
        {
            printf("    ");
            printf("|");
        }
        printf("%3d", j);
    }
    printf("\n");
    for (int j = 1; j <= 9; j++)
    {
        if (j == 1)
        {
            printf(" ---");
            printf("+");
        }
        printf("---");
    }
    printf("\n");

    for (int i = 1; i <= 9; i++)
    {
        printf("%3d |", i);
        for (int j = 1; j <= 9; j++)
            printf("%3d", i * j);
        putchar('\n');
    }

    return 0;
}
/*
// ����1-12�������� ����ǥ�� ���(���� ����)
#include <stdio.h>

int main(void)
{
    printf("   |");
    for (int i = 1;i <= 9; i++)
        printf("%3d", i);
    printf("\n---+---------------------------\n");

    for (int i = 1; i <= 9; i++) {
        printf("%2d |", i);
        for (int j = 1; j <= 9; j++)
            printf("%3d", i * j);
        putchar('\n');
    }

    return 0;
}
*/