/* 구조체 안의 비트필드 Bit-Fields */
/*
	field는 과학 공학분야에서 원래 많이 쓰는 용어 중력 '장' 자기 '장' 벡터 필드 스칼라 필드
	비트필드 bit가 나열되어 있는 형태, 필드
	15.7처럼 비트 단위 연산자를 쓰는 것보단 역시 변수를 사용하는 것이 깔끔하지 않을까? c언어에서 허용해줌

	struct
	{
		bool has_sword		: 1; 사용할 bit의 개수 꼭 1개가 아니어도 됨
		bool has_shied		: 1;
		...

	} items_flag; items_flag가 차지하는 메모리 크기는 8비트

	items_flag.has_sword = 1; // flags = flags | MASK_SWORD; 왼쪽이 편해보이지만 둘 다 혼용해서 사용하는 것이 일반적
*/
#define _CRT_SECURE_NO_WANRINGS

#include <stdio.h>

int main(void)
{

	return 0;
}