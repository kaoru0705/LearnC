/* 함수의 인수와 매개변수.Arguments vs.Parameters */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void draw(int n); // ANSI function prototype declaration

int main()
{
	int i = 5;
	char c = '#'; // 35
	float f = 7.1f;

	draw(i);	// 값이 들어가는 것이므로 values 즉 arguments
	draw((int)c);	// draw(c)는 promotion이지만 엄밀히 이렇게 한다.
	draw((int)f);	// instead of draw(f); warning C4244 : 'function' : conversion from 'float' to 'int', possible loss of data

	/* Arguments(인자, 인수) vs. Parameters(매개변수) */
	// actual argument, actual parameter -> argument (values)
	// formal argument, formal parameter -> parameter (variables)

	return 0;
}

void draw(int n) // int n variables니 파라미터 function draw가 매개변수화 되어있다.
{
	/* My answers */
	//int i = 0;
	//while (i < n)
	//{
	//	printf("*"); // asterisks
	//	i++;
	//}
	while (n-- > 0)
		printf("*");
	printf("\n");
}