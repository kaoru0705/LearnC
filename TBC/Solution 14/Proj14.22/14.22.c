/* Function Pointers 함수 포인터의 사용 방법 */
#define _CRT_SECURE_NO_WANRINGS

#include <stdio.h>
#include <ctype.h>  // toupper(), tolower()
// ToUpper ToLower의 파라미터와 리턴값이 같다? 동일한 함수포인터를 통해서 둘 다 사용할 수 있다.
void ToUpper(char* str)
{
    while (*str)
    {
        *str = toupper(*str); // 한 글자를 대문자로 바꿔줌
        str++;
    }
}

void ToLower(char* str)
{
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
}
// 위에 두 함수는 toupper tolower이 두 개만 다르고 일치한다. 이 두 개의 함수를 하나의 함수처럼 어떤 틀을 만들 수 있지 않을까?
// 공통된 패턴을 묶어서 하나의 함수를 만들고 바뀌어야 하는 부분만 바꿔주면 코딩하는 분량이 줄어든다. -> 유지보수할 노력이 적게 들고 실수할 확률이 줄어든다.
// 단점 지금 사용하고 있는 함수포인터와 함수포인터를 응용해서 사용하는 기법 ex)객체지향의 다형성을 이해하지 못하면 프로그래밍하기 힘들어진다.

void UpdateString(char* str, int (*pf)(int)) // int(*pf)(int)를 통해서 기능을 사용할 함수 자체를 파라미터로 받고 있다.
//void UpdateString(char* str, int(__cdecl *pf)(int)) //Note: __cdecl is function calling convention(함수호출 규약) 없어도 컴파일러가 내부적으로 컴파일되도록 처리해준다. windowsapi 배울 때 배움
{
    
    while (*str)
    {
        *str = (*pf)(*str);
        str++;
    }
}

int main(void)
{
    char str[] = "Hello, World!";

    void (*pf)(char*);

    pf = ToUpper;          // Name of a function is a pointer 관점의 차이
    // pf = &ToUpper;      // Acceptable
    // pf = ToUpper(str);  // Not acceptable in C 함수를 실행시켜서 반환값을 대입한다는 뜻

    printf("String literal %lld\n", (long long)("Hello, World!"));  // TEXT Segment
    printf("Function pointer %lld\n", (long long)ToUpper);          // TEXT Segment
    printf("Variable %lld\n", (long long)str);                      // Stack

    // 왜 함수 파라미터랑 반환값을 정해서 함수포인터를 선언해야 하지 다 쓸 수 있게 하면 안되나?
    (*pf)(str);//==ToUpper(str); 함수포인터를 통해 실행을 시킬려면 정할 수밖에 없다.
    //pf(str);  // K&R(NOT OK), ANSI(OK) 어차피 함수 이름 자체도 주소잖아.

    printf("ToUpper %s\n", str);

    pf = ToLower;

    pf(str);

    printf("ToLower %s\n", str);

    /*
        Passing function pointers to functions
    */

    UpdateString(str, toupper);

    printf("toupper %s\n", str);

    UpdateString(str, tolower);

    printf("tolower %s\n", str);

    

    return 0;
}