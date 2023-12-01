/* Type Qualifiers 자료형 한정자들 const, volatile, restrict */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // memcpy
#include "constants.h"

// 자주 사용하는 상수를 헤더파일에 모아놓고 다른 파일에서 사용할 때 그 헤더를 선언하는 방식으로 편리하게 사용 가능. ex) #include "constants.h"
// 헤더 파일(constants.h) 안에서 선언할 때는 static을 붙인다(static이 없으면 여러 곳에서 include 할 때 문제가 생길 수 있다 include할 때마다 전역변수를 계속 생성하는 거라 그런 듯)
//const double gravity = 9.8; // 이렇게 하면 다른 프로그램을 만들 때 번거로워진다. 또 이걸 쳐줘야 하니 그래서 재활용할 수 있도록 헤더파일을 만든다.
//const double PI = 3.141592;

int main(void)
{
    double area_circle = PI * 2.0f * 2.0f;

    /*
        Qualified types
        const, volatile, restrict, _Atomic in gcc
    */

    /*
        const 가장 사용됨
    */

    // C99 idempotent(한정자를 여러 번 중복해서 사용하는 게 가능하다)
    const const const int n = 6;  // const int n = 6;

    typedef const int zip;  // 기존에 const가 붙은 자료형을 사용자가 임의의 자료형으로 지정한 후 const를 다시 붙여도 문제가 생기지 않는다
    const zip q = 8;  // const const int zip 이때 컴파일이 안되는 문제를 방지하기 위해서 여러 번 사용해도 가능

    //const int i;  // Not initialized!(const 키워드를 사용한 변수는 값을 바꿀 수 없기 때문에 반드시 선언과 동시에 초기화해야 한다)
    //i = 12;  // Error
    //printf("%d\n", i);  // Error

    const int j = 123;
    const int arr[] = { 1, 2, 3 };

    float f1 = 3.14F, f2 = 1.2F;

    const float* pf1 = &f1;
    //*pf1 = 5.0F;  // Error
    pf1 = &f2;  // Allowed

    float* const pf2 = &f1;

    *pf2 = 6.0F;  // Allowed
    //pf2 = &f2;  // Error

    const float* const pf3 = &f1;
    //*pf3 = 7.0F;  // Error
    //pf3 = &pf2;  // Error

    /*
        Global constants: 최상단부 참고
    */

    /*
        Volatile 휘발성
        - Do not optimize(ex. hardware clock 임베디드) 최적화를 할 때 빠진다.
    */

    volatile int vi = 1;  // volatile location
    volatile int* pvi = &vi;  // points to a volatile location

    int i1 = vi;

    // ...(컴파일러가 알 수 없는 방법으로 변수 vi의 값이 바뀔 수도 있다. ex) 운영체제가 강제로 변수의 값을 바꿈 포인터를 이용한 접근, 다른 모듈에서의 접근)

    int i2 = vi;  // 컴파일러는 기본적으로 메모리로부터 vi의 값을 받아와야 하지만 위에서 사용된 vi와 지금 시점의 vi의 값이 같을거라는 가정 하에(컴파일러 입장에서 // ... 여기에 vi변수를 바꾸는 코드가 없으면 값이 안 바뀌겠지하고) vi를 임시 저장공간에서 잠깐 저장해서 vi 값을 받아오는 방식으로 최적화를 진행하기도 한다. volatile 키워드는 이러한 최적화를 하지 않도록(= 캐싱(임시 저장공간에서 잠깐 저장해서 속도를 빠르게 하는 것)을 하지 않도록) 설정한다

    /*
        restrict (__restrict in VS)
        - sole initial means of accessing a data object(포인터를 비롯한 다른 간접적인 수단으로 해당 데이터에 접근할 수 없도록 만든다) 데이터 오브젝트에 접근하는 게 이거 하나 뿐이다. 라는 의미
        - compiler can't check this restriction(restrict 키워드를 붙였다고 해서 컴파일러가 간접적인 수단(ex 동적할당받은 메모리에 대해서 포인터가 정말 restar밖에 없는지)을 체크해주지는 않는다)
        프로그래머가 스스로 restrict가 붙었으니 다른 포인터를 통해 접근하지 말자고 지켜야 됨
    */

    int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int* par = ar;

    int* __restrict restar = (int*)malloc(10 * sizeof(int)); //동적할당 받아온 메모리를 다른 포인터나 다른 수단으로 접근하지 않겠다 restar를 통해서만 접근하겠다.
    if (!restar) exit(1);

    ar[0] += 3;  // 배열을 통해서 값을 바꾸는 방법
    par[0] += 5;  // 포인터를 통해서 값을 바꾸는 방법
    // == par[0] += 8; par이 ar을 가리키고 있기에 위에 두 줄과 사실 같아서 컴파일러는 이렇게 최적화를 하고 싶을 수 있다 허나 어쨌든 다른 이름이라 최적화를 해주지 못한다. 

    restar[0] += 3;
    restar[0] += 5;
    //restar[0] += 8;  // Equivalent(컴파일러가 동적할당 받은 메모리를 접근할 수 있는 방법은 restar밖에 없고 해서 바로 위의 코드 두 줄을 이 한 줄로 최적화할 수도 있다)

    //free(restar);

    return 0;
}