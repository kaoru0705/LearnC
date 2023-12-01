/* Enumerated Types 열거형 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* Motivation : 유지보수의 편의성과 가독성의 측면에서 enum타입을 사용하는 게 좋다
 int c = 0;  // red:0, orange:1, yellow:2, green:3, ... 일일이 문자를 코딩하기보다 숫자를 배정함. 실수할 확률이 굉장히 높음 0이 red인 걸 계속 기억해야 됨 유지보수를 하다가 코드가 길어지면? 일일이 red인 걸 위에 가서 확인
 if(c == 0)
    printf("red");
 else if(c == 1)
    printf("orange");
 else if(c == 2)
    printf("yellow");
*/

/** 이 방식은 copy&paste하는 것(문자 단위로 교체해줌 전처리기의 특징)이기에 컴파일러가 오류를 잡아주지 못한다 컴파일러 입장에선 그냥 c = 3일 뿐
 #define RED 1
 #define ORANGE 2
 #define YELLOW 3

 int c = YELLOW;
 if(c == YELLOW)
    printf("yellow");
 */

int main(void)
{
    /*
        Enumerated type enumerate 나열하다
        - Symbolic names to represent integer constants
        - Improve readability and make it easy to maintain
        - enum-specifier (struct-specifier(구체화), union-specifier)

        Enumerators
        - The symbolic constants
    */

    // 열거형은 내부적으로 정수로 처리된다
    enum spectrum { red, orange, yellow, green, blue, violet };
    //              0    1       2       3      4     5

    enum spectrum color;
    color = blue;
    if (color == yellow)
        printf("yellow");   // Note: enumerators are not strings 정수일 뿐 2라는 정수에게 yellow라는 이름을 붙여줄 뿐

    for (color = red; color <= violet; color++)  // Note: ++ operators doesn't allowed in C++
        printf("%d\n", color);

    printf("red = %d, orange = %d\n", red, orange);

    enum kids { jackjack, dash, snoopy, nina, pitz };
    // nina has a value of 3
    enum kids my_kid = nina;
    printf("nano %d %d\n", my_kid, nina);

    enum levels { low = 100, medium = 500, high = 2000 }; // low를 200으로 바꾼다면? 유지보수가 쉽다.

    int score = 800;
    if (score > high) // 가독성이 좋다.
        printf("High scores!\n");
    else if (score > medium)
        printf("Good job!\n");
    else if (score > low)
        printf("Not bad\n");
    else
        printf("Do your best\n");

    enum pet { cat, dog = 10, lion, tiger };
    // lion has a value of 11 지정된 정수에 1 더한 값 주의 cat = 0;
    printf("cat %d\n", cat);
    printf("lion %d\n", lion);

    return 0;
}