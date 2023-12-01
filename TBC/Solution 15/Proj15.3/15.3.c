/* &를 이용하는 십진수 -> 이진수 연습문제 */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>
#include <math.h>	// pow()
#include <string.h>	// strlen()
#include <stdlib.h>	// exit()
#include <stdbool.h>

unsigned char to_decimal(const char bi[]);
void print_binary(const unsigned char num);

int main(void)
{
	unsigned char i = to_decimal("01000110");
	unsigned char mask = to_decimal("00000101");

	print_binary(i);
	print_binary(mask);
	print_binary(i & mask);
	print_binary(i ^ (mask ^ i));
	print_binary((i ^ mask) ^ i);
	/*
		Decimal to binary
		
				Number		Mask		Mask: 용어임
		2^7 : (01000110 & 10000000) != 10000000		print 0
		
	*/

	return 0;
}
/* my poor answer */
//void print_binary(const unsigned char num)
//{
//	printf("Decimal%4hhu\t== Binary ", num);
//	for (int i = 7; i >= 0; i--)
//	{
//		if ((((size_t)pow(2, i)) & num) != (size_t)pow(2, i)) // ㅈ중복
//			printf("0");
//		else
//			printf("1");
//	}
//	printf("\n");
//}
void print_binary(const unsigned char num)
{
	printf("Decimal %3d \t== Binary ", num);

	const size_t bits = sizeof(num) * 8;
	for (size_t i = 0; i < bits; ++i)
	{
		const unsigned char mask =
			(unsigned char)pow((double)2, (double)(bits - 1 - i)); // 보기 편하라고 2^7부터 출력 허나 메모리에 저장될 때는 반대일 수도 있다.
		// unsigned char mask = pow(2, (bits - 1 - i ));

		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}
	printf("\n");

	//for (size_t i = bits - 1; i >= 0; --i)// size_t EROOR 무한 루프를 돌게 됨 이땐 size_t를 쓰면 안 됨
}


unsigned char to_decimal(const char bi[])
{
	const size_t bits = strlen(bi);
	unsigned char sum = 0;
	for (size_t i = 0; i < bits; ++i)
	{
		if (bi[i] == '1')
			sum += (int)pow(2, bits - 1 - i);
		else if (bi[i] != '0')
		{
			printf("Wrong character : %c", bi[i]);
			exit(1);
		}
	}

	return sum;
	//printf("Binary %s == Decimal %d\n", bi, sum);
}