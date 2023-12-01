/* 주석다는 법 */
#include <stdio.h>
/*
* written by J.-M. Hong// 최근에는 저작권 걸 때 많이 씀
*/
int main() 
{
	
	printf("Hello World!");//현대적인 방법 메모할 때 많이 씀 설명
	int x = 1, y = 2, sum;
	sum = x + y; // add two numbers <- 주석보단 sum instead of z
	// right click + rename click or ctrl r or ctrl r + ctrl r rename 주석 뭉텅이로 하기 ctrl kc ctrl ku

	/*int o;
	int u;
	int d;*/ //첫 탭을 비우고 드래그하면 블럭 주석이 됨
	//주의 들여쓰기 중간에 주석이 있으면 블럭주석이 안 된다.

	return 0;
}