// ���� ���� ���α׷�
#include <stdio.h>
#include <stdlib.h>

/*--- ���� ���� �Լ�(�迭�� ��ڰ��� 0 �̻� max ����) ---*/
void counting(int a[], int n, int max)
{
    int* f = calloc(max + 1, sizeof(int));      // ���� ����
    int* b = calloc(n, sizeof(int));      // �۾��� ���� �迭

    for (int i = 0; i <= max; i++) f[i] = 0;              // [Step0]
    for (int i = 0; i < n; i++) f[a[i]]++;             // [Step1]
    for (int i = 1; i <= max; i++) f[i] += f[i - 1];      // [Step2]
    for (int i = n - 1; i >= 0; i--) b[--f[a[i]]] = a[i];   // [Step3]
    for (int i = 0; i < n; i++) a[i] = b[i];           // [Step4]

    free(b);
    free(f);
}
/*--- ���� ���� �Լ�(�迭�� ��ڰ��� min �̻� max ����) ---*/
void counting2(int a[], int n, int min, int max)
{
    int* f = calloc(max - min + 1, sizeof(int));      // ���� ����
    int* b = calloc(n, sizeof(int));      // �۾��� ���� �迭

    for (int i = 0; i <= max - min; i++) f[i] = 0;              // [Step0]
    for (int i = 0; i < n; i++) f[a[i]-min]++;             // [Step1]
    for (int i = 1; i <= max - min; i++) f[i] += f[i - 1];      // [Step2]
    for (int i = n - 1; i >= 0; i--) b[--f[a[i]-min]] = a[i];   // [Step3]
    for (int i = 0; i < n; i++) a[i] = b[i];           // [Step4]

    free(b);
    free(f);
}
int main(void)
{
    int nx;
    const int max = 100;            // ���� ū ��
    const int min = 30;
    puts("���� ����");
    printf("��� ����: ");

    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ����� ������ nx�� int�� �迭 x�� ����
    printf("%d��%d�� ������ �Է��ϼ���.\n", min, max);

    for (int i = 0; i < nx; i++)
    {
        do {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (x[i] < min || x[i] > max);
    }

    counting2(x, nx, min, max);       // �迭 x�� ���� ����
    puts("������������ �����߽��ϴ�.");

    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                    // �迭 x�� ����

    return 0;
}
//// ���� 6-22������ ����(�ּڰ��� �ִ��� ����)
//#include <stdio.h>
//#include <stdlib.h>
//
///*--- ���� ���ģ��迭 ��ڰ��� min �̻� max ���ϣ� ---*/
//void counting(int a[], int n, int min, int max)
//{
//    int* f = calloc(max - min + 2, sizeof(int));    // ���� ���� max - min + 2??? �̰� ��
//    int* b = calloc(n, sizeof(int));                // �۾��� ���� �迭
//
//    for (int i = 0; i <= max - min + 1; i++) f[i] = 0;                  // [Step0]
//    for (int i = 0; i < n; i++) f[a[i] - min]++;             // [Step1]
//    for (int i = 1; i <= max - min + 1; i++) f[i] += f[i - 1];          // [Step2]
//    for (int i = n - 1; i >= 0; i--) b[--f[a[i] - min]] = a[i];   // [Step3]
//    for (int i = 0; i < n; i++) a[i] = b[i];               // [Step4]
//
//    free(b);
//    free(f);
//}
//int main(void)
//{
//    int nx;
//    int min, max;           // �ּڰ��� �ִ�
//
//    puts("���� ����");
//    printf("��� ����: ");
//    scanf("%d", &nx);
//    int* x = calloc(nx, sizeof(int));   // ��� ������ nx�� int�� �迭 x�� ����
//
//    printf("�ּڰ�: ");
//    scanf("%d", &min);
//
//    while (1) {
//        printf("�ִ�: ");
//        scanf("%d", &max);
//        if (max > min) break;
//        printf("%d���� ū ���� �Է��ϼ���.\n", min);
//    }
//
//    printf("%d ~ %d�� ������ �Է��ϼ���.\n", min, max);
//    for (int i = 0; i < nx; i++) {
//        do {
//            printf("x[%d] : ", i);
//            scanf("%d", &x[i]);
//        } while (x[i] < min || x[i] > max);
//    }
//
//    counting(x, nx, min, max);          // �迭 x�� ���� ����
//
//    puts("������������ �����߽��ϴ�.");
//    for (int i = 0; i < nx; i++)
//        printf("x[%d] = %d\n", i, x[i]);
//
//    free(x);                            // �迭 x�� ����
//
//    return 0;
//}
