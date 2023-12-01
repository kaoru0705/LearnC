// 유클리드 호제법에 의해 최대공약수를 구하여 출력
#include <stdio.h>
#include <stdlib.h>
/*--- 정수 x, y의 최대공약수를 반환 ---*/
//int gcd_array(const int a[], int n)
//{
//    int gcd = a[0], x, y;
//    for (int i = 1; i < n; i++)
//    {
//        x = gcd;
//        y = a[i];
//        while (1)
//        {
//            gcd = x;
//            if (y == 0)
//                break;
//            else
//            {
//
//                x = y;
//                y = gcd % y;
//            }
//        }
//    }
//    return gcd;
//}
//
//int main(void)
//{
//    int* p, n;
//    printf("몇 개의 최대공약수를 구할 겁니까?: ");
//    scanf("%d", &n);
//    p = calloc(n, sizeof(int));
//    for (int i = 0; i < n; i++)
//    {
//        printf("정수를 입력하세요: ");
//        scanf("%d", &p[i]);
//    }
//    printf("최대공약수는 %d입니다.\n", gcd_array(p, n));
//
//    return 0;
//}

// 연습 5-3　배열의 모든 요소의 최대공약수를 구하여 출력
#include <stdio.h>

/*--- 정수 x, y의 최대공약수를 반환 ---*/
int gcd(int x, int y)
{
    if (y == 0)
        return (x);
    else
        return (gcd(y, x % y));
}

/*--- 요소 개수가 n인 배열 a의 모든 요소의 최대공약수 ---*/
int gcd_array(const int a[], int n)
{
    if (n == 1)
        return (a[0]);
    else if (n == 2)
        return (gcd(a[0], a[1]));
    else
        return (gcd(a[0], gcd_array(&a[1], n - 1)));
}

int main(void)
{
    int nx;

    printf("요소 개수: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    printf("최대공약수는 %d입니다.\n", gcd_array(x, nx));

    free(x);                            // 배열을 해제

    return 0;
}
