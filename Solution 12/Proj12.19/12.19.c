/* Multi-Threading */
#define _CRT_SECURE_NO_WARNINGS

/*
    ������ �����ϱ� ����� �� �ִ�. ��Ƽ������ ���θ� �ϱ� �ؾ� �Ǵµ� c++ ������ �����ϰ� c++ �޺κп��� �ſ� ȿ�������� ������ �� �ִ�. c++ ���� �Ĺݺ� c������ �ȴ�.
    ���� ����
    ���α׷��� �����Ű�� ���α׷��� ���μ������� ������ �ȴ�. �ֵ� ������ �ְ� �̾߱��� �߰��߰��� �ٸ� �̾߱�� ���� �ٰŸ��� �����尡 ������ �� �� ������ ���α׷� ������ѳ����� �帧
    �帧�� ���ٰ� ���� �����尡 �ٸ� �����带 ���� ��� �� �ִ�. ���ü� ���α׷� ���� �����尡 ���� �����尡 ������ٰ� ���� ����ó��

    �ǹ��� 1 ���� �Լ��� ���� ���� �����尡 ���ÿ� �۵���ų ��� �Լ��� ���������� ��� storage class�� ���°�?
    ���� ���� �����尡 �ϳ��� �Լ��� ���ÿ� ȣ���ϸ� �޸� �󿡴� �� �Լ��� �����Ű�� ���� �����Ͱ� ȣ�� Ƚ����ŭ �����ȴ�(���������鵵 ���� ȣ�� Ƚ�� ��ŭ �����ȴ�) �翬�� ���� �纻�� �־�� �Ѵ�

    2 �ϳ��� ���������� ���� ���� �����尡 ���ÿ� �����Ϸ��� �Ѵٸ�?
    ������ ����� CPU�� �۵����� �����Ͱ� �޸𸮿� ����Ǿ� �ִµ� �޸��� ����� ���� cpu�� �����ϸ� cpu ���� �������Ͷ�� �ӽ���������� ��� �÷����� �۾��� �ϰ� �� ����� �ٽ� �޸𸮷� ������. �ٵ� �޸𸮿� cpu�� �Դٰ����ϴ� ���̿� ������ ���� �� �ִ�.
    ù ��° �����尡 �޸𸮷κ��� cpu�� �����͸� �����ͼ� �۾��ϴ� ���ȿ� �ٸ� �����尡 ��ΰ� �޸��� ���� �ٲ�����ٸ�
*/

#include <stdio.h>
#include <windows.h>  // C��� ǥ�ؿ��� ��Ƽ�������� ���⿡ �ü������ �����ϴ� API�� ����ؼ� �����Ѵ�(�׷��� �� �ü���� ���� ����ϴ� ���α׷��� ����� �ٸ���)


//_Atomic int acnt = 0;  // NA(�����쿡���� ����� �� ����) �����쿡�� atomic�� ���� pthread ���� ��ġ�ؾ� �� �׷� �̰� ������� �ʰ� �������� �浹�� ���� ����(����ó�� ��Ƽ���������� ����)

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
 GCC �����Ϸ� Ȥ�� ���ͳݿ��� https://www.onlinegdb.com/online_c_compiler
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // sleep()
#include <pthread.h>  // windows������ ��� ���� window.h�� include���� �ʰ� pthread.h�� include�� �� ������ �װ� �����ϴ�. c++�� ���� �ض�
#include <stdatomic.h> //_Atomic

// �ϳ��� �����忡�� �����͸� �޸𸮿��� CPU���� �޾Ҵ� ���´��ϴ� ���̿� �ٸ� �����尡 ��ΰ� �ش� �������� �޸� ���� �ٲ�����ٸ� ������ ���� �� �ִ�(racing(����) condition)
// _Atomic Ű����� �̷� ������ �������ش�. ��, _Atomic ������ ����ӵ��� �����⿡ �� ������ �ȿ��� ���� ������� �ʾƾ� �Ѵ�
_Atomic int acnt = 0;  // atomic type qualifier(const����) (C11)

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void* myThreadFun(void* vargp)
{
    int n = 1;  // thread storage duration���� ������ �з��ϱ⵵ �Ѵ�
    for (int j = 0; j < 10; ++j)
    {
        sleep(1);
        acnt += n;  // �̷� ������ �� ������ �ȿ��� ����ϰ� ����ϴ� ���� �������� ����
        printf("Printing from Thread %d %llu\n", acnt, (unsigned long long) & n);
    }

    return NULL;
}

int main(void)
{
    pthread_t thread_id1, thread_id2; // thread's indentification �������� �ĺ� ���������δ� ������ó�� ���, (��������� �����Ͷ����) �����带 ������ �� ����� �� �ִ�.
    // �ĺ��ڸ� ���� �δ� �͵� �ٸ� ������� �δ� �͵� �ٸ� ������ ������ ���� ���� �������� �𸣰ڴ�

    printf("Before thread\n");

    // myThreadFun() �Լ��� ���ÿ� �� ���� ī�ǰ� �����ϰ� �ȴ� �Ͻ������� �� �� ���� �Լ��� �޸𸮿� cpu�� �� ī�ǰ� �۵��ϰ� �ȴ�.
    pthread_create(&thread_id1, NULL, myThreadFun, NULL); // myThreadFun�� �����Ű�� �����带 �����Ű��  �� �����忡 ���� �ĺ��ڸ� &thread_id1(�ּҷ�)�� �־��ش�
    pthread_create(&thread_id2, NULL, myThreadFun, NULL);

    pthread_join(thread_id1, NULL); // �����尡 ���� ������ ��ٸ��� �Լ�(���� �����尡 �ٸ� ��������� ���� ������ ��ٸ��� �����) join ������ٰ� �ٽ� �շ�
    pthread_join(thread_id2, NULL); // ���� �����尡 �ٸ� ���������� �� ���� ���ѳ��� �ڱⰡ ���� ���������ٸ�? �����Լ��� ������ ���α׷��� ���������� ������� ������ ���Ҵµ� ��ī��

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