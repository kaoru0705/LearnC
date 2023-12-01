/* 중요한 프로젝트는 책꽂이를 해라*/
/* 메모리 레이아웃(Memory Layout)과 문자열 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc

/* 문자열을 초기화하는 방법 char arr[] = "Hello, World"; char* str = "Hello, World"; 은 문법적으로 다르다. 단순하게 문법으로 외우는 게 아니라
컴퓨터 작동원리와 밀접한 layout(설계도 전체구조)을 알아보자 */

/*사진 참조*/
/* 명령줄 인수(한참뒤에 나옴) 환경 변수들(프로그램이 실행되는 환경에 대한 설정들이 담겨있는 변수 OS와 밀접)

- 주소가 높다 낮다는 GCC 기준이다.(visual studio 에선 좀다름, 학문용은 gcc가 적합) 메모리를 규칙에 맞춰서 효율적으로 안정적으로 사용하기 위해

- Stack: 컴파일러가 메모리의 크기를 미리 예측할 수 있는 경우 사용 stack memory는 memory를 운영체제로부터 받아올 때 속도가 빠름 컴파일러가 미리 준비할 수 있기 때문 
지역변수, 매개변수(함수 호출시 임시 변수저장) (크기가 가변적 주소공간에서 내려감) - FILO or LIFO 구조
운영체제가 프로그램을 실행 시킬 때 스택메모리는 스택을 더 많이 사용해야 되는 경우에는 쌓임

- Heap: 컴파일타임에 크기를 알 수 없는 메모리(프로그래머가 직접 접근가능 메모리->동적할당) (주소공간에서 올라감)

자유 공간: Stack, Heap이 늘어났다 줄어들었다.

- BSS Segment: 초기화 되지 않은 전역, 정적 변수들 (크기 고정)
프로그래머가 초기화하지 않은 얘네들은 0으로 초기화

- Data Segment: 초기화된 전역변수와 정적 변수가 저장된다. (크기 고정)
변수들이 어떤 값으로 초기화 될지 미리 알고 있다. 컴파일 할 때 결정돼 있다.
초기화됐다?: 프로그램을 작성하는 단계에서 이 변수들은 프로그램 전체에서 많이 사용될 때 전역변수, 지역적으로 사용되더라도 프로그램이 작동하는 동안 메모리가 반복적으로 사용될 때 정적변수
The values for these variables are initially stored within the read-only memory (typically within the code segment) and are copied into the data segment during the start-up routine of the program.

- Text Segment = Code Segment : 프로그램 코드
The .rodata section is usually merged with .text section and put into the executable segment.
The code segment in memory is typically read-only and has a fixed size, so on embedded systems it can usually be placed in read-only memory (ROM)
하드디스크에 있던 프로그램은 실행될 때 메모리에 옮겨가고 cpu가 읽는다.
우리가 작성한 코드를 컴파일해서 만든 exe파일은 크기가 변하지 않는다.
프로그램코드가 메모리에 올라와있을 때 메모리의 값은 마음대로 바꿀 수 없다. 운영체제가 읽기 전용으로 막음
물론 나중엔 마치 프로그램 코드가 그때 그때 변하는 것처럼 하는 기법을 배움

프로그램 파일에서 메모리로 읽어들이는 부분 : DATA, TEXT Segment

char arr[] = "Hello, World"; 한 글자 한 글자 arr:배열의 인식자가 대표하는 공간으로 복사해서 넣는다.  arr자체가 메모리를 갖고 있다. 얼마든지 값을 바꿀 수 있음
arr이 전역변수면 data segment로 지역변수면 stack으로 간다.

char* str = "Hello, World"; 주소를 가리키기만하고 string literal이 저장되어 있는 메모리 공간을 어떻게 할 권한은 없다.
"Hello, World"는 Read only DATA Segment(text segment)로 들어감 문자열 리터럴은 컴파일 타임에 결정되어 있기 때문에
//str[0] = 'M'; // ERROR! 읽기전용이라 운영체제가 막아버림

https://en.wikipedia.org/wiki/Data_segment#rodata 이걸보면 data segment랑 rodata를 따로 둔다.

왜 BSS Data Segment로 나눌까?
gcc로 보면 어디에 할당되는지 알기 쉬운 것 같다.
https://blog.naver.com/techref/222270185816 정확히는 이걸 봐라 교수님도 모든 컴퓨터분야를 다 아는 것은 아니다. 검색해라 제발
Data segment 는 컴파일 할 때 몇으로 초기화 할지 미리 알고 있다 프로그램이 시작될 때 프로그래머가 해논 값으로 쫘악 초기화
초기화 되지 않은 BSS는 0으로 초기화

Data 세그먼트와 BSS 세그먼트가 구분되는 이유는 메모리 공간을 효율적으로 사용하기 위함이다. 세그먼트에 따라 RAM과 ROM(or flash) 메모리 중 어느 위치에 저장되는 것이 효율적인지 알아보자
텍스트 세그먼트는 일반적으로 변하지 않는 명령어(Instruction)이므로, 시스템 상태에 관계없이 유지될 수 있도록 ROM 메모리에 저장한다. ROM에 직접 접근하여 데이터를 읽어오거나, 필요한 메모리공간을 RAM으로 복사하여 사용한다
데이터 세그먼트는 '초기값을 가지고 있는' 데이터이므로 원본을 ROM 메모리에 저장하되, '변수'로서 사용하기 위해서 프로그램 실행과 함께 RAM 메모리로 불러와 사용하는 것이 효율적이다
BSS 세그먼트는 '초기값을 가지고 있지 않아', 0의 값으로 초기화 될 변수들이므로 굳이 ROM에 저장하지 않아도 된다. 프로그램을 수행하면서 0으로 초기화하여 RAM 메모리로 불러와 사용한다

A computer program memory can be largely categorized into two sections: read-only and read/write.
data segment랑 rodata는 완전 다른 거다. 헷갈리지 마라. 이미 헷갈렸다. 

segment를 확인하기 위해 온라인컴파일러(https://www.tutorialspoint.com/compile_c_online.php) 를 이용해 아래를 짜보자


초기화 된 const는 rodata로 할당된다. 변경될 수 없기때문 https://stackoverflow.com/questions/10818761/gcc-why-constant-variables-not-placed-in-rodata


*/

