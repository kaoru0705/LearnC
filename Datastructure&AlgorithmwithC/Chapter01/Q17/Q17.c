// �� ������ �Է��ϰ� �ִ��� ���Ͽ� ���

#include <stdio.h>
void spira(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int starcount = (i - 1) * 2 + 1;

        for (int j = 0; j <= (n * 2 - starcount) / 2; j++)
            printf(" ");

        for (int j = 1; j <= starcount; j++)
        {
            printf("*");
        }
        
        printf("\n");
    }
}

int main(void)
{
    int n;
    do
    {
        scanf("%d", &n);
    } while (n <= 0);

    spira(n);

    return 0;
}

//// ����1-17����ȣ ����(*)�� �̿��� �Ƕ�̵带 ���
//#include <stdio.h>
//
///*--- ��ȣ ����(*)�� �̿��� �Ƕ�̵带 ��� ---*/
//void spira(int n)
//{
//    for (int i = 1; i <= n; i++) {              // i�ࣨi = 1, 2, �� ,n��
//        for (int j = 1; j <= n - i; j++)          // n-i���� ' '�� ���
//            putchar(' ');
//        for (int j = 1; j <= (i - 1) * 2 + 1; j++)    // (i-1)*2+1���� '*'�� ���
//            putchar('*');
//        putchar('\n');
//    }
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
//    spira(n);
//
//    return 0;
//}