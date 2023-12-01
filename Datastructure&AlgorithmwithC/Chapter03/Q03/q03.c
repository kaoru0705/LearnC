//#include <stdio.h>
//#include <stdlib.h>
//
///*--- ����� ������ n�� �迭 a���� key�� ��ġ�ϴ� ��Ҹ� ���� �˻�(for ��)---*/
//int search_idx(const int a[], int n, int key, int idx[])
//{
//    int count = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (a[i] == key)
//        {
//            idx[count] = i;
//            count++;
//        }
//    }
//    return count;
//}
//
//int main(void)
//{
//    int nx, ky;
//
//    puts("���� �˻�");
//    printf("��� ���� : ");
//    scanf("%d", &nx);
//    int* x = calloc(nx, sizeof(int));   // ����� ������ nx�� int�� �迭 x�� ����
//    int* y = calloc(nx, sizeof(int));   // ����� ������ nx�� int�� �迭 x�� ����
//    if (x == NULL || y == NULL)
//        exit(-1);
//
//    for (int i = 0; i < nx; i++) {
//        printf("x[%d] : ", i);
//        scanf("%d", &x[i]);
//    }
//    printf("�˻���: ");
//    scanf("%d", &ky);
//    int idx = search_idx(x, nx, ky, y);        // �迭 x�� ���� ky�� ��Ҹ� ���� �˻�
//    if (idx == 0)
//        puts("�˻��� �����߽��ϴ�.");
//    else
//        printf("������ �� %d�� ã�ҽ��ϴ�.",idx);
//    
//    for (int i = 0; i < nx; i++)
//    {
//        if (y[i] == 0)
//            break;
//        printf("%d ", y[i]);
//    }
//    free(x);                            // �迭 x�� ����
//    free(y);
//
//    return 0;
//}
// ����3-3���迭�� ������ ���� ��ġ�ϴ� ��� ����� �ε����� ����
#include <stdio.h>
#include <stdlib.h>

/*--- �迭 a ���� ���� key�� ��� ����� �ε����� idx�� ���� ---*/
int search_idx(const int a[], int n, int key, int idx[])
{
    int count = 0;

    for (int i = 0; i < n; i++)
        if (a[i] == key)
            idx[count++] = i;
    return count;
}

int main(void)
{
    int nx, ky;

    puts("���� �˻�(��� ��Ҹ� �˻�)");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));     // ��� ������ nx�� int�� �迭 x�� ����
    int* idx = calloc(nx, sizeof(int));     // ��� ������ nx�� int�� �迭 idx�� ����

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    printf("�˻���: ");
    scanf("%d", &ky);

    int no = search_idx(x, nx, ky, idx);    // �迭 x���� ���� ky�� ��� ��Ҹ� ���� Ž��

    if (no == 0)
        puts("��ġ�ϴ� ��Ұ� �����ϴ�.");
    else {
        printf("��ġ�ϴ� ��Ҵ� ������ ���� %d���Դϴ�.\n", no);
        for (int i = 0; i < no; i++)
            printf("x[%d] ", idx[i]);
        putchar('\n');
    }

    free(x);                                // �迭 x�� ����
    free(idx);                              // �迭 idx�� ����

    return 0;
}
