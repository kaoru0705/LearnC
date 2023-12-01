// ���� �˻�(���ʹ�)
#include <stdio.h>
#include <stdlib.h>

/*--- ����� ������ n�� �迭 a���� key�� ��ġ�ϴ� ��Ҹ� ���� �˻�(���ʹ�) ---*/
int search(int a[], int n, int key)
{
    int i = 0;
    a[n] = key;         // ���ʸ� �߰�
    printf("  |");
    for (int i = 0; i < n; i++)
        printf("%2d", i);
    printf("\n--+");
    for (int i = 0; i < n; i++)
        printf("--");
    printf("--\n");

    for (i = 0; i < n; i++)
    {
        printf("  |");
        for (int j = 0; j < i; j++)
            printf("  ");
        printf(" *\n");
        printf("%2d|", i);
        for (int j = 0; j < n; j++)
            printf("%2d", a[j]);
        printf("\n");
        if (a[i] == key)
            break;
        printf("  |\n");
    }
    return i == n ? -1 : i;
}

int main(void)
{
    int nx, ky;

    puts("���� �˻�(���ʹ�)");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx + 1, sizeof(int));   // ����� ������ (nx + 1)�� int�� �迭�� ����
    for (int i = 0; i < nx; i++) {          // ����: ���� ���� ���� nx��
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    printf("������ : ");
    scanf("%d", &ky);
    int idx = search(x, nx, ky);            // �迭 x���� ���� ky�� ��Ҹ� ���� �˻�
    if (idx == -1)
        puts("������������ު�����");
    else
        printf("%d��x[%d]�˪���ު���\n", ky, idx);
    free(x);                                // �迭 x�� ����

    return 0;
}
