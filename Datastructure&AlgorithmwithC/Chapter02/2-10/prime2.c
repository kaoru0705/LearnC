// 1,000 ������ �Ҽ��� ����(���� 2)
#include <stdio.h>

int main(void)
{
    int prime[500];                         // �Ҽ��� �����ϴ� �迭
    int ptr = 0;                            // �̹� ���� �Ҽ��� ����
    unsigned long counter = 0;              // ������ Ƚ��
    prime[ptr++] = 2;                       // 2�� �Ҽ�
    for (int n = 3; n <= 1000; n += 2) {    // Ȧ������ ���
        int i;
        for (i = 1; i < ptr; i++) {         // �̹� ���� �Ҽ��� ����
            counter++;
            if (n % prime[i] == 0)          // ����������Ƿ� �Ҽ��� �ƴ�
                break;                      // �� �̻��� �ݺ��� ���ʿ�
        }
        if (ptr == i)                       // ���������� ����������� �ʾҴٸ�
            prime[ptr++] = n;               // �迭�� ����
    }
    for (int i = 0; i < ptr; i++)
        printf("%d\n", prime[i]);
    printf("�������� ������ Ƚ��: %lu\n", counter);

    return 0;
}
