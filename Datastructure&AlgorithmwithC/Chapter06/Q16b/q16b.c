// 연습 6-15　비재귀적 퀵 정렬(업데이트 버전: 요소 개수가 9 이하면 단순 삽입 정렬, 요소 개수가 작은 그룹을 우선 분할)
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

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

void quick(int a[], int left, int right)
{
    IntStack lstack;        // 나눌 첫 요소 인덱스의 스택
    IntStack rstack;        // 나눌 끝 요소 인덱스의 스택

    Initialize(&lstack, right - left + 1);
    Initialize(&rstack, right - left + 1);

    Push(&lstack, left);
    Push(&rstack, right);

    while (!IsEmpty(&lstack))
    {
        Pop(&lstack, &left);
        Pop(&rstack, &right);

        if (right - left < 9) // right - left + 1 <= 9
            insertion(&a[left], right - left + 1);
        else
        {
            int pl = left;       // 왼쪽 커서
            int pr = right;     // 오른쪽 커서
            int x = a[(left + right) / 2];              // 피벗은 가운데 요소

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

            if (left < pr)
            {
                Push(&lstack, left);    // 왼쪽 그룸 범위의
                Push(&rstack, pr);      // 인덱스를 푸시
            }
            if (pl < right)
            {
                Push(&lstack, pl);      // 오른쪽 그룹 범위의
                Push(&rstack, right);   // 인덱스를 푸시
            }
        }
    }
    Terminate(&lstack);
    Terminate(&rstack);
}

int main(void)
{
    int nx;

    puts("퀵 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // 요소의 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++)
    {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    quick(x, 0, nx - 1);                // 배열 x에 대해서 퀵 정렬

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 배열 x를 해제

    return 0;
}
