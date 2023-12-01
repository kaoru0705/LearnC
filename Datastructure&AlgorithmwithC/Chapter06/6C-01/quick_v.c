// �迭�� ���� ������ ����ϴ� �� ���� ���α׷�
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- �迭�� ���� ������ ����ϴ� �� ���� ���α׷� ---*/
void quick(int a[], int left, int right)
{
    int pl = left;              // ���� Ŀ��
    int pr = right;             // ������ Ŀ��
    int x = a[(pl + pr) / 2];   // �ǹ�(��� ���)

    printf("a[%d]��a[%d]��{", left, right);
    for (int i = left; i < right; i++)
        printf("%d , ", a[i]);
    printf("%d}\n", a[right]);      // ������

    do {
        while (a[pl] < x) pl++;
        while (a[pr] > x) pr--;
        if (pl <= pr) {
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
        }
    } while (pl <= pr);

    if (left < pr)  quick(a, left, pr);
    if (pl < right) quick(a, pl, right);
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
    quick(x, 0, nx - 1);                // �迭 x�� ���ؼ� �� ����
    puts("������������ �����߽��ϴ�.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);                            // �迭 x�� ����

    return 0;
}