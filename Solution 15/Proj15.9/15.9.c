/* ����ü ���� ��Ʈ�ʵ� Bit-Fields */
/*
	field�� ���� ���ко߿��� ���� ���� ���� ��� �߷� '��' �ڱ� '��' ���� �ʵ� ��Į�� �ʵ�
	��Ʈ�ʵ� bit�� �����Ǿ� �ִ� ����, �ʵ�
	15.7ó�� ��Ʈ ���� �����ڸ� ���� �ͺ��� ���� ������ ����ϴ� ���� ������� ������? c���� �������

	struct
	{
		bool has_sword		: 1; ����� bit�� ���� �� 1���� �ƴϾ ��
		bool has_shied		: 1;
		...

	} items_flag; items_flag�� �����ϴ� �޸� ũ��� 8��Ʈ

	items_flag.has_sword = 1; // flags = flags | MASK_SWORD; ������ ���غ������� �� �� ȥ���ؼ� ����ϴ� ���� �Ϲ���
*/
#define _CRT_SECURE_NO_WANRINGS

#include <stdio.h>

int main(void)
{

	return 0;
}