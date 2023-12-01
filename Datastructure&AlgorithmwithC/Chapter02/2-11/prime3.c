// 1,000 ������ �Ҽ��� ����(���� 3)
#include <stdio.h>

int main(void)
{
    int prime[500];                         // �Ҽ��� �����ϴ� �迭
    int ptr = 0;                            // �̹� ���� �Ҽ��� ����
    unsigned long counter = 0;              // ������ �������� ���� Ƚ��
    prime[ptr++] = 2;                       // 2�� �Ҽ�
    prime[ptr++] = 3;                       // 3�� �Ҽ�
    for (int n = 5; n <= 1000; n += 2) {    // Ȧ������ ���
        int i;
        int flag = 0;
        for (i = 1; counter++, prime[i] * prime[i] <= n; i++) {
            counter++;
            if (n % prime[i] == 0) {        // ����������� �Ҽ��� �ƴ�
                flag = 1;
                break;                      // �� �̻��� �ݺ��� ���ʿ�
            }
        }
        if (!flag)                          // ���������� ����������� ����
            prime[ptr++] = n;               // �迭�� ����
    }
    for (int i = 0; i < ptr; i++)
        printf("%d\n", prime[i]);

    printf("������ �������� ������ Ƚ��: %lu\n", counter);

    return 0;
}
