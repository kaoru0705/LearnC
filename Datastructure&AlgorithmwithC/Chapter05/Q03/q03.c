// ��Ŭ���� ȣ������ ���� �ִ������� ���Ͽ� ���
#include <stdio.h>
#include <stdlib.h>
/*--- ���� x, y�� �ִ������� ��ȯ ---*/
//int gcd_array(const int a[], int n)
//{
//    int gcd = a[0], x, y;
//    for (int i = 1; i < n; i++)
//    {
//        x = gcd;
//        y = a[i];
//        while (1)
//        {
//            gcd = x;
//            if (y == 0)
//                break;
//            else
//            {
//
//                x = y;
//                y = gcd % y;
//            }
//        }
//    }
//    return gcd;
//}
//
//int main(void)
//{
//    int* p, n;
//    printf("�� ���� �ִ������� ���� �̴ϱ�?: ");
//    scanf("%d", &n);
//    p = calloc(n, sizeof(int));
//    for (int i = 0; i < n; i++)
//    {
//        printf("������ �Է��ϼ���: ");
//        scanf("%d", &p[i]);
//    }
//    printf("�ִ������� %d�Դϴ�.\n", gcd_array(p, n));
//
//    return 0;
//}

// ���� 5-3���迭�� ��� ����� �ִ������� ���Ͽ� ���
#include <stdio.h>

/*--- ���� x, y�� �ִ������� ��ȯ ---*/
int gcd(int x, int y)
{
    if (y == 0)
        return (x);
    else
        return (gcd(y, x % y));
}

/*--- ��� ������ n�� �迭 a�� ��� ����� �ִ����� ---*/
int gcd_array(const int a[], int n)
{
    if (n == 1)
        return (a[0]);
    else if (n == 2)
        return (gcd(a[0], a[1]));
    else
        return (gcd(a[0], gcd_array(&a[1], n - 1)));
}

int main(void)
{
    int nx;

    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ��� ������ nx�� int�� �迭 x�� ����

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    printf("�ִ������� %d�Դϴ�.\n", gcd_array(x, nx));

    free(x);                            // �迭�� ����

    return 0;
}
