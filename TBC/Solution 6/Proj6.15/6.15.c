/* Nested Loops 중첩된 루프들 둥지 안 둥지 같은 느낌 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_ROWS	11	// In C const보다 define이 정석
#define FIRST_CHAR	'A'
#define LAST_CHAR	'K'

int main()
{
	/* My poor answer */

	/*const int repeat = 6;
	const char favor_alphabet = 'K';	// first char last char가 더 명확하다. 이건 줫구림
	for (int i = 0; i < repeat; i++)
	{
		for (char c = 'A'; c <= favor_alphabet; c++)	// 첫 알파벳이 고정이잖아!
		{
			printf("%c ", c);
		}
		printf("\n");
	}*/

	int r; // row loop
	int c; // character loop
	// for loop 는 여러 개를 중첩 시킬 수 있다. 삼중 사중 오중 다중루프도 많이 쓰니 2중만 생각 ㄴㄴ
	for (r = 0; r < NUM_ROWS; ++r)	// outer row loop
	{
		for (c = FIRST_CHAR; c <= LAST_CHAR; ++c)	// inner character loop
			printf("%c ", c);
		printf("\n");
	}

	/* My poor answer */

	//for (c = FIRST_CHAR; c <= LAST_CHAR; ++c)
	//{
	//	for (int i = FIRST_CHAR; i <= c; ++i)
	//		printf("%c ", i);
	//	printf("\n");
	//}

	for (r = 0; r < NUM_ROWS; ++r)	// outer row loop
	{
		for (c = FIRST_CHAR; c <= FIRST_CHAR + r; ++c)	// inner character loop
			printf("%c ", c);
		printf("\n");
	}
	for (int hi = 0; hi < 1; hi++) // 후위 연산자도 증가하고 조건문 비교함
		printf("yo\n");

	/* My answer */
	//for (r = 0; r < NUM_ROWS; ++r)	// outer row loop
	//{
	//	for (c = FIRST_CHAR + r; c <= LAST_CHAR; ++c)	// inner character loop
	//		printf("%c ", c);
	//	printf("\n");
	//}

	for (r = 0; r < NUM_ROWS; ++r)	// outer row loop
	{
		for (c = FIRST_CHAR + r; c < FIRST_CHAR + NUM_ROWS; ++c)	// inner character loop
			printf("%c ", c);
		printf("\n");
	}

	return 0;
}