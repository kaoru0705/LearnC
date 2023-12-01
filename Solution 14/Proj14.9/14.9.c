/* 구조체와 할당 메모리 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  // strlen(), strcmp()
#include <stdlib.h>  // malloc(), free()
#define SLEN 81

struct namect
{
    char* fname;  // Use malloc()
    char* lname;  // Use malloc()
    int letters;
};

void getinfo(struct namect*);         // allocate memory
void makeinfo(struct namect*);
void showinfo(const struct namect*);
void cleanup(struct namect*);         // free memory when done
char* s_gets(char* st, int n);

int main(void)
{

    struct namect p = { "Jeong-Mo", "Hong" };
    printf("%s %s\n", p.fname, p.lname);

    /* Dangerous usage */

    //int f1 = scanf("%[^\n]%*c", p.lname); // 14.8c 빈 칸이 있어도 줄바꿈이 있는 곳까지 계속 입력 받을 수 있음
    //printf("%s %s\n", p.lname, p.fname); // TEXT segment 영역의 데이터는 읽기 전용이므로 포인터로 접근해서 값을 바꾸려 하는 경우 프로그램이 종료된다
    //
    ///* Recommended usage */

    //char buffer[SLEN] = { 0, }; // 임시 저장 공간
    //int f2 = scanf("%[^\n]%*c", buffer);
    //p.fname = (char*)malloc(strlen(buffer) + 1); // + 1 null character까지 더함
    //if(p.fname != NULL)
    //    strcpy(p.fname, buffer);
    //printf("%s %s\n", p.fname, p.lname);

    /* Problem */
    struct namect person;

    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);

    return 0;
}
char* s_gets(char* st, int n)
{
    char* ret_val;
    char* find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(ret_val, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

void getinfo(struct namect* pst)
{
    /* my answers */
    //char buffer[SLEN] = { 0, }; // 임시 저장 공간

    //printf("Input your first name:\n>> ");
    //int f2 = scanf("%[^\n]%*c", buffer); // 이렇게 하면 f2가 쓸모 없다.
    //pst->fname = (char*)malloc(strlen(buffer) + 1);
    //if (pst->fname != NULL)
    //    strcpy(pst->fname, buffer);

    //printf("Input your last name:\n>> ");
    //f2 = scanf("%[^\n]%*c", buffer);
    //pst->lname = (char*)malloc(strlen(buffer) + 1);
    //if (pst->lname != NULL)
    //    strcpy(pst->lname, buffer);

    int flag = 0;
    char temp[SLEN] = { 0, };

    printf("Please enter your first name.\n");
    flag = scanf("%[^\n]%*c", temp);
    if (flag != 1)
        printf("Wrong input\n");
    else
    {
        pst->fname = (char*)malloc(strlen(temp) + 1);  // +1 is for '\0'
        if (pst->fname != NULL)
            strcpy(pst->fname, temp);
        else
            printf("Malloc() failed!\n");
    }


    printf("Please enter your last name.\n");
    flag = scanf("%[^\n]%*c", temp);
    if (flag != 1)
        printf("Wrong input\n");
    else
    {
        pst->lname = (char*)malloc(strlen(temp) + 1);  // +1 is for '\0' sizeof를 곱할 필요가 없음 char는 1byte
        if (pst->lname != NULL)
            strcpy(pst->lname, temp);
        else
            printf("Malloc() failed!\n");
    }

}

void makeinfo(struct namect* pst)
{
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect* ptr)
{
    printf("Hi, %s %s, Your name has %d characteres.\n",
        ptr->fname, ptr->lname, ptr->letters);
}

void cleanup(struct namect* ptr)
{
    free(ptr->fname);
    free(ptr->lname);
}
