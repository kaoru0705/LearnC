// ���� ����(���� 2: ��ȯ Ƚ���� ���� ���� �۾��� ����)
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- ���� ����(���� 2: ��ȯ Ƚ���� ���� ���� �۾��� ����) ---*/
void bubble(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int exchg = 0;              // �н����� �õ��� ��ȯ Ƚ��
        for (int j = n - 1; j > i; j--)
            if (a[j - 1] > a[j]) {
                swap(int, a[j - 1], a[j]);
                exchg++;
            }
        if (exchg == 0) break;      // ��ȯ�� ������� �ʾҴٸ� ������ ����
    }
}
int is_sorted(const int a[], int n)
{
        int exchg = 0;              // �н����� �õ��� ��ȯ Ƚ��
        for (int j = n - 1; j > 0; j--)
        {
            if (a[j - 1] > a[j])
            {
                exchg++;
                return 0;
            }
        }
        return 1;
}

// ���� 6-3���迭�� ������ ���ƴ����� �˻�
//
///*--- �迭�� ������ ���ƴ°�? ---*/
//int is_sorted(int a[], int n)
//{
//    for (int i = n - 1; i > 0; i--)
//        if (a[i - 1] > a[i])
//            return 0;
//    return 1;
//}
int main(void)
{
    int nx;

    puts("���� ����");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ��� ���� nx�� int�� �迭 x ����

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    printf("%d\n", is_sorted(x, nx));
    bubble(x, nx);                      // �迭 x�� ���� ����
    puts("������������ �����߽��ϴ�.");
    printf("%d\n", is_sorted(x, nx));
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // �迭 ����

    return 0;
}
