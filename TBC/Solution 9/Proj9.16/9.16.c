/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* ����ŷ� �޸� �鿩�ٺ��� ���־� ��Ʃ��� */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// ��ü �޸� ��Ȳ�� ���� �� in Debuging mode Debug-Windows-Memory-memory1234
// b_ptr�� ���� �����ؼ� ã���� ������ ã�� �� �ִ�.
// 0x008FFD64  09 00 00 00  .... column 4
int main()
{
	int a = 3, b = 5, c = 7, d = 9;

	int* a_ptr = &a, * b_ptr = &b, * c_ptr = &c, * d_ptr = &d;

	printf("%p %p %p %p", &a, &b, &c, &d);
	

	return 0;
}