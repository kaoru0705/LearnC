/* ����ü�� �ٸ� ����ü�� ����� ����ϱ� Nested Structures(��ø ����ü) */
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
    struct reservation res = //�򰥷��� designated initialized �����
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

    // formatted�� �ʹ� �� �̷��� ��
    const char* formatted = //backslash�� �ٹٲ��� �����ϰ� ���� ��ó���⿡�� �ٽ� ����.
        "\
Dear %s %s,\nI would like to serve you %s.\n\
Please visit %s on %d/%d/%d at %d:%d.\n\
Sincerely,\n\
%s %s\
";
    //printf�� format string�� ���� �� ����
    printf(formatted, res.guest.given, res.guest.family, res.food, res.place, res.day, res.month, res.year, res.hours, res.minutes, res.host.given, res.host.family);

    //��ø�� ����ü�� ��� �ǿܷ� ���� ����. ����ü�� ���� �ϳ��� ���� ���� �� ���� �� �� �ִ�. �ڵ带 �����ϰ� ���ϴ� �ð��� �ٿ��� �� �ִ�.
    return 0;
}