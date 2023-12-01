// �� ������ �Է��ϰ� �ִ��� ���Ͽ� ���

//#include <stdio.h>
//
//typedef struct {
//    int y;
//    int m;
//    int d;
//} Date;
//
///*--- �� ���� �� �� ---*/
//static int  mdays[2][13] = {
//    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},   // ���
//    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},   // ����
//};
//
///*--- year���� �����ΰ�? ---*/
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
//        int year, month, day, n;       // ��, ��, ��
//        printf("��: ");   scanf("%d", &year);
//        printf("��: ");   scanf("%d", &month);
//        printf("��: ");   scanf("%d", &day);
//        printf("AfterBefore day: ");     scanf("%d", &n);
//        today = Dateof(year, month, day);
//        printf("%d�� %d�� %d��\n", today.y, today.m, today.d);
//        today = After(today, n);
//        printf("%d�� %d�� %d��\n", today.y, today.m, today.d);
//        today = Before(today, n);
//        printf("%d�� %d�� %d��\n", today.y, today.m, today.d);
//
//        printf("�ٽ� �ұ��?(1 �� �� / 0 �� �ƴϿ�): ");
//        scanf("%d", &retry);
//    } while (retry == 1);
//    return 0;
//}

// ����2-12����¥�� ��Ÿ���� ����ü
#include <stdio.h>

typedef struct {
    int y;  // ��
    int m;  // ��(1~12)
    int d;  // ��(1~31)
} Date;

Date Before(Date x, int n);
Date After(Date x, int n);

/*--- �� ���� �� �� ---*/
static int  mdays[2][13] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},   // ���
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},   // ����
};

/*--- year���� �����ΰ�? ---*/
int isleap(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
int dayofamount(int y, int m, int d)
{
    int days = 0;
    for (int i = 1; i < m; i++)
        days += mdays[isleap(y)][i - 1];
    return days%7;  //���� ��
}
/*--- y�� m�� d���� ��Ÿ���� ����ü�� ��ȯ�ϴ� DateOf �Լ� ---*/
Date DateOf(int y, int m, int d)
{
    Date temp;

    temp.y = y;
    temp.m = m;
    temp.d = d;

    return temp;
}

/*--- ��¥ x�� n�� ���� ��¥�� ��ȯ�ϴ� �Լ� ---*/
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

/*--- ��¥ x�� n�� ���� ��¥�� ��ȯ�ϴ� �Լ� ---*/
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

/*--- ��¥�� ǥ�� ---*/
int Print(Date x)
{
    int y = x.y;
    int m = x.m;
    int d = x.d;

    char* ws[] = { "��", "��", "ȭ", "��", "��", "��", "��" };
    /*if (m == 1 || m == 2) {
        y--;
        m += 12;
    }
    printf("%04d��%02d��%02d��(%s)", x.y, x.m, x.d,
        ws[(y + y / 4 - y / 100 + y / 400 + (13 * m + 8) / 5 + d) % 7]);*/ // �̰� �� ������� �𸣰���
    y--;
    printf("%04d��%02d��%02d��(%s)", x.y, x.m, x.d,
        ws[(y + y / 4 - y / 100 + y / 400 +  dayofamount(y+1, m, d) + d) % 7]);

}

int main(void)
{
    int y, m, d;

    printf("��¥�� �Է��ϼ���.\n");
    printf("��: ");  scanf("%d", &y);
    printf("��: ");  scanf("%d", &m);
    printf("��: ");  scanf("%d", &d);

    Date x = DateOf(y, m, d);

    int n;

    printf("��ĥ ��/���� ��¥�� ���մϱ�?: ");
    scanf("%d", &n);

    printf("%d�� ���� ��¥: ", n);   Print(After(x, n));   putchar('\n');

    printf("%d�� ���� ��¥: ", n);   Print(Before(x, n));  putchar('\n');

    return 0;
}