void test_function()
{
    int j; // stack 변수
    printf("Stack high \t%llu\n", (unsigned long long) & j);
}

int main()
{
 //   // in x64
 //   /* Array versus Pointer */
    char* pt2 = "I am a string!.";  // 포인터는 컴파일 타임에 확정된 우측의 문자열(rodata segment에 저장된다)을 가리키고 있을 뿐이다
    const char* pt3 = "I am a string!.";  // 컴파일러가 프로그램의 크기를 줄이고 메모리를 절약하기 위해 중복되는 문자열은 하나로 저장한다(= pt2, pt3의 값이 같다)
    const char* pt4 = "I am a string!!!!!!!.";  // 윗줄의 문자열과 다르기에 따로 저장한다
    const char ar1[] = "I am a string!.";  // 내용물은 아래와 같지만 서로 다른 메모리 공간에 사본을 저장하고 있다
    const char ar2[] = "I am a string!.";  // // 내용물은 위와 같지만 서로 다른 메모리 공간에 사본을 저장하고 있다
    const char ar3[] = "I am a string!!.";

 ////   /*rodata low      140699679633448 140699679633448 140699679633472 140699679633448
 ////     Stack high      4447205528 4447205576 4447205624 어라라 stack이 더 낮은 값이네 윈도우 컴파일은 좀 다르다
 ////     https://www.onlinegdb.com/online_c_compiler 이걸로 해 봐라
 ////   */

 //   printf("rodata low \t%llu %llu %llu %llu\n",
 //       (unsigned long long)pt2, (unsigned long long)pt3, (unsigned long long)pt4,
 //       (unsigned long long)"I am a string!."); // 문자열을 주소처럼 사용
 //   // 컴파일러가 pt2 pt3 pt4가 완전 동일한 문자열이니까 한곳에 저장해놓고 여러번 사용한다(프로그램의 크기를 줄임) 만약에 pt2[0] = 'H'가 가능하면 다 바뀌잖아 개지랄이다.
 //   // 문자열 "I am a string!."은 메모리의 rodata(Text segment)에 프로그램의 일부로서 저장되어 있다.  프로그램 실행을 위해 메모리에 올라갈 때(로딩 시) 함께 올라간다

 //   printf("Stack high \t%llu %llu %llu\n", (unsigned long long)ar1,
 //       (unsigned long long)ar2, (unsigned long long)ar3);  // check address numbers!
 //   //배열이 각각 메모리를 갖고 복사한 거니 다르다.

 //   /* Memory address check */

 //   /* Local variables */
 //   printf("Stack high \t%llu %llu %llu\n", (unsigned long long) & pt2,
 //       (unsigned long long) & pt3, (unsigned long long) & pt4);  // 지역변수(pt2)는 stack에 위치한다

 //   int i;
 //   printf("Stack high \t%llu\n", (unsigned long long) & i);

 //   /* Local variable in a function */
 //   test_function();

 //   //layout에 맞춰서 메모리주소가 나눠져 있다.

 //   /* Dynamic allocation */
 //   char* p5 = (char*)malloc(sizeof(char) * 100);
 //   printf("Heap middle \t%llu\n", (unsigned long long)p5);

 //   char* p6 = (char*)malloc(sizeof(char) * 100);
 //   printf("Heap middle \t%llu\n", (unsigned long long)p6);

    /* Array Versus Pointer(continued) */

    //ar1++;    // Error 배열의 이름으로 증감연산? 못 한다
    pt2++;       // OK
    puts(pt2);   // Check the first character

    /* Array and Pointer Differences */

    char heart[] = "I love Kelly!";  // 문자열을 배열로 정의
    const char* head = "I love Helly!";  // 문자열을 포인터로 정의

    for (int i = 0; i < 6; i++)
        putchar(heart[i]);        // Note: putchar()(아스키코드를 인수로 받아서 화면에 문자로 출력한다)
    putchar('\n');

    for (int i = 0; i < 6; i++)
        putchar(head[i]);        // Note: putchar()(아스키코드를 인수로 받아서 화면에 문자로 출력한다)
    putchar('\n');

    // pointer addition
    for (int i = 0; i < 6; i++)
        putchar(*(heart + i));        // Note: putchar()(아스키코드를 인수로 받아서 화면에 문자로 출력한다)
    putchar('\n');

    for (int i = 0; i < 6; i++)
        putchar(*(head + i));        // Note: putchar()(아스키코드를 인수로 받아서 화면에 문자로 출력한다)
    putchar('\n');

    while (*(head) != '\0')  // 문자열의 끝까지 출력하기
        putchar(*(head++));
    putchar('\n');

    head = heart;
    //heart = head;  // Error 배열의 이름은 주소를 저장할 수 있는 데이터공간이 아니다 배열자체는 heart 자체는 1차원 메모리공간을 갖는다.

    // Cannot change heart. Can change the elements of heart
    heart[7] = 'F';  // Note: character
    *(heart + 7) = 'K';

    puts(heart);

    // 포인터가 text segment에 있는 문자열을 가리키고 있기에 문자열에 접근해서 수정(해킹)하려고 하면 운영체제가 막는다
    char* word = "Goggle";
    //word[2] = 'o';  // Run-time error! // 프로그램이 만들어질때 readonlydata(text) segment 이미 들어있으므로 변경 불가
    puts(word);

    //Note: const char * word = "Goggle"; const is recommended 어차피 못 바꾸므로 넣어서 컴파일타임에 방지시키기

    const char* str1 = "When all the lights are low, ...";
    const char* copy;

    copy = str1;  // 내용물을 통째로 복사하는 게 아니라 data segment에 있는 문자열의 주소만 옮기고 있다

    printf("%s %p %p\n", str1, str1, &str1);
    printf("%s %p %p\n", copy, copy, &copy); // 포인터 변수 자체는 스택에 ㅇㅇ

    // Note: strcpy(), strncpy() 문자열 한글자 한글자 복사하는 것처럼

    return 0;
}