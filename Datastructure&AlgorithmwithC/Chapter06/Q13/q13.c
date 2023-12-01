// 퀵 정렬
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)
int count = 0;

/*--- 퀵 정렬 함수 ---*/
void quick_sort(int a[], int n)
{
    int pl = 0;
    int pr = n-1;
    int x = a[(pl + pr) / 2];   // 피벗은 가운데 요소를 선택

    do {
        while (a[pl] < x) pl++;
        while (a[pr] > x) pr--;
        if (pl <= pr)
        {
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
            count++;
        }
    } while (pl <= pr);

    if (0 < pr)  quick_sort(a, pr + 1);
    if (pl < n - 1) quick_sort(a + pl, n - pl);
}

int main(void)
{
    int nx;
    puts("퀵 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // 요소의 개수가 nx인 int형 배열 x를 생성
    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    quick_sort(x, nx);                // 배열 x에 대해서 퀵 정렬
    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);                            // 배열 x를 해제
    printf("교환횟수: %d\n", count);

    return 0;
}
