/* �߿��� ������Ʈ�� å���̸� �ض�*/
/* �Ҽ� �Ǵ� ���� prime number, 0�� 1 ���� ��, �Ҽ��� decimal */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdbool.h>
int main()
{
	unsigned num;
	bool isPrime = true; // flag ���� ������ ����� ���� ���¸� �ӽ÷� ǥ���ϴ� ����
	// int isPrime = 0; c������ flag�� ���������� ���� ����. ���ݰ��� ���� true�� false�ķ� �������� ������ boolean�� ����ϴ� �͵� ����.
	// c++������ int type�� ����ϴ� �� ���� ���� �ִ�.

	scanf("%u", &num);

	/*
		TODO: Check if num is a prime number
		ex) num is 4, try num % 2, num % 3
		ex) num is 5, try num % 2, num % 3, num % 4
	*/
	/* My fucking poor answers */ // flag �� true�� ��κ��� ���� �Ҽ��� �ƴϹǷ� �������� �� false�� �ΰ� ������ �� ������
	//unsigned count = 0;

	//for (unsigned i = 2; i < num; ++i)
	//{
	//	if (num % i == 0)
	//		count++;
	//}
	//if (count == 0)
	//	isPrime = true;

	/* ȫ���� */

	//for (unsigned div = 2; div < num; ++div)  // c++������ iterator �ȿ��� counter�� �����ϴ� �� ���ϴ�. ����� cstyle�� ������ ����
	//{
	//	if (num % div == 0)
	//		isPrime = false;
	//}

	//if (isPrime)
	//	printf("%u is a prime number.\n", num);
	//else
	//	printf("%u is not a prime number.\n", num);

	for (unsigned div = 2; (div * div) <= num; ++div)
		//(div * div) <= num �̷��� ����� �� ���� �� �ִ�. �����س��Ⱑ ���� �ʴ�. �ʺ� ���� ������ �� �߿�
	{
		if (num % div == 0)
		{
			isPrime = false;

			if (num == div * div)
				printf("%u is divisible by %u.\n", num, div);
			else
				printf("%u is divisible by %u and %u. \n", num, div, num/div);
		}
	}

	if (isPrime)
		printf("%u is a prime number.\n", num);
	else
		printf("%u is not a prime number.\n", num);

	return 0;
}