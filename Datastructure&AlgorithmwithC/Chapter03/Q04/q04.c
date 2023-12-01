#include <stdio.h>
#include <stdlib.h>

/*--- ����� ������ n�� �迭 a���� key�� ��ġ�ϴ� ��Ҹ� ���� �˻� ---*/
int bin_search(const int a[], int n, int key)
{
    int pl = 0;                     // �˻� ���� �� ���� �ε���
    int pr = n - 1;                 // �˻� ���� �� ���� �ε���

    printf("   |");
    for (int i = 0; i < n; i++)
        printf("%2d", i);
    printf("\n---+");
    for (int i = 0; i < n; i++)
        printf("---");
    printf("--\n");

    do {
        int pc = (pl + pr) / 2;     // �˻� ���� �Ѱ���� �ε���
        printf("   |");
        for (int i = 0; i < n; i++)
        {
            if (i == pl)
                printf(" <-");
            else if (i == pc)
                printf("  +");
            else if (i == pr)
                printf(" ->");
            else
                printf("   ");
        }
        printf("\n");
        printf("%3d|", pc);
        for (int i = 0; i < n; i++)
            printf("%3d", a[i]);
        printf("\n");
        if (a[pc] == key)           // �˻� ����
            return pc;
        else if (a[pc] < key)
            pl = pc + 1;            // �˻� ������ ���� �������� ����
        else
            pr = pc - 1;            // �˻� ������ ���� �������� ����
        printf("   |\n");
    } while (pl <= pr);
    return -1;                      // �˻� ����

    
}

int main(void)
{
    int nx, ky;

    puts("���� �˻�");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ��� ������ nx�� int�� �迭 x ����
    printf("������������ �Է��ϼ���.\n");
    printf("x[0] : ");
    scanf("%d", &x[0]);
    for (int i = 1; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i - 1]);      // �ٷ� ���� ������ ������ �ٽ� �Է�
    }
    printf("�˻���: ");
    scanf("%d", &ky);
    int idx = bin_search(x, nx, ky);    // �迭 x���� ���� ky�� ��Ҹ� ���� �˻�
    if (idx == -1)
        puts("�˻��� �����߽��ϴ�.");
    else
        printf("%d��(��) x[%d]�� �ֽ��ϴ�.\n", ky, idx);
    free(x);                            // �迭 x�� ����

    return 0;
}
