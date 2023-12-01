/* 이진수 -> 십진수 연습문제 */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>
#include <math.h>	// pow()
#include <string.h>	// strlen()
#include <stdlib.h>	// exit()

unsigned char to_decimal(const char bi[]);

int main(void)
{
	printf("Binary (string) to Decimal conversion\n");

	printf("%d\n", to_decimal("00000110"));// 1*(2^2) + 1 * (2^1) = 4 + 2 = 6
	printf("%d\n", to_decimal("00010110"));// 1*(2^4) + 1*(2^2) + 1 * (2^1) = 16 + 4 + 2 = 22

	// Note ^ (caret) means power in math.
	// Hint: (int)pow(2, 3) == 8

	printf("%d\n", to_decimal("10010100"));

	return 0;
}
/* my answer */
//unsigned char to_decimal(const char bi[])
//{
//	unsigned char ch = 0;
//	for (int i = strlen(bi) - 1; i > 0; i--)
//	{
//		ch += (int)pow(2, i) * (*bi - 48);
//		bi++;
//	}
//	return ch;
//}
unsigned char to_decimal(const char bi[])
{
	const size_t bits = strlen(bi);
	unsigned char sum = 0;
	for (size_t i = 0; i < bits; ++i) // size_t는 많이 쓴다. c++에서도 윈도우에서 했다가 리눅스에서 포팅할 때도
	{
		if (bi[i] == '1')
			sum += (int)pow(2, bits - 1 - i); // sum +=(unsigned char)pow((double)2, (double)(bits - 1 - i)); 더 정확한 형변환
		else if (bi[i] != '0')
		{
			printf("Wrong character : %c", bi[i]);
			exit(1);
		}
	}

	return sum;
	//printf("Binary %s == Decimal %d\n", bi, sum);
}
