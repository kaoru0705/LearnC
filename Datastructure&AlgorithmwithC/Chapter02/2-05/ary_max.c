// �迭 ����� �ִ��� ���ϰ� ���(��ڰ� �Է�)
#include <stdio.h>
#include <stdlib.h>

/*--- ��� ������ n�� �迭 a�� ����� �ִ� ---*/
int maxof(const int a[], int n)
{
    int max = a[0];             // �ִ�
    printf("%zu\n", sizeof(a));
    for (int i = 1; i < n; i++)
        if (a[i] > max) max = a[i];
    return max;
}

int main(void)
{
    int number;                 // �ο� = �迭 height�� ��� ����
    printf("��� ��: ");
    scanf("%d", &number);
    int* height = calloc(number, sizeof(int));  // ��� ���� number���� �迭�� ����
    printf("%d���� Ű�� �Է��ϼ���.\n", number);
    for (int i = 0; i < number; i++) {
        printf("height[%d] : ", i);
        scanf("%d", &height[i]);
    }
    printf("�ִ��� %d�Դϴ�.\n", maxof(height, number));
    free(height);                               // �迭 height�� ����

    return 0;
}
