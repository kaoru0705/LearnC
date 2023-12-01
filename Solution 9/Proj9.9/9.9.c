/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* ������ ��ȯ ���� */ // ��ǻ�Ͱ� ����ϴ� ���ڴ� �ᱹ ��������.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*
	10
	10 / 2 = 5, remainder = 0
	5 / 2 = 2, remainder = 1
	2 /2 = 1, remainder = 0
	1 / 2 = 0, remainder = 1
*/
// recursion�� loop�� �����ϴ� �� ���������� ���� �ܾ��� �� ����. ����� ���� ����
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
/* My answer loop���� ���ݱ��� ���ɷδ� ���� �Ұ��� �� �Ųٷ� �̾ƶ� */
//void print_binary_loop(unsigned long n)
//{
//	long remainder[100] = { 0 }; // �����Ҵ� ��� ���� ��
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
		int quotient = n / 2; // quotient = ��
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