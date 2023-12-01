/* 반복 루프와의 첫만남 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int n = 1;
/* 실제 내부 구조에서는 goto문처럼 돌아간다? */
//label:
//	printf("%d\n", n);
//	n = n + 1;
//
//	if (n == 10) goto out; // 평생 안 쓸 goto  동선이 꼬이고 읽기 힘듦 오류가 발생하기 쉽다.
//
//	goto label;
//
//out:
	while (n < 11)
	{
		printf("%d\n", n);
		n = n + 1; //변하는 조건을 반드시 명제 //n = n + 1 infinite loop
	}




	return 0;
}