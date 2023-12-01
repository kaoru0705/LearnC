/* 난수 생성기 모듈 만들기 예제 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <stdlib.h>  // srand()
#include <time.h>  // time()
#include "my_rand.h"

int main()
{
    /*
        rand()
        - 0 to RAND_MAX (typically INT_MAX)
        - defined in stdlib.h
    */

    //srand(1);  // random seed
    //srand((unsigned int)time(0));  // 반복해서 실행했을 때 다른 값을 반환하도록 시간값을 시드로 사용한다

    //for (int i = 0; i < 10; ++i)
    //{
    //    printf("%d\n", rand());  // 이 코드는 반복해서 실행해도 동일한 10개의 값을 출력한다 컴퓨터는 진정한 난수를 만드는 능력이 없다.
    //    //printf("%d\n", my_rand() % 6 + 1);  // 출력 가능한 값: 1, 2, 3, 4, 5, 6
    //}

    //unsigned int next = (unsigned int)time(0);  // 내부적으로 사용하는 알고리즘 next(시드)의 값을 바꾸면 생성하는  난수도 변화한다

    //for (int i = 0; i < 10; ++i)
    //{
    //    next = next * 1103515245 + 1234;    // 유사 난수 pseudo random number overflow 이용
    //    next = (unsigned int)(next / 65536) % 32768;    // 자릿수 맞춰주기 위해서 음수가 나오면 안되니까
    //    printf("%d\n", (int)next);
    //}
    ////라이브러리에서는 통계학적으로 더 정밀한 난수를 생성할 수 있다.

    my_srand((unsigned int)time(0));

    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", my_rand() % 6 + 1); // my_rand() % 6 == 0 ~ 5
    }

	return 0;
}