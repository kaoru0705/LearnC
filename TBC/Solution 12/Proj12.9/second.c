#include <stdio.h>

extern int g_int;  // referencing declaration(링커가 다른 파일에서 컴파일해서 만들어진 obj파일을 찾아서 연결해준다. 그래서 다른 파일에서 만들어진 함수들에서 같은 메모리를 공유하는 변수, 같은 변수, 같은 오브젝트를 사용하게 된다
// (최초에 g_int를 static으로 선언한 경우 링킹 에러 발생) 여기서 extern을 지운다면?
/*
1>main.c
1>second.obj : error LNK2001: unresolved external symbol _g_int
1>third.obj : error LNK2001: unresolved external symbol _g_int
*/


static void tool(void)
{  // 함수를 현재 모듈 내에서만 사용가능하도록 제한하고 싶을 때 static 키워드가 유용하게 쓰인다
    // do something
}

//static void fun_second(void);  // 함수의 프로토타입 또는 바디 중에 하나라도 static 키워드가 붙어 있다면 static 함수로 설정된다

void fun_second(void)
{  // 이 함수에 static을 붙이면 다른 파일에서 찾지 못하기에 링킹 에러 발생
    tool();

    g_int += 1;
    printf("g_int in fun_second() %d %p\n", g_int, &g_int);
}