//// qsort ���� ����� q13.c������
//#include <stdio.h>
//#include <stdlib.h>
//#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)
//
///*--- x, y�� ����Ű�� n����Ʈ�� ������ ��ȯ ---*/
//static void memswap(void* x, void* y, size_t n)
//{
//    unsigned char* a = (unsigned char*)x;       // unsigned char�� 1����Ʈ�� �״�� ����ϰ� �ű� �� �ִ�. ��� char���� �������.
//    unsigned char* b = (unsigned char*)y;
//   
//    for (; n--; a++, b++) // n--<0�� �ƴ� n-- ������ 0�ϰ�� �����ϹǷ� �̷��� �ߴ�. n = 4�� 4������ ;sequence point�� �ٷ� 3�� 3 2 1 0 ��
//    {
//        unsigned char c = *a;
//        *a = *b;
//        *b = c;
//    }
//}
//
///*--- int�� �� �Լ�(�������� ���Ŀ� ���) ---*/
//int int_cmp(const int* a, const int* b)
//{
//    if (*a < *b)
//        return -1;
//    else if (*a > *b)
//        return 1;
//    else
//        return 0;
//}
//q_sort(void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*))
//{
//    size_t pl = 0;              // ���� Ŀ��
//    size_t pr = nmemb - 1;      // ������ Ŀ�� pr�� -�� �Ǹ� �� �ȴ�. pl�� ���������� �þ�Ƿ� �������.
//    char* v = (char*)base;
//    char* x = &v[((pl + pr) / 2)*size];   // �ǹ��� ��� ��Ҹ� ����
//    do
//    {
//        while (compar((const void*)&v[pl * size], x) < 0) pl++;    // const void*�� casting�ϰ� const int* a�� ����
//        while (compar((const void*)&v[pr * size], x) > 0) pr--;
//        if (pl <= pr)
//        {
//            memswap(&v[pl*size], &v[pr*size], size);
//            pl++;
//            if (pr == 0)    // ��ȣ ���� ���� 0���κ����� ���� ����
//                break;
//            pr--;
//        }
//    } while (pl <= pr);
//
//    if (0 < pr)  q_sort(&v[0], pr + 1, size, compar);
//    if (pl < nmemb - 1) q_sort(&v[pl*size], nmemb - pl, size, compar);
//}
//int main(void)
//{
//    int nx;
//    printf("qsort�� ���� ����\n");
//    printf("��� ����: ");
//    scanf("%d", &nx);
//    int* x = calloc(nx, sizeof(int));   // ����� ������ nx�� int�� �迭 x�� ����
//    for (int i = 0; i < nx; i++)
//    {
//        printf("x[%d] : ", i);
//        scanf("%d", &x[i]);
//    }
//    q_sort(x,                                            // �迭
//        nx,                                           // ����� ����
//        sizeof(int),                                  // ����� ũ��
//        (int (*)(const void*, const void*))int_cmp  // �� �Լ�
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
// ���� 6-18������ �� ����(qsort �Լ��� ���� ����)
#include <stdio.h>
#include <stdlib.h>

/*--- x, y�� ����Ű�� n����Ʈ�� ������ ��ȯ ---*/
static void memswap(void* x, void* y, size_t n)
{
    unsigned char* a = (unsigned char*)x;
    unsigned char* b = (unsigned char*)y;

    for (; n--; a++, b++) {
        unsigned char c = *a;
        *a = *b;
        *b = c;
    }
}

/*--- ���� �� ����(qsort �Լ��� ���� ����)---*/
void q_sort(void* base, size_t nmemb, size_t size,
    int (*compar)(const void*, const void*))
{
    if (nmemb > 0) {
        size_t pl = 0;                  // ���� Ŀ��
        size_t pr = nmemb - 1;          // ������ Ŀ��
        size_t pv = nmemb;              // �ǹ�
        size_t pt = (pl + pr) / 2;      // �ǹ� ���Ű�
        char* v = (char*)base;         // �� �� ��ҿ� ���� ������

        do {
            char* x = &v[(pv = pt) * size];     // �ǹ��� ���� ������
            while (compar((const void*)&v[pl * size], x) < 0) pl++;
            while (compar((const void*)&v[pr * size], x) > 0) pr--;
            if (pl <= pr) {
                pt = (pl == pv) ? pr : (pr == pv) ? pl : pv;
                /*
                    ���� pt = (pl == pv) ? pr : (pr == pv) ? pl : pv;�� ������ �����ϰڽ��ϴ�.
                    ���� pl�� pv�� ���ٸ� (��, ���� Ŀ���� �ǹ� ��ġ�� �����ߴٸ�), pt�� pr�� �����մϴ�. �̰��� �ǹ��� ���������� �̵���Ű�� ���� ���Դϴ�.
                    �׷��� �ʰ�, ���� pr�� pv�� ���ٸ� (��, ������ Ŀ���� �ǹ� ��ġ�� �����ߴٸ�), pt�� pl�� �����մϴ�. �̰��� �ǹ��� �������� �̵���Ű�� ���� ���Դϴ�.
                    ���� �� ��쿡 �ش����� ������ pt�� �״�� pv�� �����մϴ�. �̴� �ǹ� ��ġ�� ������� �ʾ��� �� ���˴ϴ�.
                    ��, pt�� �ǹ��� �ű�� ���� ���� Ŀ��(pl)�� ������ Ŀ��(pr) �߿��� ��� ������ �̵���ų�� �����ϴ� ������ �մϴ�. �̷��� �����ν� �ǹ��� ��ġ�� �����ϰ� ������ ������ �� �ֽ��ϴ�.
                    �ٵ� ��ǻ� ���� ����
                */
                memswap(&v[pl * size], &v[pr * size], size);
                pl++;
                if (pr == 0)    // ��ȣ ���� ���� 0���κ����� ���� ����
                    goto QuickRight;
                pr--;
            }
        } while (pl <= pr);

        if (0 < pr)      q_sort(&v[0], pr + 1, size, compar);
    QuickRight:
        if (pl < nmemb - 1) q_sort(&v[pl * size], nmemb - pl, size, compar);
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

    printf("q_sort�� ����\n");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ��� ������ nx�� int�� �迭 x�� ����

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    q_sort(x,                                           // �迭
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
