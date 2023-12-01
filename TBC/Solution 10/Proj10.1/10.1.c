/* 중요한 프로젝트는 책꽂이를 해라*/
/* Array & Memory */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// array 비슷한 것이 쭉 나열돼 있는 것
// array는 연속된 메모리 공간을 할당받음
/*
배열의 인덱스는 (해당 값의 주소 - 첫 값의 주소) / sizeof(자료형)과 같다
[0] [1] [2] [3] 안에 0 1 2 3은 첫번째 주소로부터의 거리 를 의미한다.
C언어 동작원리로서 배열의 각 주소를 첫번째 주소만큼 빼준 후 sizeof(자료형)으로 나눠준 값이 해당 data의 index이다.
*/
int main()
{
	/* Monthly temeperatures */
	int high[12] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 }; // []bracket square bracket {}brace
	int low[12] = { -7, -5, 1, 7, 13, 18, 22, 22, 16, 9, 2, -5 };
	// array가 4000개 40000개 받는 경우도 많음 array = pointer
	// index = subscript = offset
	// &arr[1] 1이 들어오면  운영체제로부터 할당받은 첫번째 주소부터 자료형의 사이즈만큼 간다. 내부적으로는 2나 3이면 한번에 휙 간다.
	// &arr[0] = &(arr[0])
	// int arr[4] 4byte이므로 [0] [1] [2] 4byte 건너뛴 주소
	const int a = 5;

	return 0;
}