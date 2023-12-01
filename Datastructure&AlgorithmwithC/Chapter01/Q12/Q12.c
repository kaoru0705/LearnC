// °ö¼ÀÇ¥¸¦ Ãâ·Â

#include <stdio.h>

int main(void)
{
    printf("----- °ö¼ÀÇ¥ -----\n");

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
// ¿¬½À1-12¡¡±¸±¸´Ü °ö¼ÀÇ¥¸¦ Ãâ·Â(Á¦¸ñ Æ÷ÇÔ)
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