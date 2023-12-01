/* 함수 같은 매크로 */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>

/*
    stringizing(스트링아이징) operator #
    - converts macro parameters to string literals
*/
#define SQUARE(X)       (X)*(X)
#define PRINT_SQR1(X)   printf("The square of %d is %d.\n", X, SQUARE(X))
#define PRINT_SQR2(X)   printf("The square of " #X " is %d.\n", SQUARE(X)) // 전처리기에서 문자열로 바꿈 의외로 유용하게 쓰임

/*
    ## operator combines two tokens into a single token
*/

#define XNAME(n)    x ## n      //n은 argument로 들어왔고 x는 타이핑할 때 그냥 x임
#define PRT_XN(n)   printf("x" #n " = %d\n", x ## n);

int main(void)
{
    PRINT_SQR1(10);
    PRINT_SQR2(10);

    printf("\n");

    int XNAME(1) = 1;   // int x1 = 1;
    int XNAME(2) = 2;   // int x2 = 2;

    PRT_XN(1);          // printf("x1 " = %d\n", x1);
    PRT_XN(2);          // printf("x2 " = %d\n", x2);

	return 0;
}


/*
    Macro or Function ? // macro 괜찮은데? 그래도 function을 쓰는 게 좋다. 매크로는 전처리기에서 이뤄지므로 컴파일러가 오류를 잡아주지 못함
    허나 코딩하는 분량을 줄여주거나 반복적으로 코딩하는 부분을 인식하기 쉽게 해줌 대표적으로 밑에 매크로
    - no space in the macro name
    - Use parentheses 괄호를 잘 써야 된다.
    - Use capital letters for macro function names
    - Speed up? 속도가 빨라지는 기대감? 최근에는 컴파일러가 최적화해주는 것이 일반적
*/

#define MAX(X,Y)        ((X) > (Y) ? (X) : (Y)) // c언어에서는 많이 사용됨
#define MIN(X,Y)        ((X) < (Y) ? (X) : (Y))
#define ABS(X,Y)        ((X) < 0 ? -(X):(X))
