// �迭 ����� �ִ��� ���ϰ� ���(��ڰ� �Է�)
#include <stdio.h>
#include <stdlib.h>

/*--- ��� ������ n�� �迭 a�� ����� �ִ� ---*/
int sumof(const int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
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
    printf("�հ�� %d�Դϴ�.\n", sumof(height, number));
    free(height);

    return 0;
}
