/* */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdio.h>

/*
    variable scopes (visibility ������ ���ü�)
    - block, function, function prototype, file(��� �Լ��� �ٱ� ����)
*/

void f1(int hello, double world);    // to the end of the prototype declaration
                                    // (������Ÿ�� ������������ ������ ��, ��������(�׷��� �ڷ����� �߿�))
//void vla_param(int n, int m, double ar[n][m]); // gcc only
// [����] VLA�� ���̸� ��������� �ϱ⶧���� ������Ÿ�Կ��� �ĺ��� ���� �Ұ�

// function, block scope�� ���
double func_block(double d)
{

    double p = 0.0;
    int i;

    for (i = 0; i < 10; i++)
    //for (int i = 0; i < 10; i++) // C99
    {
        double q = d * i;
        p *= q;
        if (i == 5)
            goto hello; //hello ���𺸴� �տ����� (��� �ĺ��ڴ� ������ �� �ڿ� ��밡���ѵ� goto���� ����)
    }
hello:
    printf("Hello, World");

    return p;
}
int main(void)
{



    func_block(1.0);
}
void f1(int hello, double world)
{

}
//void vla_param(int n, int m, double ar[n][m])
//{
//
//}