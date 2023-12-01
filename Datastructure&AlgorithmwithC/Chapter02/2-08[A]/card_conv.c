// ���� 10������ 2���� ~ 36������ ��� ��ȯ�Ͽ� ǥ��
#include <stdio.h>

/*--- type�� x���� y���� ��ȯ ---*/
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- ������ x�� n������ ��ȯ�� ���� ������ ������ �迭 d�� ���� ---*/
int card_convr(unsigned x, int n, char d[])
{
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digits = 0;                         // ��ȯ �� �ڸ���

    if (x == 0)                             // 0�̸�
        d[digits++] = dchar[0];             // ��ȯ �Ŀ��� 0
    else
        while (x) {
            d[digits++] = dchar[x % n];     // n���� ���� �������� ����
            x /= n;
        }

    for (int i = 0; i < digits / 2; i++)    // �迭 d�� �������� ����
        swap(char, d[i], d[digits - i - 1]);

    return digits;
}

int main(void)
{
    puts("10������ ��� ��ȯ�մϴ�.");

    int retry;              // �� �� ��?

    do {
        unsigned no;        // ��ȯ�ϴ� ����
        int      cd;        // ���
        char     cno[512];  // ��ȯ�� ���� �� �ڸ��� ���ڸ� �����ϴ� ���� �迭

        printf("��ȯ�ϴ� ���� �ƴ� ����: ");
        scanf("%u", &no);

        do {
            printf("� ������ ��ȯ�ұ��?(2-36): ");
            scanf("%d", &cd);
        } while (cd < 2 || cd > 36);

        int dno = card_convr(no, cd, cno);   // no�� dno�ڸ��� cd������ ��ȯ

        printf("%d�����δ�", cd);
        for (int i = 0; i < dno; i++)       // �� �ڸ��� ���ڸ� ���ʷ� ���
            printf("%c", cno[i]);
        printf("�Դϴ�.\n");

        printf("�� �� �� �ұ��?(1����/0���ƴϿ�): ");
        scanf("%d", &retry);
    } while (retry == 1);

    return 0;
}
