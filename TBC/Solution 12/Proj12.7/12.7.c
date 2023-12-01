/*블록 영역의 정적(Static) 변수*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Static with no linkage: 정적 변수이기에 프로그램의 시작부터 끝까지 계속 메모리에 존재하지만 블록 안에서만 볼 수 있다(visible)
// 단, 포인터를 이용해 블록 밖에서도 간접적으로 접근할 수는 있지만 그렇게 사용하려는 경우 차라리 블록 밖에 변수를 선언하는 게 낫다
// 의외로 쓸모가 많다.

int* count()
{
    int ct = 0;  // 스택에 저장
    printf("count = %d %lld\n", ct, (long long)&ct);
    ct++;

    return &ct;  // 보통 값을 반환하지만 포인터를 반환하는 경우도 꽤 있다. ex) API, 하드웨어, 마우스의 포인터 등 허나
    // 함수 반환형을 int*로 바꿔보기(warning C4172: returning address of local variable or temporary: ct 변수 ct의 duration은 함수 블럭이 끝나면 사라진다. 내부이기에 함수가 종료된 이후에 해당 주소를 접근하려 하기에 경고 발생.
    // 스택 프레임 전체가 사용할 메모리를 미리 잡아 넣는 경우가 있기 때문에 포인터로 접근해서 가능한 경우도 있다. 컴파일러의 최적화 기법을 오용하는 것 허나 지양해야 한다.
}

int* static_count()
{
    static int ct = 0;  // 데이터 또는 BSS에 static하게 있는 영역에 저장. initialized only once(따라서 선언과 초기화를 분리할 경우 의미가 완전히 달라진다)

    printf("static count = %d %lld\n", ct, (long long)&ct);
    ct++;

    return &ct;  // 위에는 안 쓰지만 이건 쓸 수도 있음 함수 반환형을 int*로 바꿔보기(함수가 종료된 이후에도 포인터를 통해 접근하는 방식을 사용하기도 하지만 권장하지는 않으며 그러한 접근이 필요하다면 차라리 전역 변수로 선언하는 게 낫다)
}

//int func(static int i)
//{  // Warning(Error in GCC): parameter는 함수가 실행될 때 스택 프레임에 생성된다 그런데 static을 붙인다는 건 static한 메모리 공간에 파라미터를 집어넣겠다는 뜻
//}

void counter_caller()
{
    count();
}

void static_counter_caller()
{
    static_count();
}

int main()
{
    count();
    count(); //특정한 메모리를 가진 게 아니라 실행되는 함수가 count()밖에 없으니 올라왔다 빠졌다 하면서 같은 메모리를 사용한 거
    counter_caller(); // counter_caller() 스택 안에서 다시 한번 count()를 호출해서 쌓여있는 구조 12.5c 참조

    static_count();
    static_count();
    static_counter_caller(); // 두 번 호출해도 어차피 고정이다. 다 같은 메모리 static ct 그냥 ct 메모리 레이아웃이 다르다.

    return 0;
}