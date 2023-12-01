#pragma once

// ������尡 ǥ���� �Ǳ� ���� ���̴� ���: #ifndef, #define, #endif ����
//#ifndef __MY_FUNCTIONS__ if not define �̷� �� ������ �� �Ǿ� �ִٸ�? �׷� ���� �̰� �����ض�
//#define __MY_FUNCTIONS__

#include "my_functions.h" // pragma once�� ���ٸ� ���� �ڵ�

extern int status;

static int si = 0;             // static �� ���� ������. ���� �� ��������� include�� ���Ͽ� ���� �ٿ��ֱⰡ �ȴ�(=include�� ������ �������� ���� �ȴ�)

extern int add(int a, int b);  // �Լ��� �⺻������ extern �̹Ƿ� extern Ű���� ���� ����

static int multiply(int a, int b) // �Լ��� static���� �� ��� body�� �� �� �ִ�.
{
    return a * b;
}

// int subtract(int a, int b)
inline int subtract(int a, int b)
{
    return a - b;
}

void print_status();
void print_address();

//endif ������� �� �� ���� ����ȴ�.