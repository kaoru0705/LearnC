// 버블 정렬(버전 2: 교환 횟수에 따라 정렬 작업을 멈춤)
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 버블 정렬(버전 2: 교환 횟수에 따라 정렬 작업을 멈춤) ---*/
void bubble(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int exchg = 0;              // 패스에서 시도한 교환 횟수
        for (int j = n - 1; j > i; j--)
            if (a[j - 1] > a[j]) {
                swap(int, a[j - 1], a[j]);
                exchg++;
            }
        if (exchg == 0) break;      // 교환이 수행되지 않았다면 정렬을 멈춤
    }
}
int is_sorted(const int a[], int n)
{
        int exchg = 0;              // 패스에서 시도한 교환 횟수
        for (int j = n - 1; j > 0; j--)
        {
            if (a[j - 1] > a[j])
            {
                exchg++;
                return 0;
            }
        }
        return 1;
}

// 연습 6-3　배열이 정렬을 마쳤는지를 검사
//
///*--- 배열이 정렬을 마쳤는가? ---*/
//int is_sorted(int a[], int n)
//{
//    for (int i = n - 1; i > 0; i--)
//        if (a[i - 1] > a[i])
//            return 0;
//    return 1;
//}
int main(void)
{
    int nx;

    puts("버블 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // 요소 개수 nx의 int형 배열 x 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    printf("%d\n", is_sorted(x, nx));
    bubble(x, nx);                      // 배열 x를 버블 정렬
    puts("오름차순으로 정렬했습니다.");
    printf("%d\n", is_sorted(x, nx));
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 배열 해제

    return 0;
}
