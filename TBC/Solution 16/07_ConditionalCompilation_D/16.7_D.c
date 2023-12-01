/* build할 때 옵션으로서 어떻게 빌드할지 바꿔줄 수 있다. 그때 전처리 정의를 이용할 수 있다. */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>

#define REPORT  // 매크로 이름만 정의되어 있는 것을 empty macro, 코드를 매번 바꿔야 하는데 이걸 조건적으로 컴파일한다고 볼 수 있나?

/*
    디버그 모드와 릴리즈 모드의 차이
    - 컴파일할 때 옵션으로 디버그에 필요한 내용을 빌드에 포함시키라고 전처리 지시자에서 명령이 들어가는가, 안 들어가는가의 여부
*/

int sum(int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; ++k)
    {
        s += k;

//#ifdef _DEBUG   // 디버그 모드에서만 컴파일하는 코드 preprocessor definition에 이미 들어가 있다.
#ifdef REPORT  // TODO: change in project properties(VS에서 [C/C++]-[Preprocessor] [Preprocessor Definitions]에서 전처리기 정의가 미리 정의 된 게 있다. 거기서 REPORT;)
        printf("%d %d\n", s, k);
#endif
    }

    return s;
}

int main(void)
{
    printf("\n%d \n", sum(1, 10));

    return 0;
}