/* Entry-Condition Loop 진입조건 루프 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	/*
	while (expression)	컴퓨터 내부적으로는 조건이 0이면 false 아니면 true  
		statement
	*/

	int i;

	//i = 1;
	//while (i < 5)		// infinite loop
	//	printf("Hi!\n");// 변수 i의 유래 interation 반복하는 것 추측
	
	//i = 1;
	//while (--i < 5)		// wrong direction
	//	printf("Hi!\n");

	/*i = 1;
	while (i < 5)
	{
		printf("i before = %d\n", i);
		i++;
		printf("i after = %d\n", i);
	}*/

	//i = 10;
	//while (i++ < 5)		// cannot enter while(i++) 이런 거 의외로 많이 씀
	//{
	//	printf("Hi\n");
	//}

	/* Common mistakes */
	
	//i = 0;
	//while (i < 3)
	//	printf("%i\n", i);
	//	i++;// indenting = tab하는 걸 이렇게 부름

	//i = 0;
	//while (i++ < 3);	// null statement
	// printf("%i\n", i);

	while (scanf("%d", &i) == 1)
		;// null statement 
	// do something (?) 굳이 이렇게 암호문처럼 할 필요가 없다. 컴퓨터가 구릴 때나 쓰던 것 요즘엔 다르게 함
	// 지금은 읽기 편하고 의사가 명확한 코드를 중요 시 함
	printf("%d", i); // 문자 전값 출력 문자 입력은 걍 씹어먹음

	return 0;
}