/* 중요한 프로젝트는 책꽂이를 해라*/
/* 문자열의 배열 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    /* Arrays of Character Strings */

    const char* mythings[5] = { //포인터의 배열 debug해서 메모리를 보면 덕지덕지 붙어 있다. 완전히 붙어있진 않지만
        "Dancing in the rain",  // 메모리 상에 한 카피만 존재한다 in 11.2 메모리를 아낀다는 측면이 있다 값은 못 바꾸지만
        "Counting apples",
        "Watching movies with friends",
        "Writing sad letters",
        "Studying the C language"
    };

    char yourthings[5][40] = {
        "Studying the C++ language",  // rodata(text) segment로서 프로그램에 저장되어 있다가 그 사본을 이 배열에 저장한다(메모리 상에 원본, 사본 두 카피가 존재하게 된다)
        "Eating", // in debug mode 마우스 갖다대고 화살표 누르면 글자 수 알 수 있다.
        "Watching Netflix",
        "Walking around till dark",
        "Deleting spam emails"
    };

    /*
    * ...은 40글자라 그렇다 처음 00은 null character 나머지는 컴파일러가 넣어줌
    0x00FAFC2C  53 74 75 64 79 69 6e 67 20 74 68 65 20 43 2b 2b 20 6c  Studying the C++ l
    0x00FAFC3E  61 6e 67 75 61 67 65 00 00 00 00 00 00 00 00 00 00 00  anguage........... 
    0x00FAFC50  00 00 00 00 45 61 74 69 6e 67 00 00 00 00 00 00 00 00  ....Eating........
    */

    const char* temp1 = "Dancing in the rain";
    const char* temp2 = "Studying the C++ language";

    printf("%s %u %u\n", mythings[0], (unsigned)mythings[0], (unsigned)temp1); //pointing만 되어있으니 같음
    printf("%s %u %u\n", yourthings[0], (unsigned)yourthings[0], (unsigned)temp2); // 복사해서 저장하니 다름
    //printf("%u %u\n", (unsigned)&yourthings[0][0], (unsigned)temp2);
    printf("\n");

    printf("%-30s %-30s\n", "My Things:", "Your Things:");  //format specifier는 찾아가면서 써라 너무 많다. 못 외움
    for (int i = 0; i < 5; i++)
        printf("%-30s %-30s\n", mythings[i], yourthings[i]);

    printf("\nsizeof mythings: %zd sizeof yourthings: %zd\n",
        sizeof(mythings), sizeof(yourthings)); // pointer 5개, 전체 메모리공간 크기

    for (int i = 0; i < 100; i++)
        printf("%c", mythings[0][i]);
    printf("\n");
    printf("\n");

    for (int i = 0; i < 200; i++)
        printf("%d", (int)yourthings[0][i]); //사이 사이에 null 있다
    printf("\n");

    for (int i = 0; i < 200; i++)
        printf("%c", yourthings[0][i]);
    printf("\n");
    printf("\n");

    // 메모리에 있는 걸 쭉 출력함
    // Not a good idea to take advantage of this property(메모리에 있는 것들을 쭉 출력하는 방식이기에 작동은 하지만 배열의 크기를 넘어가는 방식이므로 권장하지는 않는다. C언어의 철학)

    return 0;
}