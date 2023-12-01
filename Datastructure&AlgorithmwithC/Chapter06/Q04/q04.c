// 버블 정렬(버전 2: 교환 횟수에 따라 정렬 작업을 멈춤)
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 버블 정렬(버전 2: 교환 횟수에 따라 정렬 작업을 멈춤) ---*/
void bubble(int a[], int n)
{
    int ccnt = 0, scnt = 0;              // 패스에서 시도한 교환 횟수
    for (int i = 0; i < n - 1; i++)
    {
        printf("패스%d: \n", i + 1);
        int exchg = 0;
        for (int j = n - 1; j > i; j--)
        {
            ccnt++;
            for (int k = 0; k < n; k++)
                printf("%c%d", (k !=j) ? ' ' : (a[j-1] > a[j]) ? '+' : '-', a[k]);
            printf("\n");
            if (a[j - 1] > a[j])
            {
                swap(int, a[j - 1], a[j]);
                exchg++;
            }
        }
        for (int k = 0; k < n; k++)
            printf("%2d", a[k]);
        printf("\n");
        if (exchg == 0) break;      // 교환이 수행되지 않았다면 정렬을 멈춤
        scnt += exchg;
    }
    printf("비교를 %d회 했습니다.\n", ccnt);
    printf("교환을 %d회 했습니다.\n", scnt);
}

int main(void)
{
    int nx;

    puts("버블 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // 요소 개수 nx의 int형 배열 x 생성

    for (int i = 0; i < nx; i++)
    {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    bubble(x, nx);                      // 배열 x를 버블 정렬

    free(x);                            // 배열 해제

    return 0;
}
