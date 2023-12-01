// ���� �˻�
#include <stdio.h>
#include <stdlib.h>

void* binsearchx(const void* key, const void* base, size_t nmemb, size_t size,
    int (*compar)(const void*, const void*))
{
    char* x = (char*)base;

    size_t pl = 0;
    size_t pr = nmemb - 1;
    int flag = 0;
    do {
        size_t pc = (pl + pr) / 2;
        flag = compar((const void*)&x[pc * size], key);
        if (!flag)
        {
            while (pc > pl && compar((const void*)&x[(pc -1) * size], key) == 0)
                pc--;
            return (&x[pc * size]);
        }
        else if (flag == -1)
            pl = pc + 1;
        else
        {
            if (pc == 0)
                break;
            pr = pc - 1;
        }
    } while (pl <= pr);
    return NULL;                            // �˻� ����
}

/*--- ������ ���ϴ� �Լ� ---*/
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
    int* p = binsearchx(
        &ky,                            // �˻����� ���� ������
        x,                              // �迭
        nx,                             // ����� ����
        sizeof(int),                    // ����� ũ��
        (int (*)(const void*, const void*))int_cmp    // �� �Լ�
    );

    if (p == NULL)
        puts("�˻��� �����߽��ϴ�.");
    else
        printf("%d��(��) x[%d]�� �ֽ��ϴ�.\n", ky, (int)(p - x));
    free(x);                            // �迭 x�� ����

    return 0;
}

//// ����3-9��bsearch �Լ��� Ȯ���� �Լ�(�� �տ� �ִ� ��Ҹ� �˻�)
//#include <stdio.h>
//#include <stdlib.h>
//
///*--- base�� ����Ű�� ����� ũ�Ⱑ size�̰� ����� ������ nmemb�� �迭���� key�� ��ġ�ϴ� ��Ҹ�
//      �� �Լ� compar�� �̿��ؼ� ���� �˻�
//      �� key�� ���� ��Ұ� ���� �� ������ �� ���� ��Ҹ� �˻� ---*/
//void* bsearchx(const void* key, const void* base, size_t nmemb, size_t size,
//    int (*compar)(const void*, const void*))
//{
//    char* x = (char*)base;
//    size_t pl = 0;                          // �˻� ���� �� ���� �ε���
//    size_t pr = nmemb - 1;                  // �˻� ���� �� ���� �ε���
//
//    if (nmemb > 0) {
//        while (1) {
//            size_t pc = (pl + pr) / 2;      // �˻� ���� �Ѱ���� �ε���
//            int comp = compar((const void*)&x[pc * size], key);
//
//            if (comp == 0) {                // �˻� ����
//                for (; pc > pl; pc--)      // key�� ���� ���� ��Ҹ� �˻�
//                    if (compar((const void*)&x[(pc - 1) * size], key))
//                        break;
//                return &x[pc * size];
//            }
//            else if (pl == pr)
//                break;
//            else if (comp < 0)
//                pl = pc + 1;                // �˻� ������ ���� �������� ����
//            else
//                pr = pc - 1;                // �˻� ������ ���� �������� ����
//        }
//    }
//
//    return NULL;                            // �˻� ����
//}
//
///*--- ������ ���ϴ� �Լ� ---*/
//int int_cmp(const int* a, const int* b)
//{
//    if (*a < *b)
//        return -1;
//    else if (*a > *b)
//        return 1;
//    else
//        return 0;
//}
//
//int main(void)
//{
//    int nx, ky;
//
//    puts("bsearchx �Լ��� �˻�");
//    printf("��� ����: ");
//    scanf("%d", &nx);
//    int* x = calloc(nx, sizeof(int));   // ��� ������ nx�� int�� �迭 x�� ����
//
//    printf("������������ �Է��ϼ���.\n");
//    printf("x[0] : ");
//    scanf("%d", &x[0]);
//
//    for (int i = 1; i < nx; i++) {
//        do {
//            printf("x[%d] : ", i);
//            scanf("%d", &x[i]);
//        } while (x[i] < x[i - 1]);      // �ٷ� ���� ������ ������ �ٽ� �Է�
//    }
//
//    printf("�˻���: ");
//    scanf("%d", &ky);
//
//    int* p = bsearchx(
//        &ky,                            // �˻����� ���� ������
//        x,                              // �迭
//        nx,                             // ����� ����
//        sizeof(int),                    // ����� ũ��
//        (int (*)(const void*, const void*))int_cmp    // �� �Լ�
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
