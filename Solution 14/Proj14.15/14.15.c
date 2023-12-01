/* 공용체 Union의 원리*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    /*
        Union 조합
        - Store different data types in the same memory space 메모리를 같이 사용함
        - Structure vs Union
    */

    union my_union {
        int     i;
        double  d;
        char    c;
    };

    union my_union uni;

    printf("%zd\n", sizeof(union my_union));  // 공용체 my_union의 멤버 중 가장 큰 자료형의 사이즈를 갖는다
    printf("%lld\n", (long long)&uni);
    printf("%lld %lld %lld\n", (long long)&uni.i, (long long)&uni.d, (long long)&uni.c); // 모두 시작 주소가 동일함

    union my_union save[10];

    printf("%zd\n", sizeof(save));

    /*
        Union of different types
    */

    union my_union uni1;

    uni1.c = 'A';
    printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i);
    //0xCCCCCC41 = -858993599(https://binaryconvert.com/ 참고) 인간이 사용하는 개념으로 정리할 때는 cccccc41 메모리에서는 41 cc cc cc로 순서가 뒤집혀있다.

    uni1.i = 0;
    uni1.c = 'A';  // 공용체는 메모리를 공유하기에 첫 번째 바이트만 'A'로 바뀌고 그 다음 세 개의 바이트에는 바로 윗줄에서 할당받은 0으로 채워져 있다
    printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i);
    //0x00000041 = 65

    uni1.d = 1.2;
    printf("%d %f %d %c\n", uni1.i, uni1.d, (int)uni1.c, uni1.c);
    // 33 33 33 33 33 33 f3 3f
    // 0x3ff3333333333333 = 1.1999999999..559107901...
    // 0x33333333 = 858993459 (decimal)
    // 0x33 = 51 = '3'

    /*
        Initializing unions
    */

    union my_union uni2 = uni1;                     // Copy another union
    union my_union uni3 = { 10 };                   // First element (member) only(my_union의 경우에는 첫 번째 원소인 int형만 가능) 10, 3.14라 하면 컴파일 에러 공용체는 선언할 때는 마치 세 가지가 있는 것처럼 하지만 실제론 메모리를 고유하기때문에 한 가지밖에 안됨
    union my_union uni4 = { .c = 'A' };             // Designated initializer
    union my_union uni5 = { .d = 1.23, .i = 100 };  // Do NOT recommend(구조체 대신 실수로 공용체를 사용한 것인지, double형을 또는 int형을 초기화하려한 것인지 의도가 명확하지 않다)

    printf("%d %f %c\n", uni5.i, uni5.d, uni5.c);

    uni.i = 123;
    uni.d = 1.2;
    uni.c = 'k';  // 가장 마지막에 초기화한 char형으로 공용체를 사용하려는 의도

    printf("%d %f %c\n", uni.i, uni.d, uni.c);

    union my_union* pu = &uni;  // Pointer to union
    int x = pu->i;  // -> arrow operator, same as x = fit.digit

    // 공용체는 유용하고 편리한 문법인데 실수를 할 가능성이 많다. 더 무서운 건 실수가 의도적인 것인지 진짜 실수인지 구분하기 어렵다.
    uni.c = 'A';
    double real = 3.14 * uni.d;  // do NOT recommend(코드를 보는 입장에서 공용체를 char형으로 초기화해놓고 double형으로 접근하는 경우 의도가 명확하지 않다)
}