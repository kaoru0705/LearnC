#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern int g_int;// referencing declaration

static void tool(void)
{
	//
}
//static void fun_second(void);

void fun_second(void) // 앞에 static을 붙인다면? prototype에만 붙여도 linking이 되는 걸 막아버릴 수 있다.
/*
1>main.obj : error LNK2019: unresolved external symbol _fun_second referenced in function _main
1>C:\Users\user\Desktop\Solution 12\Debug\Proj12.11.exe : fatal error LNK1120: 1 unresolved externals
*/
//굳이 함수를 static으로 막을 필요가 있을까? 보통 파일을 분류할 때는 모듈로 분류한다. 어떤 기능을 하는 함수들을 모아두고 또 다른 기능을 하는 함수들을 모아 둠
//어떤 모듈을 만들었는데 외부에서 사용할 때는 fun_second만 접근해서 사용할 수 있게 하고 싶고 fun_second에서 사용하는 어떤 도구가 되는 함수가 있다면
// 그리고 tool()이라는 함수는 다른 곳에서 전혀 사용할 일이 없다고 판단된다면? static을 붙임
{
	tool();

	g_int += 1;
	printf("g_int is fun_second() %d %p\n", g_int, &g_int);
}