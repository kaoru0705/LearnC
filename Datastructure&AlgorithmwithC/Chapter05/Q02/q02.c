// ��Ŭ���� ȣ������ ���� �ִ������� ���Ͽ� ���
#include <stdio.h>

/*--- ���� x, y�� �ִ������� ��ȯ ---*/

int main(void)
{
    int x, y, gcd;
    puts("�� ������ �ִ������� ���մϴ�.");
    printf("������ �Է��ϼ���: ");
    scanf("%d", &x);
    printf("������ �Է��ϼ���: ");
    scanf("%d", &y);
    while (1)
    {
        gcd = x;
        if (y == 0)
            break;
        else
        {
            
            x = y;
            y = gcd % y;
        }
    }
    printf("�ִ������� %d�Դϴ�.\n", gcd);

    return 0;
}
//// ���� 5-2����Ŭ���� ȣ������ ���� �ִ������� ����������� ���Ͽ� ���
//#include <stdio.h>
//
///*--- ���� x, y�� �ִ������� ��ȯ ---*/
//int gcd(int x, int y)
//{
//    while (y != 0) {
//        int temp = y;
//        y = x % y;
//        x = temp;
//    }
//    return x;
//}
//
//int main(void)
//{
//    int x, y;
//
//    puts("�� ������ �ִ������� ���մϴ�.");
//
//    printf("������ �Է��ϼ���.: ");
//    scanf("%d", &x);
//
//    printf("������ �Է��ϼ���.: ");
//    scanf("%d", &y);
//
//    printf("�ִ������� %d�Դϴ�.\n", gcd(x, y));
//
//    return 0;
//}
