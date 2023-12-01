/*  #define 매크로 */
#include <stdio.h>

/*
    Preprocessor directives(전처리 지시자) begins with #(hash) symbol at the beginning of a line
*/

/*
    Macro
    - An instruction that represents a sequence of instructions in abbreviated(축약된) form 여러 개의 명령어가 나열되어 있는 것을 하나의 명령어로 축약
*/

/*
#define         SAY_HELLO        printf("Hellow, world!");

Preprocessor    Macro (name)     body (or replacemnet list)
directive

Macro expansion: 매크로 name이 body로 교체되는 과정을 지칭
*/

/*
    Object-like macros vs Function-like macros(c언어에서 많이 사용하지만 위험함 c++에서 남용 가능성)

#define ONE 1
#define SQUARE(X) X*X
*/

#define PI 3.141592          // Symbolic, or manifest(명백한), constants //manifest는 목록 명단라는 뜻으로도 사용됨 나열된 파일 manifested file)
#define GRAVITY 9.8          // 전처리기가 GRAVITY를 9.8로 교체하기 때문에 컴파일러는 9.8을 받아들일뿐 GRAVITY는 볼 수 없다

#define THREE 3
#define MESSAGE "The great glory in living lies not in never falling, \
but in rising every time we fall." // 16.2 주의

#define NINE THREE*THREE // 매크로에서 매크로 권장하진 않음 매크로 사용 최소화하는 것을 권장 c++에서는 가급적 사용 안 함
#define SAY_HELLO printf("Hello, world!\n");
#define FORMAT "Number is %d.\n"

# define WITH_BLANK 1    // 매크로 선언 시 빈 칸 허용

#define MY_CH 'Z'
#define MY_ST "Z"            // Z\0

#define LIMIT 20
const int LIM = 50;
static int arr1[LIMIT];
//static int arr2[LIM]       // clang, C++는 됨. 변수가 들어간 형태로 선언 시 c는 컴파일러에 따라 다름 c는 엄격
const int LIM2 = 2 * LIMIT;
//const int LIM3 = 2 * LIM;  // clang, C++ 이게 안 되는 이유?
/*
The idea behind this requirement is to have all static storage duration object initialized at compile time.
The compiler prepares all static data in pre-initialized form so that it requires no additional initializing code at run time.
I.e. when the compiled program is loaded, all such variables begin their lives in already initialized state.

The C standard clearly prohibits initialization of global objects with non-constant values. The Section 6.7.8 of the C99 standard says:
All the expressions in an initializer for an object that has static storage duration shall be constant expressions or string literals.

The definition of an object with static storage duration
An object whose identifier is declared with external or internal linkage, or with the storage-class specifier static has static storage duration.
Its lifetime is the entire execution of the program and its stored value is initialized only once, prior to program startup.
*/

/*
    Tokens

#define SIX 3*2
#define SIX 3 * 2
#define SIX 3     *    2 // 컴파일러는 의미단위지만 전처리기에서는 이것을 어떻게 해석할지 애매함. 컴파일러 타입에 따라 다름
*/

/* Redefining Constants */
// #define의 범위는 파일 범위이지만 다른 헤더파일에 #define이 정의되어 있는 경우 그 헤더파일을 include하면 해당 헤더파일에 있던 #define도 함께 들여온다 그런 경우에 redefine이 되기도 한다. 다른 헤더파일을 include할 때 뭐가 다 있는지 모를 수 있기 때문에
// 서로 완전히 같은 여러 개의 #define 은 경고가 발생하지 않지만 띄어쓰기라도 다르다면(token단위로 봤을 때 다르다면) 경고를 발생시킨다
#define SIX 2*3
#define SIX 2*3 // ok 전처리기할 때 하나 지우면 되겠지
//#undef SIX                // 프로그래머가 의도적으로 redefine 하는 경우 #undef를 통해 그 이전에 선언된 #define을 무효화한다
//#define SIX 2 * 3         // WARNING

int main(void)
{
    int n = THREE;      // 기본적으로 replacement이지만 이렇게만 생각하면 ㅈ될 수 있다

    SAY_HELLO;              // NOTE: the additional ;(VS는 매크로에가서까지 세미콜론을 확인하지는 않기 떄문에 세미콜론이 중복되더라도 이렇게 표현하기도 한다)
    n = NINE;               // SAY_HELLO에 ; 없어도 실행은 잘 됨(이렇게 쓰는 사람 은근 많다.)  n이 들여써져서 그렇지 
    printf(FORMAT, n);      // 현대프로그래밍에서는 이렇게 하드코딩을 줄이진 않는다.
    printf("%s\n", MESSAGE);     // replaced
    printf("SAY_HELLO NINE\n");  // Not replaced // 문자열 안에선 ㅇㅇ

    const int a = 5;
    const int a2 = a * 10;

    return 0;
}
