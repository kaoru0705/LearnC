/* 2's Complement 2의 보수 표현법 확인해보기 */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>
#include <math.h>

void print_binary(const char num)
{
	printf("Decimal %3d \t== Binary ", num);

	const size_t bits = sizeof(num) * 8;
	for (size_t i = 0; i < bits; ++i)
	{
		const char mask =
			(char)pow((double)2, (double)(bits - 1 - i));

		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}
	printf("\n");

}
int main(void)
{
	/*
	Singed Integers
	
	- Sign-magnitude representation
	00000001 is 1 and 10000001 is -1
	00000000 is +0, 10000000 is -0
	Two zeros +0 -0, from -127 to + 127
	
	- One's complement method
	To reverse the sign, invert each bit.
	00000001 is 1 and 11111110 is -1.
	111111111 is - 0
	from -127 to + 127
	
	- Two's complment method (commonly used in most systems)
	To reverse the sign, invert each bit and add 1.
	from - 128 to +127
	
	*/

	print_binary(127);
	print_binary(-127);
	print_binary(~127 + 1); // 위와 동일 2의 보수

	print_binary(12);
	print_binary(-12);
	print_binary(~12 + 1);

	print_binary(7);
	print_binary(-7);
	print_binary(~-7 + 1); // 7과 동일

	return 0;
}