#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

void bubble(int a[], int n)
{
    int k = 0;                              // a[k]���� ������ ��Ҵ� ������ ��ģ ����
    int ccnt = 0;       // �� Ƚ��
    int scnt = 0;       // ��ȯ Ƚ��
    int i = 0;          // �н�
    while (k < n - 1)
    {
        printf("�н�%d: \n", ++i);
        int last = n - 1;                   // ���������� ��ȯ�� ������ ��ġ�� ����
        for (int j = n - 1; j > k; j--)
        {
            for (int m = 0; m < n; m++)
                printf("%c%d", (m != j) ? ' ' : (a[j - 1] > a[j]) ? '+' : '-', a[m]);
            printf("\n");
            ccnt++;
            if (a[j - 1] > a[j])
            {
                swap(int, a[j - 1], a[j]);
                last = j;
                scnt++;
            }
        }
        for (int m = 0; m < n; m++)
            printf("%2d", a[m]);
        printf("\n");
        k = last;
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
//// ���� 6-5������ ����(���� 3: ��ȯ ������ �ڼ��� ���)
//#include <stdio.h>
//#include <stdlib.h>
//
//#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)
//
///*--- ���� ����(���� 3: ��ĵ ������ ����) ---*/
//void bubble(int a[], int n)
//{
//    int ccnt = 0;       // �� Ƚ��
//    int scnt = 0;       // �� Ƚ��
//    int i = 0;          // �н�
//    int k = 0;          // a[k]���� ������ ��Ҵ� ������ ��ģ ����
//
//    while (k < n - 1) {
//        int last = n - 1;           // ���������� ��ȯ�� ������ ��ġ�� ����
//
//        printf("�н�%d��\n", ++i);
//        for (int j = n - 1; j > k; j--) {
//            for (int m = 0; m < n - 1; m++)
//                printf("%3d %c", a[m], (m != j - 1) ? ' ' :
//                    (a[j - 1] > a[j]) ? '+' : '-');
//            printf("%3d\n", a[n - 1]);
//
//            ccnt++;
//            if (a[j - 1] > a[j]) {
//                swap(int, a[j - 1], a[j]);
//                last = j;
//                scnt++;
//            }
//        }
//        k = last;
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
