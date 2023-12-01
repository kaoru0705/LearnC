/* 중요한 프로젝트는 책꽂이를 해라*/
/* 포인터와 배열 */ //동적할당의 도움 됨
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int arr[10];  // 배열명은 int형 10개, 즉 40바이트 크기의 공간을 대표하는 메모리 주소이다. 배열명은 포인터와 유사하다 실전에선 동적할당을 써서 포인터를 배열처럼 사용한다. 

    const int num = sizeof(arr) / sizeof(arr[0]);  // 배열 크기이므로 const 한정자 사용해서 안정성 높이기
    for (int i = 0; i < num; ++i) // i < 10보다 num을 써서 안정성을 올림
        arr[i] = (i + 1) * 100;

    int* ptr = arr;

    printf("%p %p %p\n", ptr, arr, &arr[0]); // 주소값 자체는 의미가 없고 차이를 보는 것은 의미가 있다.

    ptr += 2;

    printf("%p %p %p\n", ptr, arr + 2, &arr[2]);

    //Note: arr += 2;  // invalid(배열명은 포인터와 유사하기에 산술 연산을 이용할 수 있지만 값을 바꿀 수는 없다 이게 가능하면 배열의 이름을 잃어버린다)

    printf("%d %d %d\n", *(ptr + 1), *(arr + 3), arr[3]);  // 인덱싱과 포인터 산술 연산은 서로 대체 가능하다
    // &(arr + 3) compile error, '&' requires l-value 이건 사실상 의미 없지만 ㅇㅇ
    //Warning
    printf("%d %d %d\n", *ptr + 1, *arr + 3, arr[3]); //dereferencing한 다음에 1더함

    int* ptr2 = arr;
    //for(int i = 0, *ptr = arr; i < num ; ++i)  // 코드를 줄이는 것보다 실수를 줄이는 시대 이때 *ptr은 다른 영역
    for (int i = 0; i < num; ++i) {
        printf("%d %d\n", *ptr2++, arr[i]);  // 데이터 양이 아주 많은 고효율 컴퓨팅에서는 이처럼 배열 원소를 하나하나 짚으며 진행하는 코드를 병렬 처리, GPU 가속, SIMD 가속 등을 이용해서 하드웨어(CPU)의 성능을 최대한 이끌어내는 방식을 이용한다
        //ptr2++; 이렇게 해도 됨
        //printf("%d %d\n", *(ptr2 + i), arr[i]);  // *ptr2++ vs arr[i] 위 코드와 같은 의미(과거에는 후위 증가연산자가 더 빠르다는 의견이 있었지만 최근에는 성능 차이가 거의 없다) 이런 거에 최적화 신경 안 씀
        //printf("%d %d\n", *ptr2 + i, arr[i]);  // 괄호를 없애면 위와 결과가 달라진다
    }


	return 0;
}