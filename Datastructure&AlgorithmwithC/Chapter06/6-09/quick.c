// 퀵 정렬
/*
퀵 정렬의 평균 시간 복잡도가 O(n * log n)인 이유를 수학적으로 설명하겠습니다. 퀵 정렬은 분할 정복(divide and conquer) 알고리즘의 일종으로 작동합니다. 이 알고리즘을 통해 평균 시간 복잡도를 O(n * log n)으로 설명하는 방법은 다음과 같습니다.

1. 분할(Divide):
   - 퀵 정렬은 주어진 배열을 기준 원소(pivot)를 선택하고, 이 원소를 기준으로 배열을 두 개의 하위 배열로 분할합니다.
   - 기준 원소보다 작은 원소들은 왼쪽 하위 배열에 배치되고, 큰 원소들은 오른쪽 하위 배열에 배치됩니다.
   - 이 분할 단계에서 각 원소는 한 번의 비교 연산만으로 위치가 결정되므로 O(n) 시간이 걸립니다.

2. 정복(Conquer):
   - 분할된 하위 배열에 대해 재귀적으로 퀵 정렬을 호출합니다.
   - 각 하위 배열은 독립적으로 정렬됩니다.

3. 결합(Combine):
   - 별도의 결합 단계가 필요하지 않습니다. 퀵 정렬은 원래 배열을 분할하면서 정렬을 수행하므로 결합 단계가 없습니다.

퀵 정렬의 평균 시간 복잡도를 수학적으로 계산하려면 분할과정에서 평균적으로 몇 번의 비교가 이루어지는지를 고려해야 합니다. 이를 수식으로 나타내면 다음과 같습니다.

- T(n) = 2 * T(n/2) + O(n)

여기서 T(n)은 크기가 n인 배열을 정렬하는 데 필요한 비교 횟수를 나타냅니다.

퀵 정렬은 배열을 대략 반으로 나누고, 각 하위 배열에 대해 재귀적으로 정렬을 수행하므로 위 식을 사용하여 평균 시간 복잡도를 계산하면 다음과 같습니다.

- T(n) = 2 * T(n/2) + O(n)
- T(n) = 2 * [2 * T(n/4) + O(n/2)] + O(n)
- T(n) = 2^2 * T(n/2^2) + O(n) + O(n)
- T(n) = 2^3 * T(n/2^3) + O(n) + O(n) + O(n)
- ...
- T(n) = 2^k * T(n/2^k) + k * O(n)

여기서 k는 재귀 호출의 깊이입니다. 이제 T(n/2^k)가 1이 되는 지점을 찾으면 됩니다. 즉,

n/2^k = 1

이 됩니다. 여기서 2^k는 n과 같아지는 최소의 값은 log2(n)입니다. 따라서,

n/2^k = 1
n = 2^k
k = log2(n)

결국, T(n) = 2^k * T(n/2^k) + k * O(n)를 k = log2(n)을 대입하여 계산하면 다음과 같이 됩니다.

T(n) = 2^(log2(n)) * T(1) + log2(n) * O(n)
T(n) = n * T(1) + log2(n) * O(n)

T(1)은 상수 시간이므로 O(1)이며, 이를 전체 시간 복잡도에 대입하면 다음과 같습니다.

T(n) = n * O(1) + log2(n) * O(n)
T(n) = O(n) + O(n * log2(n))

따라서, 퀵 정렬의 평균 시간 복잡도는 O(n * log n)입니다. 이것이 퀵 정렬이 매우 효율적인 정렬 알고리즘 중 하나로 간주되는 이유 중 하나입니다.
*/
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)
int count = 0;
/*--- 퀵 정렬 함수 ---*/
void quick(int a[], int left, int right) // T(n) n == 10이라면?
{
    int pl = left;              // 왼쪽 커서
    int pr = right;             // 오른쪽 커서
    int x = a[(pl + pr) / 2];   // 피벗은 가운데 요소를 선택
    do {
        while (a[pl] < x) pl++; // n/2
        while (a[pr] > x) pr--; // n/2
        if (pl <= pr) {
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
            count++;
        }
    } while (pl <= pr); // n/2 + n/2
    if (left < pr)  quick(a, left, pr);  // T(n/2)
    if (pl < right) quick(a, pl, right); // T(n/2)
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
    quick(x, 0, nx - 1);                // 배열 x에 대해서 퀵 정렬
    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);                            // 배열 x를 해제
    printf("교환횟수: %d\n", count);

    return 0;
}
