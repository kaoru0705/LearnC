/* 중요한 프로젝트는 책꽂이를 해라*/
/* Command-Line Arguments */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
- 비주얼 스튜디오 관련 팁

*같은 솔루션에 속한 프로젝트들의 .exe 파일은 해당 솔루션 파일이 위치한 디렉터리의 Debug 폴더(Debug 모드인 경우)에 저장된다
*.exe 파일이 생성되는 위치: ex) F:\repos\Solution 11\Debug\Proj11.10.exe [Solution Explorer에서 해당 프로젝트를 우클릭]-[Properties]-[General]-[Output Directory] $=구분(SolutionDir = .sln file 위치)$(Configuraton = debug or release? x64debug x64 release?)\여기에 저장
intermediate directory: 빌드할 때 중간중간에 사용하는 파일들의 저장하는 위치
*.exe 파일 이름: //-[General]-[Target Name(프로젝트 이름과 동일하다)]
* Configuration Type: .exe
* 기본적으로 visual studio가 솔루션을 세팅할 때 여러 프로젝트의 exe파일을 한 곳에 모아둔다. 그래서 open containing folder- debug엔 exe파일이 없음
*명령 프롬프트에서 .exe 파일 실행시키기: 1.경로를 포함한 파일명 입력  /  2. 탐색기로 찾은 파일 아이콘을 드래그 앤 드랍
*에디터에서 명령줄 인수 전달하는 방법: [Solution Explorer에서 해당 프로젝트를 우클릭]-[Properties]-[Debugging]-[Command Arguments]
* 
*/

// 사용자가 프로그램을 실행시킬 때 main() 함수에 인수를 입력할 수 있다
// 누가 넣어줄까? 운영체제가. 지금까지는 인수 없이 잘 실행시켜줬는데 프로그램을 실행시킬 때 사용자 혹은 프로그래머가 넣어줄 수 있다.
// 기본적으로 실행파일의 경로를 포함한 이름이 인수로 전달된다. 프로그램을 실행시킬 때 운영체제가 뒤에 붙여주는 arguments들을 보내줌
// main() 함수의 인수는 아예 없거나 있다면 아래의 형식을 준수하도록 운영체제와 c언어가 약속함
// 아예 없다면 나는 command-line arguments에 뭐가 들어오든 관심없다. 운영체제한테 보내주지 마세요
// command-line argument가 뭔지 이런 식으로 넣어주세요
int main(int argc, char* argv[])
{
    int count;
    printf("The command line has %d arguments:\n", argc);

    for (count = 0; count < argc; count++)
        printf("Arg %d : %s\n", count, argv[count]);

    return 0;
}