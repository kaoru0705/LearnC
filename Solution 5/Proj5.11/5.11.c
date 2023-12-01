/* Type Conversions(자료형 변환) */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	/* promotions in assignments */ // 작은 것을 큰 거에 넣을 때 promotions
	short s = 64;
	int i = s;

	float f = 3.14f;
	double d = f;

	/* demotion in assignments */
	d = 1.25;
	f = 1.25;	// 아니 16번줄은 왜 워닝이 안 떠? 0.25는 double이든 float든 완벽하니까
	f = 1.123;	//warning truncation from 'double' to 'float'

	/* ranking of types in operations */
	// long double > double > float 낮을 수록 랭킹이 낮다.
	// unsigned long long, long long // 같은 줄은 랭킹이 같음
	// unsigned long, long
	// unsigned, int
	// short int, unsigned short int
	// signed char, char, unsigned char
	// _Bool
	//Ref: Google 'Integer conversion rank'
	d = f + 1.234;
	f = f + 1.234;	// '=': conversion from 'double' to 'float', possible loss of data
	// 수치적으로 정밀한 프로그램일 경우 의미가 있다.

	/* automatic promotion of function arguments */ // 추후에 설명 대부분은 위에 언급한 것처럼 되는데 그렇지 않은 두 가지 경우
	// 1. Functions without prototypes 프로토타입이 없는 함수에 들어갈 경우 C99 잘 안 쓰임
	// 2. Variadic functions (ex) ellipsis) 인자 인수가 변할 수 있는 경우 고급프로그래밍 할 때 알아만 두자. c++에서도 나옴

	/* casting operators */ // 보다 바람직하다. 컴파일러에게 의도를 보여주기 때문
	d = (double)3.14f;
	i = 1.6 + 1.7;	// 3
	i = (int) 1.6 + (int)1.7;	// 절삭 result 2
	
	/* more examples */
	char c;
	//int i;
	//float f;
	f = i = c = 'A'; // 65 char도 내부적으로는 정수 계산
	printf("%c %d %f\n", c, i, f);
	c = c + 2; // 'C', 67
	i = f + 2 * c; // 65.0f + 2 * 67
	printf("%c %d %f\n", c, i, f); // 199
	c = 1106; // demolition, 1106 = 0b10001010010, 0b01010010 앞부분이 짤림 = 1106 % 256 = 82 = 'R'
	printf("%c\n", c);
	c = 83.99;
	printf("%c\n", c);

	i = 300;
	f = 21.75324f;
	printf("%hhd %f", i, f); // demolition 복사인듯? 스택 밀리는 일 없음 overflow? // 정확하진 않음

	return 0;
}