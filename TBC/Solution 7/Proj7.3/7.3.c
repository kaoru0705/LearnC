/* 중요한 프로젝트는 책꽂이를 해라*/
/* ctype.h 문자 함수들 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h> // 문자함수 isalpha() and more
// 7.2에서 했던 짓들은 이미 라이브러리에 있다?
/*
	Reference link
	https://www.tutorialspoint.com/c_standard_library/ctype_h.htm
*/
// 프로그래머들이 다 외워서 쓰는 게 아니다. 구글링을 해서 보고 써라
int main()
{
	char ch;

	while ((ch = getchar()) != '\n')
	{
		//if (ch >= '0' && ch <= '9') // try 3
		//	ch = '*';
		if (isdigit(ch) != 0)	//  c++ 복잡한 알고리즘 쓰는 분들은 이걸 != 0을 꼬박꼬박 씀 c에선 생략 많이 함
			ch = '*';

		/*if (ch >= 'a' && ch <= 'z')
			ch -= 'a' - 'A';
		else if (ch >= 'A' && ch <= 'Z')
			ch += 'a' - 'A';*/

		if (islower(ch))	// 편안
			ch = toupper(ch);
		else if (isupper(ch))
			ch = tolower(ch);

		putchar(ch);
	}

	putchar(ch);

	return 0;
}