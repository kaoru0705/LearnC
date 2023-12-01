/* qsort 함수 포인터 연습문제 */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>
#include <stdlib.h>

//TODO: try increasing/decreasing order
int compare(const void* first, const void* second) // 규격이 정해져있음
{
	if (*(int*)first > *(int*)second) // 다루는 게 정수라 int casting함
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int main(void)
{
	int arr[] = { 8, 2, 5, 3, 6, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, n, sizeof(int), compare); // quick sort함수는 이미 stdlib에서 구현되어 있다. 왜 귀찮게 int 정렬 함수를 안 만들었나? 다른 자료형도 정렬하는 데 사용할 수 있다.
	// 함수를 넣어주면 qsort가 함수포인터를 사용해서 정렬을 함
	// float로 바꾸거나 내림차순으로 바꿀 수 있다.
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}