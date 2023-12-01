// ���� �˻�(for ����
#include <stdio.h>
#include <stdlib.h>

/*--- ����� ������ n�� �迭 a���� key�� ��ġ�ϴ� ��Ҹ� ���� �˻�(for ��)---*/
int search(const int a[], int n, int key)
{
    for (int i = 0; i < n; i++)
        if (a[i] == key)
            return i;           // �˻� ����

    return -1;                  // �˻� ����
}

int main(void)
{
    int nx, ky;

    puts("���� �˻�");
    printf("��� ���� : ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ����� ������ nx�� int�� �迭 x�� ����
    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    printf("�˻���: ");
    scanf("%d", &ky);
    int idx = search(x, nx, ky);        // �迭 x�� ���� ky�� ��Ҹ� ���� �˻�
    if (idx == -1)
        puts("�˻��� �����߽��ϴ�.");
    else
        printf("%d(��)�� x[%d]�� �ֽ��ϴ�.\n", ky, idx);
    free(x);                            // �迭 x�� ����

    return 0;
}
