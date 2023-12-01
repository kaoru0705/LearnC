// ���� �˻�
#include <stdio.h>
#include <stdlib.h>

/*--- ����� ������ n�� �迭 a���� key�� ��ġ�ϴ� ��Ҹ� ���� �˻� ---*/
int bin_search2(const int a[], int n, int key)
{
    int pl = 0;                     // �˻� ���� �� ���� �ε���
    int pr = n - 1;                 // �˻� ���� �� ���� �ε���

    do {
        int pc = (pl + pr) / 2;     // �˻� ���� �Ѱ���� �ε���
        if (a[pc] == key)           // �˻� ����
        {
            for (int i = pc - 1; i > pl; i--)
                if (a[i] == key)
                    pc = i;
            return pc;
        }
        else if (a[pc] < key)
            pl = pc + 1;            // �˻� ������ ���� �������� ����
        else
            pr = pc - 1;            // �˻� ������ ���� �������� ����
    } while (pl <= pr);
    return -1;                      // �˻� ����
}
//// ����3-5������ �˻�(�� ���� ��Ҹ� �˻�)
///*--- ��� ������ n�� �迭 a���� key�� ��ġ�ϴ� ��Ҹ� ���� �˻�(�� �տ� �ִ� ��Ҹ� �˻�) ---*/
//int bin_search2(const int a[], int n, int key)
//{
//    int pl = 0;                     // �˻� ���� �� ���� �ε���
//    int pr = n - 1;                 // �˻� ���� �� ���� �ε���
//
//
//    do {
//        int pc = (pl + pr) / 2;     // �˻� ���� �Ѱ���� �ε���
//        if (a[pc] == key) {         // �˻� ����
//            while (pc > pl && a[pc - 1] == key)
//                pc--;
//            return pc;
//        }
//        else if (a[pc] < key)
//            pl = pc + 1;            // �˻� ������ ���� �������� ����
//        else
//            pr = pc - 1;            // �˻� ������ ���� �������� ����
//    } while (pl <= pr);
//
//    return -1;                      // �˻� ����
//}
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
    int idx = bin_search2(x, nx, ky);    // �迭 x���� ���� ky�� ��Ҹ� ���� �˻�
    if (idx == -1)
        puts("�˻��� �����߽��ϴ�.");
    else
        printf("%d��(��) x[%d]�� �ֽ��ϴ�.\n", ky, idx);
    free(x);                            // �迭 x�� ����

    return 0;
}
