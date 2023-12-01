/* 구조체의 메모리 할당 Memory Allocation */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/* https://stackoverflow.com/questions/4306186/structure-padding-and-packing padding 참조 */
int main(void)
{
    /*
        well aligned structure
    */

    struct Aligned
    {
        int a;
        float b;
        double c;
    };

    /*
     0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|
     |int a |float b|double c             |
     4 + 4 + 8 = 16
     */

    struct Aligned a1, a2;

    printf("struct aligned a1\n");
    printf("Sizeof %zd\n", sizeof(struct Aligned));
    printf("%lld\n", (long long)&a1);
    printf("%lld\n", (long long)&a1.a);
    printf("%lld\n", (long long)&a1.b);
    printf("%lld\n", (long long)&a1.c);

    printf("\nstruct Aligned a2\n");
    printf("Sizeof %zd\n", sizeof(a2));
    printf("%lld\n", (long long)&a2);
    printf("%lld\n", (long long)&a2.a);
    printf("%lld\n", (long long)&a2.b);
    printf("%lld\n", (long long)&a2.c);

    /* padding (struct member alignment(줄맞춤))
        정보를 표현하는 최소 단위 1비트, 메모리에서 주소를 배정하는 최소단위 1바이트
       - 1 word: 4 bytes in x86, 8 bytes in x64 메모리와 CPU가 데이터를 주고받을 때 1바이트나 1비트씩 주고 받지 않을까 생각할 수 있지만 주고 받을 때 해야하는 부가적인 일들이 있기 때문에 느려진다 가급적 데이터를 묶어서 보내는 것이 효율성이 높음.
       - 메모리와 CPU가 데이터를 주고 받을 때의 최소 단위 = word
       - struct member alignment를 1byte로 설정하면 패딩 옵션을 사용하지 않을 수 있다
    */

    struct Padded1
    {
        char a;
        float b;
        double c;
    };

    /* Without padding // 만약에 8바이트씩 전송하고 패딩을 하지 않는다면 double에서 3나머지 5바이트가 다음번에 전송이 된다 그리고 ???도 애매해지고 효율성이 좋지 않음 어차피 빈공간이 생길 거라면 ???를 a 바로 뒤에 넣어서 줄을 맞추자라는 게 기본적인 아이디어
     0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16
    |char a|float b|double c          | ?  ?  ?
     1 + 4 + 8 = 13
     */

     /* With padding
      0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 // char 뒤에 ???를 집어 넣어서 깔끔하게 4바이트 맞춰주고 double이 짤리질 않으니 cpu 입장에선 깔끔하게 보내서 깔끔하게 계산할 수 있음
     |char a|float b|double c             |
      4(char?) + 4 + 8 = 16
      */

    struct Padded1 p1; // char는 1바이트인데? 컴파일러가 3바이트를 더 집어넣음
    printf("\nstruct Padded p1\n");
    printf("Sizeof %zd\n", sizeof(p1));  // 4 + 4 + 8
    printf("%lld\n", (long long)&p1); // 배열과 마찬가지로 구조체 변수 자체의 주소와 첫 번째 멤버의 주소가 동일
    printf("%lld\n", (long long)&p1.a);
    printf("%lld\n", (long long)&p1.b);
    printf("%lld\n", (long long)&p1.c);

    struct Padded2
    {
        float a;
        double b;
        char c;
    };

    /*
     |0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20 21 22 23|24
     |float a        |double b             |char c                 |
     8(float?) + 8 + 8(char?) = 24 컴파일러가 double을 한 번에 한 워드에 통째로 보내게 하기 위해 2곳에 패딩을 넣음
     // padding이 a와 c에 모두 들어가기에 데이터 양은 같음에도 불구하고 Padded1에 비해 비효율적이다 이것까지 고려해서 구조체를 설계해라
    */

    struct Padded2 p2;
    printf("\nstruct Padded p2\n");
    printf("Sizeof %zd\n", sizeof(p2));
    printf("%lld\n", (long long)&p2);
    printf("%lld\n", (long long)&p2.a);
    printf("%lld\n", (long long)&p2.b);
    printf("%lld\n", (long long)&p2.c);

    struct Padded3
    {
        char a;
        double b;
        double c;
    };

    /*
    |0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20 21 22 23|24
    | char a        | double b            | double c              |
    8(char?) + 8 + 8 = 24
    */

    struct Padded2 p3;
    printf("\nstruct Padded p3\n");
    printf("Sizeof %zd\n", sizeof(p3));
    printf("%lld\n", (long long)&p3);
    printf("%lld\n", (long long)&p3.a);
    printf("%lld\n", (long long)&p3.b);
    printf("%lld\n", (long long)&p3.c);

    struct Person
    {
        char name[41];  // member
        int age;        // member
        float height;   // member
    };

    struct Person mommy;

    printf("\nstruct Person\n");
    printf("%lld\n", (long long)&mommy.name[0]);
    printf("%lld\n", (long long)&mommy.age);
    printf("%lld\n", (long long)&mommy.height);
    printf("Sizeof %zd\n", sizeof(mommy));  // 41 + 4 + 4 = 49 ?(정답은 52. char 배열에 패딩이 더해져 44바이트를 차지하기 때문

    /*
        아니 그럼 시발 왜 8바이트 단위 전송인데 height은 4바이트임 ? height은 맨끝이라 그런 듯 물론 전송할 때는 8바이트겠지만 개소리다 반례 padded2)

        struct Person mommy 의 크기를 측정하면 52로 8의배수가 아닌값이 출력이됩니다.
        패딩이 3(char[41] 뒤에)byte만큼 들어간것으로 보이는데요,
        해당하는 구조체의 메모리를 할당할때의 Struct Member Alignment 의 기준이 8바이트로 (4바이트면 이해가 가겠는데) , X64에서의 워드에 맞추기위해 패딩이 들어간다는것을 고려할때 이해가 되지않는데요 , 왜그런지 알 수 있을까요?

        https://stackoverflow.com/questions/4306186/structure-padding-and-packing
        글을 참고하시면 될 것 같습니다. padding rule에 대한 내용입니다.

        struct에 대한 rule에서 가장 큰 individual member에 의해서 정해진다고 합니다.
        mommy의 경우는 int or float이 가장 큰 member이므로 4byte가 기준이 됩니다.
        member 중 하나를 double로 바꿔보세요.

    */
    struct Person f[4];

    printf("Sizeof a structure array %zd\n", sizeof(f));
    /*
     | f[0].name        | f[0].age | f[0].height |... ... | f[3].name        | f[3].age | f[3].height |
    */

    // c/c++ all options - struct member alignment default 이걸 1바이트로 바꾼다면? 패딩을 끈 결과가 나옴
    return 0;
}
