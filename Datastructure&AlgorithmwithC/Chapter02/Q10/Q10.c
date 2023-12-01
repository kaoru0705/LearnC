#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)
void shuffle(int a[], int n)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
    {
        int j = rand() % n;
        swap(int, a[i], a[j]);
    }

}

int main(void)
{
    int n;      // �迭 x�� y�� ��� ����

    printf("��� ����: ");
    scanf("%d", &n);
    int* x = calloc(n, sizeof(int));    // ��� ������ n�� int�� �迭 x�� ����

    printf("%d���� ������ �Է��ϼ���.\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    shuffle(x, n);

    for (int i = 0; i < n; i++)
        printf("%d", x[i]);

    free(x);                            // �迭 x�� ����

    return 0;
}

//// ����2-9���迭�� ��� ��Ҹ� �ڼ�� ����
//#include <time.h>
//#include <stdio.h>
//#include <stdlib.h>
//
///*--- type�� x���� y���� �� ---*/
//#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)
//
///*--- ��� ������ n�� �迭 a�� ��� ��� ������ �ڼ�� ���� ---*/
//void shuffle(int a[], int n)
//{
//    srand(time(NULL));
//    for (int i = n - 1; i > 0; i--) {   // �迭 a�� �ڼ���
//        int j = rand() % (i + 1);
//        if (i != j)
//            swap(int, a[i], a[j]);
//    }
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
//    printf("%d���� ������ �Է��ϼ���.\n", nx);
//    for (int i = 0; i < nx; i++) {
//        printf("x[%d] : ", i);
//        scanf("%d", &x[i]);
//    }
//
//    shuffle(x, nx);                     // �迭 x�� ����� ������ �ڼ���
//
//    printf("�迭�� ��� ����� ������ �ڼ������ϴ�.\n");
//    for (int i = 0; i < nx; i++)
//        printf("x[%d] = %d\n", i, x[i]);
//
//    free(x);                            // �迭 x�� ����
//
//    return 0;
//}