////// 재귀에 대한 이해를 높이기 위한 진정한 재귀적 함수(재귀 제거)
////#include <stdio.h>
//
//// 연습 5-5 진정한 재귀적 함수 recur를 메모이제이션으로 구현
//#include <stdio.h>
//#include "intstack.h"
//
///*--- 재귀 호출을 제거한 recur3 함수 ---*/
//void recur3(int n)
//{
//    IntStack stk;                   // 스택
//    Initialize(&stk, 100);
//    while (1)
//    {
//        if (n > 0)
//        {
//            Push(&stk, n);          // n값을 푸시
//            n = n - 1;
//            continue;
//        }
//        if (!IsEmpty(&stk))         // 스택이 비어 있지 않으면
//        {
//            Pop(&stk, &n);          // 값을 저장했던 n을 팝
//            printf("%d\n", n);
//            n = n - 2;
//            continue;
//        }
//        else
//            break;
//    }
//    Terminate(&stk);
//}
//
//int counter = 0;                    // recur 함수의 호출 횟수
//static char memo[128][1024];        // 메모용 문자열 배열
//
///*--- 재귀 함수 recur ---*/
//void recur_a(int n)
//{
//    counter++;
//    if (n > 0) {
//        recur_a(n - 1);
//        printf("%d\n", n);
//        recur_a(n - 2);
//    }
//}
//
///*--- 메모이제이션을 도입한 recur 함수 ---*/
//void recur_b(int n) {
//    counter++;
//    if (memo[n + 1][0] != '\0')
//        printf("%s", memo[n + 1]);              // 메모 출력으로 그냥 넘겨버림
//    else {
//        if (n > 0) {
//            recur_b(n - 1);
//            printf("%d\n", n);
//            recur_b(n - 2);
//            sprintf(memo[n + 1], "%s%d\n%s", memo[n], n, memo[n - 1]);
//        }
//        else {
//            strcpy(memo[n + 1], "");
//        }
//    }
//}
//
//int main(void)
//{
//    int x;
//
//    printf("정수를 입력하세요.: ");
//    scanf("%d", &x);
//
//    recur3(x);
//    printf("\n");
//
//    recur_a(x);
//    printf("recur 함수는 %d회 출력되었습니다.\n", counter);
//    counter = 0;
//    printf("\n");
//
//    recur_b(x);
//    printf("recur 함수는 %d회 출력되었습니다.\n", counter);
//
//
//    return 0;
//}

// 연습 5-6　recur3 함수의 비재귀적 구현
// 주의: 이 프로그램을 컴파일하려면 'IntStack.h'와 'IntStack.c'가 필요합니다.
#include <stdio.h>
#include "IntStack.h"

/*--- recur3 함수(재귀를 제거) ---*/
void recur3(int n)
{
    int sw = 0;
    IntStack nstk, sstk;            // 스택

    Initialize(&nstk, 100);
    Initialize(&sstk, 100);

    while (1) {
        if (n > 0) {
            Push(&nstk, n);
            Push(&sstk, sw);

            if (sw == 0)
                n = n - 1;
            else if (sw == 1) {
                n = n - 2;
                sw = 0;
            }
            continue;
        }
        do {
            Pop(&nstk, &n);
            Pop(&sstk, &sw);
            sw++;

            if (sw == 2) {
                printf("%d\n", n);
                if (IsEmpty(&nstk))
                    return;
            }
        } while (sw == 2);
    }

    Terminate(&nstk);
    Terminate(&sstk);
}

int main(void)
{
    int x;

    printf("정수를 입력하세요.: ");
    scanf("%d", &x);

    recur3(x);

    return 0;
}
