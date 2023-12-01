/* Nested Loops ��ø�� ������ ���� �� ���� ���� ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_ROWS	11	// In C const���� define�� ����
#define FIRST_CHAR	'A'
#define LAST_CHAR	'K'

int main()
{
	/* My poor answer */

	/*const int repeat = 6;
	const char favor_alphabet = 'K';	// first char last char�� �� ��Ȯ�ϴ�. �̰� �Z����
	for (int i = 0; i < repeat; i++)
	{
		for (char c = 'A'; c <= favor_alphabet; c++)	// ù ���ĺ��� �������ݾ�!
		{
			printf("%c ", c);
		}
		printf("\n");
	}*/

	int r; // row loop
	int c; // character loop
	// for loop �� ���� ���� ��ø ��ų �� �ִ�. ���� ���� ���� ���߷����� ���� ���� 2�߸� ���� ����
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
	for (int hi = 0; hi < 1; hi++) // ���� �����ڵ� �����ϰ� ���ǹ� ����
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