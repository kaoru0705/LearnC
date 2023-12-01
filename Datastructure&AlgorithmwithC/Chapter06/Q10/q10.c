// 이진 삽입 정렬 binary insertion sort
/*
주어진 코드는 이진 삽입 정렬을 구현한 코드입니다. 이진 삽입 정렬의 시간 복잡도를 분석하겠습니다.

1. 바깥쪽 `for` 루프에서는 배열을 순회하며 각 요소를 정렬된 부분에 삽입합니다. 이 부분의 시간 복잡도는 O(n)입니다.

2. 안쪽 `do-while` 루프에서는 이진 검색을 수행하여 현재 요소의 삽입 위치를 찾습니다. 이진 검색의 시간 복잡도는 O(log n)입니다. 이 부분은 바깥쪽 루프에서 각 요소마다 수행되므로 모든 요소에 대해 O(log n)의 시간이 소요됩니다.

3. 이진 검색 후, 요소를 실제로 삽입하기 위해 배열의 요소를 이동해야 합니다. 이 부분은 최악의 경우 O(n)의 시간이 소요됩니다.

따라서 전체적인 시간 복잡도는 바깥쪽 루프와 안쪽 루프의 시간 복잡도를 고려하여 다음과 같이 계산할 수 있습니다:

T(n) = O(n) * (O(log n) + O(n)) = O(n^2 + n*log n)

보통 이진 삽입 정렬은 이진 검색을 사용하기 때문에 일반적인 삽입 정렬보다 성능이 약간 향상됩니다. 따라서 시간 복잡도는 일반적인 삽입 정렬의 O(n^2)보다는 좀 더 낮은 수준인 O(n^2 + n*log n)입니다.
어차피 둘 다 O(n^2)이잖아 빼엑 그래도 위치를 대충은 파악하고 그걸로 계산을하니 그럴 수 있다는 말이다.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void binsertion(int a[], int n)
{


    for (int i = 1; i < n; i++)         // 1부터 n-1 대충 시간 복잡도는 O(n) 내부 이진검색은 O(log n) 합치면? O(n * log n) 실질적으로는 약간 더 낫다. O(n^2 + n*log n) 왜냐 위치를 찾아도 결국 배열옮기기를 하기 때문이다.
    {
        int pl = 0;                     // 검색 범위 맨 앞의 인덱스
        int pr = i - 1;                 // 검색 범위 맨 끝의 인덱스
        int pc;
        do
        {
            pc = (pl + pr) / 2;     // 검색 범위 한가운데의 인덱스
            if (a[pc] == a[i])           // 검색 성공
                break;
            else if (a[pc] < a[i])
                pl = pc + 1;            // 검색 범위를 뒤쪽 절반으로 좁힘
            else
                pr = pc - 1;            // 검색 범위를 앞쪽 절반으로 좁힘
        } while (pl <= pr);

        int tmp = a[i];
        /*for (j = i; j > 0 && a[j - 1] > tmp; j--)
            a[j] = a[j - 1];
        a[j] = tmp;*/
        if (a[pc] < a[i]) // 못 찾았을 때(pl>pr) 2가지 경우 a[i]가 그전놈들보다 크다? pc값은 하나 모자람 pc++. a[i]가 그전놈들보다 작다? pc==0임 그냥 넘어가도 된다 a[pc] == a[i]라면? 내건 pc++되지 않음 안정성이 없음
            pc++;
        for (int j = i; j > pc; j--)
            a[j] = a[j - 1]; // a[pc+1] = a[pc];
        a[pc] = tmp;
    }

}

int main(void)
{
    int nx;

    puts("단순 삽입 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // 요소의 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    binsertion(x, nx);                   // 배열 x를 단순 삽입 정렬

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 배열 해제
    return 0;
}

//// 연습 6-10　이진 삽입 정렬
//#include <stdio.h>
//#include <stdlib.h>
//
///*--- 이진 삽입 정렬 ---*/
//void bin_insertion(int a[], int n)
//{
//    int i, j;
//
//    for (i = 1; i < n; i++) {
//        int key = a[i];                         // key로 깔끔하게 만들어줌
//        int pl = 0;                             // 검색 범위 맨 앞의 인덱스
//        int pr = i - 1;                         // 검색 범위 맨 끝의 인덱스
//        int pc;                                 // 검색 범위 한가운데의 인덱스
//
//        do {
//            pc = (pl + pr) / 2;
//            if (a[pc] == key)                   // 검색 성공
//                break;
//            else if (a[pc] < key)
//                pl = pc + 1;
//            else
//                pr = pc - 1;
//        } while (pl <= pr);
//        int pd = (pl <= pr) ? pc + 1 : pr + 1;  // 삽입할 위치의 인덱스 pl <= pr즉 찾았으면 pc+1 pc 다음위치에 a[i]를 놓겠다. 안정성 있음 찾지 못했다? pr무조건 하나 모자른다.
//
//        for (j = i; j > pd; j--)
//            a[j] = a[j - 1];
//        a[pd] = key;
//    }
//}
//
//int main(void)
//{
//    int nx;
//
//    puts("이진 삽입 정렬");
//    printf("요소 개수: ");
//    scanf("%d", &nx);
//    int* x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성
//
//    for (int i = 0; i < nx; i++) {
//        printf("x[%d] : ", i);
//        scanf("%d", &x[i]);
//    }
//
//    bin_insertion(x, nx);               // 배열 x를 단순 삽입 정렬
//
//    puts("오름차순으로 정렬했습니다.");
//    for (int i = 0; i < nx; i++)
//        printf("x[%d] = %d\n", i, x[i]);
//
//    free(x);                            // 배열 x를 해제
//
//    return 0;
//}
