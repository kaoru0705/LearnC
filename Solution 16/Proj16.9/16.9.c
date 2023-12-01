/*  #pragma 지시자 (컴파일러에게 어떠어떠하게 컴파일해달라고 컴파일러에게 지시 명령할 수 있는 전처리 지시자 pragma)*/
#include <stdio.h> // f12를 눌러보면 #pragma once, ifndef INCSTDIO endif의 두 가지 헤더가드를 모두 사용했다.

/*
#pragma tokens (ex: once) // 컴파일러마다 pragma로 지원되는 내용이 다르다. https://learn.microsoft.com/en-us/cpp/preprocessor/pragma-directives-and-the-pragma-keyword?view=msvc-170
*/

//#pragma pack(1)     // 1바이트로 패킹(= 패딩을 하지 말라는 의미)
_Pragma("pack(1)")  // VS에서는 사용 못 함 destringizing : remove first and last ", \" -> " 위와 동일 pragma 다음의 오는 토큰을 문자열로 할 수 있음 문자열은 전처리기가 번역하는 과정에서 destringizing
//"pack(1)"를 #pragma 뒤에 옮겨주고  -> #prgma pack(1)
//#define PACK1 _Pragma("pack(1)")  // 아니 왜 굳이 위코드처럼 씀? 매크로를 만들 수 있다.
//PACK1

//#pragma warning( disable : 4477 ) //4477을 없앨 수 있다.
//#pragma warning( error : 4477 ) // warning을 error처럼 처리해라

struct s {
    int i;
    char ch;
    double d;
};

int main(void)
{
    struct s A;
    printf("Size of A is : %zd", sizeof(A)); // z를 없애면 c4477 warning
}