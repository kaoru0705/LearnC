#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
    Storage duration(메모리의 지속 기간)
    - static storage duration (프로그램이 시작될 때부터 끝날 때까지 계속 메모리에  static하게 남아있다. keyword로서의 static과는 다름
      (Note: 'static' keywords indicates the linkage type 현재의 범위를 벗어나지 않게, scope가 넓어지지 않도록 고정 시킨다., not the storage duration)
    - automatic storage duration (보통 지역변수를 의미 stack)
    - allocated storage duration (동적할당)
    - thread storage duration (multi threading)
 */

void count()
{
    int ct = 0;
    printf("count = %d\n", ct);
    ct++;
}

void static_count()
{
    static int ct = 0;  // 함수 호출 시 매번 변수가 생성/소멸되지 않고 프로그램 시작 시 메모리가 할당되어 프로그램 종료 시 해제된다
    printf("static count = %d\n", ct);
    ct++;
}

int main() {
    count();
    count();
    static_count();
    static_count();

    return 0;
}