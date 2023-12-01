/* 다양한 정수형들 */
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() 
{
	//자료형은 최소 크기다. 컴파일러에 따라 다름
	//long은 많이 쓰이지 않음 옛 int 는 2byte 그때 long은 4byte long long은 많이 쓰임
	char c = 65;
	short s = 200;
	unsigned int ui = 3000000000U;//3'000'000'000U c++에서는 자릿수 넣는 게 표준
	// literal U 표현 literal 생략 가능 숫자뒤에 literal이 있으면 눈에 잘 안 띈다. 실수할 가능성이 높아 많이 생략하는 경우가 있다.
	long l = 65537L;
	long long ll = 12345678908542LL; // 12'345'678'908'642ll

	printf("char = %hhd, %d, %c\n", c, c, c);//%c는 문자 출력
	printf("short = %hhd, %hd, %d\n", s, s, s);//%hhd overflow
	printf("unsigned int = %u, %d\n", ui, ui);//%d overflow
	printf("long = %ld, %hd\n", l, l);
	printf("long long = %lld, %ld\n", ll, ll); // warning %ld, ll

	return 0;
}