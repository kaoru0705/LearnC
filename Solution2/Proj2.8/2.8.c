/* Keywords(단어의 역할)& Reserved Identifiers(컴파일러가 내가 미리 쓸거니까 프로그래머들은 사용하지 마십쇼 미리 예약이 되어있는 예약어) */
// 예약어는 이름을 바꿀 수 있다.
/* https://en.cppreference.com/w/c/keyword */
/* 키워드 예약어는 변수 함수명으로 사용하지 마라. */
#include <stdio.h>
#include <stdbool.h>

int main() 
{
	//int printf = 1; keyword를 변수명으로 적지 마라. 
	//int _Bool; //이건 걍 말이 안되고 자료형을 두 번 쓰냐
	//int bool = 2; // cpppreference 참조 stdbool.h를 포함하는 순간 오류가 된다. 예약어는 헤더를 포함하는 순간 사용할 수 없음
	_Bool a = true;
	bool b = false;
	// if preprocessor if문과 #if? #if만 전처리기?
	printf("Hello World!"); //printf를 변수명으로 사용하면 여기서 오류가 난다.

	return 0;
}