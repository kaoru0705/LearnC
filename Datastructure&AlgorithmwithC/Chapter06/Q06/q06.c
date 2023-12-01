//// ���� ����(���� 3: ��ĵ ������ ����) ����� �������� bidirection bubble sort or cocktail sort or shaker sort
//#include <stdio.h>
//#include <stdlib.h>
//#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)
//
///*--- ���� ����(���� 3: ��ĵ ������ ����) ---*/
//void shaker(int a[], int n)
//{                     
//    int left = 0;
//    int right = n-1;   
//    int ccnt = 0;
//    while (1)
//    {
//        if (left < n - 1) // int i�� �ʿ����. ������ Ȧ¦ ������ �����̱� ������ 
//        {
//            int last = n - 1;                   // ���������� ��ȯ�� ������ ��ġ�� ����
//            for (int j = right; j > left; j--)
//            {
//                if (a[j - 1] > a[j])
//                {
//                    swap(int, a[j - 1], a[j]);
//                    last = j;
//                }
//                ccnt++;
//            }
//            left = last;
//        }
//        if (right > 0)
//        {
//
//            int last = 0;
//            for (int j = left; j < right; j++)
//            {
//                if (a[j] > a[j + 1])
//                {
//                    swap(int, a[j], a[j + 1]);
//                    last = j;
//                }
//                ccnt++;
//            }
//            right = last;
//        }
//        if (left == n-1 || right == 0) // == left > right
//        {
//            break;
//        }
//    }
//    printf("�� Ƚ���� %d�Դϴ�.\n", ccnt);
//}
//
//int main(void)
//{
//    int nx;
//
//    puts("���� ����");
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
//    shaker(x, nx);                      // �迭 x�� ���� ����
//
//    puts("������������ �����߽��ϴ�.");
//    for (int i = 0; i < nx; i++)
//        printf("x[%d] = %d\n", i, x[i]);
//
//    free(x);                            // �迭 ����
//
//    return 0;
//}
//���� 6-6������� ���� ����(����Ŀ ����)
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- ����� ���� ����(����Ŀ ����)---*/
void shaker(int a[], int n)
{
    int left = 0;
    int right = n - 1;
    int last = right;
    int ccnt = 0;
    while (left < right) {
        for (int j = right; j > left; j--) {
            if (a[j - 1] > a[j]) {
                swap(int, a[j - 1], a[j]);
                last = j;
            }
            ccnt++;
        }
        left = last;

        for (int j = left; j < right; j++) {
            if (a[j] > a[j + 1]) {
                swap(int, a[j], a[j + 1]);
                last = j;
            }
            ccnt++;
        }
        right = last;
    }
    printf("�� Ƚ���� %d�Դϴ�.\n", ccnt);
}

int main(void)
{
    int nx;

    puts("����� ���� ����");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ��� ������ nx�� int�� �迭 x�� ����

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    shaker(x, nx);                      // �迭 x�� ����� ���� ����

    puts("������������ �����߽��ϴ�.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // �迭 x�� ����

    return 0;
}
