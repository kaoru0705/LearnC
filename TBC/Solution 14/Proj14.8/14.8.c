/* 구조체와 함수 연습문제 */
#define _CRT_SECURE_NO_WARNINGS
/* First */
//#include <stdio.h>
//#include <string.h>
//
//#define NLEN 30
//
//struct name_count
//{
//    char first[NLEN];
//    char last[NLEN];
//    int num;
//};
//
//void receive_input(struct name_count*);
//void count_characters(struct name_count*);
//void show_result(const struct name_count*);
//char* s_gets(char* st, int n);
//
//int main(void)
//{
//    struct name_count user_name;
//
//    receive_input(&user_name);
//    count_characters(&user_name);
//    show_result(&user_name);
//
//    return 0;
//}
//
//char* s_gets(char* st, int n) // in 14.4c
//{
//    char* ret_val;
//    char* find;
//
//    ret_val = fgets(st, n, stdin);    // vs. scanf()
//    if (ret_val) {
//        find = strchr(st, '\n');      // look for newline
//        if (find != NULL)              // if the address is not NULL
//            *find = '\0';             // place a NULL character there
//        else
//            while (getchar() != '\n')  // dispose of rest of line
//                continue;
//    }
//
//    return ret_val;
//}
//
//void receive_input(struct name_count* ptr_nc)
//{
//    /* My answers */
//    /*while (1)
//    {
//        printf("Input your first name:\n>> ");
//        if (s_gets(ptr_nc->first, NLEN) && ptr_nc->first[0] != '\0') break;
//    }
//
//    while (1)
//    {
//        printf("Input your last name:\n>> ");
//        if (s_gets(ptr_nc->last, NLEN) && ptr_nc->last[0] != '\0') break;
//    }*/
//
//    int flag;
//
//    printf("Input your first name:\n>> ");
//
//    //s_gets(ptr_nc->first, NLEN);             // 이걸 사용하는 것이 전통적인 C 스타일
//    flag = scanf("%[^\n]%*c", ptr_nc->first);  // ^ : cap operator, [^\n] 줄바꿈이 나올 때까지 받아라, *c c하나를 무시해라 줄바꿈 기호를 먹어버림, 사용자가 입력한 문자열에서 줄바꿈을 빼고 입력받음
//    if (flag != 1)
//        printf("Wrong input");
//
//    printf("Input your last name:\n>> ");
//
//    //s_gets(ptr_nc->last, NLEN);
//    flag = scanf("%[^\n]%*c", ptr_nc->last);
//    if (flag != 1)
//        printf("Wrong input");
//}
//
//void count_characters(struct name_count* ptr_nc)
//{
//    ptr_nc->num = strlen(ptr_nc->first) + strlen(ptr_nc->last);
//}
//
//void show_result(const struct name_count* ptr_nc) // 객체지향에서는 name_count structure의 멤버를 사용하므로 이 함수를 structure안에 넣어버릴 수 있다. 구조체는 데이터의 묶음 그리고 그 데이터로 할 수 있는 일들을 기능까지 집어넣은 것이 객체, object, class
//{
//    printf("Hi, %s %s, Your name has %d characteres.\n",
//        ptr_nc->first, ptr_nc->last, ptr_nc->num);
//}


/* Second */
//#include <stdio.h>
//#include <string.h>
//
//#define NLEN 30
//
//struct name_count
//{
//    char first[NLEN];
//    char last[NLEN];
//    int num;
//};
//
//struct name_count receive_input();
//struct name_count count_characters(struct name_count);
//void show_result(const struct name_count);
//char* s_gets(char* st, int n);
//
//int main(void)
//{
//    struct name_count user_name;
//
//    user_name = receive_input();
//    user_name = count_characters(user_name);
//    show_result(user_name);
//
//    return 0;
//}
//
//char* s_gets(char* st, int n)
//{
//    char* ret_val;
//    char* find;
//
//    ret_val = fgets(st, n, stdin);    // vs. scanf()
//    if (ret_val) {
//        find = strchr(st, '\n');      // look for newline
//        if (find != NULL)              // if the address is not NULL
//            *find = '\n';             // place a NULL character there
//        else
//            while (getchar() != '\n')  // dispose of rest of line
//                continue;
//    }
//
//    return ret_val;
//}
//
//struct name_count receive_input()
//{
//    struct name_count nc;
//    int flag;
//
//    printf("Input your first name:\n>> ");
//
//    //s_gets(nc.first, NLEN);           
//    flag = scanf("%[^\n]%*c", nc.first);
//    if (flag != 1)
//        printf("Wrong input");
//
//    printf("Input your last name:\n>> ");
//
//    //s_gets(nc.last, NLEN);
//    flag = scanf("%[^\n]%*c", nc.last);
//    if (flag != 1)
//        printf("Wrong input");
//
//    return nc;
//}
//
//struct name_count count_characters(struct name_count nc)
//{
//    nc.num = strlen(nc.first) + strlen(nc.last);
//
//    return nc;
//}
//
//void show_result(struct name_count nc)
//{
//    printf("Hi, %s %s, Your name has %d characteres.\n",
//        nc.first, nc.last, nc.num);
//}
