/* 함수의 저장 공간 분류 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Storage Classes and Functions
	- Functions external (by default) or static
	- A function declaration is assumed to be extern
*/

int g_int = 123;// defining declaration
//TODO: try static

void fun(); // (extern) void fun(); 함수는 뻔하기 때문에 생략되어 있다. main.c 안에 있는 다른 함수의 전방선언 어차피 몸체를 가리키고 있다.
void fun_second(); // 다른 파일에 있는 함수에 대한 전방 선언 얘도 다른 파일에 함수를 가리키고 있다

int main()
{
	fun();
	fun_second();

	return 0;
}

void fun()
{
	extern int g_int;// optional

	g_int += 1;
	printf("g_int is fun() %d %p\n", g_int, &g_int);
}