//// 비재귀적 하노이의 탑
//#include <stdio.h>
//#include "IntStack.h"
///*--- 원반[1] ~ 원반[no]를 x 기둥에서 y 기둥으로 옮김 ---*/
//void move(int no, int x, int y)
//{
//    IntStack s[3];
//    for (int i = 0; i < 3; i++)
//        Initialize(&s[i], 100);
//    while (1)
//    {
//        // 그룹을 시작 기둥에서 중간 기둥으로
//        if (no > 0)
//        {
//            Push(&s[0], no);
//            Push(&s[1], x);
//            Push(&s[2], y);
//            no--;
//            y = 6 - x - y;
//            continue;
//        }
//        
//        if (!IsEmpty(&s[0]))
//        {
//            Pop(&s[0], &no);
//            Pop(&s[1], &x);
//            Pop(&s[2], &y);
//            // 바닥 원반을 목표 기둥으로
//            printf("원반[%d]를(을) %d 기둥에서 %d 기둥으로 옮김\n", no, x, y);
//
//            // 그룹을 중간 기둥에서 목표 기둥으로
//            no--;
//            x = 6 - x - y;
//            continue;
//        }
//        else
//            break;
//    }
//    for (int i = 0; i < 3; i++)
//        Terminate(&s[i]);
//}
//
//
//int main(void)
//{
//    int n;      // 원반의 개수
//    printf("하노이의 탑\n원반 개수: ");
//    scanf("%d", &n);
//    move(n, 1, 3);
//
//    return 0;
//}
// 연습 5-8 하노이의 탑(비재귀)
// 주의: 이 프로그램을 컴파일하려면 'IntStack.h'와 'IntStack.c'가 필요합니다.
#include <stdio.h>
#include "IntStack.h"

/*--- 원반[1] ~ 원반[no]를 x 기둥에서 y 기둥으로 옮김 ---*/
void move(int no, int x, int y)
{
    int sw = 0;
    IntStack xstk, ystk, sstk;      // 스택

    Initialize(&xstk, 100);
    Initialize(&ystk, 100);
    Initialize(&sstk, 100);

    while (1) {
        if (sw == 0 && no > 1) {
            Push(&xstk, x);             // x값을 푸시
            Push(&ystk, y);             // y값을 푸시
            Push(&sstk, sw);            // sw값을 푸시
            no = no - 1;
            y = 6 - x - y;
            continue;
        }

        printf("원반[%d]를(을) %d 기둥에서 %d 기둥으로 옮김\n", no, x, y);

        if (sw == 1 && no > 1) {
            Push(&xstk, x);             // x값을 푸시
            Push(&ystk, y);             // y값을 푸시
            Push(&sstk, sw);            // sw값을 푸시
            no = no - 1;
            x = 6 - x - y;
            if (++sw == 2) sw = 0;
            continue;
        }
        do {
            if (IsEmpty(&xstk))         // 스택이 비면
                return;
            Pop(&xstk, &x);             // 값을 저장했던 x를 팝
            Pop(&ystk, &y);             // 값을 저장했던 y를 팝
            Pop(&sstk, &sw);            // 값을 저장했던 sw를 팝
            sw++;
            no++;
        } while (sw == 2);
    }

    Terminate(&xstk);
    Terminate(&ystk);
    Terminate(&sstk);
}

int main(void)
{
    int n;      // 원반의 개수

    printf("하노이의 탑\n원반 개수: ");
    scanf("%d", &n);

    move(n, 1, 3);

    return 0;
}
/* CHATGPT
`sw` 변수는 하노이 탑 알고리즘에서 스택을 사용하여 원반을 옮기는 과정을 관리하기 위한 역할을 합니다. 이 변수는 스택을 이용하여 재귀적으로 원반을 옮기는 방법을 반복적으로 수행하는 데 사용됩니다.

하노이 탑 알고리즘은 원반을 옮기는 과정을 간단히 설명하면 다음과 같습니다:
1. 원반을 옮길 때는 항상 3개의 기둥이 관련됩니다: 출발 기둥(x), 보조 기둥(z), 목적지 기둥(y).
2. 큰 원반을 작은 원반 위로 옮길 수 없습니다.
3. 재귀적인 접근을 사용하여 원반을 옮깁니다.

`sw` 변수는 이러한 원반 옮기기 과정에서 현재 어떤 단계에 있는지를 나타냅니다. 코드에서 `sw` 값은 다음과 같이 변화합니다:

1. 초기 값으로 `sw`는 0으로 설정됩니다.
2. `sw`가 0인 경우: 현재 원반(`no`)이 1보다 크고, 아직 원반을 옮기지 않은 경우입니다.
이 경우, 현재 상태를 스택에 저장하고, `no`를 1 감소시키고 목적지 기둥(`y`)를 재계산한 후, `sw`를 1로 변경하지 않고 계속 진행합니다.
3. `sw`가 1인 경우: 원반을 옮기는 중이고, 아직 원반을 옮기지 않은 경우입니다.
이 경우, 현재 상태를 스택에 저장하고, `no`를 1 감소시키고 출발 기둥(`x`)를 재계산한 후, `sw`를 2로 변경하고 반복을 계속합니다.
4. `sw`가 2인 경우: 원반을 옮긴 후 다시 되돌아 오는 경우입니다. 스택에서 이전 상태를 팝하여 다시 그 상태로 돌아갑니다.

이런 식으로 `sw` 변수를 사용하여 원반을 옮기는 과정을 스택을 활용한 반복적인 프로세스로 구현하고, 스택을 사용하여 상태를 저장하고 복원합니다. 이를 통해 재귀적인 호출을 사용하지 않고도 하노이 탑 문제를 해결할 수 있습니다.
*/