/* 중요한 프로젝트는 책꽂이를 해라*/
/* 문자열을 입력 받는 다양한 방법들 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

char* custom_string_input(char* st, int n);

int main()
{
    /* Creating Space */ //입력받은 문자열을 저장할 메모리 공간을 확보한 다음에 입력받아야 한다

    //char* name = "";  // Error at RUN-TIME
    //char name[128];
    //int result = scanf("%s", name); //(%s, pointer)

    /*
        scanf() vs gets()
        scanf() reads one word
        gets() reads one line and removes \n and add \0
    */

    
    //char words[STRLEN] = "";             // Warning without initialization
    ////gets(words);                         // gets(char * str) receives pointer. No idea when string ends(시작점만 알고 끝을 알지 못한다) 포인터 하나를 받는 함수의 공통적인 문제 메모리 첫주소만 알고 끝을 모름 warning
    //gets_s(words, sizeof(words));      // C11(가능하면 gets() 대신 이 함수 사용하기)
    ////int result = scanf("%s", words);
    //printf("START\n");
    //printf("%s", words);                 // No \n at the end
    //puts(words);                         // puts() adds \n at the end 자동으로 줄바꿈
    //puts("END.");

     
     //TODO: try char words[5];  // gets(), gets_s() 함수를 사용해서 "Hello World" 입력시 런타임 에러 발생

     /* fgets() and fputs() */
     // fgets() 함수는 파일 입출력을 받는 함수여서 세 번째 인수에 파일의 포인터를 받는다(단, stdin을 입력하면 콘솔 입력도 받을 수 있다)
     // 읽어들이는 데이터가 언제 끝날지 모른다는 것을 미리 염두에 두고 받아들이기에 크기 넘어가는 입력 시에도 런타임 에러 발생하지 않는다(gets() 함수보다 안전)

    //char words[STRLEN] = "";
    //fgets(words, STRLEN, stdin);  // does NOT remove \n(파일입출력에서는 입력받는 파일의 내용을 곧이곧대로 받아들여야 하기에 좋은 성질 허나 stdin(macro)로 콘솔 입력을 받을 땐 번거로울 수 있다.)

    ////////TODO: replace '\n' with '\0'(fgets() 함수로 입력받으면 개행문자가 포함되어 있기에 이를 없애주는 로직 만들어보기)
    //int i = 0;
    //while (words[i] != '\n' && words[i] != '\0')
    //    i++;
    //if (words[i] == '\n')
    //    words[i] = '\0';

    //fputs(words, stdout);  // does NOT add \n 파일은 필요한 데이터만 저장해야되기 때문에 /n는 없다.
    //fputs("END", stdout);

    /* Small array */

    //char small_array[5];
    //puts("Enter long strings:");
    ////fgets(small_array, 5, stdin);  // FILE * _Stream. 문자열의 마지막 '\0'을 포함해서 5개의 문자를 입력받는다
    //printf("%p\n", small_array);
    //printf("%p\n", fgets(small_array, 5, stdin));  // Return value of fgets() (정상적으로 입력받았다면 입력값을 저장하는 포인터를 그대로 반환. EOF를 만났다면 '\0' 반환. EOF를 콘솔 입력에서 표현하려면 ctrl+z키 이용)
    //fputs(small_array, stdout);

    /* Repeating short reading */ //네트워킹 할 때는 작은 버퍼를 여러 번 재활용하면서 큰 내용을 받아들인다. 긴 문자열을 한 번에 입력받아서 한 번에 출력하는 것처럼 사용할 수 있다(버퍼를 사용하기에)
    //char small_array[5];
    //puts("Enter long strings:");
    //while (fgets(small_array, 5, stdin) != NULL && small_array[0] != '\n')
    //    fputs(small_array, stdout);
    //    //puts(small_array);  //What if we use puts()

    /* scanf() */
    //char str1[6], str2[6];
    //int count = scanf("%5s %5s", str1, str2); // 5글자만 입력받게 함
    ////int count = scanf("%6s %6s", str1, str2);  // run-time error
    ////int count = scanf_s("%5s %5s", str1, 6, str2, 6); // string pointer, 가장 큰 사이즈
    //printf("%s|%s \n", str1, str2);

    ///* As an example of custom input function */
    char word[11];
    puts(custom_string_input(word, 11));

    return 0;
}

char* custom_string_input(char* st, int n)  // 다른 언어를 공부하면 굳이 안 만들어도 라이브러리에 있을 수도 있다.
{
    char* ret_ptr;
    int i = 0;

    ret_ptr = fgets(st, n, stdin);
    if (ret_ptr) // ret_ptr != '\0'== 0
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')  // clear buffer
                continue;
    }
    return ret_ptr;
}