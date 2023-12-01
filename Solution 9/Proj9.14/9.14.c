/* 중요한 프로젝트는 책꽂이를 해라*/
/* 포인터와 코딩 스타일 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	// int *a_ptr vs int* a_ptr
	// int *my_ptr, sec_ptr;
	int* a, b; // 포인터가 개념상으로는 int형 변수의 주소를 저장하는 것이므로 이렇게 생각할 수 있다.
	// 마치 int형 포인터 자료형이 있는 것처럼
	// 이렇게 하면 b가 그냥 int라는 게 초보자는 헷갈려서 교과서에서는 int *a, b; 이렇게 많이 쓴다.
	// visual studio 자동formatting으로는 int* a, * b; 이렇게 된다.
	// 자료형 뒤에 붙일지 변수형 앞에 붙일지는 회사에 따라 다름
	//int* a;
	//int* b; //c++에서는 일반적으로 이렇게 쪼개라 한다.
	// tools - options - c/c++ formatting - general - default formatting style
	// LIVM int *a; 뒤로 붙음 tab이 두 칸으로 줄어듦
	// Google int * b; 이것만 안 되고 다 됨


	return 0;
}