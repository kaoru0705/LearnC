// 연습　퀵 정렬(업데이트 버전: 요소 개수가 9 이하면 단순 삽입 정렬） 방법2
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)
int sortoutmed(int a[], int x, int y, int z)
{
    if (a[y] > a[x])
        swap(int, a[y], a[x]);
    if (a[y] < a[z])
        swap(int, a[y], a[z]);
    if (a[y] > a[x])
        swap(int, a[y], a[x]);

    return y;
}
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
        int m = sortoutmed(a, pl, (pl + pr) / 2, pr);   // 요소의 개수가 3이상이면이지만 애초에 9이상이기 때문에 상관 없다. sortoutmed의 첫번째 parameter를 &a[left]로 하면 안 된다. pl pr이 기준을 잡아주고 있기 때문에
        int x = a[m];                                   // 피벗
        
        swap(int, a[m], a[right - 1]);
        pl++;
        pr -= 2;

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

    for (int i = 0; i < nx; i++)
    {
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

//// 연습 6-15　퀵 정렬(업데이트 버전: 요소 개수가 9 이하면 단순 삽입 정렬）
//#include <stdio.h>
//#include <stdlib.h>
//
//#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)
//
///*--- x[a], x[b], x[c]를 정렬(중앙값의 인덱스를 반환)---*/
//int sort3elem(int x[], int a, int b, int c)
//{
//    if (x[b] < x[a]) swap(int, x[b], x[a]);
//    if (x[c] < x[b]) swap(int, x[c], x[b]);
//    if (x[b] < x[a]) swap(int, x[b], x[a]);
//    return b;
//}
//
///*--- 단순 삽입 정렬 ---*/
//void insertion(int a[], int n)
//{
//    for (int i = 1; i < n; i++) {
//        int tmp = a[i];
//        int j;
//        for (j = i; j > 0 && a[j - 1] > tmp; j--)
//            a[j] = a[j - 1];
//        a[j] = tmp;
//    }
//}
//
///*--- 퀵 정렬 ---*/
//void quick(int a[], int left, int right)
//{
//    if (right - left < 9)
//        insertion(&a[left], right - left + 1);
//    else {
//        int pl = left;                                  // 왼쪽 커서
//        int pr = right;                                 // 오른쪽 커서
//        int m = sort3elem(a, pl, (pl + pr) / 2, pr);    // 처음, 끝, 가운데 요소를 정렬
//        int x = a[m];                                   // 피벗
//
//        swap(int, a[m], a[right - 1]);                  // 가운데와 끝에서 2번째 요소를 교환
//        pl++;                                           // 왼쪽 커서를 1 요소만큼 오른쪽으로 이동
//        pr -= 2;                                        // 오른쪽 커서를 2 요소만큼 왼쪽으로 이동
//
//        do {
//            while (a[pl] < x) pl++;
//            while (a[pr] > x) pr--;
//            if (pl <= pr) {
//                swap(int, a[pl], a[pr]);
//                pl++;
//                pr--;
//            }
//        } while (pl <= pr);
//
//        if (pr - left < right - pl) {
//            swap(int, pl, left);
//            swap(int, pr, right);
//        }
//        if (left < pr)  quick(a, left, pr);
//        if (pl < right) quick(a, pl, right);
//    }
//}
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
