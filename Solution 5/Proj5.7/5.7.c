/* Modullus Operator 나머지 연산자 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	//int seconds = 0, hours = 0, minutes = 0;

	//// My answer

	///*hours = seconds / 3600;
	//seconds %= 3600;

	//minutes = seconds / 60;
	//seconds %= 60;*/

	//// -1이면 출력 안 하고 바로 종료하고 싶어! while문이면 두 번 적어야됨
	//printf("Input seconds : ");
	//scanf("%d", &seconds);

	//while (seconds >= 0)
	//{

	//	minutes = seconds / 60; // Professor's answers
	//	seconds %= 60;

	//	hours = minutes / 60;
	//	minutes %= 60;

	//	printf("%d hours, %d minutes, %d seconds\n", hours, minutes, seconds);

	//	printf("Input seconds : ");
	//	scanf("%d", &seconds);
	//}

	//printf("Good bye\n");

	// 음수를 나눌 경우 어떻게 되는가?!
	// 앞에 피연산자가 음수면 나머지도 음수다.
	int div, mod;

	div = 11 / 5;
	mod = 11 % 5;
	printf("div = %d, mod = %d\n", div, mod);

	div = 11 / -5;
	mod = 11 % -5;
	printf("div = %d, mod = %d\n", div, mod);

	div = -11 / -5;
	mod = -11 % -5; // first operand is negative
	printf("div = %d, mod = %d\n", div, mod);

	div = -11 / 5;
	mod = -11 % 5; // first operand is negative
	printf("div = %d, mod = %d\n", div, mod);

	return 0;
}