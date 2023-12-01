/* 함수 만들기 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void say_hello(void); // prototyping, function declaration
//선언만 해도 알아서 호출할 때 컴파일이 넘어갔다가 링킹할 때 합침

int main() // os가 프로그램을 실행시킬 땐 무조건 main부터 실행
{
	say_hello();	// main함수에서는 선언만 되어있어도 호출할 수 있다.
	// 컴파일이 끝난 후에 링킹하는 과정에서 몸체를 찾아다가 여기서 쓸 수 있게 연결해준다.
	say_hello();


	return 0;
}

void say_hello(void)	// function definition 몸체
{
	printf("Hellow Wolrd!\n");

	//return; // output void 일 경우 return 생략 가능
}