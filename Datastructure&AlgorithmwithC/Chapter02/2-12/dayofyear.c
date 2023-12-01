// �� ���� ���� �� ���� ���Ͽ� ���
#include <stdio.h>

/*- �� ���� �� �� -*/
int mdays[][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

/*--- year���� �����ΰ�? ---*/
int isleap(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

/*--- y�� m�� d���� �� �� ���� �� ���� ���� ---*/
int dayof_year(int y, int m, int d)
{
    int days = d;       // �� ��
    for (int i = 1; i < m; i++)
        days += mdays[isleap(y)][i - 1];
    return days;
}

int main(void)
{
    int retry;      // �ٽ�?
    do {
        int year, month, day;       // ��, ��, ��
        printf("��: ");   scanf("%d", &year);
        printf("��: ");   scanf("%d", &month);
        printf("��: ");   scanf("%d", &day);
        printf("%d���� %d��°�Դϴ�.\n", year, dayof_year(year, month, day));
        printf("�ٽ� �ұ��?(1 �� �� / 0 �� �ƴϿ�): ");
        scanf("%d", &retry);
    } while (retry == 1);

    return 0;
}
