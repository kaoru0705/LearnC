/* 중요한 프로젝트는 책꽂이를 해라*/
/* 포인터에 대한 포인터 (2중 포인터)의 작동 원리 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//포인터를 배열로 사용할 수 있었고 이중 포인터는 어따 쓸까요? 배열의 배열
//int** pptr *pptr = pointer int*pointer = int
int main()
{
	int i = 10;
	int* ptr = &i;
	int** d_ptr = &ptr;
	int*** t_ptr = &d_ptr;

	printf("i    %8d %p\n", i, &i);       // i          10 00CFFAA0

	*ptr = 20;
	printf("i    %8d %p\n", i, &i);       // i          20 00CFFAA0
	printf("ptr  %p %p\n", ptr, &ptr);    // ptr  00CFFAA0 00CFFAB0

	**d_ptr = 30;
	printf("i    %8d %p\n", i, &i);       // i          30 00CFFAA0
	printf("dptr %p %p\n", d_ptr, &d_ptr);// dptr 00CFFAB0 00CFFAC0

	***t_ptr = 40;
	printf("i    %8d %p\n", i, &i);       // i          40 00CFFAA0
	printf("tptr %p %p\n", t_ptr, &t_ptr);// tptr 00CFFAC0 00CFFAD0

	return 0;
}