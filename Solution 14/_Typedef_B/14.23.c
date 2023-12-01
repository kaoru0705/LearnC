/* ������ ������ ������ �� typedef�� ��� ����� �� �ִ��� */
#define _CRT_SECURE_NO_WANRINGS

#include <stdio.h>

/*
    "One good way to synthesize declaration is  ������ ������ ������ �� typedef�� �߰� �ɰ��� ���ϴ�
     in small steps with typedef, ..."
    - K&R book Chapter 5.12
*/

/* Complicated Function Declarations */

char char3[3] = { 'A', 'B', 'C' };

char* ptrarray[3];  // ������ �迭
char(*arrayptr)[3]; // �迭 ������

char(*complicated_function1())[3]  // Function returns pointer to char[3] �������Ǹ� ���� �ؼ� ���� char (*)[3]
{
    return &char3;  // returns to a pointer to char[3]
}

typedef char(*FRPTC3())[3];  // Function returns pointer to char[3]
typedef char(*(*PTFRPTC3)())[3];    // Function pointer to function returns poitner to char[3]

char(*(*fptr1)())[3] = complicated_function1; // �̷��� �� �� ��ó�� �����ϰ� �� �� �ִ�.

FRPTC3* fptr2 = complicated_function1; //
PTFRPTC3 fptr3 = complicated_function1;

/* Use typedef to make declarations simpler */

typedef char c3[3]; // �� ����� char [3]��¥�� �迭�� c3��� �̸��� �ڷ������� ���� [3]�� �� �ڿ� �� �ֳ�? ����� �׷���.

c3* complicated_function2() // ������ char[3]�� �����͸� ��ȯ�ϴ� �Լ��� �̷��� ���� �� �ִ�. �ξ� ������
{
    return &char3;  // Returns a pointer to char[3]
}

int main(void)
{
    char(*ret_val)[3] = fptr1();

    printf("%c %c %c\n", (*ret_val)[0], (*ret_val)[1], (*ret_val)[2]);

    c3* my_c3 = fptr2(); // ���ڿ� ���� ������ �迭 �����ʹ� ��� 2���� �迭�̻��� �� ȿ����

    printf("%c %c %c\n", (*my_c3)[0], (*my_c3)[1], (*my_c3)[2]); // char3[0], char3[1], char3[2]

    return 0;
}