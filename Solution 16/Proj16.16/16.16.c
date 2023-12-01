/* memcpy()와 memmove() 메모리의 내용을 옮기거나 카피하는 함수 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // memcpy(), memmove() // string이 아닌 일반적인 메모리 복사에도 사용한다 그냥 순수하게 메모리에 대해서만 작동 문자열 마지막 널까지 고려 안 함

#define LEN 6

void ptr(int* arr, int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{
    /*
    - overlapping region
    - pointer-to-void (datatype is unknown)
    */

    int arr1[LEN] = { 1, 3, 5, 7, 9, 11 };
    //int arr2[LEN] = {0, };
    int* arr2 = (int*)malloc(LEN * sizeof(int));
    if (arr2 == NULL) exit(1);

    //memcpy()를 사용하지 않는다면?
    //for (int i = 0; i < LEN; ++i)
    //    arr2[i] = arr1[i];

    memcpy(arr2, arr1, sizeof(int) * LEN); // destination, source가 void pointer이므로 사이즈를 알려줘야 함. 위보다 이걸 추천
    ptr(arr2, LEN);

    /*
     { 1, 3, 5, 7, 9, 11 }
     { 5, 7, 9, 11, 9, 11}
    */
    // memcpy(arr1, &arr1[2], sizeof(int) * 4);  // undefined behaviour(source와 destination 간에 겹치는 부분이 있으면 문제가 있을 수 있다.)
    memmove(arr1, &arr1[2], sizeof(int) * 4);    // 기능은 memcpy와 동일한데 내부적으로는 조금 다름
    //복사할 내용을 버퍼를 거쳐서 목적지로 전달하기에 겹치는 구간이 있어도 문제가 발생하지 않는다(실제적으로는 버퍼를 사용하지 않는다는 얘기가 있다. 단, 컴파일러마다 다를 수 있다 )
    ptr(arr1, LEN);

    return 0;
}