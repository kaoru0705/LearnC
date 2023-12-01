// ���� 6-13���� ���ģ�(����� ����: Ǫ��, ��, ������ �ڼ��� ���)
// �� ���α׷��� �������Ϸ��� 'IntStack.h'�� 'IntStack.c' ������ �ʿ��մϴ�.
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- �� ����(����� ����)---*/
void quick(int a[], int left, int right)
{
    IntStack lstack;        // ���� ù ��� �ε����� ����
    IntStack rstack;        // ���� �� ��� �ε����� ����

    Initialize(&lstack, right - left + 1);
    Initialize(&rstack, right - left + 1);

    Push(&lstack, left);
    Push(&rstack, right);

    printf("a[%d] ~ a[%d]�� ������ ������ ���ÿ� Ǫ���մϴ�.\n", left, right);
    printf("Lstack:");   Print(&lstack);
    printf("Rstack:");   Print(&rstack);

    while (!IsEmpty(&lstack)) {
        int pl = (Pop(&lstack, &left), left);      // ���� Ŀ��
        int pr = (Pop(&rstack, &right), right);     // ������ Ŀ��
        int x = a[(left + right) / 2];              // �ǹ��� ��� ���
        printf("���ÿ��� ������ ������ ���½��ϴ�. a[%d] ~ a[%d]�� �����ϴ�.\n", left, right);

        do {
            while (a[pl] < x) pl++;
            while (a[pr] > x) pr--;
            if (pl <= pr) {
                swap(int, a[pl], a[pr]);
                pl++;
                pr--;
            }
        } while (pl <= pr);

        if (left < pr) {
            Push(&lstack, left);    // ���� �׷� ������
            Push(&rstack, pr);      // �ε����� Ǫ��

            printf("a[%d] ~ a[%d]�� ������ ������ ���ÿ� Ǫ���մϴ�.\n", left, pr);
            printf("Lstack:");   Print(&lstack);
            printf("Rstack:");   Print(&rstack);
        }
        if (pl < right) {
            Push(&lstack, pl);      // ������ �׷� ������
            Push(&rstack, right);   // �ε����� Ǫ��

            printf("a[%d] ~ a[%d]�� ������ ������ ���ÿ� Ǫ���մϴ�.\n", pl, right);
            printf("Lstack:");   Print(&lstack);
            printf("Rstack:");   Print(&rstack);
        }
    }
    Terminate(&lstack);
    Terminate(&rstack);
}

int main(void)
{
    int nx;

    puts("�� ����");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ��� ������ nx�� int�� �迭 x�� ����

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    quick(x, 0, nx - 1);                // �迭 x�� �� ����

    puts("������������ �����߽��ϴ�.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // �迭 x�� ����

    return 0;
}
