/* ��Ʈ�ʵ��� �е� Padding */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>
#include <limits.h> // CHAR_BIT
#include <stdbool.h>
#include <string.h>	

void char_to_binary(unsigned char uc)
{
	const int bits = CHAR_BIT * sizeof(unsigned char);
	for (int i = bits - 1; i >= 0; i--)
		printf("%d", (uc >> i) & 1);
}

void print_binary(char* data, int bytes)//Note: extended for any sizes
{
	for (int i = 0; i < bytes; ++i)
		char_to_binary(data[bytes - 1 - i]); // char_to_binary(data[0]);  arguemnt �� 1����Ʈ�� ��
	printf("\n");
}

int main(void)
{
	struct {
		bool option1 : 1;
		//bool : 0; // ������ �޸𸮸� �� �޶� �е��� ���� ���� ��������ϱ� �޸𸮸� �� �޶� 
		bool option2 : 1;
		unsigned long long option3 : 1;
	} bbf;

	printf("%zu bytes\n", sizeof(bbf)); // 16 bytes �޸� �ȿ��� unsigned longlong�� ������ ©���� �ʰ� �ϱ� ���ؼ� bool 2���� 8����Ʈ�� �е�


	memset((char*)&bbf, 0xff, sizeof(bbf));		// 1�� �ʱ�ȭ
	print_binary((char*)&bbf, sizeof(bbf));
	bbf.option1 = 0;	// padding �κ� ���� 0���� �ٲ��. �ᱹ 1��Ʈ�� �ٲ� padding ������ 16 ����Ʈ�� �Ŵ�.
	bbf.option2 = 0;
	bbf.option3 = 0;	// bbf.option3 = 2; ?? �ᱹ 1��Ʈ�� 2�� ������ �Ѿ 0�̵�
	print_binary((char*)&bbf, sizeof(bbf));

	printf("%zu bytes\n", sizeof(bbf));

	struct {
		unsigned short option1 : 1;
		unsigned short option2 : 1;
		//unsigned short : 0;
		unsigned short option3 : 1;
	} usbf;

	printf("%zu bytes\n", sizeof(usbf)); // 2 bytes unsigned short�� �ּ� ����Ʈ�� �����.

	struct {
		unsigned int option1 : 1; // unsigned int �� 1��Ʈ�� unsigned int�� �ؼ��϶�� ��� ��Ʈ�ʵ��� ũ�⸦ ������ �� �ۿ��Ѵ�.
		//unsigned int : 0; // �̰��� �߰��ϸ� �ڷ��� ��ŭ �þ��.
		unsigned int option2 : 1;
		//bool option3 : 1;
	} uibf;

	printf("%zu bytes\n", sizeof(uibf)); // 4 bytes unsigned int unsigned int : 0; �߰��� 8 bytes

	return 0;
}