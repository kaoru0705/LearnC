/*  #include와 헤더 파일 우리가 가장 많이 사용하는 전처리 지시자 preprocessor directive인 include */
#include <stdio.h>                 // <> : 컴파일러가 이미 알고있는 위치. 표준 라이브러리 또는 별도로 설정해준 라이브러리. 허나 표준라이브러리 혹은 외부에서 라이브러리를 갖고 오는데 그 라이브러리를 일방적으로 사용하기만 할 때 <>가 일반적
#include "my_functions.h"          // "" : 일반적으로 자체 제작/수정한 라이브러리인 경우 "" 씀 containing folder에 다 같이 있다.
#include "my_structures.h"
#include "my_headers/my_macros.h"  // path. 상대경로(절대경로도 가능) \(windows에서는 이게 가능) / 둘 다 가능 "my_headers"라는 파일 안에 있음
//#include "C:\
//  ....."        // 포함할 헤더파일 폴더 복사해서 붙임 절대경로 허나 이렇게 쓰는 사람을 본적이 없음 보통 상대경로가 일반적
//#include "my_macros.h" //VS의 경우 [Properties]-[C/C++]-[Additional include Directories] 에서 .(현재 디렉토리라는 뜻)/(하위 디렉터리)my_headers/ or my_headers라고 적으면
//// 전처리기 컴파일러가 additional include directories로 되어있는 폴더들을 찾는다. 실수로 오타내면 error
//#include <my_macros.h> 위처럼 추가 경로 설정할 경우 이것도 됨
// 헤더파일은 공통이되는 부분을 밖으로 뺌 특히 선언을 묶어서 뺄 때 사용 예전 강의 참고
extern int status;

int main(void)
{
#include "hello_world.h"  // #include는 전처리기가 헤더파일의 소스코드를 복사 붙여넣기하는 방식이므로 헤더파일의 내용인 printf("Hello, world from a header file.\n");로 바뀐다
                          // 허나 함수안에 include한 건 재미삼아 한 거다. 절대 이렇게 안 함
    printf("PI = %f\n", PI);

    printf("%p %d\n", &status, status);  // status의 주소는 아래와 같다(=같은 오브젝트다)

    print_status();                      // status의 주소는 위와 같다(=같은 오브젝트다)

    printf("%d\n", multiply(51, 2));

    printf("main()\n");
    printf("Static function address %p\n", multiply);  // 아래 print_address()의 출력값과 다르다 static의 file scope가 다르다
    printf("Static variable address %p\n", &si);       // 아래 print_address()의 출력값과 다르다

    print_address();

    patient_info james = { "James Bone", 45 }, michael = { "Michael Jobs", 50 };

    return 0;
}