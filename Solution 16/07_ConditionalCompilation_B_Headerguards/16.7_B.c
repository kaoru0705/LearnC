#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>

#include "Header_B.h"  // Header_B.h �� Header_A.h �� include�ϰ� �����Ƿ� Header_B.h �� include�ϸ� Header_A.h �� �Բ� include�ȴ�
                        //  ��κ��� ��� ���α׷��Ӱ� ��� ����� ��� �ִ��� �𸣱� ������ �ߺ��Ǵ� ��찡 ���� �߻� ���������� �ڵ���� �������� ��¿ �� ����
//#include "Header_A.h"  // (������尡 ���� ���)Header_A.h �� main.c �� �ߺ��ؼ� �� �� include �ȴ�

int main(void)
{
    test_function_A();
    test_function_B();

    return 0;
}