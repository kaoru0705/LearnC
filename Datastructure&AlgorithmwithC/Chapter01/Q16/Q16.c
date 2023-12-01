#include <stdio.h>

void triangleLB(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            putchar('*');
        putchar('\n');
    }
}
void triangleLU(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
            putchar('*');
        putchar('\n');
    }
}
void triangleRU(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
            putchar('*');
        for (int j = 1; j < i; j++)
            putchar(' ');
        putchar('\n');
    }
}
void triangleRB(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n - i; j >= 1; j--)
            putchar(' ');
        for (int j = 1; j <= i; j++)
            putchar('*');
        putchar('\n');
    }
}
int main(void)
{
    int n;
    do {
        printf("�� �� �ﰢ���Դϱ�?: ");
        scanf("%d", &n);
    } while (n <= 0);

    triangleLB(n);
    triangleLU(n);
    triangleRB(n);
    triangleRU(n);

    return 0;
}

//// ����1-16������ �̵ �ﰢ���� ���
//#include <stdio.h>
//
///*--- ���� �Ʒ��� ������ ���� �̵ �ﰢ���� ǥ�� ---*/
//void triangleLB(int n)
//{
//    for (int i = 1; i <= n; i++) {              // i�ࣨi = 1, 2, �� ,n��
//        for (int j = 1; j <= i; j++)            // i���� '*'�� ���
//            putchar('*');
//        putchar('\n');
//    }
//}
//
///*--- ���� ���� ������ ���� �̵ �ﰢ���� ǥ�� ---*/
//void triangleLU(int n)
//{
//    for (int i = 1; i <= n; i++) {              // i�ࣨi = 1, 2, �� ,n��
//        for (int j = 1; j <= n - i + 1; j++)        // n-i+1���� '*'�� ���
//            putchar('*');
//        putchar('\n');
//    }
//}
//
///*--- ������ ���� ������ ���� �̵ �ﰢ���� ǥ�� ---*/
//void triangleRU(int n)
//{
//    for (int i = 1; i <= n; i++) {              // i�ࣨi = 1, 2, �� ,n��
//        for (int j = 1; j <= i - 1; j++)        // i-1���� ' '�� ���
//            putchar(' ');
//        for (int j = 1; j <= n - i + 1; j++)    // n-i+1���� '*'�� ���
//            putchar('*');
//        putchar('\n');                          // �ٹٲ�
//    }
//}
//
///*--- ������ �Ʒ��� ������ ���� �̵ �ﰢ���� ǥ�� ---*/
//void triangleRB(int n)
//{
//    for (int i = 1; i <= n; i++) {              // i�ࣨi = 1, 2, �� ,n��
//        for (int j = 1; j <= n - i; j++)        // n-i���� ' '�� ���
//            putchar(' ');
//        for (int j = 1; j <= i; j++)            // i���� *'�� ���
//            putchar('*');
//        putchar('\n');                          // �ٹٲ�
//    }
//}
//
//int main(void)
//{
//    int n;
//
//    puts("���� �̵ �ﰢ���� ����մϴ�.");
//    do {
//        printf("ũ��: ");
//        scanf("%d", &n);
//    } while (n <= 0);
//
//    printf("\n���� �Ʒ��� ����\n");   triangleLB(n);
//    printf("\n���� ���� ����\n");   triangleLU(n);
//    printf("\n������ ���� ����\n");   triangleRU(n);
//    printf("\n������ �Ʒ��� ����\n");   triangleRB(n);
//
//    return 0;
//}
