/* 중요한 프로젝트는 책꽂이를 해라*/
/* Pointer Arithmetic 포인터의 산술 연산 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    //int* ptr = 0;// 엄밀히 따지면 (int*) 0; 그것보단 NULL로 초기화가 맞다. 포인터 연산 보여주려고 그런거다.
    ////try double*, long long*, char*, void*(void*는 자료형이 없다는 의미이기에 포인터 산술 연산 불가능 하드웨어 등등에 의외로 쓰임)

    ////printf("%d", *ptr);  // Error in this lecture

    //printf("%p %lld\n", ptr, (long long)ptr);

    //ptr++;  // try -=, ++, -- , - , +(포인터 변수에 1을 더하면 주소값이 1만큼 더해지는 게 아니라 포인터의 자료형 크기 만큼 더해진다)
    //ptr += 2;
    //ptr -= 2;
    //// 메모리가 어떤 값이다는 프로그래머에게 의미는 없다. 해킹할 때 빼고
    //printf("%p %lld\n", ptr, (long long)ptr);

    //ptr = -ptr;  // Not working(단항 연산자로서의 +,- 는 사용 불가) 주소의 값을 음수로 바꾼다는 게 의미가 없다. 막아둠
    //ptr = +ptr;  // Not working(단항 연산자로서의 +,- 는 사용 불가)

    /* Subtraction */
    double arr[10];
    double* ptr1 = &arr[3], * ptr2 = &arr[5];

    //ptr2 = ptr1 + ptr2;  // Not working(포인터 변수끼리 더하는 건 불가능. 별 의미를 가지지 않기에 철수의 주소와 영희의 주소를 더해보자)
    int i = ptr2 - ptr1;  // Working(포인터 변수끼리 빼는 건 가능. 두 주소의 차이를 알 수 있기에. 주어진 자료형의 크기 만큼 몇 칸 떨어져 있는지를 결과로 알려준다)
    // index 차이

    printf("%lld %lld %d\n", (long long)ptr1, (long long)ptr2, i);


	return 0;
}