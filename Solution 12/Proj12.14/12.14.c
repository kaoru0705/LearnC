/* 메모리 누수(Leak)와 free()의 중요성 비주얼 스튜디오 진단 도구(Diagnostic Tool) 사용법*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
    free()를 해서 운영체제에게 메모리를 반납해서 내가 작성한 프로그램이 다시 그 메모리를 사용하거나 운영체제가 관리하는 다른 프로그램이 그 메모리를 사용하도록 해야 한다.

    - 동적 할당받은 메모리를 사용이 끝났는데도 반납하지 않는 것을 메모리 누수라고 한다

    - 비주얼 스튜디오에서 x86을 x64로 바꾸면 힙 공간을 더 크게 사용할 수 있다 실무에서는 x64

    - 비주얼 스튜디오 진단도구: [Debug]-[Windows]-[Show Diagnostic Tools 클릭]

    *Heap Profiling을 체크하고 Take Snapshot을 클릭해가면서 힙 메모리 추적

*/
int main(void)
{
    printf("Dummy output\n");   //Diagnotics 메모리를 얼마나 쓰는지 cpu를 얼마나 쓰는지 모니터링 할 수 있다. Memory Usage Heap Profiling 클릭 Take Snapshot(현재 상태를 찍음)

    int* ptr_backup = NULL;   //개인적으로 이렇게 코딩하는 것을 권장하지 않는다. 블럭을 안에서 선언한 메모리는 블럭을 나올 때 지우는 게 깔끔하고 실수를 줄일 수 있는 측면이 있다.

    for(int k = 0 ; k < 1000000 ; ++k)  // 메모리 누수 테스트 25번 줄에 f9을 하고 f5(continue)를 연속으로 해봐라(continue는 다음 종단점까지 감 반복문이라 25번으로 다시 왔다.) 메모리가 계속 늘어난다. 무섭다. 물론 실무에서는 가급적 발생하지 않도록 하고 있다.
    {
        int n = 100000000;  //x64를 사용하면 힙을 더 크게 사용할 수 있다 힙 메모리 공간을 더 크게. x86이면 Malloc() failed가 빨리 뜸 내가 가진 최대 메모리를 힙으로 사용하는 게 아니고 컴파일러가 사용할 수 있는 한도가 낮다 몇 기가 정도 x64 사용이 일반적
        int* ptr = (int*)malloc(n * sizeof(int));  // 4억 바이트 = 4억 / 1024 = 390,625 킬로바이트
                                                   //         = 390,625 / 1024 = 381.4 메가바이트

        if (!ptr) // if(ptr == NULL). 널 포인터인 경우 종료 취향대로 써라 교수님은 ptr == NULL을 더 많이 씀
        {  
            printf("Malloc() failed\n");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < n; ++i)
            ptr[i] = i + 1;

        printf("%d %d\n", ptr[0], ptr[1]);

        //ptr_backup = ptr;  // 스코프를 벗어나서도 동적 할당된 메모리에 접근하기 위한 방법

        //free(ptr);  // 1 의도가 블럭이 끝날 때 더 이상 동적할당을 쓰지 않을 생각이라면 여기서 free() ptr = NULL
        //ptr = NULL;  // 1 블럭을 나가면 없어지겠지만 그래도 NULL을 해놓는다. 명확하게 보여주기 위해서
    }

    //printf("%d %d\n", ptr_backup[0], ptr_backup[1]);  // 만약 위쪽의 스코프에서 할당 받은 메모리를 반납했다면 예외 발생 Runtime error
    printf("Dummy output\n");  // 커서를 두면 나오는 초록색 화살표를 클릭하면 바로 진행되는 화살표가 여기로 온다. 아니면 f9을 누르고 다시 f5 or right click Run to cursor(Ctrl f10)
    // What happens?(윗 줄의 1을 생략하면 동적 할당받은 메모리 주소를 가진 포인터는 사라지지만 할당 받은 메모리는 그대로 남아있다 다시 snapshot을 해봐라 heap사이즈 변화가 없다.)

    return 0;
}