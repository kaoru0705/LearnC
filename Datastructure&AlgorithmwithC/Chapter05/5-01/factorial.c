// ���������� ����� ��������� ���Ͽ� ���
#include <stdio.h>

/*--- ���� n�� ������������ ��ȯ ---*/
int factorial(int n)
{
    if (n > 0)
        return n * factorial(n - 1);
    else
        return 1;
}
int main(void)
{
    int x;
    printf("������ �Է��ϼ���: ");
    scanf("%d", &x);
    printf("%d�� ������������ %d�Դϴ�.\n", x, factorial(x));

    return 0;
}
//// ���������� ����� ��������� ���Ͽ� ���(���� ������)
//#include <stdio.h>
//
///*--- ���� n�� ������������ ��ȯ(���� ������) ---*/
//int factorial(int n)
//{
//    return (n > 0) ? n * factorial(n - 1) : 1;
//}
//
//int main(void)
//{
//    int x;
//
//    printf("������ �Է��ϼ���: ");
//    scanf("%d", &x);
//
//    printf("%d�� ������������ %d�Դϴ�.\n", x, factorial(x));
//
//    return 0;
//}
