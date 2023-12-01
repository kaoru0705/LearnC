/*  전처리를 준비하는 번역 단계 Translation Phases 전처리기의 첫 단계라 볼 수 있는 번역단계에 대해 알아보자*/
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>

int main(void)
{
	/*
		Program written in C
		
		Translating 컴파일러가 이해할 수 있는 쉬운 언어로 바꿔주는 과정
		translating을 전처리기의 포함된 과정 혹은 분리해서 컴파일러 앞에 일어나는 과정으로 말할 수 있다.
		Preprocessing
		Compiling
		Linking
		
		Executable
	*/

	/*
		International characters 국제단계의 다국어들을 내부적으로 컴파일러가 이해할 수 있는 문자집합으로 바꿔줌 translation단계에서 처리
	*/

	puts("안녕하세요? 한글을 사랑합니다.\n");

	/*
		Trigraph Sequences
		- Some keyboards don't provide all the symbols used in C. 예전 키보드들은 이런 키가 없어서 강제로 이렇게 사용
		- Three-character sequences
		
		Trigraph		Replacement
		??=				#
		??/				\
		??'				^
		??(             [
        ??)             ]
        ??!             |
        ??<             {
        ??>             }
        ??-             ~
		
		/Zc:trigraphs trigraphs를 고려해서 컴파일 해라 - 컴파일해라? translation인데? 걍 전부 통틀어서 컴파일이라 함 현실에선 그렇다.
	// VS의 경우 [Properties]-[C/C++]-[Command Line]-[Additional Options]에 /Zc:trigraphs 를 추가해야 사용 가능
    */
    
    int arr[3] = { 1, 2, 3 };
    printf("arr??(0??) == %d\n", arr??(0??));
    //printf("arr[0] == %d\n", arr[0]);

    /*
        Digraphs
        - Two-character sequences

        Digraph         Equivalent
        <:              [
        :>              ]
        <%              {
        %>              }
        %:              #
    */

    printf("arr<:1:> == %d\n", arr<:1:>); // 앞에 부분은 []로 안 바꿔줌
    printf("arr[1] == %d\n", arr[1]);

    /* Two physical lines vs One logical line 물리적으로는 두 줄 논리적으로는 한 줄 physical이라는 용어는 많이 보인다. 전산학에서 */
    printf("This is a very very very very very very \
very very very very very long long long long long long line.\n"); // \다음 부분이 떨어져 있으면  빈칸이 생겨서 이렇게 없애줘야 한다

    /*
        Tokens 글자의 그룹,  입력한 코드를 토큰이라는 단위로 쪼갬 컴파일러 공부할 때 자세하게 배우는 용어
        - Groups separated from each other by spaces, tabs, or line breaks
        Whitespace characters -> a single space
    */

    int/*a variable to count a number*/n = 1;  // 주석은 하나의 빈 칸 하나로 번역단계에서 바꿔주기에 이 코드는 정상실행된다 
    //// 허나 이렇게 쓰는 주석은 매우 안 좋다. 권장하지 않지만 간혹 이렇게 자료형 뒤 혹은 변수명앞에 다는 사람이 있다.
    int /*a variable to count a number*/ n = 1;  // 주석을 포함해서 자료형과 변수명 사이에 빈 칸이 3개지만 이를 컴파일하기 편하도록 빈 칸 하나로 다시 번역된다.
    //int n = 1;

    return 0;
}
