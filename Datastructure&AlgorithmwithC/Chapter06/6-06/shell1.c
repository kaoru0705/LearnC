// �� ����(���� 1)
#include <stdio.h>
#include <stdlib.h>

/*--- �� ���� �Լ� ---*/
void shell(int a[], int n)
{
    int count = 0;          // �̵�Ƚ��
    for (int h = n / 2; h > 0; h /= 2)
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

    free(x);                    // �迭�� ����

    return 0;
}
