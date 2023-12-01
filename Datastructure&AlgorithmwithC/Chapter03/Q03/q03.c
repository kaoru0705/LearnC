//#include <stdio.h>
//#include <stdlib.h>
//
///*--- 요소의 개수가 n인 배열 a에서 key와 일치하는 요소를 선형 검색(for 문)---*/
//int search_idx(const int a[], int n, int key, int idx[])
//{
//    int count = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (a[i] == key)
//        {
//            idx[count] = i;
//            count++;
//        }
//    }
//    return count;
//}
//
//int main(void)
//{
//    int nx, ky;
//
//    puts("선형 검색");
//    printf("요소 개수 : ");
//    scanf("%d", &nx);
//    int* x = calloc(nx, sizeof(int));   // 요소의 개수가 nx인 int형 배열 x를 생성
//    int* y = calloc(nx, sizeof(int));   // 요소의 개수가 nx인 int형 배열 x를 생성
//    if (x == NULL || y == NULL)
//        exit(-1);
//
//    for (int i = 0; i < nx; i++) {
//        printf("x[%d] : ", i);
//        scanf("%d", &x[i]);
//    }
//    printf("검색값: ");
//    scanf("%d", &ky);
//    int idx = search_idx(x, nx, ky, y);        // 배열 x의 값이 ky인 요소를 선형 검색
//    if (idx == 0)
//        puts("검색에 실패했습니다.");
//    else
//        printf("동일한 값 %d를 찾았습니다.",idx);
//    
//    for (int i = 0; i < nx; i++)
//    {
//        if (y[i] == 0)
//            break;
//        printf("%d ", y[i]);
//    }
//    free(x);                            // 배열 x를 해제
//    free(y);
//
//    return 0;
//}
// 연습3-3　배열의 임의의 값과 일치하는 모든 요소의 인덱스를 추출
#include <stdio.h>
#include <stdlib.h>

/*--- 배열 a 안의 값이 key인 모든 요소의 인덱스를 idx에 저장 ---*/
int search_idx(const int a[], int n, int key, int idx[])
{
    int count = 0;

    for (int i = 0; i < n; i++)
        if (a[i] == key)
            idx[count++] = i;
    return count;
}

int main(void)
{
    int nx, ky;

    puts("선형 검색(모든 요소를 검색)");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));     // 요소 개수가 nx인 int형 배열 x를 생성
    int* idx = calloc(nx, sizeof(int));     // 요소 개수가 nx인 int형 배열 idx를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    printf("검색값: ");
    scanf("%d", &ky);

    int no = search_idx(x, nx, ky, idx);    // 배열 x에서 값이 ky인 모든 요소를 선형 탐색

    if (no == 0)
        puts("일치하는 요소가 없습니다.");
    else {
        printf("일치하는 요소는 다음과 같이 %d개입니다.\n", no);
        for (int i = 0; i < no; i++)
            printf("x[%d] ", idx[i]);
        putchar('\n');
    }

    free(x);                                // 배열 x를 해제
    free(idx);                              // 배열 idx를 해제

    return 0;
}
