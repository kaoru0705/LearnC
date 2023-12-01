/* 중요한 프로젝트는 책꽂이를 해라*/
/* 문자열을 출력하는 다양한 방법들 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define TEST "A string from #define."

/*
    puts() which doesn't add a new line at the end
    Use pointer increment operator and putchar()
*/

void custom_put(const char* str);  // Only two lines
int custom_put2(const char* str);  // Add \n, return # of characters

int main()
{
    /* puts() : add \n at the end */

    //char str[60] = "String array initialized";
    //const char* ptr = "A pointer initialized";

    //puts("String without \\n");
    //puts("END");
    //puts("TEST");
    //puts(TEST + 5);
    //puts(&str[3]);
    ////puts(str[3]); // Error
    //puts(ptr + 3);

    /* string without \0 */

    //char str1[] = { 'H', 'I', '!' };  // No \0 at the end 문자열을 문자마냥 초기화
    //puts(str1);  // VS warns you!(메모리에 우연히 존재하는 null character를 만날 때까지 계속 출력한다)

    /* puts() and fputs() */

    //char line[100];
    //while(gets(line))  // while(gets(line) != NULL) //gets도 마찬가지로 EOF 입력 시 null반환 참고로 null키는 없다.
    //    puts(line);

    //char line[100];
    //while (fgets(line, 100, stdin)) //fgets는 받아들이는 것이기 때문에 끝을 모르는 위험성도 있다.
    //    fputs(line, stdout);

    /* printf() */

    //char str2[] = "Just do it, do it!";
    //printf("%s\n", str2);  // \n added
    //puts(str2);

    //char input[100] = "";
    //int ret = scanf("%10s", input);  // Input: "Just do it, do it!\n" (Note %10s)
    //printf("%s\n", input);  // Output: "Just"(scanf() 함수는 빈 칸을 만나면 더 이상 입력을 받지 않기 때문. 즉, 하나의 단어를 입력받는 함수다. scanf() 함수는 여러 자료형이 섞여 있을 때 입력받기 편하다)
    //ret = scanf("%10s", input);  // Reads remaining buffer
    //printf("%s\n", input);  // Output: "do"

    /* Custom Function */

    custom_put("Just ");
    custom_put("Do it!");

    printf("%d\n", custom_put2("12345"));


    return 0;
}

void custom_put(const char* str)
{
    while (*str != '\0')  // while(*str): 과거에는 이렇게 축약형으로 적었으나 최근에는 보다 명시적으로 적는다
        putchar(*str++); // ++ > *
}

int custom_put2(const char* str)
{
    int count = 0;
    while (*str)
    {
        putchar(*str++);
        count++;
    }
    putchar('\n');

    return count;
}