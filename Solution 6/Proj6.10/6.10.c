/* 다양한 대입 연산자들 그리고 어셈블리 코드 확인법 */
/* https://en.cppreference.com/w/c/language/operator_precedence */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	/*
		+=, -=, *=, /=, %=
	*/

	int i = 1024;

	i = i + 10; // line 14 15의 차이는 없다. 예전 책에서는 +=는 이 특정상황에서 빠르다는 얘기가 있었지만... 똑같다.
	i += 10;	// 'ctrl k' + 'g' go to disassembly로 비교해보자 debug -> windows -> dissassembly
	//	사소한 최적화에 신경쓰는 것보다 컴퓨터 성능이 좋아져서 알고리즘 공부를 하는 게 추세다.
	// assembly보기
	// 시간 보기
	/*
		0042177C  mov         eax,dword ptr [i]  
		0042177F  add         eax,0Ah  
		00421782  mov         dword ptr [i],eax 

		00421785  mov         eax,dword ptr [i]
		00421788  add         eax,0Ah
		0042178B  mov         dword ptr [i],eax
	*/

	i %= 4;

	i = i * (1 + 2);
	i *= 1 + 2;
	i *= (1 + 2);	// Check precedence 대부분 괄호는 치지 않는다.

	for (int i = 0; i < 10; i += 2)
		;

	return 0;
}