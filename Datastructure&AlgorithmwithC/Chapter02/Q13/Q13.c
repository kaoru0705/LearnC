// 세 정수를 입력하고 최댓값을 구하여 출력

//#include <stdio.h>
//
//typedef struct {
//    int y;
//    int m;
//    int d;
//} Date;
//
///*--- 각 달의 날 수 ---*/
//static int  mdays[2][13] = {
//    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},   // 평년
//    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},   // 윤년
//};
//
///*--- year년이 윤년인가? ---*/
//int isleap(int year)
//{
//    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
//}
//
//Date Dateof(int y, int m, int d)
//{
//    Date now = { y, m, d };
//
//    return now;
//}
//Date After(Date x, int n)
//{
//    int daycount = x.y * 12 * 31 + x.m * 12 + x.d + n;
//    x.y = daycount / (12 * 31);
//    daycount %= (12 * 31);
//
//    x.m = daycount / 12;
//    daycount %= 12;
//
//    x.d = daycount;
//
//    return x;
//}
//Date Before(Date x, int n)
//{
//    int daycount = x.y * 12 * 31 + x.m * 12 + x.d - n;
//    x.y = daycount / (12 * 31);
//    daycount %= (12 * 31);
//
//    x.m = daycount / 12;
//    daycount %= 12;
//
//    x.d = daycount;
//
//    return x;
//}
//
//int main(void)
//{
//    int retry;
//    Date today;
//    do {
//        int year, month, day, n;       // 년, 월, 일
//        printf("년: ");   scanf("%d", &year);
//        printf("월: ");   scanf("%d", &month);
//        printf("일: ");   scanf("%d", &day);
//        printf("AfterBefore day: ");     scanf("%d", &n);
//        today = Dateof(year, month, day);
//        printf("%d년 %d월 %d일\n", today.y, today.m, today.d);
//        today = After(today, n);
//        printf("%d년 %d월 %d일\n", today.y, today.m, today.d);
//        today = Before(today, n);
//        printf("%d년 %d월 %d일\n", today.y, today.m, today.d);
//
//        printf("다시 할까요?(1 … 예 / 0 … 아니오): ");
//        scanf("%d", &retry);
//    } while (retry == 1);
//    return 0;
//}

// 연습2-12　날짜를 나타내는 구조체
#include <stdio.h>

typedef struct {
    int y;  // 년
    int m;  // 월(1~12)
    int d;  // 일(1~31)
} Date;

Date Before(Date x, int n);
Date After(Date x, int n);

/*--- 각 달의 날 수 ---*/
static int  mdays[2][13] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},   // 평년
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},   // 윤년
};

/*--- year년이 윤년인가? ---*/
int isleap(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
int dayofamount(int y, int m, int d)
{
    int days = 0;
    for (int i = 1; i < m; i++)
        days += mdays[isleap(y)][i - 1];
    return days%7;  //월의 값
}
/*--- y년 m월 d일을 나타내는 구조체를 반환하는 DateOf 함수 ---*/
Date DateOf(int y, int m, int d)
{
    Date temp;

    temp.y = y;
    temp.m = m;
    temp.d = d;

    return temp;
}

/*--- 날짜 x의 n일 뒤의 날짜를 반환하는 함수 ---*/
Date After(Date x, int n)
{
    if (n < 0)
        return Before(x, -n);

    x.d += n;

    while (x.d > mdays[isleap(x.y)][x.m - 1]) {
        x.d -= mdays[isleap(x.y)][x.m - 1];
        if (++x.m > 12) {
            x.y++;
            x.m = 1;
        }
    }
    return x;
}

/*--- 날짜 x의 n일 앞의 날짜를 반환하는 함수 ---*/
Date Before(Date x, int n)
{
    if (n < 0)
        return After(x, -n);

    x.d -= n;

    while (x.d < 1) {
        if (--x.m < 1) {
            x.y--;
            x.m = 12;
        }
        x.d += mdays[isleap(x.y)][x.m - 1];
    }

    return x;
}

/*--- 날짜를 표시 ---*/
int Print(Date x)
{
    int y = x.y;
    int m = x.m;
    int d = x.d;

    char* ws[] = { "일", "월", "화", "수", "목", "금", "토" };
    /*if (m == 1 || m == 2) {
        y--;
        m += 12;
    }
    printf("%04d년%02d월%02d일(%s)", x.y, x.m, x.d,
        ws[(y + y / 4 - y / 100 + y / 400 + (13 * m + 8) / 5 + d) % 7]);*/ // 이거 뭔 계산인지 모르겠음
    y--;
    printf("%04d년%02d월%02d일(%s)", x.y, x.m, x.d,
        ws[(y + y / 4 - y / 100 + y / 400 +  dayofamount(y+1, m, d) + d) % 7]);

}

int main(void)
{
    int y, m, d;

    printf("날짜를 입력하세요.\n");
    printf("년: ");  scanf("%d", &y);
    printf("월: ");  scanf("%d", &m);
    printf("일: ");  scanf("%d", &d);

    Date x = DateOf(y, m, d);

    int n;

    printf("며칠 전/후의 날짜를 원합니까?: ");
    scanf("%d", &n);

    printf("%d일 후의 날짜: ", n);   Print(After(x, n));   putchar('\n');

    printf("%d일 전의 날짜: ", n);   Print(Before(x, n));  putchar('\n');

    return 0;
}
