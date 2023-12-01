/* 중요한 프로젝트는 책꽂이를 해라*/
/* 문자열을 숫자로 바꾸는 방법 Command-Line Arguments 실제 예시 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//exe파일을 직접 실행시킬 필요가 있을까? c나 c++로 만든 실행파일을 다른 scripting언어를 이용해서 반복해서 실행시킬 수 있다. ex) python
// 프롬프트창 안 열고 property - debugging - command argument에 3 hello 입력하고 실행해도 됨

int main(int argc, char* argv[])
{
    /*
      string to integer, double, long
      atoi(), atof(), atol()
    */

    //if (argc < 3)
    //    printf("Wrong usage of %s\n", argv[0]);  // 실행파일 이름은 항상 첫 번째 인수로 전달된다
    //else
    //{
    //    /* Example 1 */
    //    //int times = atoi(argv[1]);
    //    ////atof(), atol()

    //    //for (int i = 0; i < times; i++)
    //    //    puts(argv[2]);

    //    /* Example 2 */
    //    printf("Sum = %d\n", atoi(argv[1]) + atoi(argv[2]));

    //}

    /*
     // atoi() 함수는 10진수만 변환 가능한 반면 strtol(), strtoul() 함수는 8, 16진수도 변환 가능하다
     string to long, unsigned long, double
     strtol(), strtoul(), strtod()

     strtod() converts base 10 only 10진수만 가능해서 비슷
    */

    //char str1[] = "-1024Hello";
    //char* end;
    //long l = strtol(str1, &end, 10); // 끝을 표현하는 문자 포인터를 넣어줌 이중포인터 10진수로 바꿀 수 없는 H 포인터를 넣어줌
    //printf("%s %ld %s %d\n", str1, l, end, (int)*end);

    //char str2[] = "10FFHello";
    //l = strtol(str2, &end, 16); // 0x10FF = 4351
    //printf("%s %ld %s %d\n", str2, l, end, (int)*end);

    /*
     Numbers to strings
     Use sprintf() instead of itoa() and ftoa()
    */

    char temp[100];
    puts(_itoa(10, temp, 16));  // itoa 표준에서 이름이 바뀜 숫자, 10을 16진수로 변환 후 문자열로 저장(이 함수는 itoa ftoa 표준이 아니기에 사용을 권장하지는 않는다)

    sprintf(temp, "%x", 10);    // 11.6 참조 이걸 더 많이 씀
    puts(temp);

    return 0;
}
