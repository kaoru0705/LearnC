// int�� �迭�� �������� �����ϰ� ����
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int na;     // �迭 a�� ��� ����
    printf("��� ������");
    scanf("%d", &na);
    int* a = calloc(na, sizeof(int));   // ��� ������ na�� int�� �迭�� ����

    if (a == NULL)
        puts("�޸� Ȯ���� �����߽��ϴ�.");
    else {
        printf("%d���� ������ �Է��ϼ���.\n", na);
        for (int i = 0; i < na; i++) {
            printf("a[%d] : ", i);
            scanf("%d", &a[i]);
        }
        printf("�� ��ڰ��� �Ʒ��� �����ϴ�.\n");
        for (int i = 0; i < na; i++)
            printf("a[%d] = %d\n", i, a[i]);
        free(a);            // ��� ������ na�� int�� �迭�� ����
    }

    return 0;
}