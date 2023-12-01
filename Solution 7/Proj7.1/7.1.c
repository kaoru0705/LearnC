/* 중요한 프로젝트는 책꽂이를 해라*/
/* Branching Statement 분기문 if */ // branch 나뭇가지 갈라지다
/* https://docs.microsoft.com/en-us/cpp/c-language/c-sequence-points?view=msvc-170 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int number;
	printf("Input a positive integer : ");
	scanf("%d", &number);

	if (number % 2 == 0)	// 0이 아닌 수일 때 true, Sequence Points
		printf("Even\n");
	else
		printf("Odd\n");

	return 0;
}