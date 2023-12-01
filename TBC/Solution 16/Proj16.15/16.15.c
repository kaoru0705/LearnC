/* assert 라이브러리 (디버깅할 때 유용하게 사용할 수 있는)*/
#define _CRT_SECURE_NO_WARNINGS // 이거 맨 위에 안 적으면 오류 남
#include <stdio.h>
#include <assert.h>

//#include <limits.h>
//_Static_assert(CHAR_BIT == 9, "9-bit char assumed"); 컴파일타임에 잡아주는 assert MSVS에서는 안됨 CHAR_BIT는 대부분 8비트이므로 assert가 뜸.
//// 상황이 조금조금 다를 수 있는 멀티플랫폼일 경우 유용 c++는 잘 된다.

int main(void)
{
    int a, b;
    int f = scanf("%d%d", &a, &b);

    printf("a / b = %d", divide(a, b));

    return 0;
}

int divide(int a, int b)
{
    assert(b != 0);  // 반드시 만족하는 조건에 대해 assert. 만족시키지 않을 경우 debug에 문제 생김. Release 모드에서 실행시키면 assert를 무시한다(빌드에 포함되지 않는다) 애초에 배포하는 모드이므로 ㅇㅇ
    // f5를 하고 3 0 입력 retry를 하면 debugging mode로 들어가고 알려줌
    // 아래 코드는 나누기라는 최소한의 기능만 담은 게 아니라 오버헤드를 발생시킨다 아주 효율적인 프로그램을 만들고 싶다면 이런 군더더기는 없어야 함
    // assert로 막아놓고 근본적인 문제를 해결하는 것이 옳다.
    //if(b == 0) {
    //  printf("Cannot divide\n");
    //  exit(1);
    //}

    return a / b;
}