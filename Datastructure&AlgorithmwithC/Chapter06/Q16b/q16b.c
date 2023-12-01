// ���� 6-15��������� �� ����(������Ʈ ����: ��� ������ 9 ���ϸ� �ܼ� ���� ����, ��� ������ ���� �׷��� �켱 ����)
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- �ܼ� ���� ���� ---*/
void insertion(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int tmp = a[i];
        int j;
        for (j = i; j > 0 && a[j - 1] > tmp; j--)
            a[j] = a[j - 1];
        a[j] = tmp;
    }
}

void quick(int a[], int left, int right)
{
    IntStack lstack;        // ���� ù ��� �ε����� ����
    IntStack rstack;        // ���� �� ��� �ε����� ����

    Initialize(&lstack, right - left + 1);
    Initialize(&rstack, right - left + 1);

    Push(&lstack, left);
    Push(&rstack, right);

    while (!IsEmpty(&lstack))
    {
        Pop(&lstack, &left);
        Pop(&rstack, &right);

        if (right - left < 9) // right - left + 1 <= 9
            insertion(&a[left], right - left + 1);
        else
        {
            int pl = left;       // ���� Ŀ��
            int pr = right;     // ������ Ŀ��
            int x = a[(left + right) / 2];              // �ǹ��� ��� ���

            do
            {
                while (a[pl] < x) pl++;
                while (a[pr] > x) pr--;
                if (pl <= pr)
                {
                    swap(int, a[pl], a[pr]);
                    pl++;
                    pr--;
                }
            } while (pl <= pr);
            if (pr - left < right - pl)
            {
                swap(int, pl, left);
                swap(int, pr, right);
            }

            if (left < pr)
            {
                Push(&lstack, left);    // ���� �׷� ������
                Push(&rstack, pr);      // �ε����� Ǫ��
            }
            if (pl < right)
            {
                Push(&lstack, pl);      // ������ �׷� ������
                Push(&rstack, right);   // �ε����� Ǫ��
            }
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
    int* x = calloc(nx, sizeof(int));   // ����� ������ nx�� int�� �迭 x�� ����

    for (int i = 0; i < nx; i++)
    {
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
