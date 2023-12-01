/* Variable Arguments 함수가 받아들이는 인수의 개수가 그때그때 달라질 수 있는 */
#include <stdio.h>
#include <string.h>
#include <stdarg.h>  // Variable Arguments

/*
    Variable Arguments
    - int printf(char const* const _Format, ...); , ... : ellipsis

    1. Provide a function prototype using an ellipsis

    void    vaf1(int n, ...);                  // OK
    int     vaf2(const char * s, int k, ...);  // OK
    char    vaf3(char c1, ..., char c2);       // Not OK, ellipsis should be the last
    double  vaf4(...);                         // Not OK, no parameter(말줄임표 이전에 있는 인수를 기준으로 말줄임표에 들어오는 인수들의 주소를 체크할 수 있기에 말줄임표 이외의 인수가 하나 이상 있어야 한다)

    2. Create a va_list type variable in the function definition
    3. Use a macro to initialize the variable to an argument list
    4. Use a macro to access the argument list

    가변인수를 실무에서 사용할 일도 없고 권장하지도 않는다. debugging이 힘들기 때문이다. 
    저수준 레벨에서 하드웨어에 가깝게 프로그래밍하거나 운영체제, 프로그래밍 언어를 만든다면 이런 것을 고려해서 프로그래밍할지도 모른다.
    응용프로그래머는 안 씀
*/

double average(int, ...); // parameter입장에서 볼 땐 int가 2개
double average2(char* format_string, ...);

int main(void)
{
    double a, b;

    //a = average(3, 1.1, 2.2, 3.3);      // 길이가 변할 수 있는 여러 개의 argument들을 하나의 parameter로 받아들임 
    //b = average(6, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);
    a = average2("dd", 1.1, 2.2, 3.3);
    b = average2("ddd", 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);

    printf("%lf\n%lf\n", a, b);

    return 0;
}

double average(int num, ...)
{
    va_list ap;
    double sum = 0.0;
    int i;

    va_start(ap, num);      // ... 앞에 있는 마지막 파라미터를 넣으면 된다. 여기선 num
    for (i = 0; i < num; i++)
        sum += va_arg(ap, double); // ...에 들어오는 타입이 어떤 타입인지 알아야 함
    va_end(ap);

    return sum / (double)num;
}

double average2(char* format_string, ...) // printf가 이런 식으로 문자열을 분석해서 출력시키고 개수를 반환했을 것이다.
{
    int num = strlen(format_string);

    va_list ap;
    double sum = 0.0;
    int i;

    va_start(ap, format_string);    // va_start에 format_string이 들어가는 이유는 내용 자체가 중요한 게 아니라 다음에 variable argument가 들어올 자리라는 걸 알려주기 위해서다.
    for (i = 0; i < num; i++)
        sum += va_arg(ap, double);
    va_end(ap);

    return sum / (double)num;
}