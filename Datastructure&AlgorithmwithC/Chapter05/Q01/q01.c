// ���������� ����� ��������� ���Ͽ� ���
#include <stdio.h>

int main(void)
{
    int x, factori = 1;
    printf("������ �Է��ϼ���: ");
    scanf("%d", &x);
    for (int i = x; i > 1; i--)
    {
        factori *= i;
    }
    printf("%d�� ������������ %d�Դϴ�.\n", x, factori);

    return 0;
}
//// ���� 5-1������������ ����� ����������� ���Ͽ� ���
//#include <stdio.h>
//
///*--- ���� n�� ������������ ��ȯ ---*/
//int factorial(int n)
//{
//    int fact = 1;
//
//    while (n > 1)
//        fact *= n--;
//    return fact;
//}
//
//int main(void)
//{
//    int x;
//
//    printf("������ �Է��ϼ���.: ");
//    scanf("%d", &x);
//
//    printf("%d�� ������������ %d�Դϴ�.\n", x, factorial(x));
//
//    return 0;
//}
