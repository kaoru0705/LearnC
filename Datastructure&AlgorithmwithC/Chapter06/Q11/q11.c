// ���� 6-10������ ���� ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*--- ���� ���� ���� ---*/
void bin_insertion(int a[], int n)
{
    int i, j;

    for (i = 1; i < n; i++) {
        int key = a[i];
        int pl = 0;                             // �˻� ���� �� ���� �ε���
        int pr = i - 1;                         // �˻� ���� �� ���� �ε���
        int pc;                                 // �˻� ���� �Ѱ���� �ε���

        do {
            pc = (pl + pr) / 2;
            if (a[pc] == key)                   // �˻� ����
                break;
            else if (a[pc] < key)
                pl = pc + 1;
            else
                pr = pc - 1;
        } while (pl <= pr);
        int pd = (pl <= pr) ? pc + 1 : pr + 1;  // ������ ��ġ�� �ε���

        memmove(&a[pd+1], &a[pd], (i-pd)*sizeof(int)); // i - pd�� �ε����� �Ÿ�
        a[pd] = key;
    }
}

int main(void)
{
    int nx;

    puts("���� ���� ����");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ��� ������ nx�� int�� �迭 x�� ����

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    bin_insertion(x, nx);               // �迭 x�� �ܼ� ���� ����

    puts("������������ �����߽��ϴ�.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // �迭 x�� ����

    return 0;
}
