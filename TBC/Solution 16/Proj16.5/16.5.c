/*  Variadic Macros 가변 인수 매크로 */
#include <stdio.h>
#include <math.h>

/*
    Variadic Macros accept a variable number of arguments
*/

#define PRINT(X, ...) printf("Message " #X ": " __VA_ARGS__)
// ... : ellipses(말줄임표) ...은 많은 인수가 들어갈 수 있다는 뜻
// __VA_ARGS : one of the predefined macros. variadic argument 약자
// ...부분이 통째로 __VA_ARGS__로 들어가고 컴파일

/*
printf(...) printf f12를 해 봐라 ...은 많은 인수가 들어갈 수 있다는 뜻
strvar.h Variadic arguments printf에서 가변인수를 사용하는 법은 나중에
*/

int main(void)
{
    double x = 48;
    double y;

    y = sqrt(x);
    PRINT(1, "x = %g\n", x);
    printf("Message " "1" ": " "x = %g\n", x); // printf("Message " "1" ": " __VA_ARGS__) -> printf("Message " "1" ": " "x = %g\n", x)

    PRINT(2, "x = %.2F, y = %.4F\n", x, y);
    printf("Message " "2" ": " "x = %.2F, y = %.4F\n", x, y);
}