// �迭 ����� �ִ��� ���ϰ� ���(��ڰ� �Է�)
#include <stdio.h>
#include <stdlib.h>

/*--- ��� ������ n�� �迭 a�� ����� �ִ� ---*/
int minof(const int a[], int n)
{
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min) min = a[i];
    return min;
}

int main(void)
{
    int number;
    printf("��� ��: ");
    scanf("%d", &number);
    int* height = calloc(number, sizeof(int));
    printf("%d���� Ű�� �Է��ϼ���.\n", number);
    for (int i = 0; i < number; i++)
    {
        printf("height[%d] : ", i);
        scanf("%d", &height[i]);
    }
    printf("�ּڰ��� %d�Դϴ�.\n", minof(height, number));
    free(height);

    return 0;
}
