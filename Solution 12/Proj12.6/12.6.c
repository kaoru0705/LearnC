/* Register �������� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// ũ�� ���� �ڵ������� ���� ���� ���� �޸𸮿����� ��ġ ��������(�Ǵ� ����)
// register Ű���带 double Ÿ�Կ� ���� ��� �����Ϸ��� ���� ������ ��ü�� �� �Ǵ� ��쵵 �ִ�
void temp(register int r)
{
    // do something with r
}

int main()
{
    register int r; // ������ �������Ϳ� ���ּ��� ��û, ���� �� �� �Ӻ����, �ϵ������� ����� ���� �ִ�.
    r = 123;

    //printf("%p\n", &r);
    //int* ptr = &r;  // Error: '&' on register variable �޸𸮰� �ƴ϶� �������Ϳ� ����� ������ �ּҴ� ������ �� ���� �������Ϳ� ������ ������ �ƹ�ư �ּҴ� �� ������ ���� ��������
    // double�� �����Ϸ��� ���� �� �� ���� �ִ�.

    return 0;
}