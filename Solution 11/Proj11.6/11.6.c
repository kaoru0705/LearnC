/* 중요한 프로젝트는 책꽂이를 해라*/
/* 다양한 문자열 함수들 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void fit_str(char*, unsigned int);
char* my_strcat(char*, const char*);
int my_strcmp(char*, char*);

int main()
{
    /* strlen() : returns length of the string */

    // TODO: use debugger
    /*char msg[] = "Just,"" do it!";
    puts(msg);
    printf("Length %d\n", strlen(msg));
    fit_str(msg, 4);
    puts(msg);
    printf("Length %d\n", strlen(msg));*/

    // TODO: implement fit_str() function

    /* strcat() and strncat() : string concatenation(연결 연쇄 연속) 프로그래밍에서 cat은 보통 이 뜻이다.  str'n'cat() number 개수 제한*/

    //char str1[100] = "First string";
    //char str2[] = "Second string";

    //strcat(str1, ", ");
    //strcat(str1, str2);
    ////strncat(str1, str2, 2);  // Append 2 characters warning: str1이 전부 null로 초기화되어있지 않다. 허나 이건 밑줄은 visual studio의 예측임
    //puts(str1);
    

    // TODO: implement strcat() function! google검색 

   /* char str1[100] = "First string";
    char str2[] = "Second string";

    puts(my_strcat(str1, str2));*/

    /* strcmp() and strncmp() : compare strings (not characters (글자끼리 비교하는 게 아님 그럴거면 비교연산자) */
    // 반환값: 서로 같으면 0, 앞에 있는 문자열이 아스키 코드 기준으로 더 작은 수라면 -1, 더 큰 수라면 1

    //printf("%d\n", strcmp("A", "A"));  // 반환값: 0
    //printf("%d\n", strcmp("A", "B"));  // 반환값: -1
    //printf("%d\n", strcmp("B", "A"));  // 반환값: 1
    //printf("%d\n", strcmp("Hello", "Hello"));  // 반환값: 0
    //printf("%d\n", strcmp("Banana", "Bananas"));  // 반환값: -1
    //printf("%d\n", strcmp("Bananas", "Banana"));  // 반환값: 1
    //printf("%d\n", strncmp("Bananas", "Banana", 6));  // 반환값: 0

    // TODO: implement strcmp!
    /*printf("%d\n", my_strcmp("Bananas", "Banana"));*/

    /*
    strcpy() and strncpy() : 메모리를 복사할 때 문자열 복사를 이용하는 방법도 있는데 그 때 이 함수들이 사용될 수 있다
    네트워크 주의) 메모리를 자체를 복사하는 다른 용도로도 종종 사용되기 때문에 null을 따로 넣어주지 않는다.
    */

    //char dest[100] = "";  // make sure memory is enough
    //char source[] = "Start programming!";
    ////dest = source;  // Error
    ////dest = "Start programming!";  // Error
    //strcpy(dest, source);   // Destination(목적지), Source(원천 원본) 우리가 자주 보게 될 용어
    //strncpy(dest, source, 5);  // '\0' is NOT added(이 줄과 바로 윗줄만 실행시키면 비정상 작동 Start programming!이 전부 출력됨. null character 없이 'S','t','a','r','t' 이 다섯 글자만 복사되기에 끝을 알 수 없다) 이 줄만 실행 시키면 Start만 뽑힌다. dest에 null이 이미 들어있기 때문
    ////strcpy(dest, source + 6);
    ////strcpy(dest, source);
    ////strcpy(dest + 6, "coding!");  // 출력값: Start Coding!(strcpy() 함수는 dest에 계속 덮어쓰는 방식이기 때문)
    //puts(dest);

    /* sprintf() capture00000.png, capture00001.png, ... 연속되는 파일을 출력할 때 파일이름을 프로그램에서 자동으로 생성해줘야 할 때 사용*/

    //char str[100] = "";
    //int i = 123;
    //double d = 3.14;
    //sprintf(str, "%05d.png %f", i, d); // printf를 문자열에 해준다.
    //puts(str);

    /* There are more functions ... */

    printf("%s\n", strchr("Hello, World", 'W')); // 해당 글자로 시작되는 포인터를 리턴

    printf("%s\n", strpbrk("Hello, World", "ABCDE")); // 해당글자중 시작되는 부분을 찾음 없으면 널
    printf("%s\n", strpbrk("Hello, World", "abcde"));

    printf("%s\n", strrchr("Hello, World, Hello, World", 'l'));  // last occurrence(이 글자가 나타나는 마지막 포인터를 리턴)

    printf("%s\n", strstr("Hello, World", "wor")); //문자열끼리 비교 없으면 널
    printf("%s\n", strstr("Hello, World", "Wor"));

    return 0;
}
/* my poor answer */
//void fit_str(char* starray, unsigned int chsize)
//{
//    *(starray + chsize) = '\0';
//}
//void my_strcat(char* firstchar, const char* secondchar)
//{
//    unsigned int firstsize = strlen(firstchar), i, j = 0;
//
//    for (i = firstsize; i < firstsize + strlen(secondchar); i++)
//    {
//        firstchar[i] = secondchar[j];
//        j++;
//    }
//    firstchar[i] = '\0';
//}
//int my_strcmp(char* firstcmp, char* secondcmp)
//{
//    int flag = 0;
//    unsigned int count = 0;
//
//    while (firstcmp[count] >= 0)
//    {
//        if (firstcmp[count] > secondcmp[count])
//        {
//            flag = 1;
//            return flag;
//        }
//        else if (firstcmp[count] < secondcmp[count])
//        {
//            flag = -1;
//            return flag;
//        }
//        else
//        {
//            count++;
//            continue;
//        }
//    }
//
//    return flag;
//}

void fit_str(char* str, unsigned int size)
{
    if (strlen(str) > size)  // 문자열 사용 시 할당된 메모리 공간을 확인하는 절차가 중요하다
        str[size] = '\0';
}
char* my_strcat(char* destination, const char* source) //legend
{
    char* ptr = destination + strlen(destination);

    while (*source != '\0')
        *ptr++ = *source++;

    *ptr = '\0';

    return destination;
}