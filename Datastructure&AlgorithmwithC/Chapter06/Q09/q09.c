// �ܼ� ���� ���� a[0] ����
#include <stdio.h>
#include <stdlib.h>

/*--- �ܼ� ���� ���� �Լ� ---*/
void insertion(int a[], int n)
{
    for (int i = 2; i <= n; i++)
    {
        a[0] = a[i];
        int j;
        for (j = i; a[j - 1] > a[0]; j--) // j > 1 && 
            a[j] = a[j - 1];
        a[j] = a[0];
    }
}

int main(void)
{
    int nx;

    puts("�ܼ� ���� ����");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx + 1, sizeof(int));   // ����� ������ nx�� int�� �迭 x�� ����

    for (int i = 1; i < nx + 1; i++)
    {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    insertion(x, nx);                   // �迭 x�� �ܼ� ���� ����

    puts("������������ �����߽��ϴ�.");
    for (int i = 1; i < nx + 1; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // �迭 ����

    return 0;
}
//// ���� 6-9���ܼ� ���� ����(�����ʹ� a[1] ���Ŀ� �����)
//#include <stdio.h>
//#include <stdlib.h>
//
///*--- �ܼ� ���� ����(�����ʹ� a[1] ���Ŀ� �����) ---*/
//void insertion(int a[], int n)
//{
//    for (int i = 2; i <= n; i++) {
//        int tmp = a[0] = a[i];
//        int j;
//        for (j = i; a[j - 1] > tmp; j--)
//            a[j] = a[j - 1];
//        if (j > 0) a[j] = tmp; // ��� a[0] > tmp �̱⿡ ������ ���� j == 1�� ������ ������.
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
//    int* x = calloc(nx + 1, sizeof(int));   // ����� ������ (nx+1)�� int�� �迭 x�� ����
//
//    for (int i = 1; i < nx + 1; i++) {
//        printf("x[%d] : ", i);
//        scanf("%d", &x[i]);
//    }
//
//    insertion(x, nx);                   // �迭 x�� �ܼ� ���� ����
//
//    puts("������������ �����߽��ϴ�.");
//    for (int i = 1; i < nx + 1; i++)
//        printf("x[%d] = %d\n", i, x[i]);
//
//    free(x);                            // �迭 x�� ����
//
//    return 0;
//}
