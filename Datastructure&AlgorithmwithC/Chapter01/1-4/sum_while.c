// 1~n�� ���� ���Ͽ� ���(while��)
#include <stdio.h>

int main(void)
{
    int n;

    puts("1���� n������ ������ ���մϴ�.");

    printf("n��: ");
    scanf("%d", &n);

    int sum = 0;        // ����
    int i = 1;

    while (i <= n)      // i�� n �����̸� �ݺ�
    {  
        sum += i;       // sum�� i�� �߰�
        i++;            // i���� 1 ����
    }
    printf("1���� %d������ ������ %d�Դϴ�.\n", n, sum);

    return 0;
}
