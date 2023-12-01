/* Use functions's return_value in Loop */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int compute_pow(int base, int exp);	// scope는 block안에서만 사용 가능하다.
// prototype 보통 이렇게 쓴다. 위에가 너무길어지면 main함수 보기가 힘듦
// prototype은 main 함수 result = compute_pow(base, exp); 부분을 컴파일할 때 이런 함수가 있다.
// 요부분을 컴파일할 때 안에서 어떻게 계산하는지는 신경쓰지 마라. 분리해서 컴파일. linking 과정에서 몸체를 찾고 연결해줌
// GCC에서 알려줬다. visual studio code part ref  1.13
// 선언만 해준다. main함수에서는 선언만 되어있어도 호출할 수 있다. 컴파일이 끝난다음에 링킹하는 과정에서 연결해줌 ref 2.9 2.10
int main()
{
	// 3 4
	// 3*3*3*3 = 81
	// 거듭 제곱 = power
	int base, exp, result;

	while (scanf("%d %d", &base, &exp) == 2)
	{
		//result = 1;
		//for (i = 0; i < exp; ++i)	// for (int i = 0) for문 안에서 i선언 교수님은 c++에서 이렇게 하고 있다.
		//	result *= base;
		//// ... 
		//// ... 길어지면 길어질수록 복잡하다. 아직은 분량이 많지 않지만 함수로 빼보자
		// int j;
		result = compute_pow(base, exp); // 변수이름이 같은 경우는 굉장히 많다. scope를 생각해라.

		printf("Result = %d\n", result);
	}

	// j = 1; //compile error
	return 0;
}

int compute_pow(int base, int exp)	// scope는 block안에서만 사용 가능하다.
{
	int i, result;	// 단어 커서에 ctrl + f 를 하면 해당 단어만 찾는다. ctrl c ctrl f ctrl v해야되는 경우도 있음

	result = 1;
	for (i = 0; i < exp; ++i)
		result *= base;

	return result;
}