//#include <stdio.h>
//#include <stdlib.h>
//
///*--- ������ ���ϴ� �Լ�(��������) ---*/
//int int_cmpr(const int* a, const int* b)
//{
//    if (*a < *b)
//        return 1;
//    else if (*a > *b)
//        return -1;
//    else
//        return 0;
//}
//void* seqsearch(const void* key, const void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*))
//{
//    for (size_t i = 0; i < nmemb; i++)
//    {
//        if (compar(((size_t*)base + i), (size_t*)key) == 0)
//            return (size_t*)base + i;
//    }
//
//    return NULL;
//}
//int main(void)
//{
//    int nx, ky;
//    puts("bsearch �Լ��� ����Ͽ� �˻�");
//    printf("��� ����: ");
//    scanf("%d", &nx);
//    int* x = calloc(nx, sizeof(int));   // ����� ������ nx�� int�� �迭 x�� ����
//    printf("���� �Է��ϼ���.\n");
//    for (int i = 0; i < nx; i++)
//    {
//        printf("x[%d] : ", i);
//        scanf("%d", &x[i]);
//    }
//    printf("�˻���: ");
//    scanf("%d", &ky);
//    int* p = seqsearch(
//        &ky,                            // �˻����� ���� ������
//        x,                              // �迭
//        nx,                             // ����� ����
//        sizeof(int),                    // ����� ũ��
//        (int (*)(const void*, const void*))int_cmpr   // �� �Լ�
//    );
//    if (p == NULL)
//        puts("�˻��� �����߽��ϴ�.");
//    else
//        printf("%d��(��) x[%d]�� �ֽ��ϴ�.\n", ky, (int)(p - x));
//    free(x);                            // �迭 x�� ����
//    return 0;
//}
// ����3-7��bsearch �Լ��� ���� ������ ���� Ž�� �Լ�
#include <stdio.h>
#include <stdlib.h>

/*--- base�� ����Ű�� ����� ũ�Ⱑ size�̰� ����� ������ nmemb�� �迭���� key�� ��ġ�ϴ� ��Ҹ�
      �� �Լ� compar�� ����ؼ� ���� �˻� ---*/
void* seqsearch(const void* key, const void* base, size_t nmemb, size_t size,
    int (*compar)(const void*, const void*))
{
    char* x = (char*)base;

    for (size_t i = 0; i < nmemb; i++)
        if (!compar((const void*)&x[i * size], key))
            return (&x[i * size]);
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

    puts("seqsearch �Լ��� �˻�");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ��� ������ nx�� int�� �迭 x�� ����

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    printf("�˻���: ");
    scanf("%d", &ky);

    int* p = seqsearch(
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
