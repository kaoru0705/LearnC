//// downheap
//#include <stdio.h>
//void downheap(int a[], int n)
//{
//    printf("%d\n", a[0]);
//    for (int i = 0; i < n; i = i * 2 + 1)
//    {
//        for (int j = i* 2 + 1, count = 0; j < n && count < 2 * (i + 1); j++, count++)
//        {
//                printf("%d ", a[j]);
//        }
//        printf("\n");
//    }
//}
//int main(void)
//{
//    int nx = 10;
//    int a[10] = { 10,9,5,8,3,2,4,6,7,1 };
//    downheap(a, nx);
//    return 0;
//}

// ���� 6-20���� ����(���� ������ Ʈ�� �������� ���)
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 2�� n���� ��ȯ ---*/
static int pow2(int n)
{
    int k = 1;

    while (n--)
        k *= 2;
    return (k);
}

/*--- ���� ��� ---*/
static void disp_heap(int a[], int n)
{
    int i, w, level;
    int height = 1;     // Ʈ���� ����
    int flag = 0;

    i = n;
    while (i /= 2)
        height++;

    i = 0;
    w = 1;
    for (level = 0; level < height; level++)
    {
        int k;
        printf("%*s", pow2(height - level) - 2, "");
        for (k = 0; k < w; k++)
        {
            printf("%02d", a[i++]);
            if (i >= n)
            {
                flag = 1;
                break;
            }
            printf("%*s", pow2(height - level + 1) - 2, "");
        }
        if (flag) break;

        putchar('\n');

        printf("%*s", pow2(height - level) - 3, "");
        for (k = 0; k < w; k++)
        {
            if (2 * k + i < n) printf("��");
            if (2 * k + i + 1 < n) printf("��");
            printf("%*s", pow2(height - level + 1) - 4, "");
        }
        putchar('\n');
        w *= 2;
    }
    putchar('\n');
    putchar('\n');
}

/*--- a[left] ~ a[right]�� ������ ����� ---*/
static void downheap(int a[], int left, int right)
{
    int temp = a[left];             // ��Ʈ
    int child;
    int parent;

    for (parent = left; parent < (right + 1) / 2; parent = child)
    {
        int cl = parent * 2 + 1;    // ���� �ڽ�
        int cr = cl + 1;            // ������ �ڽ�
        child = (cr <= right && a[cr] > a[cl]) ? cr : cl;   // ū ���� ����
        if (temp >= a[child])
            break;
        a[parent] = a[child];
    }
    a[parent] = temp;
}

/*--- �� ����(���� ������ Ʈ�� �������� ���)---*/
void heapsort(int a[], int n)
{
    int i;

    puts("�迭�� ���� ����ϴ�.\n");
    for (i = (n - 1) / 2; i >= 0; i--)
    {
        downheap(a, i, n - 1);
        disp_heap(a, n);
    }

    puts("���� �������� �����մϴ�.\n");
    for (i = n - 1; i > 0; i--)
    {
        swap(int, a[0], a[i]);
        disp_heap(a, n);
        downheap(a, 0, i - 1);
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

    heapsort(x, nx);    // �迭 x�� �� ����

    puts("������������ �����߽��ϴ�.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);            // �迭 x�� ����

    return 0;
}
