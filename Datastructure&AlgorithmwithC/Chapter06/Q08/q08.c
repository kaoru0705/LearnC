// �ܼ� ���� ����
#include <stdio.h>
#include <stdlib.h>

/*--- �ܼ� ���� ���� �Լ� ---*/
void insertion(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int tmp = a[i];
        int j;
        for (int m = 0; m < n; m++)
            printf("%2d", a[m]);
        putchar('\n');
        for (j = i; j > 0 && a[j - 1] > tmp; j--);
        for (int m = 0; m < j; m++)
            printf("  ");
        if (a[i - 1] < tmp)
            printf(" ");
        else
            printf("^");
        for (int m = j; m < i; m++)
            printf("--");
        printf("+");
        putchar('\n');
        for (j = i; j > 0 && a[j - 1] > tmp; j--)
            a[j] = a[j - 1];
        a[j] = tmp;

    }
}

int main(void)
{
    int nx;

    puts("�ܼ� ���� ����");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ����� ������ nx�� int�� �迭 x�� ����

    for (int i = 0; i < nx; i++)
    {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    insertion(x, nx);                   // �迭 x�� �ܼ� ���� ����

    puts("������������ �����߽��ϴ�.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // �迭 ����

    return 0;
}
