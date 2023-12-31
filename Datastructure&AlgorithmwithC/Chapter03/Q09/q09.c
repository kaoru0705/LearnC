// 이진 검색
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
    return NULL;                            // 검색 실패
}

/*--- 정수를 비교하는 함수 ---*/
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

    puts("이진 검색");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x 생성
    printf("오름차순으로 입력하세요.\n");
    printf("x[0] : ");
    scanf("%d", &x[0]);
    for (int i = 1; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i - 1]);      // 바로 앞의 값보다 작으면 다시 입력
    }
    printf("검색값: ");
    scanf("%d", &ky);
    int* p = binsearchx(
        &ky,                            // 검색값에 대한 포인터
        x,                              // 배열
        nx,                             // 요소의 개수
        sizeof(int),                    // 요소의 크기
        (int (*)(const void*, const void*))int_cmp    // 비교 함수
    );

    if (p == NULL)
        puts("검색에 실패했습니다.");
    else
        printf("%d는(은) x[%d]에 있습니다.\n", ky, (int)(p - x));
    free(x);                            // 배열 x를 해제

    return 0;
}

//// 연습3-9　bsearch 함수를 확장한 함수(맨 앞에 있는 요소를 검색)
//#include <stdio.h>
//#include <stdlib.h>
//
///*--- base가 가리키는 요소의 크기가 size이고 요소의 개수가 nmemb인 배열에서 key와 일치하는 요소를
//      비교 함수 compar를 이용해서 이진 검색
//      ※ key와 같은 요소가 여러 개 있으면 맨 앞의 요소를 검색 ---*/
//void* bsearchx(const void* key, const void* base, size_t nmemb, size_t size,
//    int (*compar)(const void*, const void*))
//{
//    char* x = (char*)base;
//    size_t pl = 0;                          // 검색 범위 맨 앞의 인덱스
//    size_t pr = nmemb - 1;                  // 검색 범위 맨 끝의 인덱스
//
//    if (nmemb > 0) {
//        while (1) {
//            size_t pc = (pl + pr) / 2;      // 검색 범위 한가운데의 인덱스
//            int comp = compar((const void*)&x[pc * size], key);
//
//            if (comp == 0) {                // 검색 성공
//                for (; pc > pl; pc--)      // key와 같은 앞쪽 요소를 검색
//                    if (compar((const void*)&x[(pc - 1) * size], key))
//                        break;
//                return &x[pc * size];
//            }
//            else if (pl == pr)
//                break;
//            else if (comp < 0)
//                pl = pc + 1;                // 검색 범위를 뒤쪽 절반으로 좁힘
//            else
//                pr = pc - 1;                // 검색 범위를 앞쪽 절반으로 좁힘
//        }
//    }
//
//    return NULL;                            // 검색 실패
//}
//
///*--- 정수를 비교하는 함수 ---*/
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
//    puts("bsearchx 함수로 검색");
//    printf("요소 개수: ");
//    scanf("%d", &nx);
//    int* x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성
//
//    printf("오름차순으로 입력하세요.\n");
//    printf("x[0] : ");
//    scanf("%d", &x[0]);
//
//    for (int i = 1; i < nx; i++) {
//        do {
//            printf("x[%d] : ", i);
//            scanf("%d", &x[i]);
//        } while (x[i] < x[i - 1]);      // 바로 앞의 값보다 작으면 다시 입력
//    }
//
//    printf("검색값: ");
//    scanf("%d", &ky);
//
//    int* p = bsearchx(
//        &ky,                            // 검색값에 대한 포인터
//        x,                              // 배열
//        nx,                             // 요소의 개수
//        sizeof(int),                    // 요소의 크기
//        (int (*)(const void*, const void*))int_cmp    // 비교 함수
//    );
//
//    if (p == NULL)
//        puts("검색에 실패했습니다.");
//    else
//        printf("%d는(은) x[%d]에 있습니다.\n", ky, (int)(p - x));
//
//    free(x);                            // 배열 x를 해제
//
//    return 0;
//}
