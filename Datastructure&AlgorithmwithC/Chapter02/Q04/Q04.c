// �迭 ����� �ִ��� ���ϰ� ���(��ڰ��� ������ ����)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*--- ��� ������ n�� �迭 a�� ����� �ִ� ---*/
int maxof(const int a[], int n)
{
    int max = a[0];             // �ִ�
    for (int i = 1; i < n; i++)
        if (a[i] > max) max = a[i];
    return max;
}

int main(void)
{
    int number;
    srand((unsigned int)time(NULL));
    number = rand() % 16 + 5;                   // 5~20�� ������ �ο����� ����
    int* height = calloc(number, sizeof(int));  // ��� ������ number�� �迭�� ����
    for (int i = 0; i < number; i++)
    {
        height[i] = 100 + rand() % 90;          // 100~189�� ������ ����, ����
        printf("height[%d] = %d\n", i, height[i]);
    }
    printf("�ִ��� %d�Դϴ�.\n", maxof(height, number));
    free(height);                               // �迭 height�� ����

    return 0;
}
