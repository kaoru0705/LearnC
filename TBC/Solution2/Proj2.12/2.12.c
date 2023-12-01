/* 읽기 좋은 코드를 만드는 유형 */
#include <stdio.h>
int main() 
{
	printf("Hello World!"); // 우리 회사에는 tab키를 쓰면 안된다. tab을 space 4번으로 바꿔주는 설정이 있다 tab indenting
	int x = 0, y = 1; // 띄어쓰기를 빼먹었을때 하나하나  space하지 않고 shift end ctrl x or 그냥 ctrl x ctrl v하면 알아서 정리된다.
	int z = x + y; // 기능별로 따로 둠
	// 내가 짠 코드도 일주일후엔 기억 못 한다. 코드 정리, 주석 잘 해라.
	// github고수들 코드스타일을 보고 참조해라.
	return 0;
}