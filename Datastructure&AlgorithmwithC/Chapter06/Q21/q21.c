//#include <stdio.h>
//#include <stdlib.h>
//
//static char* buff;           // �۾��� �迭
//
///*--- x, y�� ����Ű�� n����Ʈ�� ������ ��ȯ ---*/
//static void memassign(void* x, void* y, size_t n)
//{
//    unsigned char* a = (unsigned char*)x;
//    unsigned char* b = (unsigned char*)y;
//
//    for (; n--; a++, b++)
//        *a = *b;
//}
//
///*--- ���� ����(main) ---*/ // nlogn stable
//static void __mergesort(void* base, size_t size, size_t left, size_t right,
//    int (*compar)(const void*, const void*))
//{
//    char* a = (char*)base;
//
//    if (left < right)
//    {
//        size_t center = (left + right) / 2;
//        size_t p = 0;
//        size_t i;
//        size_t j = 0;
//        size_t k = left;
//        __mergesort(a, size, left, center, compar);           // �պκп� ���� ���� ����
//        __mergesort(a, size, center + 1, right, compar);      // �޺κп� ���� ���� ����
//        for (i = left; i <= center; i++)
//            memassign(&buff[p++ * size], &a[i * size], size);
//        while (i <= right && j < p)
//        {
//            if (compar(&buff[j * size], &a[i * size]) <= 0)
//                memassign(&a[k++ * size], &buff[j++ * size], size);
//            else
//                memassign(&a[k++ * size], &a[i++ * size], size);
//        }
//        while (j < p)
//            memassign(&a[k++ * size], &buff[j++ * size], size); // ex left = 0 right = 4�� �� (Ȧ����) buff�� ��Ұ� �ϳ� �� ����. 
//    }
//}
//
///*--- ���� ���� ����---*/
//void m_sort(void* base, size_t nmemb, size_t size,
//    int (*compar)(const void*, const void*))
//{
//    if ((buff = calloc(nmemb * size, sizeof(char))) == NULL)
//        exit(EXIT_FAILURE);
//    __mergesort(base, size, 0, nmemb - 1, compar);       // �迭 ��ü�� ���� ����
//
//    free(buff);
//}
//
///*--- int�� �� �Լ�(�������� ����) ---*/
//int int_cmp(const int* a, const int* b)
//{
//    return *a < *b ? -1 : *a > *b ? 1 : 0;
//}
//
//int main(void)
//{
//    int nx;
//
//    printf("m_sort�� ����\n");
//    printf("��� ����: ");
//    scanf("%d", &nx);
//    int* x = calloc(nx, sizeof(int));   // ��� ������ nx�� int�� �迭 x�� ����
//
//    for (int i = 0; i < nx; i++)
//    {
//        printf("x[%d] : ", i);
//        scanf("%d", &x[i]);
//    }
//
//    m_sort(x,                                           // �迭
//        nx,                                          // ��� ����
//        sizeof(int),                                 // ��� ũ��
//        (int (*)(const void*, const void*))int_cmp // �� �Լ�
//    );
//
//    puts("������������ �����߽��ϴ�.");
//    for (int i = 0; i < nx; i++)
//        printf("x[%d] = %d\n", i, x[i]);
//
//    free(x);                            // �迭 x�� ����
//
//    return 0;
//}
// ���� 6-19������ ���� ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* buff;          // �۾��� �迭

/*--- ���� ���� ����(main) ---*/
void __mergesort(char* a, size_t left, size_t right, size_t size,
    int (*compar)(const void*, const void*))
{
    if (left < right) {
        size_t center = (left + right) / 2;
        size_t p = 0;
        size_t i;
        size_t j = 0;
        size_t k = left;

        __mergesort(a, left, center, size, compar);         // �պκп� ���� ���� ����
        __mergesort(a, center + 1, right, size, compar);    // �޺κп� ���� ���� ����

        for (i = left; i <= center; i++)
            memcpy(&buff[p++ * size], &a[i * size], size);

        while (i <= right && j < p)
            memcpy(&a[k++ * size], compar((const void*)&buff[j * size], (const void*)&a[i * size]) <= 0 ?
                &buff[j++ * size] : &a[i++ * size], size);

        while (j < p)
            memcpy(&a[k++ * size], &buff[j++ * size], size);
    }
}

/*--- ���� ���� ���� ---*/
void m_sort(void* base, size_t nmemb, size_t size,
    int (*compar)(const void*, const void*))
{
    if (nmemb > 0) {
        buff = calloc(nmemb, size);

        __mergesort(base, 0, nmemb - 1, size, compar);      // �迭 ��ü�� ���� ����

        free(buff);
    }
}

/*--- int�� �� �Լ�(�������� ����) ---*/
int int_cmp(const int* a, const int* b)
{
    return *a < *b ? -1 : *a > *b ? 1 : 0;
}

int main(void)
{
    int nx;

    printf("m_sort�� ����\n");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ��� ������ nx�� int�� �迭 x�� ����

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    m_sort(x,                                           // �迭
        nx,                                          // ��� ����
        sizeof(int),                                 // ��� ũ��
        (int (*)(const void*, const void*))int_cmp // �� �Լ�
    );

    puts("������������ �����߽��ϴ�.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // �迭 x�� ����

    return 0;
}
