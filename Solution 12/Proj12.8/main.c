/* Static Variables with External Linkage 정적 변수의 외부 연결 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* 컴파일러가 파일들을 따로 따로 컴파일하고 실행파일을 만들기 전에 그것을 링커가 연결해준다. 그때 external linkage를 갖는 변수들이 서로 연결될 수 있도록 연결해준다. 변수말고 함수도 그렇다. */
/*
    Static with external linkage
    - File scope(현재 파일의 어떤 스코프에서도 접근 가능), external linkage(다른 파일에서도 접근 가능), static storage duration
    - External storage class
    - External variables
    - 번역 단위(.c 파일) 외부로 연결 가능
    - 링커는 번역 단위 간 변수와 함수를 연결
*/

// defining declaration: 가급적이면 defining declaration에서 초기화를 하는 게 좋다 0으로 자동으로 초기화가 된다 하더라도 초기화를 하는 게 좋다.
int g_int = 0;  // 지역변수를 스택에 오르기 때문에 컴파일러가 자동으로 초기화하게 되면 오버헤드가 발생하는 반면 정적/전역 변수는 처음에 딱 한 번만 초기화하면 되기에 컴파일러가 자동으로 초기화해준다. 그럼에도 설령 0으로 초기화하더라도명시적으로 초기화하는 습관 들이기를 권장한다
// int g_int = 7;
double g_arr[1000] = { 0.0, };  // 위와 마찬가지로 array도 선언만 해도 컴파일러가 자동으로 초기화해준다

/*
    Initializing external variables
*/
int x = 5;               // Ok. constant expression(컴파일 타임에 확정되는 값)  참조 https://en.cppreference.com/w/c/language/constant_expression
int y = 1 + 2;           // Ok. constant expression(컴파일 타임에 확정되는 값)
size_t z = sizeof(int);  // Ok. constant expression(컴파일 타임에 확정되는 값)
//int x2 = x * 2;        // Not ok. x is a variable

void fun()
{
    printf("g_int in fun() %d %p\n", g_int, &g_int);
    g_int += 10;
}

void fun_sec();  // 다른 파일에 정의되어 있는 함수를 사용하기 전에 선언하면 이 아랫줄부터는 함수를 사용할 수 있다(후에 링커가 연결해준다)

int main()
{
    /*
        defining declaration vs referencing declaration
    */

    // referencing declaration
    extern int g_int;         // Optional , referencing declaration. (현재 스코프 바깥에 있는 변수와 연결한다 -> 처음에 선언한 전역변수를 사용한다. 이 식별자가 파일 스코프에 있는 식별자임을 명시하기 위해 이렇게 extern 사용하는 습관 들이기 
    // 같은 파일에 있기 때문에 굳이 링커가 연결할 필요는 없다. 컴파일러가 봄.
    // 전역/정적 변수를 이처럼 접두어ex)g_로 구분하기도 한다)
    //extern int g_int = 1024;  // Error in block scope

    //int g_int = 123;          // name hiding hides global g_int(윗윗줄의 extern int g_int; 이후에 이 줄의 코드를 입력하면 'int g_int': redefinition 발생. 현재 스코프에서 해당 식별자가 이미 정의되어 있기 때문)

    extern double g_arr[];      // Optional, size is not necessary(크기는 이미 defining declaration에 의해 정해져 있기에)
    // extern은 나 이런 걸 가져다 쓸 거예요.라고 선언만 해주는 것 사이즈 필요 없다.
    printf("g_int in main() %d %p\n", g_int, &g_int);
    g_int += 1;

    fun();
    fun_sec();

    return 0;
}