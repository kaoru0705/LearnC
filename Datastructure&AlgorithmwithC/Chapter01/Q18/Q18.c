#include <stdio.h>

void nspira(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
            putchar(' ');
        for (int j = 1; j <= (n - i) * 2 + 1; j++)
            printf("%d", i % 10);
        putchar('\n');
    }
}

int main(void)
{
    int n;

    puts("�Ƕ�̵带 ����մϴ�.");
    do {
        printf("�� ��: ");
        scanf("%d", &n);
    } while (n <= 0);

    nspira(n);

    return 0;
}

//// ����1-18������ ���ڷ� ������ �Ƕ�̵� ���
//#include <stdio.h>
//
///*--- ���� ���ڷ� ������ �Ƕ�̵� ��� ---*/
//void nrpira(int n)
//{
//    for (int i = 1; i <= n; i++) {              // i�ࣨi = 1, 2, �� ,n��
//        for (int j = 1; j <= i - 1; j++)          // i-1���� ' '�� ���
//            putchar(' ');
//        for (int j = 1; j <= (n - i) * 2 + 1; j++)  // (n-i)*2+1���� ���ڸ� ���
//            printf("%d", i % 10);
//        putchar('\n');
//    }��
//}
//
//int main(void)
//{
//    int n;
//
//    puts("�Ƕ�̵带 ����մϴ�.");
//    do {
//        printf("�� ��: ");
//        scanf("%d", &n);
//    } while (n <= 0);
//
//    nrpira(n);
//
//    return 0;
//}
