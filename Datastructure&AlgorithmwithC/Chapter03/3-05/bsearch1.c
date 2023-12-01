// bsearch �Լ��� ����� ������������ ���ĵ� �迭�� �˻�
#include <stdio.h>
#include <stdlib.h>

/*--- ������ ���ϴ� �Լ�(��������) ---*/
int int_cmp(const int* a, const int* b)
{
    if (*a < *b)
        return -1;
    else if (*a > *b)
        return 1;
    else
        return 0;
}

int main(void)
{
    int nx, ky;
    puts("bsearch �Լ��� ����Ͽ� �˻�");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ����� ������ nx�� int�� �迭�� ����

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
    int* p = bsearch(
        &ky,                            // �˻����� ���� ������
        x,                              // �迭
        nx,                             // ����� ����
        sizeof(int),                    // ����� ũ��
        (int (*)(const void*, const void*))int_cmp    // �� �Լ� _CompreFunction �ڸ����� �μ��� const void*�� �����Ƿ� casting�ߴ�
    );
    if (p == NULL)
        puts("�˻��� �����߽��ϴ�.");
    else
        printf("%d��(��) x[%d]�� �ֽ��ϴ�.\n", ky, (int)(p - x));
    free(x);                            // �迭 x�� ����
    return 0;
}
/*
// �� ������ �Է��ϰ� �ִ��� ���Ͽ� ���

#include <stdio.h>

int main(void)
{
    // examining object representation is a legitimate use of cast
    double d = 3.14;
    printf("The double %.2f (%a) is: ", d, d);
    for (size_t n = 0; n < sizeof d; ++n)
        printf("0x%02x ", ((unsigned char*)&d)[n]); // �̵� �� casting??? (unsigned char pointer to &d) [n] -> n��° �迭�� ��

    // edge cases
    struct S { int x; } s;
    //    (struct S)s; // error; not a scalar type
                       // even though casting to the same type does nothing
    (void)s; // okay to cast any type to void
}
*/
// bsearch �Լ��� ����Ͽ� ������������ ������ �迭���� Ž��(ĳ��Ʈ���� �ʰ� �̿��� �� �ִ� �� �Լ�)
#include <stdio.h>
#include <stdlib.h>

/*-- ĳ��Ʈ���� �ʰ� �̿��� �� �ִ� �� �Լ� --*/
//int int_cmp(const void* a, const void* b)
//{
//    if (*(int*)a < *(int*)b)
//        return -1;
//    else if (*(int*)a > *(int*)b)
//        return 1;
//    else
//        return 0;
//}
//
//int main(void)
//{
//    int nx, ky;
//    puts("bsearch �Լ��� ����Ͽ� �˻�");
//    printf("��� ����: ");
//    scanf("%d", &nx);
//    int* x = calloc(nx, sizeof(int));   // ����� ������ nx�� int�� �迭 x�� ����
//
//    printf("������������ �Է��ϼ���.\n");
//    printf("x[0] : ");
//    scanf("%d", &x[0]);
//    for (int i = 1; i < nx; i++) {
//        do {
//            printf("x[%d] : ", i);
//            scanf("%d", &x[i]);
//        } while (x[i] < x[i - 1]);      // �ٷ� ���� ������ ������ �ٽ� �Է�
//    }
//    printf("�˻���: ");
//    scanf("%d", &ky);
//    int* p = bsearch(
//        &ky,            // ������ ���� ������
//        x,              // �迭
//        nx,             // ��� ����
//        sizeof(int),    // ��� ũ��
//        int_cmp         // �� �Լ�
//    );
//
//    if (p == NULL)
//        puts("�˻��� �����߽��ϴ�.");
//    else
//        printf("%d��(��) x[%d]�� �ֽ��ϴ�.\n", ky, (int)(p - x));
//
//    free(x);                            // �迭 x�� ����
//
//    return 0;
//}