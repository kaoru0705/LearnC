// �� ���� 1���� ���� ��ġ�ϴ� ������ ��������� ����
#include <stdio.h>

int pos[8];         // �� ������ ���� ��ġ

/*--- �� ���� ���� ��ġ�� ��� ---*/
void print(void)
{
    for (int i = 0; i < 8; i++)
        printf("%2d", pos[i]);
    putchar('\n');
}

/*--- i���� ���� ��ġ ---*/
void set(int i)
{
    for (int j = 0; j < 8; j++) {
        pos[i] = j;
        if (i == 7)             // ��� ���� ��ġ�� ��ħ
            print();
        else
            set(i + 1);         // ���� ���� ���� ��ġ
    }
}

int main(void)
{
    set(0);                     // 0���� ���� ��ġ

    return 0;
}
