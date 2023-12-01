//#include <stdio.h>
//#include <stdlib.h>
//
//static char* buff;           // 작업용 배열
//
///*--- x, y가 가리키는 n바이트의 영역을 교환 ---*/
//static void memassign(void* x, void* y, size_t n)
//{
//    unsigned char* a = (unsigned char*)x;
//    unsigned char* b = (unsigned char*)y;
//
//    for (; n--; a++, b++)
//        *a = *b;
//}
//
///*--- 병합 정렬(main) ---*/ // nlogn stable
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
//        __mergesort(a, size, left, center, compar);           // 앞부분에 대한 병합 정렬
//        __mergesort(a, size, center + 1, right, compar);      // 뒷부분에 대한 병합 정렬
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
//            memassign(&a[k++ * size], &buff[j++ * size], size); // ex left = 0 right = 4일 시 (홀수개) buff쪽 요소가 하나 더 많다. 
//    }
//}
//
///*--- 범용 병합 정렬---*/
//void m_sort(void* base, size_t nmemb, size_t size,
//    int (*compar)(const void*, const void*))
//{
//    if ((buff = calloc(nmemb * size, sizeof(char))) == NULL)
//        exit(EXIT_FAILURE);
//    __mergesort(base, size, 0, nmemb - 1, compar);       // 배열 전체를 병합 정렬
//
//    free(buff);
//}
//
///*--- int형 비교 함수(오름차순 정렬) ---*/
//int int_cmp(const int* a, const int* b)
//{
//    return *a < *b ? -1 : *a > *b ? 1 : 0;
//}
//
//int main(void)
//{
//    int nx;
//
//    printf("m_sort로 정렬\n");
//    printf("요소 개수: ");
//    scanf("%d", &nx);
//    int* x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성
//
//    for (int i = 0; i < nx; i++)
//    {
//        printf("x[%d] : ", i);
//        scanf("%d", &x[i]);
//    }
//
//    m_sort(x,                                           // 배열
//        nx,                                          // 요소 개수
//        sizeof(int),                                 // 요소 크기
//        (int (*)(const void*, const void*))int_cmp // 비교 함수
//    );
//
//    puts("오름차순으로 정렬했습니다.");
//    for (int i = 0; i < nx; i++)
//        printf("x[%d] = %d\n", i, x[i]);
//
//    free(x);                            // 배열 x를 해제
//
//    return 0;
//}
// 연습 6-19　범용 병합 정렬
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* buff;          // 작업용 배열

/*--- 범용 병합 정렬(main) ---*/
void __mergesort(char* a, size_t left, size_t right, size_t size,
    int (*compar)(const void*, const void*))
{
    if (left < right) {
        size_t center = (left + right) / 2;
        size_t p = 0;
        size_t i;
        size_t j = 0;
        size_t k = left;

        __mergesort(a, left, center, size, compar);         // 앞부분에 대한 병합 정렬
        __mergesort(a, center + 1, right, size, compar);    // 뒷부분에 대한 병합 정렬

        for (i = left; i <= center; i++)
            memcpy(&buff[p++ * size], &a[i * size], size);

        while (i <= right && j < p)
            memcpy(&a[k++ * size], compar((const void*)&buff[j * size], (const void*)&a[i * size]) <= 0 ?
                &buff[j++ * size] : &a[i++ * size], size);

        while (j < p)
            memcpy(&a[k++ * size], &buff[j++ * size], size);
    }
}

/*--- 범용 병합 정렬 ---*/
void m_sort(void* base, size_t nmemb, size_t size,
    int (*compar)(const void*, const void*))
{
    if (nmemb > 0) {
        buff = calloc(nmemb, size);

        __mergesort(base, 0, nmemb - 1, size, compar);      // 배열 전체를 병합 정렬

        free(buff);
    }
}

/*--- int형 비교 함수(오름차순 정렬) ---*/
int int_cmp(const int* a, const int* b)
{
    return *a < *b ? -1 : *a > *b ? 1 : 0;
}

int main(void)
{
    int nx;

    printf("m_sort로 정렬\n");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    m_sort(x,                                           // 배열
        nx,                                          // 요소 개수
        sizeof(int),                                 // 요소 크기
        (int (*)(const void*, const void*))int_cmp // 비교 함수
    );

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 배열 x를 해제

    return 0;
}
