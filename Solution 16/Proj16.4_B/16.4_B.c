/* �Լ� ���� ��ũ�� */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>

/*
    stringizing(��Ʈ������¡) operator #
    - converts macro parameters to string literals
*/
#define SQUARE(X)       (X)*(X)
#define PRINT_SQR1(X)   printf("The square of %d is %d.\n", X, SQUARE(X))
#define PRINT_SQR2(X)   printf("The square of " #X " is %d.\n", SQUARE(X)) // ��ó���⿡�� ���ڿ��� �ٲ� �ǿܷ� �����ϰ� ����

/*
    ## operator combines two tokens into a single token
*/

#define XNAME(n)    x ## n      //n�� argument�� ���԰� x�� Ÿ������ �� �׳� x��
#define PRT_XN(n)   printf("x" #n " = %d\n", x ## n);

int main(void)
{
    PRINT_SQR1(10);
    PRINT_SQR2(10);

    printf("\n");

    int XNAME(1) = 1;   // int x1 = 1;
    int XNAME(2) = 2;   // int x2 = 2;

    PRT_XN(1);          // printf("x1 " = %d\n", x1);
    PRT_XN(2);          // printf("x2 " = %d\n", x2);

	return 0;
}


/*
    Macro or Function ? // macro ��������? �׷��� function�� ���� �� ����. ��ũ�δ� ��ó���⿡�� �̷����Ƿ� �����Ϸ��� ������ ������� ����
    �㳪 �ڵ��ϴ� �з��� �ٿ��ְų� �ݺ������� �ڵ��ϴ� �κ��� �ν��ϱ� ���� ���� ��ǥ������ �ؿ� ��ũ��
    - no space in the macro name
    - Use parentheses ��ȣ�� �� ��� �ȴ�.
    - Use capital letters for macro function names
    - Speed up? �ӵ��� �������� ��밨? �ֱٿ��� �����Ϸ��� ����ȭ���ִ� ���� �Ϲ���
*/

#define MAX(X,Y)        ((X) > (Y) ? (X) : (Y)) // c������ ���� ����
#define MIN(X,Y)        ((X) < (Y) ? (X) : (Y))
#define ABS(X,Y)        ((X) < 0 ? -(X):(X))
