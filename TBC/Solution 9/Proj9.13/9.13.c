/* 중요한 프로젝트는 책꽂이를 해라*/
/* Pointer의 기본적인 사용 방법 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    int a, b;
    a = 123;
    int *a_ptr; // asterisk or int *a_ptr; 타입의 뒤냐 변수명 앞이냐 코딩 스타일 변수명 앞이 더 많다

    a_ptr = &a; // &: address-of operator 

    printf("%d %d %p\n", a, *a_ptr, a_ptr); // printf로 주소를 출력할 때는 %p 사용 가능
    // 주소 값의 크기는 변수형의 크기와 상관이 없다. int = float = double = ... *a_ptr
    // 주소가 매번 바뀜 운영체제가 결정 운영체제가 어떻게 작동하는지 예측하는 건 매우 어려운 문제

    *a_ptr = 456; // * : re-direction or de-referencing

    printf("%d %d %p\n", a, *a_ptr, a_ptr); //a *a_ptr은  변수를 통해서 할거냐 주소를 통해서 할거냐
    // 프로그래머 입장에서만 약간 차이날뿐 내부적으로 같은일을 하는 것
    // 
    // b = a_ptr; //warning C4047: '=': 'int' differs in levels of indirection from 'int *'
    // *a_ptr의 실수가 아니냐 (int)a_ptr;이걸 적고 싶은 걸지도 모르니 경고만 해줌 
    // 실제로 쓸일 없다고 보는게 맞음 대부분 실수다.
    b = *a_ptr; // *a_ptr이란, 주소값이 향하는 주소의 값, 즉 a값
    printf("%d\n", b);
    *a_ptr = 789;
    printf("%d\n", b);
    printf("%d %d %p %p\n", a, *a_ptr, a_ptr, &b); //a와 b는 다른 변수다, 다른 object(메모리의 뭔가를 차지하고 있는 거)다.

	return 0;
}