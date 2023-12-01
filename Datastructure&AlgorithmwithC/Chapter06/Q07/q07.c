//// �ܼ� ���� ����
//#include <stdio.h>
//#include <stdlib.h>
//#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)
//
///*--- �ܼ� ���� ���� ---*/
//void selection(int a[], int n)
//{
//    for (int i = 0; i < n - 1; i++)
//    {
//        int min = i;
//        for (int j = i + 1; j < n; j++)
//            if (a[j] < a[min])
//                min = j;
//        for (int k = 0; k < n; k++)
//        {
//            printf(" ");
//            printf("%c", (k == i) ? '*' : (k == min) ? '+' : ' ');
//        }
//        printf("\n");
//        for (int k = 0; k < n; k++)
//        {
//            printf("%2d", a[k]);
//        }
//        printf("\n");
//        swap(int, a[i], a[min]);
//    }
//}
//
//int main(void)
//{
//    int nx;
//
//    puts("�ܼ� ���� ����");
//    printf("��� ����: ");
//    scanf("%d", &nx);
//    int* x = calloc(nx, sizeof(int));   // ��� ���� nx�� int�� �迭 x ����
//
//    for (int i = 0; i < nx; i++)
//    {
//        printf("x[%d] : ", i);
//        scanf("%d", &x[i]);
//    }
//
//    selection(x, nx);                   // �迭 x�� �ܼ� ���� ����
//
//    puts("������������ �����߽��ϴ�.");
//    for (int i = 0; i < nx; i++)
//        printf("x[%d] = %d\n", i, x[i]);
//
//    free(x);                            // �迭 ����
//
//    return 0;
//}
// ���� 6-7���ܼ� ���� ����(��ȯ ������ �ڼ��� ���)
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- �ܼ� ���� ����(��ȯ ������ �ڼ��� ���)---*/
void selection(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        for (int m = 0; m < n; m++)
            printf((m == i) ? "  * " : (m == min) ? "  + " : "    ");
        putchar('\n');

        for (int m = 0; m < n; m++)
            printf("%3d ", a[m]);
        putchar('\n');

        swap(int, a[i], a[min]);
    }
    putchar('\n');
    for (int m = 0; m < n; m++)
        printf("%3d ", a[m]);
    putchar('\n');
}

int main(void)
{
    int nx;

    puts("�ܼ� ���� ����");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ��� ������ nx�� int�� �迭 x�� ����

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    selection(x, nx);                   // �迭 x�� �ܼ� ���� ����

    puts("������������ �����߽��ϴ�.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // �迭 x�� ����

    return 0;
}

