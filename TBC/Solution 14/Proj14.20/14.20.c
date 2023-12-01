/* Namespace 이름공간(명칭공간) 공유하기 */
#define _CRT_SECURE_NO_WANRINGS

#include <stdio.h>

int iamfunction()
{
    return 0;
}


int main(void)
{
    /*
        namespace
        - Identify parts of a program in which a name is recognized
        - You can use the same name for one variable and one tag. structure, union은 카테고리가 다르기 때문에 문법적으로 가능 허나 c에서만 그렇다. 변수와 함수도 이름이 겹치면 안 된다.
        - C++: use 'namespace' to use the same identifiers in the duplicated scopes 한 영역에서 이 이름을 꼭 쓰고 싶을 때 가능 커다란 프로그램을 만들 경우 변수이름이 중복되는 경우가 많이 발생
     */

    int myname = 123;
    {
        int myname = 345;                           // 스코프 바깥의 myname을 name hiding한다
        //double myname = 3.14;                     // ERROR(자료형이 다르더라도 동일한 스코프에서는 같은 이름(식별자)를 사용할 수 없다
    }

    struct rect { double x; double y; };            // struct의 태그가 rect인 경우

    //int rect = 123;  // OK in C (NOT OK in C++) 구조체 이름의 rect가 있을 경우 그래도 가능 허나 권장하지 않음
    struct rect rect = { 1.1, 2.2 };                // struct rect and rect(struct rect's variable name) are in different categories

    /*
     typedef struct rect rect;
     rect rect = { 1.1, 2.2 };                      // NOT OK(컴파일러 입장에서 봤을 때 둘을 구분할 수 없기에 불가능)
     */

     //int iamfunction = iamfunction();             // 변수와 함수는 같은 이름을 사용할 수 없다 error C2063: 'iamfunction': not a function 이미 iamfunction을 쓰고 있기 때문에 iamfunction() 이이름이 함수를 가리키는 거라고 인식할 수 없다.

     /*
         Namespace pollution (KNK p.465) a를 b로 바꾸니 또 안 되고 c로 바꾸니 또 안 된다. 공해 수준
         - Names in different files accidentally conflicting with each other
         - C에서는 전역변수를 최소로 사용하거나 static으로 선언하는 방식으로 방지 가능
     */

     //printf("%d\n", a);                            // other.c 에 a, b, c, d, e, f라는 이름의 변수가 선언돼있다면 컴파일할 때는 translation unit이 다르기 떄문에 에러가 발생하지 않지만 링킹 에러 발생,
     // 꽤 쓸만한 변수의 이름이 다른 곳에서 이미 쓰이고 있는 경우가 많다. 가급적 변수의 이름을 작은 스코프 안에 가둬놔야 이름을 재사용할 수 있다.
     // 전역변수 안 좋다는 말이 나온 이유
     // 다른 언어는 namespace관련 고급 문법이 많음
                                                     // error LNK2005: _a already defined in 14.20.obj
    return 0;
}