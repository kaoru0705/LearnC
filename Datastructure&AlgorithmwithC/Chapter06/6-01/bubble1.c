// ���� ����(���� 1)
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- ���� ���� ---*/
void bubble(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--)
            if (a[j - 1] > a[j])
                swap(int, a[j - 1], a[j]);
    }
}

int main(void)
{
    int nx;

    puts("���� ����");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ��� ���� nx�� int�� �迭 x ����

    for (int i = 0; i < nx; i++) {
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