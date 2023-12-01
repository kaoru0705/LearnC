/* 구조체의 배열 연습문제 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_TITLE 40   // 최대 39글자 + null character
#define MAX_AUTHOR 40  // 최대 39글자 + null character
#define MAX_BOOKS 3 /* maximum number of books */

char* s_gets(char* st, int n)
{
    char* ret_val;
    char* find;

    ret_val = fgets(st, n, stdin);  // vs. scanf() fgets() n의 크기를 넘어도 런타임 에러가 나지 않음 안전성 in 11.4 제대로 입력 받을 시 st 문자열의 포인터 반환 아닐 시 NULL 반환
    if (ret_val)
    {
        find = strchr(st, '\n');  // look for newline in 11.6 찾은 위치의 주소 반환
        if (find)                  // if the address is not NULL
            *find = '\0';         // place a null character there
        else                      // 긴 문자를 입력할 경우 처리하기 위해
            while (getchar() != '\n')
                continue;         // dispose(처리하다) of rest of line
    }

    return ret_val;
}

struct book
{
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    float price;
};

int main(void)
{
    struct book library[MAX_BOOKS] = { { "Empty", "Empty", 0.0F }, };  // 초기화되어야함을 명시적으로 표현 안 적으면 visual studio가 경고하는 경우도 있다
    int count = 0;

    while (1)
    {
        printf("Input a book title or press [Enter] to stop.\n>>");
        /* my poor answer */
        //s_gets(library[count].title, max_title);
        //if ((library[count].title[0]) == '\0') break; // 이렇게 하면 ret_val = null 인 즉 EOF를 받을 때 그냥 넘어가잖아
        if (s_gets(library[count].title, MAX_TITLE) == NULL) break;
        if ((library[count].title[0]) == '\0') break; // == *(library[count].title)

        printf("Input the author.\n>>");
        s_gets(library[count].author, MAX_AUTHOR);

        printf("Input the price.\n>>");
        scanf("%f", &library[count].price);
        
        while (getchar() != '\n')   // scanf끝나고 '\n' 없애기
            continue;

        count++;

        if (count == MAX_BOOKS)
        {
            printf("No more books.\n");
            break;
        }
    }

    if (count > 0)
    {
        printf("\nThe list of books:\n");
        for (int index = 0; index < count; index++)
        {
            printf("\"%s\" written by %s: $%.1f\n", library[index].title, library[index].author, library[index].price);
        }
    }
    else
    {
        printf("No book to show.\n");
    }

    return 0;
}