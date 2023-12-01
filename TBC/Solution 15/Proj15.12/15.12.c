/* 메모리 줄맞춤 alignof, alignas */
/* https://www.onlinegdb.com/online_c_compiler code가 VS에서는 실행이 안된다. */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdalign.h> // c++ style alignas, alignof 원랜 _Alignof 이거지만 stadalign.h를 포함시키면 alignof 가능

int main()
{
    /* 지금 사용하는 컴파일러가 clang인지 gcc인지 구분하는 코드 */
#ifdef __clang_major__
    printf("clang detected version %d.%d\n", __clang_major__, __clang_minor__);
#endif

#ifdef __GNUC__
    // note that clang 3.7 declares itself as a gcc 4.2"
    printf("gcc deteceted version %d.%d\n", __GNUC__, __GNUC_MINOR__);
#endif

    printf("Alignment of char = %zu\n", alignof(char)); // 1bytes, alignof align을 몇 바이트 간격으로 해줘야 하는가를 알려줌
    printf("alignof(float[10]) = %zu\n", alignof(float[10])); // 4bytes
    printf("alignof(struct{char c; int n;}) = %zu\n",
        alignof(struct { char c; int n; })); // 4bytes

    double dx;
    char ca;
    char cx;
    double dz;
    char cb;
    //char _Alignas(double) cz; // 이걸 실행하면 &cz % 8은 0이 나온다. alignas align하는 방법을 바꿔줌
    //char alignas(16) cz;
    char cz;

    /*printf("char alignment: %zd\n", _Alignof(char));
    printf("double alignment: %zd\n", _Alignof(double));*/
    printf("char alignment: %zd\n", alignof(char));
    printf("double alignment: %zd\n", alignof(double));

    printf("&dx: %p %lld\n", &dx, (long long)&dx % 8); // 8의 배수 주솟값이 alignment에 맞춰서 되고 있다.
    printf("&ca: %p %lld\n", &ca, (long long)&ca % 8);
    printf("&cx: %p %lld\n", &cx, (long long)&cx % 8);
    printf("&dz: %p %lld\n", &dz, (long long)&dz % 8); // 8의 배수 위와 마찬가지
    printf("&cb: %p %lld\n", &cb, (long long)&cb % 8);
    printf("&cz: %p %lld\n", &cz, (long long)&cz % 8);

    unsigned char alignas(long double) c_arr[sizeof(long double)]; // 배열을 만들 때도 alilgn을 사용할 수가 있다.



    return 0;
}
