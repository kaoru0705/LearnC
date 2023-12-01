// 비재귀적 8퀸
//#include <stdio.h>
//#include "IntStack.h"
//
//int flag_a[8];      // 각 행에 퀸을 배치했는지 체크하는 배열
//int flag_b[15];     // 대각선 /에 퀸을 배치했는지 체크하는 배열
//int flag_c[15];     // 대각선 \에 퀸을 배치했는지 체크하는 배열
//int pos[8];         // 각 열에서 퀸의 위치
//
///*--- 각 열에서 퀸의 위치를 출력 ---*/
//void print(void)
//{
//    for (int i = 0; i < 8; i++)
//        printf("%2d", pos[i]);
//    putchar('\n');
//}
//
///*--- i열에서 알맞은 위치에 퀸을 배치 ---*/
//void set2(int i)
//{
//    for (int j = 0; j < 8; j++)
//    {
//        if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7])
//        {
//            pos[i] = j;
//            if (i == 7)         // 모든 열에 배치를 마침
//                print();
//            else
//            {
//                flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
//                set2(i + 1);     // 다음 열에 배치
//                flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
//            }
//        }
//    }
//}
//
//void set(int i)
//{
//    IntStack x, y;
//    Initialize(&x, 100);
//    Initialize(&y, 100);
//
//    for (int j = 0; j < 8; j++)
//    {
//        if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7])
//        {
//            Push(&x, i);
//            Push(&y, j);
//
//            pos[i] = j;
//            if (i == 7)         // 모든 열에 배치를 마침
//                print();
//            else
//            {
//                flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
//                i++;
//                j = -1;
//                continue;
//            }
//        }
//        while (!IsEmpty(&x) && j == 7)
//        {
//            Pop(&x, &i);
//            Pop(&y, &j);
//            flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
//        }
//        if(IsEmpty(&x) && pos[0] == 7) break;
//    }
//    Terminate(&x);
//    Terminate(&y);
//}
//int main(void)
//{
//    for (int i = 0; i < 8; i++)
//        flag_a[i] = 0;
//    for (int i = 0; i < 15; i++)
//        flag_b[i] = flag_c[i] = 0;
//
//    set(0);                     // 0열에 배치
//
//    return 0;
//}
// 연습 5-10　8퀸 문제를 비재귀적으로 풀이
// 주의: 이 프로그램을 컴파일하려면 'IntStack.h'와 'IntStack.c'가 필요합니다.
#include <stdio.h>
#include "IntStack.h"

int flag_a[8];      // 각 행에 퀸을 배치했는지 체크하는 배열
int flag_b[15];     // 대각선 /에 퀸을 배치했는지 체크하는 배열
int flag_c[15];     // 대각선 \에 퀸을 배치했는지 체크하는 배열
int pos[8];         // 각 열에서 퀸의 위치 */

/*--- 각 열에서 퀸의 위치를 출력 ---*/
void print(void)
{
    for (int i = 0; i < 8; i++)
        printf("%2d", pos[i]);
    putchar('\n');
}

/*--- i열에서 알맞은 위치에 퀸을 배치(비재귀 버전)--- 정답은 goto문을 썼으니 바꿔보겠다.*/
void set(int i)
{
    IntStack jstk;
    Initialize(&jstk, 8);

    while (1)
    {
        int j = 0;
        int flag = 0;
        while (1)
        {
            while (j < 8)
            {
                if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7])
                {
                    pos[i] = j;
                    if (i == 7)             // 모든 열에 배치를 마침
                        print();
                    else
                    {
                        flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
                        i++;
                        Push(&jstk, j);     // i열의 행을 푸시
                        flag = 1;
                        break;
                    }
                }
                if (flag) break;
                j++;
            }
            if (flag) break;
            if (--i == -1) return;
            Pop(&jstk, &j);                 // i열의 행을 팝
            flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
            j++;
        }
    }
    Terminate(&jstk);
}

int main(void)
{
    for (int i = 0; i < 8; i++)
        flag_a[i] = 0;
    for (int i = 0; i < 15; i++)
        flag_b[i] = flag_c[i] = 0;

    set(0);                     // 0열에 배치

    return 0;
}

