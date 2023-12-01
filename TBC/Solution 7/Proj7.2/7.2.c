/* 중요한 프로젝트는 책꽂이를 해라*/
/* 표준 입출력 함수들  getchar(), putchar() */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	// getchar(), putchar()

int main()
{
	/* 
		1. Intrduce getchar(), putchar()
		2. Use while loop to process character sequences
		3. Filter a specific character
		4. Convert numbers to asterisks
		5. Lower characters to Upper characters
	*/

	char ch; // int ch도 마찬가지 문자 출력, int ch; scanf("%c", &ch); printf("%c", ch);도 마찬가지

	ch = getchar();		// 한 글자를 가져온다. abcdef\n치면 ch = 'a'가 되고 나머지는 buffer에 쌓임
	putchar(ch);		// 한 글자를 출력한다.

	while (ch != '\n') // Use '\n' to find the end of a sentence
	while ((ch = getchar()) != '\n') // =은 연산자 우선순위 거의 꼴지라 소괄호를 침
	{
		putchar(ch);	// 한 글자씩 입력을 안 받네? buffer

	}


	while ((ch = getchar()) != '\n')
	{
		/* try 3 */
		if (ch >= '0' && ch <= '9')
			ch = '*';
		/* try 2 */
		//for (int i = '0'; i <= '9'; ++i) // 내부적으로 계속 반복을 하므로 보통 프로그래머들은 try 3을 쓴다.
		//	if (ch == i)
		//		ch = '*';

		/* try 1 */
		/*if (ch == '0')
			ch = '*';*/

		/*if (ch == 'f')
			ch = 'X';*/
		/*else if (ch == 'F') 실전에선 이렇게 안 한다. 논리연산자 씀
			ch = 'X';*/
		/*if (ch == 'f' || ch == 'F')
			ch = 'X';*/


		/* my poor answer */
		/*if (ch >= 'a' && ch <= 'z')
			ch -= 32;*/
		if (ch >= 'a' && ch <= 'z')
			ch -= 'a' - 'A';
		else if (ch >= 'A' && ch <= 'Z')
			ch += 'a' - 'A';
		putchar(ch);
	}

	putchar(ch); // ch = '\n'

	return 0;
}