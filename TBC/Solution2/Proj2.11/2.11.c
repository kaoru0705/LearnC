/* Syntax Errors Semantic[si maentic] Errors 문법오류와 문맥오류 */
#include <stdio.h>

int main() 
{
	int n1, n2, n3, n4;

	//n5 = 3; //compile 시 = 1>C:\Users\KDH\source\repos\Solution2\Proj2.11\2.11.c(7,5): error C2065: 'n5': undeclared identifier
	// 밑줄은 visual studio 개발환경에서 잡아주는 것
	// output message compiler가 뭐라 하는 것
	// 아무튼 문법오류는 잡기 쉬움.

	n1 = 1;
	n2 = n1 * n1;
	n3 = n2 * n1;
	n4 = n2 * n1; //문맥 오류를 어떻게 해결하나 1. 디버그로 해 보기
				  // 2.코딩을 할 때 compiler가 최대한 도와주는 방식으로 프로그래밍할 수 있음 ex) assault 단언하기 나중에 등장

	
	return 0;
}