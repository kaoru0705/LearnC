/* 8������ 16���� */
#include <stdio.h>

int main() 
{
	unsigned int decimal = 4294967295;
	unsigned int binary = 0b11111111111111111111111111111111;
	unsigned int oct = 037777777777;//0 8����
	unsigned int hex = 0xffffffff;//0x 16���� 16������ ������ �� ���� �پ���. .google�� ���� to hex�� �Է��ϸ� �˾Ƽ� �ٲ��ش�.

	printf("%u\n", decimal);
	printf("%u\n", binary);
	printf("%u\n", oct);
	printf("%u\n", hex);

	printf("%o %x %#o %#x %#X", decimal, decimal, decimal, decimal, decimal);//#��ȣ�� ���̸� ����ǥ���� �� x�� �빮�ڷ� �ϸ� �빮�ڷ� ��µ�

	return 0;
}