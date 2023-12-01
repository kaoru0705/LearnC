/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* Pointer�� �⺻���� ��� ��� */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    int a, b;
    a = 123;
    int *a_ptr; // asterisk or int *a_ptr; Ÿ���� �ڳ� ������ ���̳� �ڵ� ��Ÿ�� ������ ���� �� ����

    a_ptr = &a; // &: address-of operator 

    printf("%d %d %p\n", a, *a_ptr, a_ptr); // printf�� �ּҸ� ����� ���� %p ��� ����
    // �ּ� ���� ũ��� �������� ũ��� ����� ����. int = float = double = ... *a_ptr
    // �ּҰ� �Ź� �ٲ� �ü���� ���� �ü���� ��� �۵��ϴ��� �����ϴ� �� �ſ� ����� ����

    *a_ptr = 456; // * : re-direction or de-referencing

    printf("%d %d %p\n", a, *a_ptr, a_ptr); //a *a_ptr��  ������ ���ؼ� �Ұų� �ּҸ� ���ؼ� �Ұų�
    // ���α׷��� ���忡���� �ణ ���̳��� ���������� �������� �ϴ� ��
    // 
    // b = a_ptr; //warning C4047: '=': 'int' differs in levels of indirection from 'int *'
    // *a_ptr�� �Ǽ��� �ƴϳ� (int)a_ptr;�̰� ���� ���� ������ �𸣴� ��� ���� 
    // ������ ���� ���ٰ� ���°� ���� ��κ� �Ǽ���.
    b = *a_ptr; // *a_ptr�̶�, �ּҰ��� ���ϴ� �ּ��� ��, �� a��
    printf("%d\n", b);
    *a_ptr = 789;
    printf("%d\n", b);
    printf("%d %d %p %p\n", a, *a_ptr, a_ptr, &b); //a�� b�� �ٸ� ������, �ٸ� object(�޸��� ������ �����ϰ� �ִ� ��)��.

	return 0;
}