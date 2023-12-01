/* 라이브러리 */
#define _CRT_SECURE_NO_WANRINGS
#include <stdio.h>
//debug 모드일 땐 debug용으로 빌드된 lib, dll파일을 사용해야 되고 release일 때도 마찬가지 헤더파일의 위치는 공통
#include "C:\Users\shkdh\Desktop\repos\TBC\Solution 16\Library_A\MyLibrary.h" // 이런 절대경로(MyLibrary.h - right click - Copy Full Path)보다는 상대경로(보통 라이브러리를 배포하거나 재사용할 때는 lib와 헤더파일 같이 배포하므로 사용자 입장에서는 자기가 사용하기 편리한 곳에 복사해서 사용)를 많이 사용한다
//#include <MyLibrary.h>  // [Configuration Properties]-[C/C++]-[General]-[Additional Include Directories]에 MyLibrary.h 이전의 절대경로 주소를 입력
/*
1>main.obj : error LNK2019: unresolved external symbol say_hello referenced in function main
1>main.obj : error LNK2019: unresolved external symbol say_world referenced in function main
1>C:\Users\shkdh\Desktop\repos\Solution 16\x64\Debug\Library_B.exe : fatal error LNK1120: 2 unresolved externals
*/
int main(void)
{
    // [Configuration Properties]-[Linker]-[General]-[Additional Library Directories]에 ex)C:\Users\shkdh\Desktop\repos\TBC\Solution 16\x64\Debug 절대경로 주소를 입력해야 링킹 에러가 발생하지 않는다
    // [Configuration Properties]-[Linker]-[Input]-[Additional Dependencies]에 생성한 .lib파일을 확장자까지 입력한다(ex. Library.lib;) 이미 라이브러리 파일들이 엄청나게 많은 것을 확인할 수 있다. 덕분에 편하게 이용가능
    // 절대경로라 exe파일까지 뒤섞인 곳에 있다.
    say_hello();
    say_world();

    return 0;
}
