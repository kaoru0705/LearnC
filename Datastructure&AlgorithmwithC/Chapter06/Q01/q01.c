// ���� ����(���� 1) ���ʺ��� ��
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- ���� ���� ---*/
void bubble(int a[], int n)
{
    for (int i = n-1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
            if (a[j] > a[j+1])
                swap(int, a[j], a[j+1]);
    }
}

int main(void)
{
    int nx;

    puts("���� ����");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ��� ���� nx�� int�� �迭 x ����

    for (int i = 0; i < nx; i++)
    {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    bubble(x, nx);                      // �迭 x�� ���� ����

    puts("������������ �����߽��ϴ�.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // �迭 ����

    return 0;
}
