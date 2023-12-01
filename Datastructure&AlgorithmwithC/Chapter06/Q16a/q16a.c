//// 퀵 정렬(요소 개수가 작은 그룹을 우선 분할: 재귀 버전)
//#include <stdio.h>
//#include <stdlib.h>
//
//#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)
///*--- 단순 삽입 정렬 함수 ---*/
//void insertion(int a[], int n)
//{
//    for (int i = 1; i < n; i++)
//    {
//        int tmp = a[i];
//        int j;
//        for (j = i; j > 0 && a[j - 1] > tmp; j--)
//        {
//            a[j] = a[j - 1];
//        }
//        a[j] = tmp;
//    }
//}
//
///*--- 퀵 정렬(요소 개수가 작은 그룹을 우선 분할) ---*/
//void quick(int a[], int left, int right)
//{
//    int pl = left;              // 왼쪽 커서
//    int pr = right;             // 오른쪽 커서
//    int x = a[(pl + pr) / 2];   // 피벗은 가운데 요소
//
//    do
//    {
//        while (a[pl] < x) pl++;
//        while (a[pr] > x) pr--;
//        if (pl <= pr)
//        {
//            swap(int, a[pl], a[pr]);
//            pl++;
//            pr--;
//        }
//    } while (pl <= pr);
//
//    if (pr - left < right - pl)
//    {
//        swap(int, pl, left);
//        swap(int, pr, right);
//    }
//    if (pl < right)
//        if (right - pl <= 9)
//            insertion(a + pl, right - pl + 1);
//        else
//        quick(a, pl, right); // 사실 하나 호출하고 끝나고 호출하는 거라 의미 적은 요소부터 호출하는 게 의미가 없다. 메모리를 딱히 줄일 수가 없다.
//
//    if (left < pr)
//        if (pr - left <= 9)
//            insertion(a + left, pr - left + 1);
//        else
//            quick(a, left, pr);
//}
//
//
//int main(void)
//{
//    int nx;
//
//    puts("퀵 정렬");
//    printf("요소 개수: ");
//    scanf("%d", &nx);
//    int* x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성
//
//    for (int i = 0; i < nx; i++) {
//        printf("x[%d] : ", i);
//        scanf("%d", &x[i]);
//    }
//
//    quick(x, 0, nx - 1);                // 배열 x를 퀵 정렬
//
//    puts("오름차순으로 정렬했습니다.");
//    for (int i = 0; i < nx; i++)
//        printf("x[%d] = %d\n", i, x[i]);
//
//    free(x);                            // 배열 x를 해제
//
//    return 0;
//}

// 연습 6-15　퀵 정렬(업데이트 버전: 요소 개수가 9 이하면 단순 삽입 정렬）
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- 단순 삽입 정렬 ---*/
void insertion(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int tmp = a[i];
        int j;
        for (j = i; j > 0 && a[j - 1] > tmp; j--)
            a[j] = a[j - 1];
        a[j] = tmp;
    }
}

/*--- 퀵 정렬 ---*/
void quick(int a[], int left, int right)
{
    if (right - left < 9) // right - left + 1 <= 9
        insertion(&a[left], right - left + 1);
    else
    {
        int pl = left;                                  // 왼쪽 커서
        int pr = right;                                 // 오른쪽 커서
        int x = a[(pl + pr) / 2];                       // 피벗

        do
        {
            while (a[pl] < x) pl++;
            while (a[pr] > x) pr--;
            if (pl <= pr)
            {
                swap(int, a[pl], a[pr]);
                pl++;
                pr--;
            }
        } while (pl <= pr);

        if (pr - left < right - pl)
        {
            swap(int, pl, left);
            swap(int, pr, right);
        }
        if (left < pr)  quick(a, left, pr);
        if (pl < right) quick(a, pl, right);
    }
}

int main(void)
{
    int nx;

    puts("퀵 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    quick(x, 0, nx - 1);                // 배열 x를 퀵 정렬

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 배열 x를 해제

    return 0;
}
