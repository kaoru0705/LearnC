// ���� ����(���� 1) ��� ���ϰ�
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- ���� ���� ---*/
void bubble(int a[], int n)
{
    int cmp = 0, exch = 0;
    for (int i = 0; i < n - 1; i++)
    {
        printf("�н�%d: \n", i+1);
        for (int j = n - 1; j > i; j--)
        {
            cmp++;
            for (int k = 0; k < n; k++)
            {
                if (k == j && a[j - 1] > a[j]) // printf("%c%d", (k !=j) ? ' ' : (a[j-1] > a[j]) ? '+' : '-', a[k]);
                {
                    printf("+");
                }
                else if (k == j && a[j - 1] <= a[j])
                    printf("-");
                else
                    printf(" ");
                printf("%d", a[k]);
            }
            printf("\n");
            if (a[j - 1] > a[j])
            {
                exch++;
                swap(int, a[j - 1], a[j]);
            }
        }
        for (int k = 0; k < n; k++)
            printf("%2d", a[k]);
        printf("\n");
    }
    printf("�񱳸� %dȸ �߽��ϴ�.\n", cmp);
    printf("��ȯ�� %dȸ �߽��ϴ�.\n", exch);
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
//// ���� 6-2������ ����(��ȯ ������ �ڼ��� ���)
//#include <stdio.h>
//#include <stdlib.h>
//
//#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)
//
///*--- ���� ���� ---*/
//void bubble(int a[], int n)
//{
//    int ccnt = 0;       // �� Ƚ��
//    int scnt = 0;       // �� Ƚ��
//
//    for (int i = 0; i < n - 1; i++) {
//        printf("�н�%d��\n", i + 1);
//        for (int j = n - 1; j > i; j--) {
//            for (int m = 0; m < n - 1; m++)
//                printf("%3d %c", a[m], (m != j - 1) ? ' ' :
//                    (a[j - 1] > a[j]) ? '+' : '-');
//            printf("%3d\n", a[n - 1]);
//
//            ccnt++;
//            if (a[j - 1] > a[j]) {
//                scnt++;
//                swap(int, a[j - 1], a[j]);
//            }
//        }
//        for (int m = 0; m < n; m++)
//            printf("%3d  ", a[m]);
//        putchar('\n');
//    }
//    printf("�񱳸� %dȸ �߽��ϴ�.\n", ccnt);
//    printf("��ȯ�� %dȸ �߽��ϴ�.\n", scnt);
//}
//
//int main(void)
//{
//    int nx;
//
//    puts("���� ����");
//    printf("��� ����: ");
//    scanf("%d", &nx);
//    int* x = calloc(nx, sizeof(int));   // ��� ������ nx�� int�� �迭 x�� ����
//
//    for (int i = 0; i < nx; i++) {
//        printf("x[%d] : ", i);
//        scanf("%d", &x[i]);
//    }
//
//    bubble(x, nx);                      // �迭 x�� ���� ����
//
//    puts("������������ �����߽��ϴ�.");
//    for (int i = 0; i < nx; i++)
//        printf("x[%d] = %d\n", i, x[i]);
//
//    free(x);                            // �迭 x�� ����
//
//    return 0;
//}
