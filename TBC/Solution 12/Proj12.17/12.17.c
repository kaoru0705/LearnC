/* 동적 할당 메모리와 저장 공간 분류 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int g = 123;

void func()
{
	int i = 123;
	printf("Local variable		\t%lld\n", (long long)&i);
}

int main()
{
	// visual studio c로 보려니까 경향성은 비슷한데 약간 다르게 나온다. GCC가 깔끔하다 역시
	const char* message = "Banana";

	void (*f_ptr)() = func; // address of a funciton 함수 포인터를 선언할 때는 함수 포인터와 저장될 함수의 반환값 자료형, 매개변수 자료형과 개수가 일치해야 합니다.

	printf("Local pointer		\t%lld\n", (long long)&message); // stack
	printf("Function pointer	\t%lld\n", (long long)&f_ptr); // stack
	printf("String data		\t%lld\n", (long long)message); // rodata text segment
	printf("Function address	\t%lld\n", (long long)f_ptr); // 함수자체는 프로그램 text segment
	printf("Function address	\t%lld\n", (long long)main); 
	printf("Global variable		\t%lld\n", (long long)&g); // data segment

	func();

	int* ptr = (int*)malloc(100 * sizeof(int));
	if (!ptr) exit(EXIT_FAILURE);

	printf("Allocated memory	\t%lld\n", (long long)ptr); // heap segment 동적할당 메모리는 heap의 특성상 다른 저장공간과는 달리 영역이란 게 자동으로 관리해주는 게 아니고 수동으로 관리해줘야 한다
	

	free(ptr);
	return 0;
}