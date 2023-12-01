/* ��Ʈ���� ����ƮShift ������ */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>
#include <limits.h> // CHAR_BIT
void int_binary(const int num);

int main(void)
{
	/*
		Bitwise shift operators
		
		- Left shift 
		number << n : multiply number by 2^n // ���� �̷��� ������ ���� �ƴϴ�. ���� ������ ��� ���� ��
		
		- Right shift
		number >> n : divide by 2^n (for non-negative numbers)
	*/

	// 8 bit integer cases

	printf("%hhd\n", 1 << 3); // bitwise ���ʿ� �ִ� ���ڿ� �ָ� ���� 3ĭ�� ������ ������ 3ĭ�� 0���� ä��
	printf("%hhd\n", 8 << 1); // ������ 1ĭ�� ������

	printf("%hhd\n", -119 >> 3);	// 10001001 -> ???10001001 -> 11110001 (-15) signed integer�� ��� �� �տ� ���ڰ� 1�̸� right shift�� �� 1�� ä�� (arithemetic right shift)
	//printf("%hhd\n", -119 / 8);	// -14 ������ ��� �� �� ���� ��ȣ�� �ִ� ������ ��� ����
	printf("%hhu\n", 137 >> 3);		// 10001001 -> ???10001001 -> 00010001 (17) unsigned�� ��� 0���� ä��
	//printf("%hhu\n", 137 / 8);	// 17 ������
	printf("%hhd\n", -119 << 4);	// warning signed�� �ҽǵȴ�. 10001001 -> 10001001????	-> 10010000 (-112)
	printf("%hhu\n", 137 << 4);		// 10001001 -> 10001001???? -> 10010000 (-144)

	//Note: the signed result is machine dependent VS�� Linux�� signed 1�� ��� ???1�� 1�� ä��ٰ� �����ض�

	int a = 1;
	a <<= 3; // shift �ϰ� assignment
	a >>= 2;

	printf("Unsigned int %u\n", 0xffffffff);
	printf("Signed int %d\n", 0xffffffff);
	int_binary(0xffffffff);
	printf("Right shift by 3\n");
	int_binary(	 (signed)0xffffffff >> 3);
	int_binary((unsigned)0xffffffff >> 3);

	printf("\nUnsigned int %u\n", 0x00ffffff);
	printf("Signed int %d\n", 0x00ffffff);
	int_binary(0x00ffffff);
	printf("Right shift by 3\n");
	int_binary((signed)0x00ffffff >> 3);
	int_binary((unsigned)0x00ffffff >> 3);

	return 0;
}

void int_binary(const int num)
{
	printf("Decimal %12d \t== Binary ", num);

	const size_t bits = sizeof(num) * CHAR_BIT;
	for (size_t i = 0; i < bits; ++i)
	{
		/*const int mask =
			(int)pow((double)2, (double)(bits - 1 - i));*/ // �տ����� shift�����ڸ� ���� ���̶� ����ߴ�.
		const int mask = 1 << (bits - 1 - i); // ��Ʈ�̵������ڸ� ����ϴ� ���� ȿ�����̰� c c++ �ٿ� ���α׷���

		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}

	printf("\n");
}