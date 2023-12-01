/* 중요한 프로젝트는 책꽂이를 해라*/
/* 문자열(Strings)을 정의하는 방법 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MESSAGE "A symbolic string constant"  // 문자열도 기호적 상수로 선언 가능
#define MAXLENGTH 81

int main() {
    char words[MAXLENGTH] = "A string in an array";  // 매번 문자 배열의 정확한 크기를 알기는 힘들기 때문에 넉넉하게 선언한다
    const char* pt1 = "A pointer to a string";  // 윗줄의 배열은 자기가 갖고 있는 메모리 공간maxlength*char에 문자열을 저장하고 있는 데 반해 이 포인터는 어떤 메모리 공간에 있는 문자열의 첫 번째 주소를 가리키고 있을 뿐이다

    puts("Puts() adds a newline at the end:");  // puts(const char *_Buffer) add \n at the end 문자열도 배열의 일종으로 첫 번째 주소를 포인터로 넘길 수 있다.
    puts(MESSAGE);
    puts(words);  // warning(배열의 일부만 초기화했기 때문) Using uninitialized memory null포함 21글자만 초기화해서
    puts(pt1);
    words[3] = 'p';  // OK(배열이기 때문에 배열의 원소에 접근하는 방식으로 문자열의 일부를 바꿀 수 있다)
    puts(words);    //null를 찾을 때까지 쭉 읽는다.
    //pt1[8] = 'A';  // Error(접근하면 안 되는 곳을 접근하고 있기 때문. 윗쪽에서 선언할 때 const를 제거하면 컴파일은 되지만 런타임 에러 발생. 따라서 실수를 방지하기 위해 const를 붙여서 컴파일 자체가 안 되도록 만드는 게 좋다)
    // [예습] 읽기 전용 메모리에 저장된 데이터의 값을 바꾸려고 시도하면 운영체제가 중단시킵니다. 
    //  배열은 읽기/쓰기가 모두 가능한 메모리를 사용합니다.
    // 문자열 리터럴은 프로그램의 일부이기 때문에 읽기 전용 메모리에 저장되어 있습니다.

    //char greeting[50] = "Hello, and How are you today!";
    char greeting[50] = "Hello, and"" How are" " you"
        " today!";  // 따옴표를 나눠서 문자열을 만들 수도 있다(윗줄과 동일)

    printf("\" To be, or not to be\" Hamlet said.\n");  // 큰따옴표를 출력하는 방식

    printf("%s, %p, %c\n", "We", "are", *"excellent programmers");
    // 문자열을 배열에 넣어서 초기화할 수 있다면 "are"의 주소는 첫 글자가 저장된 주소 %s

    const char m1[15] = "Love you!";

    for (int i = 0; i < 15; ++i)
        printf("%d ", (int)m1[i]);  // Note the null characters(배열의 초기화되지 않고 남은 부분을 컴파일러가 null character로 초기화해주기도 한다)
    printf("\n");

    const char m2[15] = { 'L', 'o', 'v', 'e', ' ', 'y', 'o', 'u', '!', '\0' };  // 문자의 배열(문자열로 만드려면 수동으로 null character를 추가해야 한다 null character를 빼도 컴파일러가 알아서 초기화 해준다.)

    for (int i = 0; i < 15; ++i)
        printf("%d ", (int)m2[i]);
    printf("\n");

    const char m3[] = "Love you, too!";  // 배열 크기를 컴파일러가 세도록 선언하는 방식. 컴파일러가 맨 끝에 null character를 자동으로 추가해준다

    int n = 8;
    char cookies[1] = { 'A', }; // 배열의 길이에 대해서는 unsigned integer
    char cakes[2 + 5] = { 'A', };
    char pies[2 * sizeof(long double) + 1] = { 'A', };  // sizeof도 괜찮다 실제로 종종 쓰임 허나 실수가 들어가면 안 된다.
    //char crumbs[n];  // VLA  in 10.17

    char truth[10] = "Truth is ";
    if (truth == &truth[0]) puts("true!");
    if (*truth == 'T') puts("true!");
    if (*(truth + 1) == truth[1]) puts("true!");
    if (truth[1] == 'r') puts("true!");

    return 0;
}