/* 중요한 프로젝트는 책꽂이를 해라*/
/* Functions's proto-type */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>	// strlen()
#include <stdbool.h>
#define WIDTH 40
#define NAME "Jeong-Mo Hong"
#define ADDRESS "Seoul, Korea"
// 모든 함수가 내부에서 어떻게 작동하는지를 외울 필요가 없다.
// 인풋 아웃풋을 알고 모듈(부품)을 조합하는 형식으로 함 현대적 프로그래밍
// 내부가 블랙박스 허나 인풋 아웃풋만 알면 됨
void print_multiple_chars(char c, int n_stars, bool print_newline); // 이렇게만 해도 컴파일은 되고 링킹이 안된다.
/* ref 2.9 컴파일이 끝난후 링킹하는 과정에서 링커가 몸체를 연결해준다. 
1>------ Build started: Project: Proj9.2, Configuration: Debug Win32 ------
1>9.2.c
1>9.2.obj : error LNK2019: unresolved external symbol _print_multiple_chars referenced in function _main
*/	// 컴파일하는 단계에서는 프로토타입(입력과 출력만 가진 블랙박스로서의 함수)만 가지고 컴파일 함
	// 실행파일을 만드는 링킹단계에서 링커가 몸체를 찾아서 연결시켜 준다. 컴파일과 링킹이 분리되어 있다.
	// 이러한 내용은 객체지향 프로그래밍할 때 다형성을 이해하는 데 도움이 된다.
//{
//	for (int i = 0; i < n_stars; ++i)
//		printf("%c", c);
//
//	if (print_newline == true)
//		printf("\n");
//
//}
void print_centered_str(char str[]); // prototype으로 바꾸는 법
// 우클릭 quick actions and refactoriongs create declaration / definition 선언과 정의 따로 한다.
// change signature 서명 = 블랙박스로서의 함수 프로토타입, 입력이 뭐고 출력이 뭔지 함수의 특징을 표현한다고 해서 signature
// file을 여러 개로 만들어 생각을 더 단순하고 간결하게 할 수 있다.

//void print_centered_str(); // 옛날 프로그래밍에서는 이렇게 해도 됐었다.
//void print_centered_str(void); // 이렇게 적으면 실행은 되지만 warning () != (void)
//void print_centered_str(char[]);
//void print_multiple_chars(char, int, bool);
// 사실 프로토타입에는 변수명이 없어도 된다. 자료형만 있으면 됨 쓰질 않으니
// 블랙박스 관점으로 볼 때 어떤 자료형이 들어가고 나오는지만 알면 되기 때문
// 프로토타입에서 이 자료형이 어떠한 변수명으로 사용하는지는 알 필요 없다.
// 허나 변수명까지 맞춰서 명시하는 게 더 좋다. 혼란을 줄여줌 허나 생략하는 경우도 의외로 많이 씀
// 1 코드가 너무 길어질 경우 2 이름은 같은 함수가 매개변수만 다른 형태로 여러 개 존재할 경우
// 정신이 없어서 변수명을 생략하는 경우가 있다.


int main()	// program이 시작할 때 main함수로부터 시작
{
	print_multiple_chars('*', WIDTH, true); // actual parameter/argument(옛날 문헌) or argument

	print_centered_str(NAME);
	print_centered_str(ADDRESS);
	print_centered_str("I love you");
	
	print_multiple_chars('*', WIDTH, false);
	return 0;
}

void print_multiple_chars(char c, int n_stars, bool print_newline)
// formel(형식적) argument/parameter(옛날 문헌) or parameter(매개변수)
// 함수의 기능을 일반화 시킨다. = 매개변수화  매개변수의 값에 따라 달라지니 
// 매개변수에 뭐가 들어오는지를 프로토타입에 명시해주는 게 좋다. 꼭 해야 된다고 말 안 했다.
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