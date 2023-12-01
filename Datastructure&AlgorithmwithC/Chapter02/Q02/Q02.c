// 배열 요소의 최댓값을 구하고 출력(요솟값 입력)
#include <stdio.h>
#include <stdlib.h>

/*--- 요소 개수가 n인 배열 a의 요소의 최댓값 ---*/
int sumof(const int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
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
    printf("합계는 %d입니다.\n", sumof(height, number));
    free(height);

    return 0;
}
