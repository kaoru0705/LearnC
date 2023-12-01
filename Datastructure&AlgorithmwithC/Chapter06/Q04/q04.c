// ���� ����(���� 2: ��ȯ Ƚ���� ���� ���� �۾��� ����)
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- ���� ����(���� 2: ��ȯ Ƚ���� ���� ���� �۾��� ����) ---*/
void bubble(int a[], int n)
{
    int ccnt = 0, scnt = 0;              // �н����� �õ��� ��ȯ Ƚ��
    for (int i = 0; i < n - 1; i++)
    {
        printf("�н�%d: \n", i + 1);
        int exchg = 0;
        for (int j = n - 1; j > i; j--)
        {
            ccnt++;
            for (int k = 0; k < n; k++)
                printf("%c%d", (k !=j) ? ' ' : (a[j-1] > a[j]) ? '+' : '-', a[k]);
            printf("\n");
            if (a[j - 1] > a[j])
            {
                swap(int, a[j - 1], a[j]);
                exchg++;
            }
        }
        for (int k = 0; k < n; k++)
            printf("%2d", a[k]);
        printf("\n");
        if (exchg == 0) break;      // ��ȯ�� ������� �ʾҴٸ� ������ ����
        scnt += exchg;
    }
    printf("�񱳸� %dȸ �߽��ϴ�.\n", ccnt);
    printf("��ȯ�� %dȸ �߽��ϴ�.\n", scnt);
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

    free(x);                            // �迭 ����

    return 0;
}
