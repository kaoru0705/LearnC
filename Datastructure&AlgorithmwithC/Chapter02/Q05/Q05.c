// �迭 ��Ҹ� �������� ����
#include <stdio.h>
#include <stdlib.h>

/*--- type�� x���� y���� ��ȯ ---*/
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- ��� ������ n�� �迭 a�� ��Ҹ� �������� ���� ---*/
void ary_reverse(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    for (int i = 0; i < n / 2; i++)
    {
        printf("a[%d]�� a[%d]�� ��ȯ�մϴ�.\n", i, n - i - 1);
        swap(int, a[i], a[n - i - 1]);
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
        
    }
    printf("���� ������ �����մϴ�.\n");

}

int main(void)
{
    int nx;     // �迭 x�� ��� ����

    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ��� ���� nx�� int�� �迭 x�� ����
    for (int i = 0; i < nx; i++)
    {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    ary_reverse(x, nx);                 // �迭 x�� ��Ҹ� �������� ����
    free(x);                            // �迭 x�� ����

    return 0;
}

// ����2-5���迭 ��Ҹ� �������� ����(���� ����� ǥ��)
//#include <stdio.h>
//#include <stdlib.h>
//
///*--- type�� x���� y���� ��ȯ ---*/
//#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)
//
///*--- ��� ������ n�� �迭 a�� ��Ҹ� ���� ---*/
//void ary_print(const int a[], int n)
//{
//    for (int i = 0; i < n; i++)
//        printf("%d ", a[i]);
//    putchar('\n');
//}
//
///*--- ��� ������ n�� �迭 a�� ��Ҹ� �������� ���� ---*/
//void ary_reverse(int a[], int n)
//{
//    for (int i = 0; i < n / 2; i++) {
//        ary_print(a, n);
//        printf("a[%d]�� a[%d]�� ��ȯ�մϴ�.\n", i, n - i - 1);
//        swap(int, a[i], a[n - i - 1]);
//    }
//    ary_print(a, n);
//    puts("������ �����մϴ�.");
//}
//
//int main(void)
//{
//    int nx;     // �迭 x�� ��� ����
//
//    printf("��� ����: ");
//    scanf("%d", &nx);
//    int* x = calloc(nx, sizeof(int));   // ��� ������ nx�� int�� �迭 x�� ����
//
//    for (int i = 0; i < nx; i++) {
//        printf("x[%d] : ", i);
//        scanf("%d", &x[i]);
//    }
//
//    ary_reverse(x, nx);                 // �迭 x�� ��Ҹ� �������� ����
//
//    printf("�迭�� ��Ҹ� �������� �����߽��ϴ�.\n");
//    for (int i = 0; i < nx; i++)
//        printf("x[%d] = %d\n", i, x[i]);
//
//    free(x);                            // �迭 x�� ����
//
//    return 0;
//}

