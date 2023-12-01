// �� ����(���� 2: h = ��, 13, 4, 1)
#include <stdio.h>
#include <stdlib.h>

/*--- �� ���� �Լ�(���� 2: h = ��, 13, 4, 1) ---*/
void shell(int a[], int n)
{
    int h;
    int count = 0;      // �̵�Ƚ��
    for (h = 1; h < n/9; h = h * 3 + 1)
        ;
    for (; h > 0; h /= 3)
        for (int i = h; i < n; i++) {
            int tmp = a[i];
            int j;
            for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
            {
                a[j + h] = a[j];
                count++;
            }
            a[j + h] = tmp;
            count++;
        }
    printf("��ȯȽ��: %d\n", count);
}

int main(void)
{
    int nx;

    puts("�� ����");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ����� ������ nx�� int�� �迭 x�� ����

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    shell(x, nx);               // �迭 x�� �� ����

    puts("������������ �����߽��ϴ�.");
        for (int i = 0; i < nx; i++)
            printf("x[%d] = %d\n", i, x[i]);
    free(x);                    // �迭 x�� ����

    return 0;
}
