/* 비트단위 쉬프트Shift 연산자 */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>
#include <limits.h> // CHAR_BIT
void int_binary(const int num);

int main(void)
{
	/*
		Bitwise shift operators
		
		- Left shift 
		number << n : multiply number by 2^n // 전부 이렇게 나오는 것은 아니다. 작은 숫자일 경우 많이 씀
		
		- Right shift
		number >> n : divide by 2^n (for non-negative numbers)
	*/

	// 8 bit integer cases

	printf("%hhd\n", 1 << 3); // bitwise 왼쪽에 있는 숫자에 주목 왼쪽 3칸은 없어짐 오른쪽 3칸은 0으로 채움
	printf("%hhd\n", 8 << 1); // 오른쪽 1칸은 없어짐

	printf("%hhd\n", -119 >> 3);	// 10001001 -> ???10001001 -> 11110001 (-15) signed integer일 경우 맨 앞에 숫자가 1이면 right shift할 때 1로 채움 (arithemetic right shift)
	//printf("%hhd\n", -119 / 8);	// -14 음수일 경우 잘 안 맞음 부호가 있는 음수일 경우 조심
	printf("%hhu\n", 137 >> 3);		// 10001001 -> ???10001001 -> 00010001 (17) unsigned일 경우 0으로 채움
	//printf("%hhu\n", 137 / 8);	// 17 동일함
	printf("%hhd\n", -119 << 4);	// warning signed가 소실된다. 10001001 -> 10001001????	-> 10010000 (-112)
	printf("%hhu\n", 137 << 4);		// 10001001 -> 10001001???? -> 10010000 (-144)

	//Note: the signed result is machine dependent VS나 Linux는 signed 1일 경우 ???1을 1로 채운다고 생각해라

	int a = 1;
	a <<= 3; // shift 하고 assignment
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
			(int)pow((double)2, (double)(bits - 1 - i));*/ // 앞에서는 shift연산자를 배우기 전이라 사용했다.
		const int mask = 1 << (bits - 1 - i); // 비트이동연산자를 사용하는 것이 효율적이고 c c++ 다운 프로그래밍

		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}

	printf("\n");
}