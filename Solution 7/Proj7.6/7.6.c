/* 중요한 프로젝트는 책꽂이를 해라*/
/* 소수 판단 예제 prime number, 0과 1 사이 즉, 소수는 decimal */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdbool.h>
int main()
{
	unsigned num;
	bool isPrime = true; // flag 내가 수행한 결과에 대해 상태를 임시로 표현하는 변수
	// int isPrime = 0; c언어에서는 flag를 정수형으로 많이 쓴다. 지금같은 경우는 true냐 false냐로 갈라지는 문제라 boolean을 사용하는 것도 좋다.
	// c++조차도 int type을 사용하는 게 좋을 때도 있다.

	scanf("%u", &num);

	/*
		TODO: Check if num is a prime number
		ex) num is 4, try num % 2, num % 3
		ex) num is 5, try num % 2, num % 3, num % 4
	*/
	/* My fucking poor answers */ // flag 가 true고 대부분의 수는 소수가 아니므로 나눠졌을 때 false로 두고 나가는 게 현명함
	//unsigned count = 0;

	//for (unsigned i = 2; i < num; ++i)
	//{
	//	if (num % i == 0)
	//		count++;
	//}
	//if (count == 0)
	//	isPrime = true;

	/* 홍정모 */

	//for (unsigned div = 2; div < num; ++div)  // c++에서는 iterator 안에서 counter를 선언하는 게 흔하다. 깔끔한 cstyle은 위에서 선언
	//{
	//	if (num % div == 0)
	//		isPrime = false;
	//}

	//if (isPrime)
	//	printf("%u is a prime number.\n", num);
	//else
	//	printf("%u is not a prime number.\n", num);

	for (unsigned div = 2; (div * div) <= num; ++div)
		//(div * div) <= num 이러면 계산을 더 줄일 수 있다. 생각해내기가 쉽지 않다. 초보 때는 경험이 더 중요
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