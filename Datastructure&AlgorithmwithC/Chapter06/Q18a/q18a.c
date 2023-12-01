// �������� ����(������Ʈ ����: ��� ������ 9 ���ϸ� �ܼ� ���� ���ģ� ���2
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)
int sortoutmed(int a[], int x, int y, int z)
{
    if (a[y] > a[x])
        swap(int, a[y], a[x]);
    if (a[y] < a[z])
        swap(int, a[y], a[z]);
    if (a[y] > a[x])
        swap(int, a[y], a[x]);

    return y;
}
/*--- �ܼ� ���� ���� ---*/
void insertion(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int tmp = a[i];
        int j;
        for (j = i; j > 0 && a[j - 1] > tmp; j--)
            a[j] = a[j - 1];
        a[j] = tmp;
    }
}

/*--- �� ���� ---*/
void quick(int a[], int left, int right)
{
    if (right - left < 9) // right - left + 1 <= 9
        insertion(&a[left], right - left + 1);
    else
    {

        int pl = left;                                  // ���� Ŀ��
        int pr = right;                                 // ������ Ŀ��
        int m = sortoutmed(a, pl, (pl + pr) / 2, pr);   // ����� ������ 3�̻��̸������� ���ʿ� 9�̻��̱� ������ ��� ����. sortoutmed�� ù��° parameter�� &a[left]�� �ϸ� �� �ȴ�. pl pr�� ������ ����ְ� �ֱ� ������
        int x = a[m];                                   // �ǹ�
        
        swap(int, a[m], a[right - 1]);
        pl++;
        pr -= 2;

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
        if (left < pr)  quick(a, left, pr);
        if (pl < right) quick(a, pl, right);
    }
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

//// ���� 6-15���� ����(������Ʈ ����: ��� ������ 9 ���ϸ� �ܼ� ���� ���ģ�
//#include <stdio.h>
//#include <stdlib.h>
//
//#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)
//
///*--- x[a], x[b], x[c]�� ����(�߾Ӱ��� �ε����� ��ȯ)---*/
//int sort3elem(int x[], int a, int b, int c)
//{
//    if (x[b] < x[a]) swap(int, x[b], x[a]);
//    if (x[c] < x[b]) swap(int, x[c], x[b]);
//    if (x[b] < x[a]) swap(int, x[b], x[a]);
//    return b;
//}
//
///*--- �ܼ� ���� ���� ---*/
//void insertion(int a[], int n)
//{
//    for (int i = 1; i < n; i++) {
//        int tmp = a[i];
//        int j;
//        for (j = i; j > 0 && a[j - 1] > tmp; j--)
//            a[j] = a[j - 1];
//        a[j] = tmp;
//    }
//}
//
///*--- �� ���� ---*/
//void quick(int a[], int left, int right)
//{
//    if (right - left < 9)
//        insertion(&a[left], right - left + 1);
//    else {
//        int pl = left;                                  // ���� Ŀ��
//        int pr = right;                                 // ������ Ŀ��
//        int m = sort3elem(a, pl, (pl + pr) / 2, pr);    // ó��, ��, ��� ��Ҹ� ����
//        int x = a[m];                                   // �ǹ�
//
//        swap(int, a[m], a[right - 1]);                  // ����� ������ 2��° ��Ҹ� ��ȯ
//        pl++;                                           // ���� Ŀ���� 1 ��Ҹ�ŭ ���������� �̵�
//        pr -= 2;                                        // ������ Ŀ���� 2 ��Ҹ�ŭ �������� �̵�
//
//        do {
//            while (a[pl] < x) pl++;
//            while (a[pr] > x) pr--;
//            if (pl <= pr) {
//                swap(int, a[pl], a[pr]);
//                pl++;
//                pr--;
//            }
//        } while (pl <= pr);
//
//        if (pr - left < right - pl) {
//            swap(int, pl, left);
//            swap(int, pr, right);
//        }
//        if (left < pr)  quick(a, left, pr);
//        if (pl < right) quick(a, pl, right);
//    }
//}
//
//int main(void)
//{
//    int nx;
//
//    puts("�� ����");
//    printf("��� ����: ");
//    scanf("%d", &nx);
//    int* x = calloc(nx, sizeof(int));   // ��� ������ nx�� int�� �迭 x�� ����
//
//    for (int i = 0; i < nx; i++) {
//        printf("x[%d] : ", i);
//        scanf("%d", &x[i]);
//    }
//
//    quick(x, 0, nx - 1);                // �迭 x�� �� ����
//
//    puts("������������ �����߽��ϴ�.");
//    for (int i = 0; i < nx; i++)
//        printf("x[%d] = %d\n", i, x[i]);
//
//    free(x);                            // �迭 x�� ����
//
//    return 0;
//}
