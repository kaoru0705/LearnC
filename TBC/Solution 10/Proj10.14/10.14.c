/* 중요한 프로젝트는 책꽂이를 해라*/
/* 2차원 배열과 포인터 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//사진 참조
// int arr[2][3] 메모리 순서로 읽는 게 중요하다.
// arr + 1 == &arr[1] == &arr[0] + 1 == &arr[1][0] != arr[1][0]
// arr == arr[0] == &arr[0] == &arr[0][0] != arr[0][0] 이것은 가리키는 주솟값이 동일하다는 것이지 자료형이 같다는 건 아니다. pdf를 봐라
// 이때 이중포인터관점에서 볼 때 arr[0]자체가 포인터와 같은 형태기 때문에 &를 붙이면 arr[0]를 저장하고 있는 주소 아닌가 생각할 수 있다.
// 하지만 &를 붙인다고 해서 주소가 어딘가에 저장되진 않는다. 컴파일러가 내부적으로 index를 보고 계산해줄 뿐
// 따라서 arr[0] == &arr[0] 배열에서는 같다. 포인터의 배열에서는 다를 수 있다. ref 10.12 d_ptr != &d_ptr
// &parr[0] != parr[0] but &arr[0] == arr[0]
//in 10.13 배열의 이름은 첫 번째 원소의 주소 즉, arr == &arr[0]
// arr[0](두 번째 인덱스가 붙은 배열의 이름이라 볼 수 있기 때문) == &arr[0][0]
// in 10.13c printf("%p\n", arr);  // 배열명 마치 첫 번째 원소의 주소인 것처럼(&arr[0]) 사용할 수 있다.
// 그러나 배열명은 주소를 저장할 수 있는 별도의 데이터 저장 공간을 가지고 있는 게 아니라 C 문법에서 arr[0]의 주소를 사용할 수 있게 해주는 것일 뿐이다. 포인터의 배열명도 마찬가지 l-value가 아님ㅇㅇ
// 이런 게 있을 리 없다. arr(&arr[0] 주소데이터) parr[0](arr[0]) parr(&parr[0])
int main()
{
	//float arr2d[2][4] = { {1.0f, 2.0f, 3.0f, 4.0f}, {5.0f, 6.0f, 7.0f, 8.0f} };

	//printf("%p %p %p %p %f\n", arr2d, arr2d[0], &arr2d[0], &arr2d[0][0], arr2d[0][0]);
	//printf("%u\n", (unsigned)arr2d);		//use unsigned long long in x64
	//printf("%u\n", (unsigned)arr2d[0]); // == &arr2d[0] arr2d[0]의 주소가 담겨있는 메모리 공간을 찾는 게 아니라 그냥 arr2d[0]의 주소다. 이중포인터랑 다르다. 
	//printf("\n");

	//// arr2d points to arr2d[0] (not arr2d[0][0] 이건 그냥 메모리 공간의 값), KNK Ch. 12.4
	////arr2d == &arr2d[0] 'points' to arr2d[0], *arr2d == arr2d[0]

	//printf("%u\n", (unsigned)* arr2d);
	//printf("%u\n", (unsigned)& arr2d[0]);	// C language allows this
	//printf("%u\n", (unsigned)& arr2d[0][0]);
	//printf("%f %f\n", arr2d[0][0], **arr2d);
	//printf("\n");

	//printf("%u\n", (unsigned)(arr2d + 1));		// 원소4개(16byte) 건너 뜀 10.15 원소가 4개인 배열의 포인터
	//printf("%u\n", (unsigned)(&arr2d[1]));		// arr2d + 1
	//printf("%u\n", (unsigned)(arr2d[1]));		// 
	//printf("%u\n", (unsigned)(*(arr2d + 1)));	// *(arr2d + 1) = *(&arr2d[1]) -> arr2d[1]
	//printf("%u\n", (unsigned)(&arr2d[0] + 1));	// arr2d + 1
	//printf("%u\n", (unsigned)(&arr2d[1][0]));	// arr2d[1]
	//printf("\n");

	//printf("%f\n", *(*(arr2d + 1) + 2));		// *(arr2d[1] + 2) = *(&arr2d[1][2]) -> arr2d[1][2]
	//printf("\n");

	//int n1 = sizeof arr2d / sizeof arr2d[0];
	//int n2 = sizeof arr2d[0] / sizeof(float);

	//for (int j = 0; j < 2; ++j)
	//{
	//	printf("[%d] = %u, %u\n", j, (unsigned)(arr2d[j]), (unsigned)*(arr2d + j));
	//	for (int i = 0; i < 4; ++i)
	//	{
	//		printf("[%d][%d] = %f, %f\n", j, i, arr2d[j][i], *(*(arr2d + j) + i));
	//		*(*(arr2d + j) + i) += 1.0f; //arr2d[j][i] += 1.0f
	//	}
	//}
	//printf("\n");


	/* Pointers to Multidimensional Arrays */

	float arr2d[2][4] = { {1.0f, 2.0f, 3.0f, 4.0f},{5.0f, 6.0f, 7.0f, 8.0f} };
	float(*pa)[4]; // a SINGLE pointer to an array of 4 floats, 4개의 float을 가진 배열을 가리키는 pointer 한 개
	//float* pa; 만약 이거였다면? 2차원은 불가능 1차원처럼 쓸 수 있다. 10.5.c처럼 10.15봐라 
	float* ap[2];	// an array of TWO pointers-to-float, 원소가 2개인 포인터의 배열 [] > *

	printf("%zu\n", sizeof(pa));	// 포인터가 한 개니까 4bytes, 8 in x64
	printf("%zu\n", sizeof(ap));	// 포인터의 배열 8bytes, 16 in x64
	printf("\n");

	pa = arr2d; // pa = &arr2d[0]도 안전하게 작동, arr2d도 4개의 float(arr2d[0])을 가리키는 포인터와 같은 형태다. 그렇기에 arr2d + 1이 다음행으로 넘어가는 것 arr2d[0]는 float(arr2d[0][0])을 가리키는 포인터와 같은 형태
	//pa[0] = arr2d[0];	// error 포인터가 하나라 배열처럼 쓸 수 없다. 이중포인터처럼 쓸 순 있다. 10.5c는 ptr[1] = 5;이 되잖아 그건 값이니까
	//pa[1] = arr2d[1];	// error

	//ap = arr2d;		// error not modifiable l-value 포인터의 배열은 이렇게 초기화 ap는 &ap[0] 지정된 포인터의 주소에서 뭘 넣노
	ap[0] = arr2d[0];
	ap[1] = arr2d[1];
	printf("%zu %zu\n", sizeof(&arr2d[0]), sizeof(&pa[0])); // &arr2d[0] &pa[0]는 pointer 사이즈 like ref 10.13 arr2d[0] pa[0]는 16byte
	printf("\n");
	printf("%u %u\n", (unsigned)pa, (unsigned)(pa + 1)); // ap ap+1과의 차이는?
	printf("%u %u\n", (unsigned)arr2d[0], (unsigned)arr2d[1]);
	printf("%u %u\n", (unsigned)pa[0], (unsigned)(pa[0] + 1));
	printf("%f\n", pa[0][0]);
	printf("%f\n", *pa[0]);
	printf("%f\n", **pa);
	printf("%f\n", pa[1][3]);
	printf("%f\n", *(*(pa + 1) + 3));
	printf("\n");

	printf("%u %u %u\n", (unsigned)ap, (unsigned)&ap[0], (unsigned)(ap + 1)); // 포인터의 배열 포인터를 담는 배열이 새로 생긴 것 포인터의 주소
	printf("%u %u\n", (unsigned)arr2d[0], (unsigned)arr2d[1]);
	printf("%u %u\n", (unsigned)ap[0], (unsigned)(ap[0] + 1));
	printf("%f\n", ap[0][0]);
	printf("%f\n", *ap[0]);
	printf("%f\n", **ap); // *(*(&ap[0])) -> *(ap[0]) = *(&ap[0][0]) -> ap[0][0]
	printf("%f\n", ap[1][3]);
	printf("%f\n", *(*(ap + 1) + 3));

	float ar[2][4];
	float(*pr)[4] = &ar[0]; // ar이 (float*)[4]라는 점에서 ar[0]는 float[4]일 수 있고 ar[0] = &ar[0][0]라는 점에서 float*이기도 하다
	return 0;
}