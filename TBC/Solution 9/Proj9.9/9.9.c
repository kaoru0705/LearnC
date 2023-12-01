/* 중요한 프로젝트는 책꽂이를 해라*/
/* 이진수 변환 예제 */ // 컴퓨터가 사용하는 숫자는 결국 이진수다.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*
	10
	10 / 2 = 5, remainder = 0
	5 / 2 = 2, remainder = 1
	2 /2 = 1, remainder = 0
	1 / 2 = 0, remainder = 1
*/
// recursion을 loop로 구현하는 건 가능하지만 역은 단언할 수 없다. 장단점 다음 강의
void print_binary(unsigned long n);
void print_binary_loop(unsigned long n);

int main()
{
	unsigned long num = 10;

	print_binary_loop(num);

	printf("\n");

	print_binary(num);

	printf("\n");

	return 0;
}
/* My answer loop문은 지금까지 배운걸로는 구현 불가능 걍 거꾸로 뽑아라 */
//void print_binary_loop(unsigned long n)
//{
//	long remainder[100] = { 0 }; // 동적할당 써야 됐을 듯
//	int i;
//
//	for (i = 0; n > 0; i++)
//	{
//		remainder[i] = n % 2;
//		n /= 2;
//	}
//
//	for (i = i - 1; i >= 0; i--)
//		printf("%d", remainder[i]);
//}

void print_binary_loop(unsigned long n)
{
	while (1)
	{
		int quotient = n / 2; // quotient = 몫
		int remainder = n % 2;

		printf("%d", remainder); // remainder is 0 or 1

		n = quotient;

		if (n == 0) break;
	}
}
//void print_binary(unsigned long n)
//{
//
//	if (n > 1)
//		print_binary(n / 2);
//
//	printf("%d", n % 2);
//}
void print_binary(unsigned long n)
{
	int remainder = n % 2;

	if (n >= 2)
		print_binary(n / 2);

	printf("%d", remainder);

}