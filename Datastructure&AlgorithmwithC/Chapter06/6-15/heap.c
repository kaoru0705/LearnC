// 힙 정렬 프로그램
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)
/*--- a[left] ~ a[right]를 힙으로 만드는 함수 ---*/
static void downheap(int a[], int left, int right)
{
    int temp = a[left];             // 루트
    int child;
    int parent;
    for (parent = left; parent < (right + 1) / 2; parent = child) { // (right + 1) / 2? 부모는 (i - 1) /2 n개면 부모는 <= (n-1 + 1) / 2 == < n/2 범위가 부모까지 q22를 잘 봐라
        int cl = parent * 2 + 1;    // 왼쪽 자식
        int cr = cl + 1;            // 오른쪽 자식
        child = (cr <= right && a[cr] > a[cl]) ? cr : cl;   // 큰 값을 선택

        if (temp >= a[child])
            break;
        a[parent] = a[child];
    }
    a[parent] = temp;
}

/*--- 힙 정렬 함수 ---*/
void heapsort(int a[], int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--) // i가 (n-2)/2여야 마지막 부모니까 마지막부모부터 힙정렬하지 않음? ㅇㅇ 실제로 n-1/2로 하면 downheap했을 때 for문 건너뛴다. n = 11로 해서 실험해봐라 
        downheap(a, i, n - 1);

    for (int i = n - 1; i > 0; i--) { // n log n 위도 n/2 log n 즉 n log n
        swap(int, a[0], a[i]);
        downheap(a, 0, i - 1);
    }
}

int main(void)
{
    int nx;
    puts("힙 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // 요소의 개수가 nx인 int형 배열 x를 생성
    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    heapsort(x, nx);    // 배열 x를 힙 정렬
    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);            // 배열 x를 해제

    return 0;
}
