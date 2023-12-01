/* 표현식과 문장 Expressions Statements */
// expression = 연산자와 피연산자가 조합되어 있는 식, 값을 갖고 있다.
// q = 5 * 2 이 표현식의 기능은 오히려 값을 계산하는 것 컴파일러 내부에서는 그렇다.
// 대입은 side effect 꼭 부작용이란 뜻은 아니다. 좋은 뜻도 있음
// x = 4; 4라는 expression(숫자 자체가 값을 가지고 있으므로)과 4를 대입하는 sideeffect가 있다. assignment statement다. 
// statements, expression으로 만들어지는 문장 semicolon이 붙어 있는 형태
/* https://docs.microsoft.com/en-us/cpp/c-language/c-sequence-points?view=msvc-170 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	/* Statements */
	/*
	int x, y, apples;	// declaration statement
	apples = 3;			// assignment statement
	;					// null statement
	7;
	1 + 2;
	x = 4;
	x = 1 + (y = 5);	// y = 5 is subexpression 부분식
	while (x++ < 10);	// while statement (structed statements)
	printf("%d\n", y)	// function statement
	
	return 0; // return statement
	*/

	/* Side Effects and Sequence Points(값을 언제 계산하는 가? 마침표. 이 expression의 값을 계산해도 되는구나) */
	int x = 4;					// main intent is evaluating expressions 허나 직관적으로는 x에 4를 대입하는 것
	int y = 1 + x++;

	while (x++ < 10)			// (x++ < 10) is a full expression. 원래는 compiler가 세미콜론(sequence points)를 만나야 expression을 계산하는 건데
		printf("%d\n", x);		// while 문 같은 경우는 조건문 자체가 full expression이라 딱 계산을 마친다.

	printf("%d\n", x); // x = 11

	y = (4 + x++) + (6 + x++);	// Not (4 + x++) nor (6 + x++) is a full expression.
								// compiler는 괄호 끝나고 계산할지 세미콜론끝나고 계산할지가 모호하다.
								// 특정 컴파일러는 결과가 같으나 컴파일러에 따라 다를 수 있다.
								// 한 문장 안에 증가 연산자 증감 연산자를 두 세 번씩 쓰지 마라. 특히 함수의 파라미터에서 그러지 마라.
	printf("%d\n", y);
	return 0;
}