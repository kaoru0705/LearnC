/* Multi-Threading */
#define _CRT_SECURE_NO_WARNINGS

/*
    지금은 이해하기 어려울 수 있다. 멀티쓰레딩 공부를 하긴 해야 되는데 c++ 문법을 공부하고 c++ 뒷부분에서 매우 효율적으로 공부할 수 있다. c++ 강의 후반부 c언어에서도 된다.
    사진 참조
    프로그램을 실행시키면 프로그램이 프로세스에서 실행이 된다. 주된 문맥이 있고 이야기의 중간중간에 다른 이야기로 샌다 줄거리의 쓰레드가 갈린다 할 때 쓰레드 프로그램 실행시켜나가는 흐름
    흐름이 가다가 메인 쓰레드가 다른 쓰레드를 만들어서 띄울 수 있다. 동시성 프로그램 여러 쓰레드가 실행 쓰레드가 띄워졌다가 종료 병렬처리

    의문점 1 같은 함수를 여러 개의 쓰레드가 동시에 작동시킬 경우 함수의 지역변수는 어떠한 storage class를 갖는가?
    여러 개의 쓰레드가 하나의 함수를 동시에 호출하면 메모리 상에는 그 함수를 실행시키기 위한 데이터가 호출 횟수만큼 생성된다(지역변수들도 각각 호출 횟수 만큼 생성된다) 당연히 여러 사본이 있어야 한다

    2 하나의 전역변수를 여러 개의 쓰레드가 동시에 접근하려고 한다면?
    경쟁이 생긴다 CPU의 작동원리 데이터가 메모리에 저장되어 있는데 메모리의 저장된 값을 cpu의 전송하면 cpu 안의 레지스터라는 임시저장공간의 잠깐 올려놓고 작업을 하고 그 결과를 다시 메모리로 보낸다. 근데 메모리와 cpu가 왔다갔다하는 사이에 문제가 생길 수 있다.
    첫 번째 쓰레드가 메모리로부터 cpu로 데이터를 가져와서 작업하는 동안에 다른 쓰레드가 잽싸게 메모리의 값을 바꿔버린다면
*/

#include <stdio.h>
#include <windows.h>  // C언어 표준에는 멀티쓰레딩이 없기에 운영체제에서 제공하는 API를 사용해서 구현한다(그렇단 건 운영체제에 따라서 사용하는 프로그래밍 기술이 다르다)


//_Atomic int acnt = 0;  // NA(윈도우에서는 사용할 수 없다) 윈도우에선 atomic이 없고 pthread 따로 설치해야 됨 그럼 이걸 사용하지 않고 전역변수 충돌을 어케 막냐(병렬처리 멀티쓰레딩에서 나옴)

//DWORD WINAPI ThreadFunc(void* data)
//{
//    int n = 1;
//    Sleep(1000);
//
//    //acnt += n;  // NA
//    printf("Printing from thread \n");
//    return 0;
//}
//
//int main(void)
//{
//    HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);
//
//    if (thread)
//        WaitForSingleObject(thread, INFINITE);
//
//    return 0;
//}

/*
 GCC 컴파일러 혹은 인터넷에서 https://www.onlinegdb.com/online_c_compiler
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // sleep()
#include <pthread.h>  // windows에서도 사용 가능 window.h를 include하지 않고 pthread.h를 include할 수 있지만 그건 복잡하다. c++을 배우고 해라
#include <stdatomic.h> //_Atomic

// 하나의 쓰레드에서 데이터를 메모리에서 CPU까지 받았다 보냈다하는 사이에 다른 쓰레드가 잽싸게 해당 데이터의 메모리 값을 바꿔버린다면 문제가 생길 수 있다(racing(경쟁) condition)
// _Atomic 키워드는 이런 문제를 방지해준다. 단, _Atomic 변수는 연산속도가 느리기에 한 쓰레드 안에서 자주 사용하지 않아야 한다
_Atomic int acnt = 0;  // atomic type qualifier(const마냥) (C11)

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void* myThreadFun(void* vargp)
{
    int n = 1;  // thread storage duration으로 별도로 분류하기도 한다
    for (int j = 0; j < 10; ++j)
    {
        sleep(1);
        acnt += n;  // 이런 식으로 한 쓰레드 안에서 빈번하게 사용하는 것은 권장하지 않음
        printf("Printing from Thread %d %llu\n", acnt, (unsigned long long) & n);
    }

    return NULL;
}

int main(void)
{
    pthread_t thread_id1, thread_id2; // thread's indentification 쓰레드의 식별 내부적으로는 포인터처럼 사용, (변수라든지 포인터라든지) 쓰레드를 지정할 때 사용할 수 있다.
    // 식별자를 따로 두는 것들 다른 방법으로 두는 것들 다른 언어에서도 나오는 패턴 아직 뭔말인지 모르겠다

    printf("Before thread\n");

    // myThreadFun() 함수는 동시에 두 개의 카피가 존재하게 된다 일시적으로 이 두 개의 함수가 메모리와 cpu의 두 카피가 작동하게 된다.
    pthread_create(&thread_id1, NULL, myThreadFun, NULL); // myThreadFun을 실행시키는 쓰레드를 실행시키고  그 쓰레드에 대한 식별자를 &thread_id1(주소로)에 넣어준다
    pthread_create(&thread_id2, NULL, myThreadFun, NULL);

    pthread_join(thread_id1, NULL); // 쓰레드가 끝날 때까지 기다리는 함수(메인 쓰레드가 다른 쓰레드들이 끝날 때까지 기다리게 만든다) join 흩어졌다가 다시 합류
    pthread_join(thread_id2, NULL); // 메인 쓰레드가 다른 쓰레드한테 일 ㅈㄴ 시켜놓고 자기가 먼저 끝나버린다면? 메인함수가 끝나면 프로그램이 끝나버리니 쓰레드는 할일이 남았는데 어카노

    printf("After thread\n");
    printf("Atomic %d\n", acnt);
    return 0;
}

in gcc

To compile
    $ gcc <file-name.c> -o <output-file-name> -1pthread
To run
    & ./<output-file-name>
*/