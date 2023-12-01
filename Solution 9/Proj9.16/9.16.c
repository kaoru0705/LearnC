/* 중요한 프로젝트는 책꽂이를 해라*/
/* 디버거로 메모리 들여다보기 비주얼 스튜디오 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// 전체 메모리 상황을 보는 법 in Debuging mode Debug-Windows-Memory-memory1234
// b_ptr의 값을 복사해서 찾으면 빠르게 찾을 수 있다.
// 0x008FFD64  09 00 00 00  .... column 4
int main()
{
	int a = 3, b = 5, c = 7, d = 9;

	int* a_ptr = &a, * b_ptr = &b, * c_ptr = &c, * d_ptr = &d;

	printf("%p %p %p %p", &a, &b, &c, &d);
	

	return 0;
}