/* 구조체를 다른 구조체의 멤버로 사용하기 Nested Structures(중첩 구조체) */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 20

struct names // A structure
{          
    char given[LEN];    // first name given name familiy name
    char family[LEN];   // last name
};

struct reservation // Another structure
{   
    struct names guest; // a nested structure
    struct names host;  // one more nested structure
    char food[LEN];
    char place[LEN];

    // time
    int year;
    int month;
    int day;
    int hours;
    int minutes;
};

int main(void)
{
    struct reservation res = //헷갈려서 designated initialized 사용함
    {
        .guest = { "Nick", "Carraway" },
        .host = { "Jay", "Gatsby" },
        .place = { "the Gatsby mansion" },
        .food = { "Escargot" },
        .year = 1925,
        .month = 4,
        .day = 10,
        .hours = 18,
        .minutes = 30
    };

    /*
        Dear Nick Carraway,
        I would like to serve you Escargot.
        Please visit the Gatsby mansion on 10/4/1925 at 18:30.
        Sincerely,
        Jay Gatsby
    */
        //printf("Dear %s %s,\nI would like to serve you %s.\n Please visit %s on %d/%d/%d at %d:%d.\nSincerely,\n%s %s\n", res.guest.given, res.guest.family, res.food, res.place, res.day, res.month, res.year, res.hours, res.minutes, res.host.given, res.host.family);

    // formatted이 너무 길어서 이렇게 함
    const char* formatted = //backslash가 줄바꿈이 가능하게 해줌 전처리기에서 다시 배운다.
        "\
Dear %s %s,\nI would like to serve you %s.\n\
Please visit %s on %d/%d/%d at %d:%d.\n\
Sincerely,\n\
%s %s\
";
    //printf에 format string을 넣을 수 있음
    printf(formatted, res.guest.given, res.guest.family, res.food, res.place, res.day, res.month, res.year, res.hours, res.minutes, res.host.given, res.host.family);

    //중첩된 구조체의 멤버 의외로 많이 쓴다. 구조체의 장점 하나를 만들어서 여러 번 재사용 할 수 있다. 코드를 간결하고 일하는 시간을 줄여줄 수 있다.
    return 0;
}