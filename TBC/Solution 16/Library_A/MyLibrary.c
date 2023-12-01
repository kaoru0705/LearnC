/* 라이브러리 */
// [Configuration Properties]-[General]-[Configuration Type]에서 Static library 선택 후 빌드하면(선택 안 하면 운영체제가 main.c부터 찾으려 하므로 오류 발생 복습) .lib파일이 생성된다(Debug/Release 모드 둘 다 빌드하기)
// Static Library 작성한 프로그램에 라이브러리가 바로 포함이 된다. Dynamic Library 프로그램 자체가 라이브러리를 가지고 있는 게 아니라 실행할 때 동적으로 그때그때 가져다 씀
// 1>Library_A.vcxproj -> C:\Users\shkdh\Desktop\repos\Solution 16\x64\Debug\Library_A.lib
// 1>Library_A.vcxproj -> C:\Users\shkdh\Desktop\repos\Solution 16\x64\Release\Library_A.lib
// Debug/Release 모드에 따라 헤더파일은 공통이지만 .lib 파일이나 .dll 파일은 달라진다
#include "MyLibrary.h"

#include <stdio.h> // library. 컴파일은 영어에서 책을 출판하기 위해 '편집한다'는 의미

void say_hello()
{
    printf("Hello.\n");
}

void say_world()
{
    printf("World\n");
}