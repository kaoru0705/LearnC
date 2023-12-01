/* 표준 수학 라이브러리 */
/* https://www.onlinegdb.com/online_c_compiler */
#include <stdio.h>
#include <math.h>
//#include <tgmath.h>  // type generic macros

// Generic Selection Expression
#define SQRT(X) _Generic((X),\
long double: sqrtl, \
default: sqrt, \
float: sqrtf)(X)


int main(void)
{
    printf("%f\n", cos(3.141592));

    /*
        Pythagorean theorem
        https://en.wikipedia.org/wiki/Pythagorean_theorem
    */

    double c = 5.0, b = 4.0, a;  // a?
    a = sqrt(c * c - b * b);     // sqrtf() 함수 보다 정밀도가 높다
    printf("a = %f\n", a);

    float cf = 5.0F, bf = 4.0F, af;
    af = sqrtf(cf * cf - bf * bf);
    printf("af = %f\n", af);

    /* 이후 코드 VS로 실행 불가능 */
    /*
        Type Variants
    */

    double t1 = SQRT(2.0F);  // float로 계산한 후 double로 캐스팅된다(=sqrtf()의 정밀도를 갖는다)
    double t2 = SQRT(2.0);   // double로 계산한다(=sqrt()의 정밀도를 갖는다)

    if (t1 == t2)
        printf("Identical\n");
    else
        printf("Not identical\n");

    /*
        tgmath.h Library
        tgmath.h 의 sqrt()함수는 인수의 타입에 따라 sqrt()와 sqrtf() 중에 자동으로 선택한 후 호출된다(따라서 아래 출력결과가 Not identical이 된다)
    */

    double a1 = sqrt(2.0F); // tgmath.h include 안 할 경우 2.0f가 double로 promotion돼서 입력되므로 indentical 출력
    double a2 = sqrt(2.0);

    // 정밀도가 달라지기에 아래 출력 결과가 Not identical이 된다
    //double a1 = sqrt(1.0F / 3.0F);
    //double a2 = sqrt(1.0 / 3.0);

    if (a1 == a2)
        printf("Identical\n");
    else
        printf("Not identical\n");

    return 0;

    // 라이브러리 내용이 필수적인 것만 들어있는 c조차도 내용을 다 알아보기 힘들다. 구글링해라 cppreference 추천한다.
}