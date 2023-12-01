/* 간단한 입출력 프로그램 만들기 */
#include <stdio.h>

int main()
{
	//breakpoint를 안찍고도 f10으로 debug 가능 허나 보통 toggle
	//int i = 0, j = 0;

	//printf("Input two intergers\n");

	//scanf("%d%d", &i, &j);//%d%d %d %d 문법상 같게 적용 허나 다른 경우도 있다. 형식지정자의 개수가 같아야 한다.

	//printf("Your numbers are %d and %d\n", i, j); //%f float의 약자
	float won = 0.0f;
	float dollar = 0.0f;

	printf("Input Won\n");
	scanf("%f", &won);

	dollar = won * 0.00089f; //warning C4244: '=': conversion from 'double' to 'float', possible loss of data
	//warning도 지우는 게 낫다. 0.00089를 float형 literal로 바꿈
	// won & 0.00089는 type이 다름
	printf("Dollar = %f\n", dollar);

	return 0;
}