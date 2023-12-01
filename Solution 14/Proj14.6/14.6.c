/* 구조체와 포인터 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define LEN 20

struct names {
    char given[LEN];
    char family[LEN];
};

struct friend {
    struct names full_name;
    char mobile[LEN];
};

struct my_data {
    int a;
    char c;
    float arr[2];
};

struct my_data_1 {
    int a;
    char c;
    float* arr;
};

int main(void)
{
    //struct friend my_friends[2] = {
    //    { { "Ariana", "Grande" }, "1234-1234" },
    //    { { "Taylor", "Swift" }, "6550-8888"}
    //};

    //struct friend* girl_friend; // girl_friend라는 구조체 friend 타입 변수에 대한 포인터

    //girl_friend = &my_friends[0];

    //printf("%zd\n", sizeof(struct friend));
    //printf("%lld %s\n", (long long)girl_friend, girl_friend->full_name.given);
    //// -> : indirect member access operator 포인터는 arrow로 멤버 접근 가능 구조체는 .으로 접근가능

    //girl_friend++;  // 포인터 연산 그 자료형의 사이즈만큼 더해준다.

    //printf("%lld %s\n", (long long)girl_friend, (*girl_friend).full_name.given);
    //// . has higher precedence than * indirection을 먼저 하고 dot operator

    /* 구조체의 복사 1 */
    //struct my_data d1 = { 1234, 'A', };
    ////struct my_data d1 = { 1234, 'A', { 1.1F, 2.2F }};  // 이렇게 초기화할 수도 있고 아래처럼 배열 요소 하나씩 초기화할 수도 있다
    //d1.arr[0] = 1.1F;
    //d1.arr[1] = 2.2F;

    //printf("%zu\n", sizeof(struct my_data));
    //printf("%d %c %lld\n", d1.a, d1.c, (long long)d1.arr);
    //printf("%f %f\n", d1.arr[0], d1.arr[1]);
    //printf("%lld %lld\n\n", (long long)&d1.arr[0], (long long)&d1.arr[1]);

    //struct my_data d2 = d1; //d1 멤버들의 값들을 복사한다. 구조체를 대입하면 내부적으로 복사해준다. 당연하지만 d1과 d2는 다른 메모리를 갖는다.

    //printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);
    //printf("%f %f\n", d2.arr[0], d2.arr[1]);
    //printf("%lld %lld\n\n", (long long)&d2.arr[0], (long long)&d2.arr[1]);

    /* 구조체의 복사 2 */
    struct my_data_1 d3 = { 1234, 'A', NULL };
    d3.arr = (float*)malloc(sizeof(float) * 2);
    d3.arr[0] = 1.1F;
    d3.arr[1] = 2.2F;

    printf("%d %c %lld\n", d3.a, d3.c, (long long)d3.arr);
    printf("%f %f\n", d3.arr[0], d3.arr[1]);
    printf("%lld %lld\n\n", (long long)&d3.arr[0], (long long)&d3.arr[1]);

    struct my_data_1 d4 = d3; // d3.arr의 값이 그대로 옮겨갔으니 주소값이 같아진다. 결과적으로 메모리를 공유하게 된다. 주의해라.

    printf("%d %c %lld\n", d4.a, d4.c, (long long)d4.arr);
    printf("%f %f\n", d4.arr[0], d4.arr[1]);
    printf("%lld %lld\n\n", (long long)&d4.arr[0], (long long)&d4.arr[1]);

    return 0;
}