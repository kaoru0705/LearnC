/* for loop introduction mainly uses in loop */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	/* Indefinite loop vs.Counting loop */
	//while (1)	// 진입 조건은 검사하지만 그다음부터는 신경 안 쓴다. indefinite
	//{
	//	// do something
	//}

	/*
		Counting Loop
		1. Counter intialization
		2. Counter check
		3. Counter change
	*/

	// while을 틀리기 쉬운 이유는 indefinite이기 때문 
	//int i;

	//i = 1;

	//while (i <= 10)		//Note: <=
	//{
	//	printf("%d ", i);
	//	i++;
	//}

	// int i; for loop 안에서 선언 가능

	for (int i = 1; i <= 10; i++)	// 위에 세 가지를 한 번에 적는다. 실수가 적고 편하고 명확하고 유연하게 사용할 수 있다.
		printf("%d ", i);

	// printf("%d\n", i); //error

	return 0;
}