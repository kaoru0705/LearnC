/* Automatic Variables 자동 변수 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
    Automatic storage class
    - Automatic storage duration(이래서 이름이 자동변수), block scope, no linkage(메모리에 있다 없다 하니 연결할 수가 없다)
    자동변수니 편하겠네? ㄴㄴ 블록을 잘 정해야 함
    - Any variable declared in a block or function header
*/

void func(int k);  // automatic variable in function header

int main() //Note: main() is a function
{  
    //auto int a;  // keyword auto : a storage class specifier(auto 키워드는 생략 가능하며 지역변수임을 강조하기 위해 붙이기도 한다. 대부분 안 붙임. 단, C++에서는 auto 키워드가 전혀 다른 의미를 지니기에 주의해야 한다)
    //a = 1024;
    //printf("%d\n", a);     // What happens if uninitialized?(BSS 세그먼트에 저장된 전역/정적변수의 경우 처음 한 번만 초기화하면 되기에 컴파일러가 자동으로 초기화해준다. 하지만 스택에 빈번하게 드나드는 자동변수들을 매번 0으로 초기화하기에는 비용이 발생하므로 초기화되지 않은 자동변수가 있을 경우 자동으로 초기화해주지 않고 에러를 발생시킨다 c++에서는 불편함 해소 가능)
    //auto int b = a * 3;    // What happens if uninitialized?()

    int i = 1;
    int j = 2;

    printf("i %lld\n", (long long)&i);

    {
        int i = 3;  // 바깥 식별자 name hiding 덮여 있어서 부르기가 애매함
        printf("i %lld\n", (long long)&i);

        int ii = 123;

        // j is visible here(스택의 관점에서 보면 변수 j가 여전히 아래에 쌓여있는 상태이기 때문)
        printf("j = %d\n", j);
    }

    // ii is not visible here
    
    //stack frame main이라면 main 함수 전체의 필요한 메모리 그안에서 변수가 push pop되는 구조는 스택 자료구조 12.5 질문
    /*
        여기서 말하는 스텍 프레임은 그 12.1 에서 배우셨을 메모리 레이아웃 중 하나인 스택 메모리에 대해 언급하신 것입니다! (메모리 영역의 이름이 '스택'인 것) 
        main 함수를 비롯한 여러 함수들 실행에 필요한 메모리는 이 스택 메모리에 위치하게 되기 때문입니다.
        근데 이 메모리 또한 그 자료구조 스택처럼 작동하는 것도 맞습니다 ㅎㅎ 그렇기에 교수님께서 저렇게 push pop 을 언급하신 것으로 보입니다. 
        예를 들어서 main 함수 안에서 func 라는 함수를 호출했다면 main 함수에서 func 를 호출하기 전까지의 메모리 그 위에 func 실행하는데 필요한 메모리들이 쌓입니다.(같은 영역이니까)
        그리고 func 호출이 끝나면 func 실행하는데 필요한 메모리들이 빠지고 다시 main 함수 메모리가 top 이 됩니다. 딱 자료구조로서의 스택의 원리와 똑같습니다.
    */

    printf("i %lld\n", (long long)&i);  // which i?

    for (int m = 1; m < 2; m++)
        printf("m %lld\n", (long long)&m);  // no block?(for문 뒤에 한 문장까지는 블럭 없이 붙일 수 있으며 변수 m의 스코프도 그 문장 내로 제한된다

    func(5);  // cannot see any of the variables defined so far(위에서 선언된 변수 i,j와 func() 함수의 스코프는 같지만, func() 함수의 body로 제어권이 넘어가는 순간 stack frame 자체가 달라지기에 i,j에 접근할 수 없다)
    
    for (int m = 3; m < 4; m++)
    {
        printf("m %lld\n", (long long)&m);  // block?
    }

    return 0;
}

void func(int k)
{
    int i = k * 2;
    // do something with i and k
    printf("i %lld\n", (long long)&i);
}