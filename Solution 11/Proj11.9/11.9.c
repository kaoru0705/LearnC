/* 중요한 프로젝트는 책꽂이를 해라*/
/* ctype.h 문자 함수를 문자열에 사용하기 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>  // toupper(), ispunct() ...

#define NUM_LIMIT 1024

void ToUpper(char*);
int PunctCount(const char*);

int main() {
    char line[NUM_LIMIT];
    char* new_line = NULL;
    fgets(line, NUM_LIMIT, stdin);
    new_line = strchr(line, '\n');  // find first newline 11.6 for 문으로 할 걸 간단히 해결
    if (new_line)
        *new_line = '\0';

    ToUpper(line);
    puts(line);
    printf("%d\n", PunctCount(line));

    return 0;
}

void ToUpper(char* str) {  // C에서 char* 타입을 매개변수로 사용하는 대부분의 경우는 문자에 대한 포인터로 받기보단 문자열을 받기 위한 것이다
    //while(*str){
    //    if(*str >= 'a' && *str <= 'z')
    //        *str -= 32;
    //    str++;
    //}

    while (*str) {  // null character 를 만나면 반복문이 중지된다
        *str = toupper(*str);
        // 소문자인지 확인하는 로직은 toupper() 함수 안에 이미 구현되어 있기에 생략 가능하다(단, 성능이 매우 중요한 프로그램에서는 이 정도 수준에서도 최적화를 고민해야 한다)
        // if(islower(*str))
        //     *str = toupper(*str);
        str++;
    }
}

int PunctCount(const char* str) {
    int ct = 0;
    while (*str) {
        if (ispunct(*str))
            ct++;
        str++;
    }

    return ct;
}