/* 어떤 루프를 사용할까? */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	// 진입조건 vs 탈출조건
	// 어차피 셋 다 가능하다.
	// for while vs do while 진입조건이 대체로 더 낫다. 탈출조건은 조건이 잘 안 보인다.
	// 진입조건일 경우 for vs while 몇 번 입력할지 모르는 경우 while indefinite
	// for(int i = 0; i < 100; ++i)	while(scanf("%d", &num) == 1) <- main loop while indefinite
	//사람이 개입돼서 언제 끝낼지 모르는 계속 돌리는 상황 


	return 0;
}