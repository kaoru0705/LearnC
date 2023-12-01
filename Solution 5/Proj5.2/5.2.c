/* 대입 연산자와 몇 가지 용어들 Object, L - value, R - value, 피연산자(operand) */
// 어떤 데이터가 메모리에 존재하고 있다면 data object 
// L-value (object locator value) 메모리 주소를 나타내는 변수명 메모리를 차지하고 있는 특정 데이터 객체(개체)
// R-value (value of an expression) 수정 가능한 L-value에게 대입될 수는 있지만 자기 자신은 L-value가 될 수 없는 것들 계산이 끝나면 사라짐
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	// L-value냐 R-value냐는 data object냐 메모리에 자기 자리가 있냐
	/*const int TWO = 2; // 수정 불가능한 L-value  여기서 변수를 선언할 때 =은 대입이 아니라 초기화

	int a; // 수정 가능한 L-value
	int b;
	int c;

	a = 42; // 42는 일시적으로 생겨난 literal constant data object가 아님
	b = a; // (L-value는 임시적으로 R-value의 역할을 할 수 있다.)
	c = TWO * (a + b);*/ //(a+b)는 R-value(프로그램이 계산하는 임시 값, 끝나면 사라짐) register에 임시로 있는 거다. ㅇㅇ


	return 0;
}