/* 중요한 프로젝트는 책꽂이를 해라*/
/* 포인터 연산 총정리 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    /*
     Pointer operations
     - Assignment
     - Value finding (dereferencing)
     - Taking a pointer address
     - Adding an integer to a pointer
     - Incrementing a pointer
     - Subtracting an integer from a pointer
     - Decrementing a pointer
     - Differencing
     - Comparisons
    */

    int arr[5] = { 100, 200, 300, 400, 500 };
    int* ptr1, * ptr2, * ptr3;

    ptr1 = arr;  // Assignment

    printf("%p, %d %p\n", ptr1, *ptr1, &ptr1);  // Dereferencing, Taking a pointer address

    ptr2 = &arr[2];  // Address-of operator &

    printf("%p, %d %p\n", ptr2, *ptr2, &ptr2);

    ptr3 = ptr1 + 4;  // Adding an integer from a pointer

    printf("%p, %d %p\n", ptr3, *ptr3, &ptr3);

    // Differencing
    printf("%td\n", ptr3 - ptr1);   //Note: t is for pointer difference

    ptr3 = ptr3 - 4;  // Subtracting an integer from a pointer

    printf("%p %d %p\n", ptr3, *ptr3, &ptr3);

    ptr1++;  // Incrementing, ptr1 = ptr1 + 1
    ptr1--;  // Decrementing
    --ptr1;
    ++ptr1;

    if (ptr1 == ptr3)
        printf("Same\n");
    else
        printf("Different\n");

    double d = 3.14;
    double* ptr_d = &d;

    //if(ptr1 == (int*)ptr_d)  // 서로 다른 포인터형을 비교하려는 경우 명시적으로 의도를 표현하기. 포인터도 결국 변수다
    // 실무에서 이렇게까지 사용하진 않는다. c++ 다형성에서 부득이하게 사용
    //if((void*)ptr1 == (void*)ptr_d)  // 양쪽을 void형 포인터로 캐스팅하는 방법
    if (ptr1 == ptr_d)  // warning(C4133, incompatible types):
        // 사실 둘 다 메모리사이즈도 같고 주소를 가리키기에 비교는 가능하지만 보통 실수로 이렇게 사용하는 경우가 많기에 경고 발생
        printf("Same\n");
    else
        printf("Different\n");

	return 0;
}