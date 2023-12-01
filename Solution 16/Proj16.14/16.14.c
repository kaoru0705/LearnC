/* 표준 유틸리티 Utilities 라이브러리*/
/* https://www.onlinegdb.com/online_c_compiler */
#include <stdio.h>
#include <stdlib.h>  // rand(), srand(), malloc(), free(), ...
//#include <stdnoreturn.h>

void goodbye(void)
{
    printf("Goodbye\n");
}
void thankyou(void)
{
    printf("Thankyou\n");
}

//// causes undefined behaviour if i <= 0 MSVC에서는 안 됨
//// exits if i > 0
//_Noreturn void stop_now(int i)  // _Noreturn : 이 함수가 끝나고 다시 어떤 프로그램이 실행되는 곳으로 돌아가지 않는 프로그램을 종료시키는 function specifier
//{ 
//    if (i > 0) exit(i);
//    //exit(i);
//}

int main(void)
{
    printf("Purchased?\n");
    if (getchar() == 'y')
        atexit(thankyou);  // 프로그램이 종료될 때 어떤 함수를 호출할지 등록할 수 있다. 어떤 함수를 종료할 때 실행시킬지 runtime에 결정 내부적으로 함수포인터의 list를 가지고 있다.

    while (getchar() != '\n') {};

    printf("Goodbye message?\n");
    if (getchar() == 'y')
        atexit(goodbye);

    /*
        exit(0);
        puts("Preparing to stop ...");
        stop_now(2);
        puts("This code is never executed.");
    */

    /*
        qsort();
    */

    return 0;
}