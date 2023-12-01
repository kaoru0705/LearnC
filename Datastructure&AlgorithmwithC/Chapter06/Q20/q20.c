//// qsort 직접 만들기 q13.c참조함
//#include <stdio.h>
//#include <stdlib.h>
//#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)
//
///*--- x, y가 가리키는 n바이트의 영역을 교환 ---*/
//static void memswap(void* x, void* y, size_t n)
//{
//    unsigned char* a = (unsigned char*)x;       // unsigned char는 1바이트를 그대로 깔끔하게 옮길 수 있다. 사실 char여도 상관없다.
//    unsigned char* b = (unsigned char*)y;
//   
//    for (; n--; a++, b++) // n--<0이 아닌 n-- 조건은 0일경우 실패하므로 이렇게 했다. n = 4면 4끝나고 ;sequence point니 바로 3됨 3 2 1 0 끝
//    {
//        unsigned char c = *a;
//        *a = *b;
//        *b = c;
//    }
//}
//
///*--- int형 비교 함수(오름차순 정렬에 사용) ---*/
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
//    size_t pl = 0;              // 왼쪽 커서
//    size_t pr = nmemb - 1;      // 오른쪽 커서 pr이 -가 되면 안 된다. pl은 오른쪽으로 늘어나므로 상관없다.
//    char* v = (char*)base;
//    char* x = &v[((pl + pr) / 2)*size];   // 피벗은 가운데 요소를 선택
//    do
//    {
//        while (compar((const void*)&v[pl * size], x) < 0) pl++;    // const void*로 casting하고 const int* a에 넣음
//        while (compar((const void*)&v[pr * size], x) > 0) pr--;
//        if (pl <= pr)
//        {
//            memswap(&v[pl*size], &v[pr*size], size);
//            pl++;
//            if (pr == 0)    // 부호 없는 정수 0으로부터의 감소 방지
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
//    printf("qsort에 의한 정렬\n");
//    printf("요소 개수: ");
//    scanf("%d", &nx);
//    int* x = calloc(nx, sizeof(int));   // 요소의 개수가 nx인 int형 배열 x를 생성
//    for (int i = 0; i < nx; i++)
//    {
//        printf("x[%d] : ", i);
//        scanf("%d", &x[i]);
//    }
//    q_sort(x,                                            // 배열
//        nx,                                           // 요소의 개수
//        sizeof(int),                                  // 요소의 크기
//        (int (*)(const void*, const void*))int_cmp  // 비교 함수
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
// 연습 6-18　범용 퀵 정렬(qsort 함수와 같은 형식)
#include <stdio.h>
#include <stdlib.h>

/*--- x, y가 가리키는 n바이트의 영역을 교환 ---*/
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

/*--- 범용 퀵 정렬(qsort 함수와 같은 형식)---*/
void q_sort(void* base, size_t nmemb, size_t size,
    int (*compar)(const void*, const void*))
{
    if (nmemb > 0) {
        size_t pl = 0;                  // 왼쪽 커서
        size_t pr = nmemb - 1;          // 오른쪽 커서
        size_t pv = nmemb;              // 피벗
        size_t pt = (pl + pr) / 2;      // 피벗 갱신값
        char* v = (char*)base;         // 맨 앞 요소에 대한 포인터

        do {
            char* x = &v[(pv = pt) * size];     // 피벗에 대한 포인터
            while (compar((const void*)&v[pl * size], x) < 0) pl++;
            while (compar((const void*)&v[pr * size], x) > 0) pr--;
            if (pl <= pr) {
                pt = (pl == pv) ? pr : (pr == pv) ? pl : pv;
                /*
                    이제 pt = (pl == pv) ? pr : (pr == pv) ? pl : pv;의 역할을 설명하겠습니다.
                    만약 pl이 pv와 같다면 (즉, 왼쪽 커서가 피벗 위치에 도달했다면), pt를 pr로 설정합니다. 이것은 피벗을 오른쪽으로 이동시키기 위한 것입니다.
                    그렇지 않고, 만약 pr이 pv와 같다면 (즉, 오른쪽 커서가 피벗 위치에 도달했다면), pt를 pl로 설정합니다. 이것은 피벗을 왼쪽으로 이동시키기 위한 것입니다.
                    위의 두 경우에 해당하지 않으면 pt를 그대로 pv로 설정합니다. 이는 피벗 위치가 변경되지 않았을 때 사용됩니다.
                    즉, pt는 피벗을 옮기기 위해 왼쪽 커서(pl)와 오른쪽 커서(pr) 중에서 어느 쪽으로 이동시킬지 결정하는 역할을 합니다. 이렇게 함으로써 피벗의 위치를 조정하고 정렬을 진행할 수 있습니다.
                    근데 사실상 쓸모가 ㅋㅋ
                */
                memswap(&v[pl * size], &v[pr * size], size);
                pl++;
                if (pr == 0)    // 부호 없는 정수 0으로부터의 감소 방지
                    goto QuickRight;
                pr--;
            }
        } while (pl <= pr);

        if (0 < pr)      q_sort(&v[0], pr + 1, size, compar);
    QuickRight:
        if (pl < nmemb - 1) q_sort(&v[pl * size], nmemb - pl, size, compar);
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

    printf("q_sort로 정렬\n");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    q_sort(x,                                           // 배열
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
