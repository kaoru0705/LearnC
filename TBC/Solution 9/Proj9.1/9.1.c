/* 중요한 프로젝트는 책꽂이를 해라*/
/* 함수가 필요할 때 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>	// strlen()
#include <stdbool.h>

// 프로그래밍을 할 때 지켜야 할 두 가지
// 일반화라는 관점에서 더 많은 경우에 대해 쉽게 작동할 수 있도록 하기
// 같은 기능이 여러 번 나오면 안 됨 - 유지보수가 어려워짐
// 함수의 이름을 잘 지어라
/* My poor answers */
//void staroutput(int starcount)
//void yourinfo(char name[], char location[]);
#define WIDTH 40
#define NAME "Jeong-Mo Hong"
#define ADDRESS "Seoul, Korea"
/* try 2 */
//void print_bar(int n_stars) // 얼마든지 별을 입력할 수 있다.
//{
//	for (int i = 0; i < n_stars; ++i)
//		printf("*");
//	printf("\n");
//}
//
//void print_blank(int n_blank) // 얼마든지 별을 입력할 수 있다.
//{
//	for (int i = 0; i < n_blank; ++i) // ctrl + R ctrl + R
//		printf(" ");
//}
/* try 4*/
//void print_multiple_chars(char c, int n_stars) // 함수 하나로 합침
//{
//	for (int i = 0; i < n_stars; ++i)
//		printf("%c", c);
//
//}
void print_multiple_chars(char c, int n_stars, bool print_newline) // 함수 하나로 합침
{
	for (int i = 0; i < n_stars; ++i)
		printf("%c", c);

	if (print_newline == true)
		printf("\n");

}

void print_centered_str(char str[])
{
	int n_blanks = 0;
	n_blanks = (WIDTH - strlen(str)) / 2;
	print_multiple_chars(' ', n_blanks, false); // debug error 나면 클릭해서 그 라인으로 갈 수 있다.
	printf("%s\n", str);
}
int main()
{
	/* try 1 */
	//printf("*********************\n");
	//printf("	Jeong-Mo Hong	\n);
	//printf("	Seoul, Korea	\n");
	//printf("*********************\n");	// 기능이 겹친다.
	
	/* try 2 */
	//print_bar(WIDTH); // 단점 print_bar()에 input 값을 꼭 입력해야 한다. c++에서는 기본값이란 걸 넣을 수 있게 된다.
	//print_blank(10);
	//printf("   %s\n", NAME);
	//printf("   %s\n", ADDRESS);
	//print_bar(WIDTH);

	/* try 4 공백이 불편함 stdbool 활용 */
	/*print_multiple_chars('*', WIDTH);
	printf("\n");

	print_centered_str(NAME);
	print_centered_str(ADDRESS);
	print_centered_str("I love you");

	print_multiple_chars('*', WIDTH);
	printf("\n");*/
	
	print_multiple_chars('*', WIDTH, true);

	print_centered_str(NAME);
	print_centered_str(ADDRESS);
	print_centered_str("I love you");

	print_multiple_chars('*', WIDTH, false);

	/* try 3 또 기능 중복 */
	/*int n_blanks = 0;
	n_blanks = (WIDTH - strlen(NAME)) / 2;
	print_multiple_chars(' ', n_blanks);
	printf("%s\n", NAME);

	n_blanks = (WIDTH - strlen(ADDRESS)) / 2;
	print_multiple_chars(' ', n_blanks);
	printf("%s\n", ADDRESS);*/

	// 함수를 사용하지 않는 코드를 사용하는 구조로 바꾸고 있다. REFACTORING

	return 0;
}