//// 버블 정렬(버전 3: 스캔 범위를 제한) 양방향 버블정렬 bidirection bubble sort or cocktail sort or shaker sort
//#include <stdio.h>
//#include <stdlib.h>
//#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)
//
///*--- 버블 정렬(버전 3: 스캔 범위를 제한) ---*/
//void shaker(int a[], int n)
//{                     
//    int left = 0;
//    int right = n-1;   
//    int ccnt = 0;
//    while (1)
//    {
//        if (left < n - 1) // int i는 필요없다. 어차피 홀짝 순서로 실행이기 때문에 
//        {
//            int last = n - 1;                   // 마지막으로 교환을 수행한 위치를 저장
//            for (int j = right; j > left; j--)
//            {
//                if (a[j - 1] > a[j])
//                {
//                    swap(int, a[j - 1], a[j]);
//                    last = j;
//                }
//                ccnt++;
//            }
//            left = last;
//        }
//        if (right > 0)
//        {
//
//            int last = 0;
//            for (int j = left; j < right; j++)
//            {
//                if (a[j] > a[j + 1])
//                {
//                    swap(int, a[j], a[j + 1]);
//                    last = j;
//                }
//                ccnt++;
//            }
//            right = last;
//        }
//        if (left == n-1 || right == 0) // == left > right
//        {
//            break;
//        }
//    }
//    printf("비교 횟수는 %d입니다.\n", ccnt);
//}
//
//int main(void)
//{
//    int nx;
//
//    puts("버블 정렬");
//    printf("요소 개수: ");
//    scanf("%d", &nx);
//    int* x = calloc(nx, sizeof(int));   // 요소 개수 nx의 int형 배열 x 생성
//
//    for (int i = 0; i < nx; i++)
//    {
//        printf("x[%d] : ", i);
//        scanf("%d", &x[i]);
//    }
//
//    shaker(x, nx);                      // 배열 x를 버블 정렬
//
//    puts("오름차순으로 정렬했습니다.");
//    for (int i = 0; i < nx; i++)
//        printf("x[%d] = %d\n", i, x[i]);
//
//    free(x);                            // 배열 해제
//
//    return 0;
//}
//연습 6-6　양방향 버블 정렬(셰이커 정렬)
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 양방향 버블 정렬(셰이커 정렬)---*/
void shaker(int a[], int n)
{
    int left = 0;
    int right = n - 1;
    int last = right;
    int ccnt = 0;
    while (left < right) {
        for (int j = right; j > left; j--) {
            if (a[j - 1] > a[j]) {
                swap(int, a[j - 1], a[j]);
                last = j;
            }
            ccnt++;
        }
        left = last;

        for (int j = left; j < right; j++) {
            if (a[j] > a[j + 1]) {
                swap(int, a[j], a[j + 1]);
                last = j;
            }
            ccnt++;
        }
        right = last;
    }
    printf("비교 횟수는 %d입니다.\n", ccnt);
}

int main(void)
{
    int nx;

    puts("양방향 버블 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    shaker(x, nx);                      // 배열 x를 양방향 버블 정렬

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 배열 x를 해제

    return 0;
}
