// 1,000 ������ �Ҽ��� ����(���� 1)
#include <stdio.h>

int main(void)
{
    unsigned long counter = 0;  // ������ Ƚ����
    for (int n = 2; n <= 1000; n++)
    {
        int i;
        for (i = 2; i < n; i++)
        {
            counter++;
            if (n % i == 0)     // ����������� �Ҽ��� �ƴ�
                break;          // �� �̻��� �ݺ��� ���ʿ�
        }
        if (n == i)             // ���������� ����������� ����
            printf("%d\n", n);
    }
    printf("�������� ������ Ƚ��: %lu\n", counter);

    return 0;
}
