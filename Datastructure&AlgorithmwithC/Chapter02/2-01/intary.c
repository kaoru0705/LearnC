// int[5]�� �迭(�ڷ����� int���̰� ��Ұ� 5��)�� ���� �Է��� ���
#include <stdio.h>

#define N   5                       // �迭�� ��� ����
int main()
{
    int a[N];                       // �迭�� ����
    for (int i = 0; i < N; i++) {   // �� ��ҿ� ���� �Է�
        printf("a[%d] : ", i);
        scanf("%d", &a[i]);
    }
    puts("�� ����� ��");
    for (int i = 0; i < N; i++) {   // �� ����� ���� ���
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}
