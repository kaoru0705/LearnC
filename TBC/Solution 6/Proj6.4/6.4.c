/* Relational Operators 관계 연산자 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <math.h>	//fabs()
int main()
{
	/*
		Relational Operators
		<		is less than
		<=		is less than or equal to
		==		is equal to
		>=		is greater than or equal to
		>		is greater than
		!=		is not equal to		!는 다른 기호로도 쓰인다.
	*/

	//int n = 0;
	//while (n++ < 5)		// n++ < 5 is a relational expression
	//	printf("%d ", n);

	//printf("\n");

	//char c = 'A';
	//while (c != 'Z')
	//	printf("%c ", c++);

	const double PI = 3.1415926535897932384626433832795;
	double guess = 0.0;

	printf("Input PI : ");
	scanf("%lf", &guess);;
	//while (guess != PI)
	while (fabs(guess - PI) > 0.001)		//fabs 절댓값 adsolute double 적당한 차이일 때 맞다고 해주니 딱 좋다.
	{
		printf("Fool! Try again.\n");
		scanf("%lf", &guess);
	}

	printf("Good!");

	return 0;
}