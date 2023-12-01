// �ܼ� ���� ����
#include <stdio.h>
#include <stdlib.h>

/*--- �ܼ� ���� ���� �Լ� ---*/
void insertion(int a[], int n)
{
    int count = 0;
    for (int i = 1; i < n; i++) {
        int tmp = a[i];
        int j;
        for (j = i; j > 0 && a[j - 1] > tmp; j--)
        {
            a[j] = a[j - 1];
            count++;
        }
        a[j] = tmp;
        count++;
    }
    printf("�̵� Ƚ��: %d\n", count);
}

int main(void)
{
    int nx;

    puts("�ܼ� ���� ����");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ����� ������ nx�� int�� �迭 x�� ����

    for (int i = 0; i < nx; i++) {
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
