// �� ����
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)
int count = 0;

/*--- �� ���� �Լ� ---*/
void quick_sort(int a[], int n)
{
    int pl = 0;
    int pr = n-1;
    int x = a[(pl + pr) / 2];   // �ǹ��� ��� ��Ҹ� ����

    do {
        while (a[pl] < x) pl++;
        while (a[pr] > x) pr--;
        if (pl <= pr)
        {
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
            count++;
        }
    } while (pl <= pr);

    if (0 < pr)  quick_sort(a, pr + 1);
    if (pl < n - 1) quick_sort(a + pl, n - pl);
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
    quick_sort(x, nx);                // �迭 x�� ���ؼ� �� ����
    puts("������������ �����߽��ϴ�.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);                            // �迭 x�� ����
    printf("��ȯȽ��: %d\n", count);

    return 0;
}
