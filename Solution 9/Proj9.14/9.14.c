/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* �����Ϳ� �ڵ� ��Ÿ�� */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	// int *a_ptr vs int* a_ptr
	// int *my_ptr, sec_ptr;
	int* a, b; // �����Ͱ� ��������δ� int�� ������ �ּҸ� �����ϴ� ���̹Ƿ� �̷��� ������ �� �ִ�.
	// ��ġ int�� ������ �ڷ����� �ִ� ��ó��
	// �̷��� �ϸ� b�� �׳� int��� �� �ʺ��ڴ� �򰥷��� ������������ int *a, b; �̷��� ���� ����.
	// visual studio �ڵ�formatting���δ� int* a, * b; �̷��� �ȴ�.
	// �ڷ��� �ڿ� ������ ������ �տ� �������� ȸ�翡 ���� �ٸ�
	//int* a;
	//int* b; //c++������ �Ϲ������� �̷��� �ɰ��� �Ѵ�.
	// tools - options - c/c++ formatting - general - default formatting style
	// LIVM int *a; �ڷ� ���� tab�� �� ĭ���� �پ��
	// Google int * b; �̰͸� �� �ǰ� �� ��


	return 0;
}