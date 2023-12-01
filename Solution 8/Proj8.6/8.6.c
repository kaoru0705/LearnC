/* 중요한 프로젝트는 책꽂이를 해라 */
/* 입력 확인하기 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long get_long(void);

int main()
{
	long number;
	while (1)
	{
		printf("Please input a integer between 1 and 100.\n"); // between은 1 100 포함 안 함

		number = get_long();

		if (number > 1 && number < 100)
		{
			printf("Ok, Thank you.\n");
			break;
		}
		else
			printf("Wrong input. Please try again.\n");
	}

	printf("Your input %d is between 1 and 100. Thank you.\n", number);

	return 0;
}

long get_long(void)		// 사실 이것도 더럽다 file로 나눠서 깔끔하게 넣을 수 있다.
{
	printf("Please input an integer and press enter.\n");

	long input;
	char c;

	while (scanf("%ld", &input) != 1)
	{
		printf("Your input - ");

		while ((c = getchar()) != '\n') // 제대로 입력받지 않았다면 사용자의 입력이 버퍼에 계속 남아있다.
			putchar(c); // input left in buffer
		// 프로그래머는 ㅈ중복을 없애야 된다. 함수를 써라 long type을 매번 이렇게 copy and paste로 입력받으면 ㅈ된다
		// 함수를 쓰자
		printf(" - is not an integer. Please try again.\n");
	}

	printf("Your input %ld is an integer. Thank you.\n", input);

	return input;
}