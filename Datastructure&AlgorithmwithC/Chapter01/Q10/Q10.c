#include <stdio.h>

int main(void)
{
    int a, b;

    printf("a�� �� : ");
    scanf("%d", &a);
    printf("b�� �� : ");
    scanf("%d", &b);
    while (b <= a)
    {
        printf("a���� ū ���� �Է��ϼ���!\n");
        printf("b�� �� : ");
        scanf("%d", &b);
    }
    printf("b - a�� %d�Դϴ�.\n", b - a);

    return 0;
}
/*
// ����1-10��b - a�� ���� ���Ͽ� ���(b > a�� �ǵ��� �б�)
#include <stdio.h>

int main(void)
{
    int a, b;

    printf("a��: ");
    scanf("%d", &a);

    while (1) {
        printf("b��: ");
        scanf("%d", &b);
        if (b > a) break;
        printf("a���� ū ���� �Է��ϼ���!\n");
    }

    printf("b - a�� %d�Դϴ�.\n", b - a);

    return 0;
}
*/