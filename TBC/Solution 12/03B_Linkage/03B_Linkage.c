#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// file은 컴파일이 이뤄지는 최소 단위이다(translation(컴파일이 번역기니) unit)
// 기본적으로 서로 다른 .c 파일을 각각 컴파일해서 생성되는 .o 파일들은 서로의 내용을 알 수 없지만 링커를 통해 서로 연결될 수 있다

/*
    Linkage

    Variables with block scope, function scope, or function prototype scope
    - No linkage

    File scope variables
    - External or internal linkage
*/

// 어느 translation unit이든 사용가능하기 때문에 global variable
int el;         // File scope with external linkage (global variable)
static int il;  // File scope with internal linkage(이 file안에서만 볼 수 있다.) (키워드로서의 static은 이변수의 범위가 현재 scope로 제한함)

void testLinkage();  // 다른 파일에 정의되어 있는 함수를 사용하기 위해 프로토타입을 선언해야 한다(링킹)

int main() {
    el = 1024;

    testLinkage();

    printf("%d\n", el);

    return 0;
}