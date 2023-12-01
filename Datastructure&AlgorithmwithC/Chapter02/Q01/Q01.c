// 배열 요소의 최댓값을 구하고 출력(요솟값 입력)
#include <stdio.h>
#include <stdlib.h>

/*--- 요소 개수가 n인 배열 a의 요소의 최댓값 ---*/
int minof(const int a[], int n)
{
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min) min = a[i];
    return min;
}

int main(void)
{
    int number;
    printf("사람 수: ");
    scanf("%d", &number);
    int* height = calloc(number, sizeof(int));
    printf("%d명의 키를 입력하세요.\n", number);
    for (int i = 0; i < number; i++)
    {
        printf("height[%d] : ", i);
        scanf("%d", &height[i]);
    }
    printf("최솟값은 %d입니다.\n", minof(height, number));
    free(height);

    return 0;
}
