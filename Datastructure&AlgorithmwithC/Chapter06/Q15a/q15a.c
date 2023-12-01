//// �� ����
//#include <stdio.h>
//#include <stdlib.h>
//#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)
//int count = 0;
///*--- �� ���� �Լ� ---*/
//void quick(int a[], int left, int right)
//{
//    int pl = left;              // ���� Ŀ��
//    int pr = right;             // ������ Ŀ��
//    int x = a[(pl + pr) / 2];   // �ǹ��� ��� ��Ҹ� ����
//    do
//    {
//        while (a[pl] < x) pl++;
//        while (a[pr] > x) pr--;
//        if (pl <= pr)
//        {
//            swap(int, a[pl], a[pr]);
//            pl++;
//            pr--;
//            count++;
//        }
//    } while (pl <= pr);
//    if (pr - left < right - pl)
//    {
//        if (left < pr)  quick(a, left, pr);
//        if (pl < right) quick(a, pl, right);
//    }
//    else
//    {
//        if (pl < right) quick(a, pl, right);
//        if (left < pr)  quick(a, left, pr);
//    }
//}
//
//int main(void)
//{
//    int nx;
//    puts("�� ����");
//    printf("��� ����: ");
//    scanf("%d", &nx);
//    int* x = calloc(nx, sizeof(int));   // ����� ������ nx�� int�� �迭 x�� ����
//    for (int i = 0; i < nx; i++)
//    {
//        printf("x[%d] : ", i);
//        scanf("%d", &x[i]);
//    }
//    quick(x, 0, nx - 1);                // �迭 x�� ���ؼ� �� ����
//    puts("������������ �����߽��ϴ�.");
//    for (int i = 0; i < nx; i++)
//        printf("x[%d] = %d\n", i, x[i]);
//    free(x);                            // �迭 x�� ����
//    printf("��ȯȽ��: %d\n", count);
//
//    return 0;
//}
// ���� 6-14���� ����(��� ������ ���� �׷��� �켱 ����: ��� ����)
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- �� ����(��� ������ ���� �׷��� �켱 ����) ---*/
void quick(int a[], int left, int right)
{
    int pl = left;              // ���� Ŀ��
    int pr = right;             // ������ Ŀ��
    int x = a[(pl + pr) / 2];   // �ǹ��� ��� ���

    do
    {
        while (a[pl] < x) pl++;
        while (a[pr] > x) pr--;
        if (pl <= pr)
        {
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
        }
    } while (pl <= pr);

    if (pr - left < right - pl)
    {
        swap(int, pl, left);
        swap(int, pr, right);
    }
    if (pl < right) quick(a, pl, right); // ��� �ϳ� ȣ���ϰ� ������ ȣ���ϴ� �Ŷ� �ǹ� ���� ��Һ��� ȣ���ϴ� �� �ǹ̰� ����. �޸𸮸� ���� ���� �� �� ����.
    if (left < pr)  quick(a, left, pr);
}

int main(void)
{
    int nx;

    puts("�� ����");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ��� ������ nx�� int�� �迭 x�� ����

    for (int i = 0; i < nx; i++)
    {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    quick(x, 0, nx - 1);                // �迭 x�� �� ����

    puts("������������ �����߽��ϴ�.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // �迭 x�� ����

    return 0;
}
